
#include "Array.hpp"
#include <string>

// Example dummy structure
struct	Point
{
	int	x;
	int	y;
};

int	main(void)
{
	Array<int> a = Array<int>();
	Array<int> b = Array<int>(10);
	b[1] = 9;

	Array<double> c = Array<double>(10);
	Array<float> d = Array<float>(10);
	Array<bool> e = Array<bool>(10);
	Array<char> f = Array<char>(10);
	Array<std::string> g = Array<std::string>(10);
	// 3. ADVANCED TYPES TO TRY :
	// Array<Point> h(5); // Custom structures
	// Array<int *> i(5); // Raw pointers
}