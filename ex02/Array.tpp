template <typename T> class Array
{
  public:
	// Construction with no parameter: Creates an empty array.
	Array(T);
	// Construction with an unsigned int n as a parameter: Creates an array of n elements
	// initialized by default.
	// Tip: Try to compile int * a = new int(); then display *a
	Array(n, T);
	Array(const Array &other, T);
	Array &operator=(const Array &other, T);
	// Elements can be accessed through the subscript operator: [ ].
	T &operator[](int);
	int size();
};