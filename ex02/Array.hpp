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
				if (this->array_ == nullptr)
					throw std::exception();
				for (unsigned int iter = 0; iter < n; iter++)
				{
					this->array_[iter] = 0;
				}
				this->len = n;
			}
			catch(const std::exception& e)
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
			if (source.len == 0)
			{
				this->array_ = nullptr;
				this->len = 0;
				return ;
			}
			this->array_ = new T[source.len];
			for (unsigned int iter = 0; iter < source.len; iter++)
			{
				this->array_[iter] = 0;
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
			this->array_ = new T[source.len];
			for (unsigned int iter = 0; iter < source.len; iter++)
			{
				this->array_[iter] = 0;
			}
			return (*this);
		}

		T&	operator[](unsigned int n)
		{
			try
			{
				if (n >= this->len)
				{
					throw std::exception();
				}
			}
			catch(...)
			{
				throw ;
			}
			return (this->array_[n]);
		}

		const T& operator[](unsigned int n) const
		{
			try
			{
				if (n >= this->len)
				{
					throw std::exception();
				}
			}
			catch(...)
			{
				throw ;
			}
			return (this->array_[n]);
		}

		const unsigned int&	size(void) const
		{
			return (this->len);
		}
};

#endif