#ifndef iter_HPP
# define iter_HPP

# include <iostream>

template<typename T>
void	iter_function(T what)
{
	std::cout << what;
}

template <typename T>
void	iter(T array[], int length, void iter_function(T what))
{
	for (int iter = 0; iter < length; iter++)
	{
		iter_function(array[iter]);
	}
	std::cout << std::endl;
}

#endif