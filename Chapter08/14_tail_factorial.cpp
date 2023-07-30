#include <iostream>

int tail_factorial(int n, int result)
{
  if (n <= 1) return result;
  return tail_factorial(n - 1, n * result);
}

int main()
{
    std::cout << tail_factorial(5,1);
}