/*
Thomas Wimer
Advanced File Operations
Langley
3/28/2021
*/


#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <iomanip>


const int NAME_SIZE = 40;

struct Product_S
{

	long int number;
	char name[NAME_SIZE];
	double price;
	int quantity;

};



using namespace std;


int Show_Menu();
void Create_File(fstream& bin);
void Display_File(fstream& bin);
void Display_Record(fstream& bin, int counter);
void Modify_Record(fstream& bin);

int main()
{

	Product_S prod;

	string inventory;

	int choice = 0;

	bool go = true;

	int counter = 0;

	


	fstream bin(inventory, ios::out | ios::binary);

	//Create_File(bin);

	while (choice != 4)
	{
		//Create_File(bin);

		Show_Menu();





		switch (choice)
		{

		case 1:

			Display_File(bin);

			break;

		case 2:

			Display_Record(bin, counter);

			break;

		case 3:

			Modify_Record(bin);

			break;

		case 4:


			cout << "Goodbye";

			break;

		default:

			

			cout << "Default";

			Create_File(bin);
			Display_File(bin);
			Display_Record(bin, counter);
			Modify_Record(bin);


		}


		//if (choice == 1)
		//{

		//	Display_File(bin);

		//}
		//else if (choice == 2)
		//{

		//	cout << "choice 2";

		//}
		//else if (choice == 3)
		//{

		//	cout << "choice 3";

		//}
		//else if (choice == 4)
		//{

		//	
		//	cout << "\nGoodbye";
		//	go = false;
		//}







		
	}
	

	bin.close();


	cout << endl << endl;
	system("pause");
	return 0;
}


int Show_Menu()
{
	int choice = 0;

	bool proc = true;

	
		

		cout << "\nProduct Inventory";
		cout << "\n1. Display the entire inventory";
		cout << "\n2. Display a particular product";
		cout << "\n3. Modify a product";
		cout << "\n4. Exit the program" << endl;

		cin >> choice;

		if (choice < 1 || choice > 4)
		{
			cout << "\nSorry but " << choice << " was not a valid option. Please try again . . .";
			cin >> choice;
		}

		//cin >> choice;

		//cout << choice;

		return choice;
	

	
}

void Create_File(fstream& bin)
{

	Product_S prod;

	int counter = 0;


	while (counter != 2) // <----------------------CHANGE BACK TO 4 
	{
	
		cout << "\nRecord #" << counter;
		cout << "\nProduct Number: ";
		cin >> prod.number;

		bin << prod.number << endl;

		cout << "Product Name: ";
		cin.ignore();
		cin.get(prod.name, NAME_SIZE);
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		bin << prod.name << endl;

		cout << "Price: ";
		cin >> prod.price;

		bin << prod.price << endl;

		cout << "Quantity: ";
		cin >> prod.quantity;

		bin << prod.quantity << endl;


		counter++;
	}
}

void Display_File(fstream& bin)
{

	int counter = 0;

	cout << setprecision(2) << fixed;

	Product_S prod;

	while (bin >> prod.number)
	{

		bin >> prod.number;

		bin.get();
		bin.get(prod.name, NAME_SIZE);

		bin >> prod.price;

		bin >> prod.quantity;


		cout << "\nProduct Number: "<< prod.number;
		cout << "\nProdct Name: " << prod.name;
		cout << "\nPrice: $" << prod.price;
		cout << "\nQuantity: " << prod.quantity;


		counter++;
	}

	for (int i = 0; i < counter; i++)
	{
		bin >> prod.number;

		bin.get();
		bin.get(prod.name, NAME_SIZE);

		bin >> prod.price;

		bin >> prod.quantity;


		cout << "\nProduct Number: " << prod.number;
		cout << "\nProdct Name: " << prod.name;
		cout << "\nPrice: $" << prod.price;
		cout << "\nQuantity: " << prod.quantity;


		counter++;
	}




}

void Display_Record(fstream& bin, int counter)
{
	Product_S prod;

	int record;

	cout << "\nEnter the record number to be displayed: ";
	cin >> record;

	/*for (int i = 0; i < 1; i++)
	{

		cout << "\nProduct Number: " << prod.number;
		cout << "\nProdct Name: " << prod.name;
		cout << "\nPrice: $" << prod.price;
		cout << "\nQuantity: " << prod.quantity;



	}*/






}

void Modify_Record(fstream& bin)
{

	Product_S prod;

	int record;

	cout << "\nEnter the record number to be modified: ";
	cin >> record;

	for (int i = 0; i < 1; i++)
	{

		cout << "\nRecord #" << record;
		cout << "\nProduct Number: ";
		cin >> prod.number;

		bin << prod.number << endl;

		cout << "Product Name: ";
		cin.ignore();
		cin.get(prod.name, NAME_SIZE);
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		bin << prod.name << endl;

		cout << "Price: ";
		cin >> prod.price;

		bin << prod.price << endl;

		cout << "Quantity: ";
		cin >> prod.quantity;

		bin << prod.quantity << endl;



	}





}