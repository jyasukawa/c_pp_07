#include "iter.hpp"

int	main(void)
{
	int int_array[] = {1, 2, 3, 4, 5};

	::iter(int_array, 4, ft_print_array);
	::iter(int_array, 3, ft_increase_element);

	std::cout << "-----------------" << std::endl;

	::iter(int_array, 5, ft_print_array);


	std::cout << "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << std::endl;


	char	char_array[] = {'a', 'b', 'c', 'd', 'e'};

	::iter(char_array, 4, ft_print_array);
	::iter(char_array, 3, ft_increase_element);

	std::cout << "-----------------" << std::endl;

	::iter(char_array, 5, ft_print_array);

	return (0);
}

// <const int> は、関数テンプレート iter を const int の型で具現化（インスタンス化）しています。
// :: 演算子は、グローバルなスコープを指定します。この場合、グローバルスコープから iter を探しに行きます。
// 特に、グローバルスコープからの ::iter の使用は、名前の衝突を避けるためなど、特定の状況で有用です。通常は iter のみを使用することが一般的です。
