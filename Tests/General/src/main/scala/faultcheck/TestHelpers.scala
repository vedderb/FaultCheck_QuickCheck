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
import faultcheck.CWrapper._
import org.bridj.Pointer._

object TestHelpers {
  val smallInt = Gen.choose(-2000, 2000)
  val smallerPosInt = Gen.choose(1, 10)

  abstract class Fault
  case class BitFlip(bit: Int) extends Fault
  case class Scaling(scale: Int) extends Fault
  case class StuckToValue(value: Int) extends Fault

  def evalTrigger(time: Int, duration: Int, set: Int, fault: Fault, name: String): Boolean = {
    val intPtr = allocateInt
    val str = pointerToCString(name)
    
    intPtr(0) = set
    
    faultcheck_injectFaultInt(str, intPtr)
    
    if (time > 0) {
      if (intPtr(0) == set) {
        evalTrigger(time - 1, duration, set, fault, name)
      } else {
        false
      }
    } else if (duration > 0) {
      if (intPtr(0) == evalFault(fault, set)) {
        evalTrigger(time, duration - 1, set, fault, name)
      } else {
        false
      }
    } else {
      intPtr(0) == set
    }
  }

  def evalFault(t: Fault, set: Int): Int = t match {
    case BitFlip(bit) => set ^ (1 << bit)
    case Scaling(n) => set * n
    case StuckToValue(n) => n
  }

  def faultIterate(num: Int, set: Int, fault: Fault, name: String): Boolean = {
    val str = pointerToCString(name)

    val intPtr = allocateInt
    intPtr(0) = set
    faultcheck_injectFaultInt(str, intPtr)

    val res = intPtr(0) == evalFault(fault, set)

    if (num > 0 && res) {
      faultIterate(num - 1, set, fault, name)
    } else {
      res
    }
  }
}

