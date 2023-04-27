#include "iter.hpp"

int main ()
{
	char	c[5] = {'a', 'b', 'c', 'd', 'e'};
	int		i[10] = {0, 1, 2, 3, 4, 5 ,6 ,7 ,8 ,9};
	iter(c, 5, iter_function);
	iter(i, 10, iter_function);
}
