#include <iostream>

int main(){
	int i = -7;				// (signed) int
	signed sn = -5;				// signed
	signed int sni = -6;	

	short s = 13;				// (signed) short (int) 
	short int si = 14;
	signed short sns = 15;
	signed short int snsi = 16;

	long l = -7L;				// (signed) long (int)
	long long ll = 14LL;			// (signed) long long (int)

	unsigned j = 5U;			// unsigned (int)
	unsigned int ui = 2U;	
	unsigned short us = 23U;		// unsigned short (int)
	unsigned long ul = 5400UL;		// unsigned long (int)
	unsigned long long ull = 140ULL;	// unsigned long long (int) 
	
	float f = 7.2f;				// float
	double d = 7.2;				// double
	long double ld = 16.98L;		// long double

	char ch = 'm';				// char
	char16_t c16 = u'm';			// char16_t
	char32_t c32 = U'm';			// char32_t
	wchar_t w = L'm';			// wchar_t
	
	bool b = true;				// bool

	std::cout << "int i : " << i << " sizeof : " << sizeof(i) << std::endl;
	std::cout << "signed sn : " << sn << " sizeof : " << sizeof(sn) << std::endl;
	std::cout << "signed int sni : " << sni << " sizeof : " << sizeof(sni) << std::endl;
	std::cout << "short s : " << s << " sizeof : " << sizeof(s) << std::endl;
	std::cout << "short int si : " << si << " sizeof : " << sizeof(si) << std::endl;
	std::cout << "signed short : " << sns << " sizeof : " << sizeof(sns) << std::endl;
	std::cout << "signed short int : " << snsi << " sizeof : " << sizeof(snsi) << std::endl;
	std::cout << "long l : " << l << " sizeof : " << sizeof(l) << std::endl;
	std::cout << "long long ll : " << ll << " sizeof : " << sizeof(ll) << std::endl;
	std::cout << "unsigned j : " << j << " sizeof : " << sizeof(j) << std::endl;
	std::cout << "unsigned int ui : " << ui << " sizeof : " << sizeof(ui) << std::endl;
	std::cout << "unsigned short us : " << us << " sizeof : " << sizeof(us) << std::endl;
	std::cout << "unsigned long ul : " << ul << " sizeof : " << sizeof(ul) << std::endl;
	std::cout << "unsigned long long uul : " << ull << " sizeof : " << sizeof(ull) << std::endl;
	std::cout << "float f : " << f << " sizeof : " << sizeof(f) << std::endl;
	std::cout << "double d : " << d << " sizeof : " << sizeof(d) << std::endl;
	std::cout << "long double ld : " << ld << " sizeof : " << sizeof(ld) << std::endl;
	std::cout << "char ch : " << ch << " sizeof : " << sizeof(ch) << std::endl;
	std::cout << "char16_t c16 : " << c16 << " sizeof : " << sizeof(c16) << std::endl;
	std::cout << "char32_t c32 : " << c32 << " sizeof : " << sizeof(c32) << std::endl;
	std::cout << "wchar_t w : " << w << " sizeof : " << sizeof(w) << std::endl;
	std::cout << "bool b : " << b << " sizeof : " << sizeof(b) << std::endl;

	return 0;
}
