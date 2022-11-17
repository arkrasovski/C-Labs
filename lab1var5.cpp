#include <iostream>
#include <ctime>
using namespace std;

struct FullName {
	string surname;
	char firstName;
	char secondName;
};

class Worker {
	private:
		FullName fullName;
		string position;
		int joinYear;
		int salary;
	
	public:
		Worker();
		Worker(FullName fullname, string position, int joinYear, int salary);
		Worker(string surname, char firstName, char secondName, string position, int joinYear, int salary);
		void setFullName(FullName fullName);
		void setPosition(string position);
		void setJoinYear(int joinYear);
		void setSalary(int salary);
		void fillObject();

		FullName getFullName();
		string getPosition();
		int getJoinYear();
		int getSalary();

		void show();

};

void Worker::show() {
	cout << fullName.surname << " " << fullName.firstName << ". " << fullName.secondName << ". " << position << " " << joinYear << " " << salary << endl;
	}

Worker::Worker() {
	this->fullName.surname = "Surname";
	this->fullName.firstName = 'N';
	this->fullName.secondName = 'S';
	this->position = "Worker";
	this->joinYear = 2021;
	this->salary = 100;
}

Worker::Worker(FullName fullName, string position, int joinYear, int salary) {
	this->fullName = fullName;
	this->position = position;
	this->joinYear = joinYear;
	this->salary = salary;
}

Worker::Worker(string surname, char firstName, char secondName, string position, int joinYear, int salary) {
	this->fullName.surname = surname;
	this->fullName.firstName = firstName;
	this->fullName.secondName = secondName;
	this->position = position;
	this->joinYear = joinYear;
	this->salary = salary;
}

void Worker::setFullName(FullName fullName) {
	this->fullName = fullName;
}

void Worker::setPosition(string position){
	this->position = position;
}

void Worker::setJoinYear(int joinYear) {
	this->joinYear = joinYear;
}

void Worker::setSalary(int salary) {
	this->salary = salary;
}

void Worker::fillObject() {
	cout << "Input surname:" << endl; cin >> fullName.surname;
	cout << "Input initials:" << endl; cin >> fullName.firstName >> fullName.firstName;
	cout << "Input position" << endl; cin >> position;
	cout << "Input join Year" << endl; cin >> joinYear;
	cout << "Input salary" << endl; cin >> salary;
}

FullName Worker::getFullName() {
	return fullName;
}

string Worker::getPosition() {
	return position;
}

int Worker::getJoinYear() {
	return joinYear;
}

int Worker::getSalary() {
	return salary;
}

void greaterSalary(Worker workers[], int n) {
	int count = 0;
	int salary;
	cout << "Enter the minimum salary" << endl;
	cin >> salary;
	for (int i = 0; i < n; i++) {
		if (workers[i].getSalary() >= salary) {
			workers[i].show();
			cout << "_________________________" << endl;
			count++;
		}
	}
	if (count == 0) {
		cout << "Sorry, no results were found." << endl;
	}

}

void certainPosition(Worker workers[], int n) {
	int count = 0;
	string position;
	cout << "Enter person`s position" << endl;
	cin >> position;
	for (int i = 0; i < n; i++) {
		if (workers[i].getPosition() == position) {
			workers[i].show();
			cout << "_________________________" << endl;
			count++;
		}
	}
	if (count == 0) {
		cout << "Sorry, no results were found." << endl;
	}

}

void greaterWorkingExperience(Worker workers[], int n, int currentYear) {
	int count = 0;
	int years;
	cout << "Enter person`s working experience" << endl;
	cin >> years;
	for (int i = 0; i < n; i++) {
		if (currentYear - workers[i].getJoinYear() >= years ) {
			workers[i].show();
			cout << "_________________________" << endl;
			count++;
		}
	}
	if (count == 0) {
		cout << "Sorry, no results were found." << endl;
	}
}

