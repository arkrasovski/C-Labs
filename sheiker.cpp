/* Задание.
Реализовать алгоритм пузырьковой сортировки. Использовать отдельные функции:
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
	int begin = 0;
	int end = n - 1;
	// Через необязательный параметр выбор по возрастанию или убыванию
	while(begin < end){
		
		if (begin % 2 == 0) {
			for (int i = begin; i < n - begin - 1; i++)
			{

				if (*(p + i) > * (p + i + 1)) { swap(*(p + i), *(p + i + 1)); }
			}
			end--;
		}
		else if (begin % 2 != 0){
			for (int i = end; i > begin; i--)
			{

				if (*(p + i) > * (p + i + 1)) { swap(*(p + i), *(p + i + 1)); }
			}
			begin++;
		}
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