#include <iostream>
#include <string>
using namespace std;

class Strings {
private:
	char** strArr;
	int size;
	char** getArray() {
		return strArr;
	}
public:
	Strings() {};
	//Strings(int size);
	Strings(char** strAr, int size);
	Strings(const Strings& strings);
	void show();
	void sort();
	int getSize();
	//char** getArray();
	Strings concatenation(Strings second);
	Strings merger(Strings s2);
	char* operator [] (int index);

	Strings& operator = (const Strings& second);

	~Strings();

};

Strings::Strings(char** strArr, int size) {
	this->strArr = new char* [size];
	this->size = size;

	for (int i = 0; i < size; i++) {
		this->strArr[i] = new char[strlen(strArr[i]) + 1];
		strcpy_s(this->strArr[i], strlen(strArr[i]) + 1, strArr[i]);
	}
}

Strings::Strings(const Strings& strings) {

	this->strArr = new char* [strings.size];
	this->size = strings.size;
	for (int i = 0; i < size; i++) {
		this->strArr[i] = new char[strlen(strings.strArr[i]) + 1];
		strcpy_s(this->strArr[i], strlen(strings.strArr[i]) + 1, strings.strArr[i]);
	}
}

void Strings::sort()
{

	for (int j = 0; j < size - 1; j++)
	{
		for (int i = j + 1; i < size; i++)
		{
			if (strcmp(strArr[j], strArr[i]) > 0)
			{
				char* temp = strArr[j];
				strArr[j] = strArr[i];
				strArr[i] = temp;
			}
		}
	}

}

int Strings::getSize() {
	return size;
}

void Strings::show() {
	cout << "=================================" << endl;
	for (int i = 0; i < size; i++) {
		cout << strArr[i] << " ";
	}
	cout << endl;
	cout << "=================================" << endl;
}


Strings Strings::concatenation(Strings second) {
	if (size >= second.getSize()) {
		//char** newArr = concant(strArr, size, second.getArray(), second.getSize());
		char** newArr = new char* [size];
		for (int i = 0; i < second.getSize(); i++) {
			newArr[i] = new char[strlen(strArr[i]) + strlen(second.getArray()[i]) + 1];
			strcpy_s(newArr[i], strlen(strArr[i]) + 1, strArr[i]);
			strcat_s(newArr[i], (strlen(strArr[i]) + strlen(second.getArray()[i]) + 1), second.getArray()[i]);
		}
		for (int i = second.getSize(); i < size; i++) {
			newArr[i] = new char[strlen(strArr[i]) + 1];
			strcpy_s(newArr[i], strlen(strArr[i]) + 1, strArr[i]);

		}
		Strings newObj(newArr, size);

		for (int i = 0; i < size; i++) {
			delete[] newArr[i];
		}
		delete[] newArr;

		return newObj;

	}
	else {
		//char** newArr = concant(second.getArray(), second.getSize(), strArr, size);
		char** newArr = new char* [second.getSize()];
		for (int i = 0; i < size; i++) {
			newArr[i] = new char[strlen(strArr[i]) + strlen(second.getArray()[i]) + 1];
			strcpy_s(newArr[i], strlen(second.getArray()[i]) + 1, second.getArray()[i]);
			strcat_s(newArr[i], (strlen(strArr[i]) + strlen(second.getArray()[i]) + 1), strArr[i]);
		}
		for (int i = size; i < second.getSize(); i++) {
			newArr[i] = new char[strlen(second.getArray()[i]) + 1];
			strcpy_s(newArr[i], strlen(second.getArray()[i]) + 1, second.getArray()[i]);

		}
		Strings newObj(newArr, second.getSize());

		for (int i = 0; i < second.getSize(); i++) {
			delete[] newArr[i];
		}
		delete[] newArr;

		return newObj;
	}
}

Strings Strings::merger(Strings s2) {
	int length = s2.getSize();
	char** Arr = s2.getArray();
	char** newArr = new char* [length + size];
	for (int i = 0; i < size; i++) {
		newArr[i] = new char[strlen(strArr[i]) + 1];
		strcpy_s(newArr[i], strlen(strArr[i]) + 1, strArr[i]);
		//newArr[i] = strArr[i];
	}
	for (int i = 0; i < length; i++) {
		newArr[i + size] = new char[strlen(Arr[i]) + 1];
		strcpy_s(newArr[i + size], strlen(Arr[i]) + 1, Arr[i]);
		//newArr[i + size] = Arr[i];


	}

	int sz = length + size;
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz; j++)
		{
			if (i != j)
			{
				if (strcmp(newArr[i], newArr[j]) == 0)
				{
					swap(newArr[sz - 1], newArr[j]);
					sz--;
				}
			}
		}
	}

	char** m1 = new char* [sz];

	for (int i = 0; i < sz; i++) {
		m1[i] = new char[strlen(newArr[i]) + 1];
		strcpy_s(m1[i], strlen(newArr[i]) + 1, newArr[i]);
		//m1[i] = newArr[i];
	}

	for (int i = 0; i < length + size; i++) {
		delete[] newArr[i];
	}
	delete[] newArr;

	Strings newObj(m1, sz);

	for (int i = 0; i < sz; i++) {
		delete[] m1[i];
	}
	delete[] m1;

	return newObj;

}


Strings::~Strings() {
	for (int i = 0; i < size; i++) {
		delete[] strArr[i];
	}
	delete[]strArr;
}


int main() {
	cout << "ke";

	char** newArr1 = new char* [3];
	newArr1[0] = new char[4];
	newArr1[1] = new char[5];
	newArr1[2] = new char[5];
	strcpy_s(newArr1[0], 4, "Den");
	strcpy_s(newArr1[1], 5, "Zima");
	strcpy_s(newArr1[2], 5, "Leto");


	char** newArr2 = new char* [2];
	newArr2[0] = new char[6];
	newArr2[1] = new char[5];
	strcpy_s(newArr2[0], 6, "Vesna");
	strcpy_s(newArr2[1], 5, "Zima");


	char** newArr3 = new char* [4];
	newArr3[0] = new char[6];
	newArr3[1] = new char[5];
	newArr3[2] = new char[5];
	newArr3[3] = new char[5];
	strcpy_s(newArr3[0], 6, "Vesna");
	strcpy_s(newArr3[1], 5, "Osen");
	strcpy_s(newArr3[2], 5, "Krot");
	strcpy_s(newArr3[3], 5, "Stol");

	/*==================================*/

	/*===Сортировка====*/
	Strings a(newArr1, 3);
	Strings b(newArr2, 2);
	Strings c(newArr3, 4);
	a.show();
	b.show();
	c.show();
	Strings d(a);
	d.sort();
	d.show();

	Strings m(b.concatenation(a));
	m.show();

	Strings f(a.merger(c));
	f.show();

	return 0;

}
