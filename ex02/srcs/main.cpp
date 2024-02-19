#include <iostream>
#include "Array.hpp"

#define MAX_VAL 5

int main(void)
{
	Array<int>	array;
	std::cout << "array:" << array.size() << std::endl;

	std::cout << "------------------------ 0" << std::endl;

	Array<int>	original(MAX_VAL);
	srand(time(NULL));
	for (size_t i = 0; i < MAX_VAL; i++)
	{
		const size_t value = rand();
		original[i] = value;
	}
	Array<int> copy1 = original;
	Array<int> copy2(copy1);

	std::cout << "original:" << original.size() << std::endl;
	std::cout << "copy1:" << copy1.size() << std::endl;
	std::cout << "copy2:" << copy2.size() << std::endl;

	std::cout << "------------------------ 1" << std::endl;

	for (size_t i = 0; i < MAX_VAL; i++)
	{
		if (copy1[i] == original[i] || copy2[i] == copy1[i])
				std::cout << "saveed the same value!!" << std::endl;
	}

	std::cout << "------------------------ 2" << std::endl;

	try
	{
			original[-2] = 0;//負のインデックスにアクセス
	}
	catch(const std::exception& e)
	{
			std::cerr << "Error 1" << std::endl;
	}
	try
	{
			original[MAX_VAL] = 0;//インデックスの最大値+1にアクセス
	}
	catch(const std::exception& e)
	{
			std::cerr << "Error 2" << std::endl;
	}

	std::cout << "------------------------ 3" << std::endl;

	std::cout << "original[3]:	" << original[3] << std::endl;
	std::cout << "copy1[3]:	" << copy1[3] << std::endl;
	std::cout << "copy2[3]:	" << copy2[3] << std::endl;

	std::cout << "------------------------ 4" << std::endl;

	original[3] = 99999;
	std::cout << "original[3]:	" << original[3] << std::endl;
	std::cout << "copy1[3]:	" << copy1[3] << std::endl;
	std::cout << "copy2[3]:	" << copy2[3] << std::endl;

	std::cout << "------------------------ 5" << std::endl;

	copy1[3] = 0;
	std::cout << "original[3]:	" << original[3] << std::endl;
	std::cout << "copy1[3]:	" << copy1[3] << std::endl;
	std::cout << "copy2[3]:	" << copy2[3] << std::endl;

	return (0);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> original(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         original[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = original;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != original[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         original[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         original[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         original[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }