#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void	iter(T *array, ssize_t length, void (*f)(T &))
{
	if (array == NULL || length < 0 || f == NULL)
	{
		std::cerr << "An error has been found. Exit" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	for (ssize_t i = 0; i < length; i++)
		f(array[i]);
}

// const 修飾子がついた関数は非変更の操作を行うことが保証されているため、関数が引数を変更しないことが期待される
// const T *arrayとするべき。error: call to 'iter' is ambiguousもある
template <typename T>
void	iter(const T *array, ssize_t length, void (*f)(const T &))//constバージョン
{
	if (array == NULL || length < 0 || f == NULL)
	{
		std::cerr << "An error has been found. Exit" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	for (ssize_t i = 0; i < length; i++)
		f(array[i]);
}

template <typename T>
void	ft_print_array(const T &element)
{
	std::cout << element << std::endl;
}

template <typename T>
void	ft_increase_element(T &element)
{
	element++;
}

#endif
