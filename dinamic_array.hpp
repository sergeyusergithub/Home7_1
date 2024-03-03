// dinamic_array.hpp

/*!
	\file 
	\brief Описание задачи

	\details
Обязятельными пунктаи задания являются следующие возможности коллекции:
-- размещение в себе элементов произвольного типа;
-- добавление и удаление элементов;
-- предоставление доступа к элементам массива;
-- возможность работы с колекцией через range based for, sdt::size;
-- корректная передача по параметру в функции.

*/

#pragma once

#ifndef DINAMIC_ARRAY_HPP
#define DINAMIC_ARRAY_HPP
#include <iostream>


/**
 * @brief Шаблонный класс динамический массив 
 * \author Буньков Сергей
 * \version 1.0.0
 * \date 29.02.2024 
 * @details Создан в учебныйх целях. Домашнее задание 7.
 * @tparam Type - параметр шаблона
 */
template<typename Type>
class DinamicArray {
public:

	/// конструктор по умолчанию
	DinamicArray() :data_{}, size_{} {}

	/// @brief конструктор с параметром, параметр - размер динамического массива
	/// @param size - размер создаваемого массива
	DinamicArray(int size) :data_{}, size_(size) {
		data_ = new Type[size_]{};
	}

	/**
	 * @brief конструктор копирования
	 * @param other - ссылка на другой динамический массив  
	 * 
	 */
	DinamicArray(const DinamicArray<Type>& other);

	DinamicArray<Type>& operator =(const DinamicArray<Type>& other);

	DinamicArray<Type>& operator =(const char* str);

	/// @brief оператор [] доступ к элементам массива
	/// @param index - индекс элемента массива
	/// @return Type& - возвращается ссылка на содержимое массива
	/// которое может быть изменено
	Type& operator[](int index) noexcept;

	/**
	 * @brief оператор [] доступа к содержимому массива
	 * 
	 * @param index - индекс элемента массива 
	 * @return const Type& - возвращается константная ссылка на содержимео
	 * 			позволяя получить содержимое массива
	 */
	const Type& operator[](int index) const noexcept;
		
	/// @brief деструктор, освобождает память
	~DinamicArray() {
		delete[] data_;
		size_ = {};
	}

	/// @brief метод возвращающий размер массива, также необходим для использования функцией std::size()
	int size() const {
		return size_;
	}

	/**
	 * @brief метод добавления элемента к концу 
	 * массива, при этом массив увеличивает свой 
	 * размер на добавленный элемент
	 * 
	 * @param data - данные добавляемы в конец массива
	 */
	void add(const Type& data);

	/// @brief метод удаления элемента с конца массива,
	/// при этом массив уменньшает свой массив на удаленный элемент
	void remove();

	/// @brief возвращает адрес начала массива
	/// @return Type* - возвращает адрес заданного типа
	Type* begin() {
		return data_;
	}


	
	/// @brief возвращает адрес конца массива
	/// @return Type* - возвращает адрес заданного типа
	Type* end() {
		return data_ + size_;
	}


private:
	Type *data_;
	int size_;
};


//===================================================================
template<typename Type>
DinamicArray<Type>::DinamicArray(const DinamicArray<Type>& other)
{
	size_ = other.size_;
	data_ = new Type[size_]{};
	for (int i = 0; i < size_; ++i) {
		data_[i] = other.data_[i];
	}
}



//! ===================================================================
template<typename Type>
Type& DinamicArray<Type>::operator[](int index) noexcept
{
	return data_[index];
}


//==============================================================
template<typename Type>
const Type& DinamicArray<Type>::operator[](int index) const noexcept
{
	return data_[index];
}

template<typename Type>
inline void DinamicArray<Type>::add(const Type& data)
{
	Type* tmp = new Type[size_ + 1];
	for (int i = 0; i < size_; ++i) {
		tmp[i] = data_[i];
	}
	delete[] data_;
	data_ = tmp;
	data_[size_] = data;
	size_ += 1;
}

template<typename Type>
inline void DinamicArray<Type>::remove()
{
	--size_;
	Type* tmp = new Type[size_]{};
	for (int i = 0; i < size_; ++i) {
		tmp[i] = data_[i];
	}
	delete[] data_;
	data_ = tmp;
	
}


template<typename Type>
DinamicArray<Type>& DinamicArray<Type>::operator =(const DinamicArray<Type>& other){
	size_ = other.size_;
	data_ = new Type[size_]{};
	for (int i = 0; i < size_; ++i) {
		data_[i] = other.data_[i];
	}
	return *this;
}

template<typename Type>
DinamicArray<Type>& DinamicArray<Type>::operator =(const char* str){
	int count {};
	while(str[count] != '\0'){
		if(count < size_){
			data_[count] = str[count];
		} else {
			add(str[count]);
		}
		
		count++;
	}
	return *this;
}

#endif // !DINAMIC_ARRAY_HPP
