#include <ranges>
#include <vector>
#include <cmath>
#include <iostream>

int main()
{
    std::vector<double> vec{ 1.1, 2.2, 4.3, 5.6, 2.4 };
    auto result = vec | std::views::transform(static_cast<double (*)(double)>(std::sqrt));

    for (const auto& value : result)
    {
        std::cout << value << " ";
    }

    return 0;
}