void operationWithArrays(Worker* workers, int size, int currentYear) {
	int a3;
	do {
		cout << "select function" << endl;
		cout << "1. withdraw employees, work experience at this enterprise for a given number of years;" << endl;
		cout << "2. withdraw a list of employees whose salary is higher than the specified one" << endl;
		cout << "3. withdraw a list of employees holding a given position." << endl;
		cin >> a3;

		switch (a3) {
		case 1: greaterWorkingExperience(workers, size, currentYear);
			break;
		case 2:
			greaterSalary(workers, size);
			break;
		case 3: certainPosition(workers, size);
			break;
		}

	} while (a3 < 0 || a3 > 3);
}

int main() {
	const int timeAdd = 1900;
	struct tm newtime;
	time_t now = time(NULL);
	localtime_s(&newtime, &now);
	


	FullName name;
	name.surname = "Krasovski";
	name.firstName = 'A';
	name.secondName = 'N';
	Worker testObject(name, "student", 2020, 190);
	testObject.setJoinYear(2005);
	testObject.show();
	
	int a;
	do {
		cout << "select function" << endl;
		cout << "1. change object fields" << endl;
		cout << "2. show object fields" << endl;
		cout << "3. working with static array" << endl;
		cout << "4. working with dynamic array" << endl;
		cout << "0. exit" << endl;
		cin >> a;

		switch (a) {
		case 1: 
		{int a1;
		do {
			cout << "select function" << endl;
			cout << "1. change full name" << endl;
			cout << "2. change working position" << endl;
			cout << "3. change the year of joining" << endl;
			cout << "4. change salary" << endl;
			cin >> a1;

			switch (a1) {
			case 1:
			{FullName changedName;
			cout << "Enter surname" << endl;
			cin >> changedName.surname;
			cout << "Enter initials" << endl;
			cin >> changedName.firstName >> changedName.secondName;
			testObject.setFullName(changedName);
			cout << "Now your object:: " << endl;
			testObject.show(); }
			break;
			case 2:
			{string changedPosition;
			cout << "Enter a new person`s position" << endl;
			cin >> changedPosition;
			testObject.setPosition(changedPosition);
			cout << "Now your object:: " << endl;
			testObject.show(); }
			break;
			case 3:
			{int changedJoinYear;
			cout << "Enter the changed start year of work " << endl;
			cin >> changedJoinYear;
			testObject.setJoinYear(changedJoinYear);
			cout << "Now your object:: " << endl;
			testObject.show(); }
			break;
			case 4:
			{int changedSalary;
			cout << "Enter new salary" << endl;
			cin >> changedSalary;
			testObject.setSalary(changedSalary);
			cout << "Now your object:: " << endl;
			testObject.show(); }
			break;
			}


		} while (a1 < 0 || a1 > 4); }
			break;

		case 2: {testObject.show(); }
			break;

		case 3:
		{const int size = 6;
		Worker workers[size];

		workers[0] = Worker("Krasovski", 'A', 'N', "student", 2020, 190);
		workers[1] = Worker("Travkina", 'V', 'R', "mathprofi", 2003, 140);
		workers[2] = Worker("Solovei", 'V', 'R', "student", 2004, 150);
		workers[3] = Worker("Logash", 'P', 'A', "worker", 2011, 200);
		workers[4] = Worker("Reshetnikov", 'N', 'S', "student", 2008, 140);
		workers[5] = Worker("Zakharina", 'E', 'I', "student", 2021, 110);

		operationWithArrays(workers, size, newtime.tm_year + timeAdd);	}
			break;

		case 4: 
		{cout << "Enter the size of the array" << endl;
		int n;
		cin >> n;

		Worker* workers = new Worker[n];

		for (int i = 0; i < n; i++) {
			workers[i].fillObject();
		}

		operationWithArrays(workers, n, newtime.tm_year + timeAdd); 
		delete[] workers; }
		
		break;
		}
	} while (a != 0);

	return 0;
}

