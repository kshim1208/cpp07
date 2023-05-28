#include "Array.hpp"

int main()
{
	Array<int>		int_arr_0;
	Array<int>		int_arr_5(5);
	Array<char>		char_arr_10(10);
	Array<float>	float_arr_15(15);

	for (int iter = 0; iter < 6; iter++)
	{
		try
		{
			std::cout << int_arr_0[iter] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << int_arr_0.size() << std::endl;

	std::cout << "\n------------------------------\n" << std::endl;

	for (int iter = 0; iter < 6; iter++)
	{
		try
		{
			int_arr_5[iter] = iter;
			std::cout << int_arr_5[iter] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << int_arr_5.size() << std::endl;

	std::cout << "\n------------------------------\n" << std::endl;
	
	for (int iter = 0; iter < 12; iter++)
	{
		try
		{
			char_arr_10[iter] = 'a' + iter;
			std::cout << char_arr_10[iter] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << char_arr_10.size() << std::endl;

	std::cout << "\n------------------------------\n" << std::endl;
	
	for (int iter = 0; iter < 18; iter++)
	{
		try
		{
			float_arr_15[iter] = static_cast<float>(iter) * 0.8314;
			std::cout << float_arr_15[iter] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << float_arr_15.size() << std::endl;

	
}