#include <gtest.h>
#include "TComplex.h"

TEST(TComplexTest, DefaultConstructor)
{
  TComplex<double> c;
  EXPECT_DOUBLE_EQ(c.GetRe(), 0.0);
  EXPECT_DOUBLE_EQ(c.GetIm(), 0.0);
}

TEST(TComplexTest, ParameterizedConstructor)
{
  TComplex<double> c(2.5, 3.7);
  EXPECT_DOUBLE_EQ(c.GetRe(), 2.5);
  EXPECT_DOUBLE_EQ(c.GetIm(), 3.7);
}

TEST(TComplexTest, CopyConstructor)
{
  TComplex<double> original(5.0, 7.0);
  TComplex<double> copy(original);
  EXPECT_DOUBLE_EQ(copy.GetRe(), 5.0);
  EXPECT_DOUBLE_EQ(copy.GetIm(), 7.0);
}

TEST(TComplexTest, SetGetRe)
{
  TComplex<double> c;
  c.SetRe(4.2);
  EXPECT_DOUBLE_EQ(c.GetRe(), 4.2);
}

TEST(TComplexTest, SetGetIm)
{
  TComplex<double> c;
  c.SetIm(-3.1);
  EXPECT_DOUBLE_EQ(c.GetIm(), -3.1);
}

TEST(TComplexTest, AdditionOperator)
{
  TComplex<double> c1(1.0, 2.0);
  TComplex<double> c2(3.0, 4.0);
  TComplex<double> result = c1 + c2;
  EXPECT_DOUBLE_EQ(result.GetRe(), 4.0);
  EXPECT_DOUBLE_EQ(result.GetIm(), 6.0);
}

TEST(TComplexTest, SubtractionOperator)
{
  TComplex<double> c1(5.0, 5.0);
  TComplex<double> c2(2.0, 3.0);
  TComplex<double> result = c1 - c2;
  EXPECT_DOUBLE_EQ(result.GetRe(), 3.0);
  EXPECT_DOUBLE_EQ(result.GetIm(), 2.0);
}

TEST(TComplexTest, MultiplicationOperator)
{
  TComplex<double> c1(1.0, 2.0);
  TComplex<double> c2(3.0, 4.0);
  TComplex<double> result = c1 * c2;
  EXPECT_DOUBLE_EQ(result.GetRe(), -5.0);
  EXPECT_DOUBLE_EQ(result.GetIm(), 10.0);
}

TEST(TComplexTest, DivisionOperator)
{
  TComplex<double> c1(4.0, 4.0);
  TComplex<double> c2(2.0, 2.0);
  TComplex<double> result = c1 / c2;
  EXPECT_DOUBLE_EQ(result.GetRe(), 2.0);
  EXPECT_DOUBLE_EQ(result.GetIm(), 0.0);
}

TEST(TComplexTest, DivisionByZeroThrows)
{
  TComplex<double> c1(1.0, 1.0);
  TComplex<double> c2(0.0, 0.0);
  EXPECT_THROW(c1 / c2, std::invalid_argument);
}

TEST(TComplexTest, PlusEqualsOperator)
{
  TComplex<double> c1(1.0, 2.0);
  TComplex<double> c2(3.0, 4.0);
  c1 += c2;
  EXPECT_DOUBLE_EQ(c1.GetRe(), 4.0);
  EXPECT_DOUBLE_EQ(c1.GetIm(), 6.0);
}

TEST(TComplexTest, MultiplyEqualsOperator)
{
  TComplex<double> c1(1.0, 2.0);
  TComplex<double> c2(3.0, 4.0);
  c1 *= c2;
  EXPECT_DOUBLE_EQ(c1.GetRe(), -5.0);
  EXPECT_DOUBLE_EQ(c1.GetIm(), 10.0);
}

TEST(TComplexTest, EqualityOperator)
{
  TComplex<double> c1(2.0, 3.0);
  TComplex<double> c2(2.0, 3.0);
  TComplex<double> c3(3.0, 3.0);
  EXPECT_TRUE(c1 == c2);
  EXPECT_FALSE(c1 == c3);
}

TEST(TComplexTest, InequalityOperator)
{
  TComplex<double> c1(2.0, 3.0);
  TComplex<double> c2(2.0, 3.0);
  TComplex<double> c3(3.0, 3.0);
  EXPECT_FALSE(c1 != c2);
  EXPECT_TRUE(c1 != c3);
}

TEST(TComplexTest, AssignmentOperator) {
  TComplex<double> c1(5.0, 7.0);
  TComplex<double> c2;
  c2 = c1;
  EXPECT_DOUBLE_EQ(c2.GetRe(), 5.0);
  EXPECT_DOUBLE_EQ(c2.GetIm(), 7.0);
}

TEST(TComplexTest, AbsMethod) {
  TComplex<double> c(3.0, 4.0);
  EXPECT_DOUBLE_EQ(c.Abs(), 5.0);
}

TEST(TComplexTest, FractionalPowerBasic) {
  TComplex<double> c(4.0, 0.0);
  TComplex<double> res = c.Power(0.5);
  EXPECT_NEAR(res.GetRe(), 2.0, 1e-6);
  EXPECT_NEAR(res.GetIm(), 0.0, 1e-6);
}

TEST(TComplexTest, NegativeBaseFractionalPower) {
  TComplex<double> c(-1, 0);
  TComplex<double> res = c.Power(0.5);
  EXPECT_NEAR(res.GetRe(), 0.0, 1e-6);
  EXPECT_NEAR(res.GetIm(), 1.0, 1e-6);
}

TEST(TComplexTest, ComplexNumberFractionalPower) {
  TComplex<double> c(1, 1);
  TComplex<double> res = c.Power(0.5);
  EXPECT_NEAR(res.GetRe(), 1.098684, 1e-6);
  EXPECT_NEAR(res.GetIm(), 0.455090, 1e-6);
}

TEST(TComplexTest, NegativeExponent) {
  TComplex<double> c(2, 0);
  TComplex<double> res = c.Power(-1.5);
  EXPECT_NEAR(res.GetRe(), 0.353553, 1e-6);
  EXPECT_NEAR(res.GetIm(), 0.0, 1e-6);
}

TEST(TComplexTest, ZeroToFractionalPower) {
  TComplex<double> c(0, 0);
  TComplex<double> res = c.Power(3.5);
  EXPECT_DOUBLE_EQ(res.GetRe(), 0.0);
  EXPECT_DOUBLE_EQ(res.GetIm(), 0.0);
}

TEST(TComplexTest, InvalidZeroPower) {
  TComplex<double> c(0, 0);
  EXPECT_THROW(c.Power(-2.5), std::invalid_argument);
  EXPECT_THROW(c.Power(0.0), std::invalid_argument);
}