#include <vector>
#include <cmath>

std::vector<double> pure_calc_square_roots(const std::vector<double>& vec)
{
  std::vector<double> new_vector;
  for (const auto& elem : vec) {
    new_vector.push_back(std::sqrt(elem));
  }
  return new_vector;
}

int main(){
    std::vector<double> vec{1.1, 2.2, 4.3, 5.6, 2.4};
    pure_calc_square_roots(vec);
}