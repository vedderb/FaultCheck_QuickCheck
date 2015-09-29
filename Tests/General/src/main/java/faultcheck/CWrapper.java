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

package faultcheck;

import org.bridj.BridJ;
import org.bridj.CRuntime;
import org.bridj.Pointer;
import org.bridj.ann.CLong;
import org.bridj.ann.Library;
import org.bridj.ann.Runtime;

@Library("FaultCheck") 
@Runtime(CRuntime.class) 
public class CWrapper {
	static {
		BridJ.register();
	}
	/**
	 * Original signature : <code>void faultcheck_addFaultBitFlip(const char*, int)</code><br>
	 * <i>native declaration : line 2</i>
	 */
	native public static void faultcheck_addFaultBitFlip(Pointer<Byte > identifier, int bitToFlip);
	/**
	 * Original signature : <code>void faultcheck_addFaultBitFlipRandom(const char*)</code><br>
	 * <i>native declaration : line 3</i>
	 */
	native public static void faultcheck_addFaultBitFlipRandom(Pointer<Byte > identifier);
	/**
	 * Original signature : <code>void faultcheck_addFaultAmplification(const char*, double)</code><br>
	 * <i>native declaration : line 4</i>
	 */
	native public static void faultcheck_addFaultAmplification(Pointer<Byte > identifier, double factor);
	/**
	 * Original signature : <code>void faultcheck_addFaultOffset(const char*, double)</code><br>
	 * <i>native declaration : line 5</i>
	 */
	native public static void faultcheck_addFaultOffset(Pointer<Byte > identifier, double constant);
	/**
	 * Original signature : <code>void faultcheck_addFaultSetTo(const char*, double)</code><br>
	 * <i>native declaration : line 6</i>
	 */
	native public static void faultcheck_addFaultSetTo(Pointer<Byte > identifier, double value);
	/**
	 * Original signature : <code>void faultcheck_setTriggerOnceAfterIterations(const char*, unsigned long)</code><br>
	 * <i>native declaration : line 7</i>
	 */
	native public static void faultcheck_setTriggerOnceAfterIterations(Pointer<Byte > identifier, @CLong long iterations);
	/**
	 * Original signature : <code>void faultcheck_setTriggerAfterIterations(const char*, unsigned long)</code><br>
	 * <i>native declaration : line 8</i>
	 */
	native public static void faultcheck_setTriggerAfterIterations(Pointer<Byte > identifier, @CLong long iterations);
	/**
	 * Original signature : <code>void faultcheck_setDurationAfterTrigger(const char*, int)</code><br>
	 * <i>native declaration : line 9</i>
	 */
	native public static void faultcheck_setDurationAfterTrigger(Pointer<Byte > identifier, int iterations);
	/**
	 * Original signature : <code>void faultcheck_removeAllFaultsIdentifier(const char*)</code><br>
	 * <i>native declaration : line 10</i>
	 */
	native public static void faultcheck_removeAllFaultsIdentifier(Pointer<Byte > identifier);
	/**
	 * Original signature : <code>void faultcheck_removeAllFaults()</code><br>
	 * <i>native declaration : line 11</i>
	 */
	native public static void faultcheck_removeAllFaults();
	/**
	 * Original signature : <code>void faultcheck_injectFaultInt(const char*, int*)</code><br>
	 * <i>native declaration : line 12</i>
	 */
	native public static void faultcheck_injectFaultInt(Pointer<Byte > identifier, Pointer<Integer > integer);
}
