#include <iostream>
#include <cstdlib>
#include <ctime>
template <typename T>
void fill_arr(T arr[], const int length, int left, int right) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (right - left) + left;
}
template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << "Массив: \n";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;
}
template <typename T>
void add_arr(T*& arr, int length, int num);
template <typename T>
void del_arr(T*& arr, int length, int num);

int main() {
	setlocale(LC_ALL, "ru");
	int n,m;
	// Динамическая память
	/*
	int* pointer = new int; //выделение участка динамической памяти размером в тип int(4 байта)

	*pointer = 7;
	std::cout << "pointer = " << pointer << std::endl;
	std::cout << "*pointer = " <<  *pointer << std::endl;

	delete pointer;  //Освобождение памяти, выделенной динамически. Удаляет область памяти на которую направлен указатель. 

	pointer = nullptr;
	if (pointer == nullptr);
		pointer = new int;

	*pointer = 15;
	std::cout << "pointer = " << pointer << std::endl;
	std::cout << "*pointer = " << *pointer << std::endl;
	//При перенаправлении памяти , старый участо кпамяит все еще хранит значенме 
	//Утечка памяти - явление, когда в связи с небрежным применением указателей, в памяти остаются значения, не связанные с какими либо указателями.
	// Данные значения "блокируют" ячейки памяти и не дают другим программам с ними взаимодействовать.
	delete pointer;
	pointer = nullptr;

	*/

	//Одномерные динамические массивы
	
	std::cout << "Введите длину массива -> ";
	int dsize;
	std::cin >> dsize;
	int* darr = new int[dsize];


	fill_arr(darr, dsize, 1, 11);
	print_arr(darr, dsize);

	delete[] darr;
	
	//Области применения динамических массивов:
	// 1.Размер массива неизвестен на этапе написания кода
	// 2.Размер массива должен иметь возможность изменится
	// 3. Реализация сложных структур данных

	// Двумерные динамические массивы

	int rows = 5, cols = 5;
	//int* mx = new int[rows][cols]; //не применимо к двумерным динамическим массивам

	int** mx = new int* [rows]; // создаем массив указателей
	for (int i = 0; i < rows; i++) // создаем стройки двумерного массива
		mx[i] = new int[cols];

	for (int i = 0; i < rows; i++) //удаляем все строки двумерного массива
		delete[] mx[i];
	delete[] mx; //удаляем массив указателей



	//Трехмерный массив
	/*
	int w = 5; l = 4; h = 3;
	int*** cube = new int** [w];
	for (int i = 0; i < w; i++) {
		cube[i] = new int* [l];
		for (int j = 0; j < l; j++)
			cube[j] = new int[h];
	}
	
	*/
	std::cout << "Задача 1.\nВведите размер массива -> ";
	int size1;
	std::cin >> size1;
	int* arr1 = new int[size1];
	fill_arr(arr1, size1, 10, 20);
	std::cout << "Изначальный ";
	print_arr(arr1, size1);
	std::cout << "Введите кол-во новых элементов -> ";
	std::cin >> n;
	add_arr(arr1, size1, n);
	if (n > 0)
		size1 += n;
	print_arr(arr1, size1);	
	delete[] arr1;
	
	std::cout << "Задача 2. Уменьшение размера массива.\n";
	int size2;
	std::cout << "Введите размер массива -> ";
	std::cin >> size2;
	int* arr2 = new int[size2];
	fill_arr(arr2, size2, 10, 20);
	std::cout << "Изначальный ";
	print_arr(arr2, size2);
	std::cout << "Введите кол-во элементов для удаления -> ";
	std::cin >> m;
	
	del_arr(arr2, size2, m);

	if (m >= size2)
		size2 = 0;
	
	if (m > 0)
		size2 -= m;
		
	print_arr(arr2, size2);


	return 0;
}

template <typename T>
void add_arr(T*& arr, int length, int num) {
	//Шаг 0. Защита от лишних действий
	if (num <= 0)
		return;
	//Шаг 1. Выделение памяти под новый массив нужного размера
	T* tmp = new T[length + num]{};
	//Шаг 2. Копирование значений старого массива
	for (int i = 0; i < length; i++)
		tmp[i] = arr[i];
	//Шаг 3. Освобождение памяти, выделенной под старый массив
	delete[] arr;
	//Шаг 4. Перенаправление указателя на новый массив
	arr = tmp;
} 

template <typename T>
void del_arr(T*& arr, int length, int num) {
	if (num <= 0)
		return;
	if (num >= length) {
		delete[] arr;
		arr = nullptr;
		return;
	}
	T* tmp = new T[length - num];	
	for (int i = 0; i < length - num; i++)
		tmp[i] = arr[i];	
	delete[] arr;	
	arr = tmp;
}
