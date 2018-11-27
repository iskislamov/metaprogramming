#include "typelist.h"
#include "hierarchy.h"
#include "fibonacci.h"
#include <typeinfo>


class A {
};

class B : A {

};


using TL1 = TypeList<int>;
using TL2 = TypeList<char, short, std::string>;
using TL3 = TypeList<double, float, float, double, int, char, int, NullType>;
using TL4 = TypeList<long int, std::string, float, double, int, char, char, int, char, A>;

using GLH = GenLinearHierarchy<Fibonacci<7>::value, TL4, Unit>;
using GSH = GenScatterHierarchy<TL4, Unit>;

void test() {
	std::cout << std::boolalpha << IsEmpty<TL1>::value << " " << IsEmpty<EmptyList>() << std::endl;
	std::cout << Length<TL3>::value << " " << Length<EmptyList>() << std::endl;
	static_assert(std::is_same<TypeAt<1, TL2>::type, short>::value, "Something wrong!");
	printTypeList<TL4>();
	std::cout << typeid(TypeAt<7, TL4>::type).name();
	printTypeList<Skip<Fibonacci<6>::value, TL4>::result>();
}

int main() {
	GLH glh;
	GSH gsh;

	std::cout << sizeof(static_cast<GenLinearHierarchy<Fibonacci<0>::value , TL4, Unit>> (gsh)) << std::endl;
	std::cout << sizeof(TypeAt<0, TL4>::type) << std::endl;
	
	std::cout << sizeof(static_cast<GenLinearHierarchy<Fibonacci<1>::value, Skip<Fibonacci<0>::value, TL4>::result, Unit>> (gsh)) << std::endl;
	std::cout << sizeof(TypeAt<1, TL4>::type) << std::endl;
	return 0;
}
