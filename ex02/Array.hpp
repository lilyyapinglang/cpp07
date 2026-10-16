#ifndef ARRAY_HPP
# define ARRAY_HPP

// template class
/*
template <typename T>
class Geek {
public:
	T x;
	T y;

	Geek(T val1, T val2) : x(val1), y(val2) {}

	void getValues() {
		cout << x << " " << y;
	}
};
*/
template <typename T> class Array
{
  public:
	Array();
	Array(int n);
	Array(const Array &other);
	Array &operator=(const Array &other);
	T &operator[](int);
	int size();
};

# include "Array.tpp"
#endif