#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class List
{

private:

	class Node
	{
	public:
		Node* pNext;
		int data;

		Node(int data = int(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node* head;

public:
	List();
	List(const List& secondList);
	~List();

	void show();

	void pop_front();

	void push_back(int data);

	void clear();

	int GetSize() const { return Size; }

	int& operator[](const int index);

	const int& operator[] (const int index) const;
	
	void push_front(int data);

	void insert(int data, int index);

	void insertInSorted(int data);

	void removeAt(int index);
	
	void pop_back();

	void sortb();

	void sorts();

	void sorti();

};


List::List()
{
	Size = 0;
	head = nullptr;
}


List::~List()
{
	clear();
}

List::List(const List& secondList) {

	if (this == &secondList) { return; }

	if (this->Size > 0) {
		for (int i = 0; i < this->Size; i++) {
			Node* temp = head;
			head = head->pNext;
			delete temp;
		}
	}
	this->Size = secondList.GetSize();
	this->head = new Node(secondList[0]);
	for (int i = 1; i < secondList.GetSize(); i++) {
		
			Node* current = this->head;

			while (current->pNext != nullptr)
			{
				current = current->pNext;
			}
			current->pNext = new Node(secondList[i]);

		
	}

}

void List::show() {
	Node* showP = head;
	for (int i = 0; i < Size; i++) {
		cout << showP->data << endl;
		showP = showP->pNext;
	}
}

void List::pop_front()
{
	Node *temp = head;

	head = head->pNext;

	delete temp;

	Size--;

}

void List::push_back(int data)
{
	if (head == nullptr)
	{
		head = new Node(data);
	}
	else
	{
		Node *current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node(data);

	}

	Size++;
}


void List::clear()
{
	while (Size)
	{
		pop_front();
	}
}


int& List::operator[](const int index)
{
	int counter = 0;

	Node *current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

const int& List::operator[] (const int index) const
{
	int counter = 0;

	Node* current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}


void List::push_front(int data)
{
	head = new Node(data, head);
	Size++;
}

void List::insert(int data, int index)
{

	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node *previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node *newNode = new Node(data, previous->pNext);

		previous->pNext = newNode;

		Size++;
	}


}

void List::insertInSorted(int data)
{
		Node* previous = this->head;

		for (int i = 0; i < Size && previous->pNext->data < data; i++)
		{
			previous = previous->pNext;
		}

		Node* newNode = new Node(data, previous->pNext);

		previous->pNext = newNode;

		Size++;
	


}

void List::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node *previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		
		Node *toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;

		Size--;
	}

}

void List::pop_back()
{
	removeAt(Size - 1);
}


void List::sortb() {
	//Node* left = head;                 //Первый элемент — это пусть будет голова
	//Node* right = head->pNext;          //Второй элемент — это пусть будет следующий за головой элемент

	//Node* temp = new Node;              //Временное звено для хранения переставляемого всех значений переставляемого звена

	//while (left->pNext) {                 //Обходим по всем звеньям, за исключением крайнего правого
	//	while (right) {              //Обходим по всем звеньям, включая крайний правый (по всем относительно первого левого на текущий момент)
	//		if ((left->data) > (right->data)) {        //Проверяем необходимость перестановки
	//			temp->data = left->data;              //И переставляем все внутренние элементы, за исключением указателей связи, местами
	//			left->data = right->data;             //Сейчас у нас имеется только x, поэтому только его
	//			right->data = temp->data;             //иначе бы  нужно было это проделывать для каждого несвязующего элемента
	//		}
	//		right = right->pNext;                    //не забываем направлять указатель на следующий элемент (по подобию инкремента), иначе цикл зависнет
	//	}
	//	left = left->pNext;                              //не забываем направлять указатель на следующий элемент (по подобию инкремента), иначе цикл зависнет
	//	right = left->pNext;                             //Поскольку второй указатель убежал немного вперёд, обязательно возвращаем его назад, это следующий элемент относительно текущего первого
	//}
	if (head == nullptr || head->pNext == nullptr) { return; }
	int n = Size;

	while (n--)

	{
		Node* prev = nullptr;
		Node* cur = head;
		while (cur->pNext != nullptr)
		{
			if (cur->data > cur->pNext->data)
			{

				if (prev == nullptr)
				{
					//first node
					Node* nxt = cur->pNext;
					cur->pNext = nxt->pNext;
					nxt->pNext = cur;
					prev = nxt;
					head = prev;


				}
				else
				{
					Node* nxt = cur->pNext;
					prev->pNext = nxt;
					cur->pNext = nxt->pNext;
					nxt->pNext = cur;
					prev = nxt;
				}
			}
			else
			{

				prev = cur;
				cur = cur->pNext;

			}



		}

	}

}


void List::sorts()			// функция возвращает заголовок нового списка
{
	/*Node* p1 = head;
	while (p1)
	{
		Node* marker = p1;
		Node* cursor = p1;
		while (cursor)
		{
			if (cursor->data < marker->data)
			{
				marker = cursor;
			}
			cursor = cursor->pNext;
		}
		swap(p1->data, marker->data);
		p1 = p1->pNext;
	}*/
	if (head == nullptr || head->pNext == nullptr) { return; }
	Node* connectionFirst, * first, * connectionSecond, * second, * temp;

	connectionFirst = first = head;

	// While b is not the last node
	while (first->pNext) {

		connectionSecond = second = first->pNext;

		// While d is pointing to a valid node
		while (second) {

			if (first->data > second->data) {

				// If d appears immediately after b
				if (first->pNext == second) {

					// Case 1: b is the head of the linked list
					if (first == head) {

						// Move d before b
						first->pNext = second->pNext;
						second->pNext = first;

						// Swap b and d pointers
						temp = first;
						first = second;
						second = temp;

						connectionSecond = second;

						// Update the head
						head = first;

						// Skip to the next element
						// as it is already in order
						second = second->pNext;
					}

					// Case 2: b is not the head of the linked list
					else {

						// Move d before b
						first->pNext = second->pNext;
						second->pNext = first;
						connectionFirst->pNext = second;

						// Swap b and d pointers
						temp = first;
						first = second;
						second = temp;

						connectionSecond = second;

						// Skip to the next element
						// as it is already in order
						second = second->pNext;
					}
				}

				// If b and d have some non-zero
				// number of nodes in between them
				else {

					// Case 3: b is the head of the linked list
					if (first == head) {

						// Swap b->next and d->next
						temp = first->pNext;
						first->pNext = second->pNext;
						second->pNext = temp;
						connectionSecond->pNext = first;

						// Swap b and d pointers
						temp = first;
						first = second;
						second = temp;

						connectionSecond = second;

						// Skip to the next element
						// as it is already in order
						second = second->pNext;

						// Update the head
						head = first;
					}

					// Case 4: b is not the head of the linked list
					else {

						// Swap b->next and d->next
						temp = first->pNext;
						first->pNext = second->pNext;
						second->pNext = temp;
						connectionSecond->pNext = first;
						connectionFirst->pNext = second;

						// Swap b and d pointers
						temp = first;
						first = second;
						second = temp;

						connectionSecond = second;

						// Skip to the next element
						// as it is already in order
						second = second->pNext;
					}
				}
			}
			else {

				// Update c and skip to the next element
				// as it is already in order
				connectionSecond = second;
				second = second->pNext;
			}
		}

		connectionFirst = first;
		first = first->pNext;
	}
}

void List::sorti()			// функция возвращает заголовок нового списка
{
	//Node* r;
	//Node* insertionPointer = head;
	//Node* current = head->pNext;
	//
	//while (current != nullptr) {
	//	insertionPointer = head;
	//	
	//	while (insertionPointer != current) {
	//		if (insertionPointer->data > current->data) {
	//			
	//			insertionPointer->pNext = current->pNext;
	//			current->pNext = insertionPointer;
	//			r = insertionPointer;
	//			insertionPointer = current;
	//			current = r;
	//			/*if (insertionPointer == head) {
	//				head = insertionPointer;
	//			}*/

	//			// Swap b and d pointers
	//			/*r = b;
	//			b = d;
	//			d = r;*/



	//			/*int temp = current->data;
	//			current->data = insertionPointer->data;
	//			insertionPointer->data = temp;*/
	//		}
	//		else {
	//			insertionPointer = insertionPointer->pNext;

	//		}
	//	}
	//	current = current->pNext;
	//}

	if (head == nullptr || head->pNext == nullptr) { return; }
	Node* temp = head;

	while (temp != nullptr) {
		Node* next = temp->pNext;
		Node* start = head;
		Node* prev = head;

		while(start != next){
			if (start->data > temp->data) {
				temp->pNext = start;
				if (start == head) {
					head = temp;
				}
				else {
					prev->pNext = temp;

				}
				while (start->pNext != temp) {
					start = start->pNext;

				}
				start->pNext = next;
			}
			prev = start;
			start = start->pNext;
		}
		temp = next;
	}



}



int main()
{

	setlocale(LC_ALL, "ru");

	int a;
	do {
		cout << "select function" << endl;
		cout << "1. read elements from keyboard" << endl;
		cout << "2. read elements from file" << endl;
		cout << "0. exit" << endl;
		cin >> a;

		switch (a) {
		case 1:
		{	List lst;
			cout << "enter the length of list" << endl;
			int length;
			cin >> length;

			for (int i = 0; i < length; i++) {
				cout << "enter the " << i + 1 << " number of list" << endl;
				int num;
				cin >> num;
				lst.push_back(num);
			}


			lst.sorti();

			lst.show();

			break;
		}
		case 2: {
			List lst;
			ifstream fin("list.txt");
			if (!fin.is_open()) {
				cout << "oshibka otkritiya faile" << endl;
			}
			else {
				int num;
				fin >> num;
				cout << "num is " << num << endl;

				int* number = new int[num];

				for (int i = 0; i < num; i++) {
					int value;
					fin >> value;
					number[i] = value;
				}


				for (int i = num - 1; i >= 0; i--) {
					lst.push_front(number[i]);
				}

				fin.close();
			}
			lst.sorti();
			lst.insertInSorted(60);
			//lst.show();

			List lst2(lst);
			lst2.show();
		}
	}
	} while (a != 0);


	

	return 0;
}
