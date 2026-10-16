#ifndef WHATEVER_HPP
# define WHATEVER_HPP

/*
Templates must be defined in the header files.
Data stypes to consider :  bool, char , int ,float, double, string
*/
// swap: Swaps the values of two given parameters. Does not return anything.
// int a =2, int b =3
template <typename T> void swap(T &x, T &y)
{
	T	temp;

	temp = x;
	x = y;
	y = temp;
}
// min: Compares the two values passed as parameters and returns the smallest one.
// If they are equal, it returns the second one.
template <typename T> const T &min(const T &x, const T &y)
{
	if (x >= y)
		return (y);
	else
		return (x);
}
// max : Compares the two values passed as parameters and returns the greatest one.If they are equal,
// it returns the second one.
template <typename T> const T &max(const T &x, const T &y)
{
	if (x <= y)
		return (y);
	else
		return (x);
}

#endif