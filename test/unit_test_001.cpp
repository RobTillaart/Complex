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

  a += b;
  assertEqual(13, a.real());
  assertEqual(-1.5, a.imag());

  a -= b;
  assertEqual(10,  a.real());
  assertEqual(-2.5, a.imag());

  a *= b;
  assertEqual(32.5,  a.real());
  assertEqual(2.5,  a.imag());

  a /= b;
  assertEqual(10, a.real());
  assertEqual(-2.5, a.imag());
}

unittest(test_basic_functions)
{
  fprintf(stderr, COMPLEX_LIB_VERSION);

  Complex a;
  assertEqual(0, a.real());
  assertEqual(0, a.imag());

  a.set(5, 34);
  assertEqual(5, a.real());
  assertEqual(34, a.imag());

  a.setReal(10);
  assertEqual(10, a.real());
  assertEqual(34, a.imag());

  a.setImag(-2.5);
  assertEqual(10, a.real());
  assertEqual(-2.5, a.imag());

  float ph = a.phase();
  assertEqual(0, ph);
  
  float mod = a.modulus();
  assertEqual(0, mod);

  Complex conj = a.conjugate();
  assertEqual(0, conj.real());
  assertEqual(0, conj.imag());

  Complex reci = a.reciprocal();
  assertEqual(0, reci.real());
  assertEqual(0, reci.imag());
}


unittest(test_power_functions)
{
  fprintf(stderr, COMPLEX_LIB_VERSION);

  Complex a(3, 4);
  Complex b;

  b = a.c_sqrt();
  assertEqual(0, b.real());
  assertEqual(0, b.imag());

  b = a.c_sqr();
  assertEqual(0, b.real());
  assertEqual(0, b.imag());

  b = a.c_exp();
  assertEqual(0, b.real());
  assertEqual(0, b.imag());

  b = a.c_log();
  assertEqual(0, b.real());
  assertEqual(0, b.imag());

  b = a.c_log10();
  assertEqual(0, b.real());
  assertEqual(0, b.imag());

  b = a.c_pow(a);
  assertEqual(0, b.real());
  assertEqual(0, b.imag());

  b = a.c_logn(a);
  assertEqual(0, b.real());
  assertEqual(0, b.imag());
}



unittest_main()

// --------
