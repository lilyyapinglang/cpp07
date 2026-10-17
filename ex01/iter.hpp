
#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>
/*
Implement a function template iter that takes 3 parameters and returns nothing.
-The first parameter is the address of an array.
- The second one is the length of the array, passed as a const value.
- The third one is a function that will be called on every element of the array
-Your iter function template must work with any type of array
-The third parameter can be an instantiated function template.
-The function passed as the third parameter may take its argument by const reference
or non-const reference, depending on the context.
*/

template <typename T, typename F> void iter(T *arr_addr,
	const std::size_t len_arr, F func_ptr)
{
	size_t	i;

	if (!arr_addr || !func_ptr)
		return ;
	i = 0;
	while (i < len_arr)
	{
		func_ptr(arr_addr[i]);
		i++;
	}
}

template <typename T, typename F> void iter(const T *arr_addr,
	const std::size_t len_arr, F func_ptr)
{
	size_t	i;

	if (!arr_addr || !func_ptr)
		return ;
	i = 0;
	while (i < len_arr)
	{
		func_ptr(arr_addr[i]);
		i++;
	}
}

#endif
