
#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>

template <typename T>
class Array
{
	public:
		Array(void);
		Array(const Array &copy_src);
		Array &operator=(const Array &rhs);
		~Array(void);

		Array(const unsigned int n);
		T &operator[](const ssize_t i);
		const T &operator[](const ssize_t i) const;
		unsigned int	size() const;//musn’t modify the current instance 

	private:
		T							*_array;
		unsigned int	_size;
};



template <typename T>
Array<T>::Array(void) : _array(NULL), _size(0)
{
	// std::cout << "Array default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array<T> &copy_src) : _array(NULL), _size(0)//C++17以降は引数の<T>省略可能
{
	// std::cout << "Array copy constructor called" << std::endl;
	*this = copy_src;
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array<T> &rhs)
{
	// std::cout << "Array copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		if (this->_size > 0)
			delete [] this->_array;
		this->_array = new(std::nothrow) T[rhs._size];
		if (this->_array == NULL)
			std::exit(EXIT_FAILURE);
		for (unsigned int i = 0; i < rhs._size; i++)
			this->_array[i] = rhs._array[i];
		this->_size = rhs._size;
	}
	return (*this);
}

template <typename T>
Array<T>::~Array(void)
{
	// std::cout << "Array destructor called" << std::endl;
	delete [] this->_array;
}


template <typename T>
Array<T>::Array(const unsigned int n)// : _array(new T[n]), _size(n)
{
	// std::cout << "Array unsigned int constructor called" << std::endl;
	if (n != 0)
	{
		this->_array = new(std::nothrow) T[n];
		if (this->_array == NULL)
			std::exit(EXIT_FAILURE);
		for (unsigned int i = 0; i < n; i++)
			this->_array[i] = 0;//Tのデータ型が何になるかわからないため、=0で初期化
	}
	this->_size = n;
}

template <typename T>
T	&Array<T>::operator[](const ssize_t i)//要素への読み書きアクセス
{
	if (i < 0 || static_cast<unsigned int>(i) >= this->_size || this->_size == 0)//this->_sizeはuintなのでマイナスはない
		throw std::exception();
	return (this->_array[i]);
}

template <typename T>
const T	&Array<T>::operator[](const ssize_t i) const//constパターン、要素への読み取り専用アクセス
{
	if (i < 0 || static_cast<unsigned int>(i) >= this->_size || this->_size == 0)
		throw std::exception();
	return (this->_array[i]);
}

template <typename T>
unsigned int	Array<T>::size(void) const
{
	return (this->_size);
}

#endif
