#include <iostream>

int main()
{
	float myFloat = 3.14f;

	int i1 = (int)myFloat;			// 방법1
	int i2 = int(myFloat);			// 방법2
	int i3 = static_cast<int>(myFloat);	// 방법3

	short someShort = 10;
	long someLong = someShort;		// 명시적으로 캐스팅 할 필요가 없다. short < long

	std::cout << "myFloat = 3.14f" << std::endl;
	std::cout << "i1 = (int)myFloat : " << i1 << std::endl;
	std::cout << "i1 = int(myFloat) : " << i2 << std::endl;
	std::cout << "i1 = static_cast<int>(myFloat) : " << i3 << std::endl;

	return 0;
}
