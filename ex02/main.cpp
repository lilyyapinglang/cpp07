
#include "Array.hpp"
#include <string>

// Example dummy structure
struct	Point
{
	int	x = 0;
	int	y = 0;
};

int	main(void)
{
	Array a = Array<int>();
	Array b = Array<int>(10);
	b[9] = 1;
	Array c = Array<double>(10);
	Array c = Array<float>(10);
	Array c = Array<bool>(10);
	Array c = Array<char>(10);
	Array c = Array<std::string>(10);
	// 3. ADVANCED TYPES TO TRY :
	Array<Point> h(5); // Custom structures
	Array<int *> i(5); // Raw pointers
}