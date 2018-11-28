#include "observer.h"
#include "proxy.h"
#include "mediator.h"


void test1() {
	A* a1 = new A();
	A a2;
	A a3;
	B b;
	Pattern<OBSERVER> obs;

	obs.attach(&b);

	obs.addSubscriber(a1);
	obs.addSubscriber(&a2);
	obs.addSubscriber(&a2);

	obs.execute();

	obs.addSubscriber(&a3);
	obs.execute();

	delete a1;

}


void test2() {
	B* b = new B();
	A* a1 = new A();
	A* a2 = new A();
	Pattern<PROXY> prx;
	a1->execute(&prx);
	prx.attach(b);
	a2->execute(&prx);
	delete b;
	delete a1;
	delete a2;
}

void test3() {
	A a;
	B* b1 = new B();
	B* b2 = new B();
	B* b3 = new B();

	Pattern<MEDIATOR> mediator;

	mediator.attach(b1);
	mediator.attach(b1);
	mediator.attach(b2);
	a.execute(&mediator);
	a.execute(&mediator);
	a.execute(&mediator);

	mediator.attach(b3);
	a.execute(&mediator);
	delete b1;
	delete b2;
	delete b3;
}

int main() {
	srand(time(0));
	std::cout << "Observer test:" << std::endl;
	test1();
	std::cout << "Proxy test:" << std::endl;
	test2();
	std::cout << "Mediator test:" << std::endl;
	test3();

	int a;
	std::cin >> a;
	return 0;
}