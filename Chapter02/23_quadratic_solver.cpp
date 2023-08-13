#include<iostream>
#include <cmath>

class QuadraticSolver {
public:
	QuadraticSolver() = default;
	void set_a(double a) { a_ = a; }
	void set_b(double b) { b_ = b; }
	void set_c(double c) { c_ = c; }

	void find_discriminant() { discriminant_ = b_ * b_ - 4 * a_ * c_; }

	double solve() {
		if (discriminant_ < 0) {
			std::cout << "No real roots exist." << std::endl;
			return 0;
		}
		else {
			double x1 = (-b_ + std::sqrt(discriminant_)) / (2 * a_);
			double x2 = (-b_ - std::sqrt(discriminant_)) / (2 * a_);
			if (x1 == x2) {
				std::cout << "The equation has one real root." << std::endl;
			}
			else {
				std::cout << "The equation has two real roots." << std::endl;
			}
			return x1;
		}
	}
private:
	double a_;
	double b_;
	double c_;
	double discriminant_;
};
int main() {
	QuadraticSolver solver;
	solver.set_a(2);
	solver.set_b(5);
	solver.set_c(-8);
	solver.find_discriminant();
	std::cout << "x is: " << solver.solve() << std::endl;
	return 0;
}
