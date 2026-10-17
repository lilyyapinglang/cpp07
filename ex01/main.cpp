
#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T> void add(T &a)
{
	a = a + 1;
}

template <typename T> void print(const T &a)
{
	std::cout << a << " ";
}
int	main(void)
{
	// test int
	std::cout << "\n=== 1. TEST : int ===" << std::endl;

	int a[6] = {1, 1, 3, 1, 5, 4};
	iter(a, 6, print<int>);
	std::cout << std::endl;
	iter(a, 6, add<int>);
	iter(a, 6, print<int>);
	std::cout << std::endl;

	std::cout << "\n=== 1-2. TEST : const int ===" << std::endl;

	const int x[6] = {1, 1, 3, 1, 5, 4};
	iter(x, 6, print<int>);
	std::cout << std::endl;
	// iter(x, 6, add<int>);
	// iter(x, 6, print<int>);
	std::cout << std::endl;

	std::cout << "\n=== 2. TEST : float ===" << std::endl;

	// test float
	float b[3] = {42.1, 42.4, 42.7};
	iter(b, 3, print<float>);

	std::cout << std::endl;

	iter(b, 3, add<float>);
	iter(b, 3, print<float>);
	std::cout << std::endl;

	std::cout << "\n=== 3. TEST : double ===" << std::endl;

	// test double
	double c[4] = {32.01, 42, 1, 56.01};
	iter(c, 4, print<double>);

	std::cout << std::endl;

	iter(c, 4, add<double>);
	iter(c, 4, print<double>);
	std::cout << std::endl;
	std::cout << "\n=== 4. TEST : char ===" << std::endl;

	// test char
	char d[12] = "hello world";
	iter(d, 12, print<char>);

	std::cout << std::endl;

	iter(d, 12, add<char>);
	iter(d, 12, print<char>);
	std::cout << std::endl;
	std::cout << "\n=== 5. TEST : bool ===" << std::endl;

	// test bool
	bool f[3] = {true, false, true};
	iter(f, 3, print<bool>);

	std::cout << std::endl;

	iter(f, 3, add<bool>);
	iter(f, 3, print<bool>);
	std::cout << std::endl;

	std::cout << "\n=== 5. TEST : std::string ===" << std::endl;

	// test string
	// std::string e[3] = {"Hello world", "It is a wonderful world" "Good bye"};
	// iter(e, 3, add<std::string>);

	// test with class

	// test with structure
}