#ifndef Array_HPP
# define Array_HPP

# include <exception>

# include <iostream>

template <typename T>
class Array
{
	private:
		unsigned int	len;
		T				*array_;

	public:
		Array()
		{
			this->array_ = nullptr;
			this->len = 0;
		};

		Array(unsigned int n)
		{
			try
			{
				this->array_ = new T[n];
				for (unsigned int iter = 0; iter < n; iter++)
				{
					this->array_[iter] = 0;
				}
				this->len = n;
			}
			catch(const std::bad_alloc& e)
			{
				std::cerr << e.what() << '\n';
				this->array_ = nullptr;
				this->len = 0;
			}
		}

		~Array()
		{
			this->len = 0;
			if (this->array_ != nullptr)
				delete[] this->array_;
		};

		Array(const Array& source)
		{
			this->array_ = nullptr;
			this->len = 0;
			if (source.len == 0)
			{
				return ;
			}
			try
			{
				this->array_ = new T[source.len];
				for (unsigned int iter = 0; iter < source.len; iter++)
				{
					this->array_[iter] = source.array_[iter];
				}
				this->len = source.len;
			}
			catch(const std::bad_alloc& e)
			{
				std::cerr << e.what() << '\n';
			}
		}

		Array& operator=(const Array& source)
		{
			if (source.len == 0)
			{
				this->array_ = nullptr;
				this->len = 0;
				return (*this);
			}
			if (this->array_ != nullptr)
			{
				delete[] this->array_;
			}
			try
			{
				this->array_ = new T[source.len];
				for (unsigned int iter = 0; iter < source.len; iter++)
				{
					this->array_[iter] = source.array_[iter];
				}
				this->len = source.len;
			}
			catch(const std::bad_alloc& e)
			{
				std::cerr << e.what() << '\n';
			}
			return (*this);
		}

		T&	operator[](unsigned int n)
		{
			if (n >= this->len)
			{
				throw std::exception();
			}
			return (this->array_[n]); 
		}

		const T& operator[](unsigned int n) const
		{
			if (n >= this->len)
			{
				throw std::exception();
			}
			return (this->array_[n]);
		}

		const unsigned int&	size(void) const
		{
			return (this->len);
		}
};

#endif