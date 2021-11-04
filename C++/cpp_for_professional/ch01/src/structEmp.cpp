#include <iostream>
#include "employeestruct.h"

int main()
{
	// 직원 레코드 생성 및 값 채우기
	Employee anEmployee;
	anEmployee.firstInitial = 'M';
	anEmployee.lastInitial = 'G';
	anEmployee.employeeNumber = 42;
	anEmployee.salary = 80000;

	// 직원 레코드에 저장된 값 출력하기
	std::cout << "Employee : " << anEmployee.firstInitial <<
				      anEmployee.lastInitial << std::endl;

	std::cout << "Number : " << anEmployee.employeeNumber << std::endl;
	std::cout << "Salary : " << anEmployee.salary << std::endl;

	return 0;

}
