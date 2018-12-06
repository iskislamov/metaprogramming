#include <cassert>
#include "typelist.h"
#include "scatter.h"


class A {};


using TL1 = TypeList<int>;
using TL2 = TypeList<char, short, std::string>;
using TL3 = TypeList<double, float, std::string, char, int, NullType>;
using TL4 = TypeList<long int, std::string, float, double, int, char, char, int, char>;
using TL5 = TypeList<NullType>;


using GSH = GenScatterHierarchy<TL3, Unit>;


int main() {
	std::cout << Length<TL4>::value << std::endl;
	printTypeList<TL3>();
	printTypeList<Erase<int, TL3>::result>();

	GSH gsh;
	float f = Field<float>(gsh).value_;
	double d = Field<double>(gsh).value_;
	static_cast<Unit<int>&>(gsh).value_ = 21;
	int i = Field<int>(gsh).value_;
	assert(i == 21);

	int n;
	std::cin >> n;
	return 0;
}