#include "5_class_template_implicit_inst_v2.h"

int main() {
	X<int> xi;
	xi.f();
	xi.g();  //if un-comment this line, we'll have build errors
	return 0;
}