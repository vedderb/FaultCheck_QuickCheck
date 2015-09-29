/*
	Copyright 2014 Benjamin Vedder	benjamin@vedder.se

	This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    */

package faultcheck

import org.scalacheck._
import org.scalacheck.Properties
import org.scalacheck.Prop.forAll
import org.bridj.Pointer
import org.bridj.Pointer._
import faultcheck.CWrapper._
import org.scalacheck.Prop._
import org.scalatest.prop.Checkers._
import faultcheck.TestHelpers._

object PacketProperties {

  val testMarker = ""

  val propCorruptionBitFlip = forAll(
    Gen.choose(-128, 127),
    Gen.choose(-128, 127),
    Gen.choose(0, 7),
    Gen.choose(0, 7),
    Gen.alphaStr) {
      (b1, b2, flip1, flip2, name) =>
        (flip1 >= 0 && flip2 >= 0) ==> { // This precondition is required for shrinking
          val bytePtr = allocateBytes(2)
          val byteResPtr = allocateBytes(2)
          val len = allocateInt()
          val str = pointerToCString(name)

          bytePtr(0) = b1.toByte
          bytePtr(1) = b2.toByte

          faultcheck_packet_removeAllFaults()
          faultcheck_packet_addFaultCorruptionBitFlip(str, 0, flip1)
          faultcheck_packet_addFaultCorruptionBitFlip(str, 1, flip2)

          faultcheck_packet_addPacket(str, bytePtr, 2)
          faultcheck_packet_getPacket(str, byteResPtr, len)

          val res = (b1.toByte ^ (1 << flip1)).toByte == byteResPtr(0) &&
            (b2.toByte ^ (1 << flip2)).toByte == byteResPtr(1)

          if (!res) {
            println("b1: " + b1)
            println("b2: " + b2)
            println("PTR0: " + byteResPtr(0))
            println("PTR1: " + byteResPtr(1))
            println("flip1: " + flip1)
            println("flip2: " + flip2 + "\n")
          }

          res
        }
    }

  val propDrop = forAll(
    Gen.listOf(Gen.listOf(Gen.choose(-128, 127))),
    Gen.choose(0, 100),
    Gen.alphaStr) {
      (packets, toDrop, name) =>
        val str = pointerToCString(name)

        faultcheck_packet_removeAllFaults()
        faultcheck_packet_addFaultDrop(str, toDrop)

        for (i <- packets) {
          val array = allocateBytes(i.size)
          var ind = 0

          for (j <- i) {
            array(ind) = j.toByte
            ind = ind + 1
          }

          faultcheck_packet_addPacket(str, array, i.size)
        }

        val resArray = allocateBytes(400)
        val size = allocateInt()
        var resListList = List[List[Int]]()

        while (faultcheck_packet_getPacket(str, resArray, size) != 0) {
          var resList = List[Int]()

          for (i <- 0 until size(0)) {
            resList = resList :+ resArray(i).toInt
          }

          resListList = resListList :+ resList
        }

        resListList == packets.slice(toDrop, packets.size);
    }
}
