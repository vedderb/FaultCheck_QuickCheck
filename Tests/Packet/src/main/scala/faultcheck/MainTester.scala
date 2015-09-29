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
import faultcheck.PacketProperties._
import org.scalacheck.Prop._
import org.scalacheck.Test.Parameters
import org.scalatest.prop.Checkers._

object MainTester {

  val propTest = forAll(Gen.choose(1, 4), Gen.choose(1, 4)) {
    (x: Int, y: Int) =>
      true
  }

  def myCheck(name: String, prop: Prop, numTests: Int) = {
    println("\nTesting property " + name)
    check(prop, Parameters.default.withMinSuccessfulTests(numTests))
    println("OK, passed " + numTests + " tests.")
  }

  def main(args: Array[String]) {
    val numTests = 1000

    myCheck("Corruption BitFlip", propCorruptionBitFlip, numTests)
    myCheck("Drop", propDrop, numTests)
  }

}
