#include <iostream>
#include <fstream>
using namespace std;

struct Employee
{
	int empID;
	char name[30];
	char designation[30];
	float salary;
	bool isDeleted;
};

struct IndexEntry
{
	int empID;
	int position;
};

// Add employee
void addEmployee()
{
	Employee emp;
	cout << "Enter Employee ID: ";
	cin >> emp.empID;
	cin.ignore();
	cout << "Enter Name: ";
	cin.getline(emp.name, 30);
	cout << "Enter Designation: ";
	cin.getline(emp.designation, 30);
	cout << "Enter Salary: ";
	cin >> emp.salary;
	emp.isDeleted = false;

	ofstream dataFile("employee.dat", ios::binary | ios::app);
	dataFile.write((char*)&emp, sizeof(emp));
	dataFile.close();

	// Get record position
	ifstream check("employee.dat", ios::binary);
	check.seekg(0, ios::end);
	int pos = (check.tellg() / sizeof(emp)) - 1;
	check.close();
	cout<<"Position"<<pos;
	// Add index entry
	IndexEntry idx;
	idx.empID = emp.empID;
	idx.position = pos;

	ofstream indexFile("index.dat", ios::binary | ios::app);
	indexFile.write((char*)&idx, sizeof(idx));
	indexFile.close();

	cout << "Employee added successfully.\n";
}

// Search employee by ID
void searchEmployee() {
	int id;
	bool found = false;
	cout << "Enter Employee ID to search: ";
	cin >> id;

	ifstream indexFile("index.dat", ios::binary);
	IndexEntry idx;
	while (indexFile.read((char*)&idx, sizeof(idx))) {
	if (idx.empID == id) {
	ifstream dataFile("employee.dat", ios::binary);
	Employee emp;
	dataFile.seekg(idx.position * sizeof(emp));
	dataFile.read((char*)&emp, sizeof(emp));
	dataFile.close();

	if (!emp.isDeleted) {
	cout << "\nEmployee ID: " << emp.empID
	<< "\nName: " << emp.name
	<< "\nDesignation: " << emp.designation
	<< "\nSalary: " << emp.salary << "\n";
	}
	else {
	cout << "Employee record has been deleted.\n";
	}

	found = true;
	break;
	}
	}

	if (!found)
	cout << "Employee not found.\n";

	indexFile.close();
}

// Delete employee (logical)
void deleteEmployee() {
	int id;
	bool found = false;
	cout << "Enter Employee ID to delete: ";
	cin >> id;

	ifstream indexFile("index.dat", ios::binary);
	IndexEntry idx;
	while (indexFile.read((char*)&idx, sizeof(idx))) {
	if (idx.empID == id) {
	fstream dataFile("employee.dat", ios::in | ios::out | ios::binary);
	Employee emp;
	dataFile.seekg(idx.position * sizeof(emp));
	dataFile.read((char*)&emp, sizeof(emp));

	if (!emp.isDeleted) {
	emp.isDeleted = true;
	dataFile.seekp(idx.position * sizeof(emp));
	dataFile.write((char*)&emp, sizeof(emp));
	cout << "Employee deleted successfully.\n";
	} else {
	cout << "Employee is already deleted.\n";
	}

	dataFile.close();
	found = true;
	break;
	}
	}

	if (!found)
		cout << "Employee not found.\n";
	indexFile.close();
}

// Main menu
int main() {
int choice;
do {
cout << "\n--- Employee Management ---\n";
cout << "1. Add Employee\n";
cout << "2. Search Employee\n";
cout << "3. Delete Employee\n";
cout << "4. Exit\n";
cout << "Enter your choice: ";
cin >> choice;

switch (choice) {
case 1: addEmployee(); break;
case 2: searchEmployee(); break;
case 3: deleteEmployee(); break;
case 4: cout << "Exiting...\n"; break;
default: cout << "Invalid choice. Try again.\n";
}
} while (choice != 4);

return 0;
}