/* Задание.
Реализовать алгоритм сортировки выбором. Использовать отдельные функции:
print(int* p, int n);
swap(int* p, int i, int j);
sort(int* p, int n).
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int* init_array(int);
void print(int*, int);
void swap(int*, int*); // пришлось изменить для удобства
void sort(int*, int, bool = false);
void reverse_arr(int*, int);

int main()
{
	const int size = 9;
	int* arr = nullptr; //нулевой указатель
	arr = init_array(size);
	print(arr, size);
	sort(arr, size);
	// sort(arr, size, true) - сортировка по убыанию
	print(arr, size);

	return 0;
}

int* init_array(int size)
{
	const int left_border = -10; //левая граница
	const int right_border = 10; //правая граница
	int* ptr = new int[size];

	srand(time(NULL));

	for (int i = 0; i < size; i++)
	{
		*(ptr + i) = rand() % (right_border - left_border + 1) + left_border;
	}

	return ptr;
}
void print(int* p, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << *(p + i) << " ";
	}
	cout << "\n";
}
void swap(int* p, int* t)
{
	int tmp = *p;
	*p = *t;
	*t = tmp;
}
void sort(int* p, int n, bool reverse)
{
	// Через необязательный параметр выбор по возрастанию или убыванию
	
	for (int i = 0; i < n - 1; i++)
	{
		int* smallest = p+i;
		for (int currentIndex = i + 1; currentIndex < n; ++currentIndex)
		{
			if (*(p + currentIndex) < *(smallest))
				smallest = p + currentIndex;
		}

		swap(*(p + i), *smallest);
	}
	if (reverse)
		reverse_arr(p, n);
}
void reverse_arr(int* arr, int size)
{
	for (int i = 0; i < size / 2; i++)
	{
		swap(arr + i, arr + size - i - 1);
	}
}