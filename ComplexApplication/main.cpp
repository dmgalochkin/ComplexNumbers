#include <iostream>
#include "TComplex.h"
int main()
{
  TComplex<double> c(3.0, 4.0);
  std::cout << c.Abs() << '\n';
  c.PrintTrigonometricForm();
}