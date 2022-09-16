#include "include/factorial.hpp"

#include <limits>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cassert>

const int digits_per_vector_element = 12;

std::string factorial(uint64_t n)
{
  uint64_t max_element_per_vector_element = 1;
  for (int i = 0; i < digits_per_vector_element; i++)
  {
    max_element_per_vector_element *= 10;
  }

  assert(n <= (std::numeric_limits<uint64_t>::max() / max_element_per_vector_element - 1));

  std::vector<uint64_t> result_vec(1, 1);
  for (uint64_t i = 2; i <= n; i++)
  {
    uint64_t carry = 0;
    for (int j = 0; j < result_vec.size(); j++)
    {
      uint64_t tmp_result = result_vec[j] * i + carry;
      result_vec[j] = tmp_result % max_element_per_vector_element;
      carry = tmp_result / max_element_per_vector_element;
    }
    while (carry > 0)
    {
      result_vec.push_back(carry % max_element_per_vector_element);
      carry /= max_element_per_vector_element;
    }
  }

  std::stringstream stringStream;
  stringStream << result_vec[result_vec.size() - 1];
  for (int i = result_vec.size() - 2; i >= 0; i--)
    stringStream << std::setw(digits_per_vector_element) << std::setfill('0') << result_vec[i];

  return stringStream.str();
}
