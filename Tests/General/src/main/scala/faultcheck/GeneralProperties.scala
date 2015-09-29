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

object GeneralProperties {

  val testMarker = ""
  
  val propSetTo = forAll(smallInt, smallInt, smallerPosInt) { (par, set, num) =>
    val name = "test"
    val str = pointerToCString(name)
  
    faultcheck_removeAllFaults()
    faultcheck_addFaultSetTo(str, par)
    
    val fault = StuckToValue(par)

    val res = faultIterate(num, set, fault, name)
    
    print(testMarker)
    res
  }
  
  val propBitflip = forAll(Gen.choose(0, 31), smallInt, smallerPosInt) { (par, set, num) =>
    val name = "test"
    val str = pointerToCString(name)
  
    faultcheck_removeAllFaults()
    faultcheck_addFaultBitFlip(str, par)
    
    val fault = BitFlip(par)
    val res = faultIterate(num, set, fault, name)
    
    print(testMarker)
    res
  }

  val propAmplification = forAll(smallInt, smallInt, smallerPosInt) { (set, par, num) =>
    val name = "test"
    val str = pointerToCString(name)

    faultcheck_removeAllFaults()
    faultcheck_addFaultAmplification(str, par)
    
    val fault = Scaling(par)

    val res = faultIterate(num, set, fault, name)
    
    print(testMarker)
    res
  }
  
  val propTriggeredSetTo = forAll(smallInt, smallerPosInt, smallerPosInt, smallInt)
  { (par, time, duration, set) =>
    // This is required for shrinking to avoid negative numbers
    (time >= 0 && duration >= 0) ==> {
      val name = "test"
      val str = pointerToCString(name)

      faultcheck_removeAllFaults()
      faultcheck_addFaultSetTo(str, par)
      faultcheck_setTriggerAfterIterations(str, time)
      faultcheck_setDurationAfterTrigger(str, duration)
      
      val fault = StuckToValue(par)
      val res = evalTrigger(time, duration, set, fault, name)
      
      // Print the shrinking sequence
      if (!res) {
        println(" Set: " + set + " par: " + par + " time: " + time + " dur: " + duration)
      }
      
      print(testMarker)
      res
    }
  }

  val propTriggeredAmplification = forAll(smallerPosInt, smallerPosInt, smallerPosInt, smallInt) 
  { (duration, time, set, scale) =>
    // This is required for shrinking to avoid negative numbers
    (time >= 0 && duration >= 0) ==> {
      val name = "test"
      val str = pointerToCString(name)

      faultcheck_removeAllFaults()
      faultcheck_addFaultAmplification(str, scale)
      faultcheck_setTriggerAfterIterations(str, time)
      faultcheck_setDurationAfterTrigger(str, duration)
      
      val fault = Scaling(scale)
      val res = evalTrigger(time, duration, set, fault, name)
      
      // Print the shrinking sequence
      if (!res) {
        //println(" Set: " + set + " scale: " + scale + " time: " + time + " dur: " + duration)
      }
      
      print(testMarker)
      res
    }
  }
  
  val propTriggeredBitflip = forAll(Gen.choose(0, 31), smallerPosInt, smallerPosInt, smallInt) 
  { (bit, time, duration, set) =>
    // This is required for shrinking to avoid negative numbers
    (time >= 0 && bit >= 0 && duration >= 0) ==> {
      val name = "test"
      val str = pointerToCString(name)

      faultcheck_removeAllFaults()
      faultcheck_addFaultBitFlip(str, bit)
      faultcheck_setTriggerAfterIterations(str, time)
      faultcheck_setDurationAfterTrigger(str, duration)
      
      val fault = BitFlip(bit)
      val res = evalTrigger(time, duration, set, fault, name)
      
      // Print the shrinking sequence
      if (!res) {
        println(" Set: " + set + " bit: " + bit + " time: " + time + " dur: " + duration)
      }

      print(testMarker)
      res
    }
  }
}

