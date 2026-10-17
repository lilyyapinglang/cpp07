#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <cstddef>
# include <exception>
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
  private:
	T *arr;
	unsigned int _size;

  public:
	Array() : arr(new T[0]()), _size(0)
	{
	}
	Array(unsigned int n) : arr(new T[n]()), _size(n)
	{
	}
	Array(const Array &other) : arr(new T[other._size]()), _size(other._size)
	{
		for (unsigned int i = 0; i < _size; i++)
		{
			arr[i] = other[i];
		}
	}

	Array &operator=(const Array &other)
	{
		if (this != &other)
		{
			// delete old array
			delete[] arr;
			// copy array;
			this->_size = other._size;
			this->arr = new T[_size]();

			for (unsigned int i = 0; i < _size; i++)
			{
				arr[i] = other[i];
			}
		}
		return (*this);
	}

	~Array()
	{
		delete[] arr;
	}

	T &operator[](unsigned int index)
	{
		if (index >= this->size())
			throw std::exception();

		return (arr[index]);
	}

	const T &operator[](unsigned int index) const
	{
		if (index >= _size)
			throw std::exception();

		return (arr[index]);
	}

	unsigned int size() const
	{
		return (_size);
	}
};

#endif