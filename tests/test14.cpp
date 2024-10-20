
#include "gtest/gtest.h"
#include "main14.h"
#include <vector>
#include <numeric>
using namespace homework;
TEST(SumVector, Int){
std::vector<int> vint = {1,2,3,4,5};
auto sum_ints = sum_elements(vint);
auto sum_ints_ref = std::accumulate(vint.begin(),vint.end(),0);
ASSERT_EQ(sum_ints,sum_ints_ref);
}
TEST(SumVector, Double){
std::vector<double> vdouble = {1.1,2.2,3.3,4.4,5.5};
auto sum_doubles = sum_elements(vdouble, 0.0);
auto sum_doubles_ref =
std::accumulate(vdouble.begin(),vdouble.end(),0.0);
ASSERT_NEAR(sum_doubles,sum_doubles_ref,1e-10);
}
TEST(SumVector, String){
std::vector<std::string> vstring = {"hello","world"};
auto sum_string = sum_elements(vstring, std::string());
ASSERT_EQ(sum_string,"helloworld");
}