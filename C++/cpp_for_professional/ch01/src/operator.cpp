#include <iostream>

int main()
{
	int someInteger = 256;
	short someShort;
	long someLong;
	float someFloat;
	double someDouble;

	someInteger++;	// 256 -> 257
	someInteger *= 2;	// 514
	someShort = static_cast<short>(someInteger);	// 514
	someLong = someShort * 10000;	// 5140000
	someFloat = someLong + 0.785f;	// 5140000.785 => 5140000??
	someDouble = static_cast<double>(someFloat) / 100000;	// 51.40000785

	std::cout << "someFloat : " << someFloat << std::endl;
	std::cout << "someDouble : " << someDouble << std::endl;

	return 0;
}
