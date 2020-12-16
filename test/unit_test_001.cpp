//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2020-12-16
// PURPOSE: unit tests for the Complex datatype Library
//          https://github.com/RobTillaart/Complex
//          https://github.com/Arduino-CI/arduino_ci/blob/master/REFERENCE.md
//

// supported assertions
// ----------------------------
// assertEqual(expected, actual)
// assertNotEqual(expected, actual)
// assertLess(expected, actual)
// assertMore(expected, actual)
// assertLessOrEqual(expected, actual)
// assertMoreOrEqual(expected, actual)
// assertTrue(actual)
// assertFalse(actual)
// assertNull(actual)

#include <ArduinoUnitTests.h>

#include "Arduino.h"
#include "Complex.h"


unittest_setup()
{
}

unittest_teardown()
{
}

unittest(test_constructor)
{
  fprintf(stderr, COMPLEX_LIB_VERSION);

  Complex c1(10.0, -2.0);
  Complex c2(3, 0);
  Complex c3(-10, 4);
  Complex c4(-5,-5);
  Complex c5;  // (0, 0)

  assertEqual(10.0, c1.real());
  assertEqual(-2.0, c1.imag());
  assertEqual( 3.0, c2.real());
  assertEqual( 0.0, c2.imag());
  assertEqual(-10,  c3.real());
  assertEqual(4.0,  c3.imag());
  assertEqual(-5.0, c4.real());
  assertEqual(-5.0, c4.imag());
  assertEqual(0.0, c5.real());
  assertEqual(0.0, c5.imag());
  
  // one is a default available var.
  assertEqual(1.0, one.real());
  assertEqual(0.0, one.imag());
}

unittest(test_basic_math)
{
  fprintf(stderr, COMPLEX_LIB_VERSION);

  Complex a(10.0, -2.5);
  Complex b(3, 1);
  
  Complex c1 = a + b;
  assertEqual(13, c1.real());
  assertEqual(-1.5, c1.imag());

  Complex c2 = a - b;
  assertEqual(7,  c2.real());
  assertEqual(-3.5, c2.imag());

  Complex c3 = a * b;
  assertEqual(32.5,  c3.real());
  assertEqual(2.5,  c3.imag());

  Complex c4 = a / b;
  assertEqual(2.75, c4.real());
  assertEqual(-1.75, c4.imag());
  
  Complex c5 = -a;
  assertEqual(-10, c5.real());
  assertEqual(2.5, c5.imag());
}

unittest_main()

// --------
