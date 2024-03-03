// main.cpp

#include <iostream>
#include "dinamic_array.hpp"

/// @brief  функция заполнение динамического массива
/// типа char строкой символов не увеличивая размер массива
/// @param str - динамический массив типа char
/// @param chr - константная строка
void arr_char(DinamicArray<char>& str, const char* chr) {
	for (int i = 0; i < str.size(); i++) {
		str[i] = chr[i];
	}
}

int main() {

	// создание массива типа int определенного размера
	DinamicArray<int> arr(10);

	// заполним произвольную ячейку массива числом
	std::cout << "Enter the data into array and check it: ";
	arr[3] = 15;

	// выведем результат и посмотрим соответсвует ли введенному значению
	std::cout << arr[3] << std::endl;
	
	// проверим текущий размер массива
	std::cout << "Check the size of array with std::size() = " << std::size(arr) << '\n';

	// добавим еще число в конец массива, данная операция возможна
	// так как массив может расширяться
	arr.add(12);

	// проверим, что действительно массив стал больше, выведем размер массива
	std::cout << "Check the new size of array with std::size() = " << std::size(arr) << '\n';

	// проверим содержимое конца массива, чтобы узнать добавилось ли наше число
	std::cout << "Print last two value of the new array:\n";
	std::cout << "arr[10] = " << arr[10] << '\n';
	std::cout << "arr[9] = " << arr[9] << '\n';

	// удалим последний элемент массива
	std::cout << "Remove last data.\n";
	arr.remove();

	//проверим снова размер массива после удаления элемента массива 
	std::cout << "Check one more time the size of array  with std::size() = " << std::size(arr) << '\n';

	// проверка работы с range base for циклом
	// выведем содержимое массива
	std::cout << "Print contents of array using range base for:\n";
	for (auto &ar : arr) {
		std::cout << ar << ' ';
	}
	std::cout << "\n";

	// добавим еще данных в массив
	std::cout << "Add new data to array.\n";
	arr.add(9);

	
	// выведем содержимое массива range base for циклом
	std::cout << "Print new contents of array using range base for:\n";
	for (auto& ar : arr) {
		std::cout << ar << ' ';
	}

	// создаем массив символов длинной 10
	DinamicArray<char> str(10);

	std::cout << std::endl;

	// заполняем массив строкой символов
	str = "HelloWorld DDD";

	
	// выведем содержимое массива range base for циклом
	for (auto& st : str) {
		std::cout << st;
	}

	// создадим массив символов используя конструктор копирования
	DinamicArray<char> str2(str);
	DinamicArray<char> str3;
	std::cout << std::endl;

	// добавим к новой строке отличительный символ
	str2.add('2');

	// выведем содержимое массива range base for циклом
	for (auto& st : str2) {
		std::cout << st;
	}
	std::cout << std::endl;

	// передача массива в функцию, для заполнения
	// массива строкой
	arr_char(str, "HelloWorld!!!!!!!!");

	// выведем содержимое массива range base for циклом
	for (auto& st : str) {
		std::cout << st;
	}
	std::cout << '\n';

	//проверим работу оператора присваивания копированием
	str3 = str;

	str3.add('N');

	// выведем содержимое массива range base for циклом
	for (auto& st : str3) {
		std::cout << st;
	}

	std::cout << "\n\n";

	return 0;
}