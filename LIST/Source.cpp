#include<iostream>
#include<string>
#include<Windows.h>
#include"LinkedList.h"
#include"Data.h"
#pragma region Int
//int main()
//{
//	LinkedList<int> list;
//
//
//	list.push_back(1);
//	list.push_back(2);
//	list.push_back(3);
//	list.push_back(4);
//	list.push_back(5);
//
//
//	std::cout << list;
//
//
//	list.pop();
//	std::cout << std::endl;
//	list.display();
//
//
//	list.push_back(5);
//	std::cout << std::endl;
//	list.display();
//
//
//	list.pop_back();
//	std::cout << std::endl;
//	list.display();
//
//
//	list.push_back(4);
//	std::cout << std::endl;
//	list.display();
//
//
//	list.insert(0, 100);
//	std::cout << std::endl;
//	list.display();
//
//
//	list.Remove(1);
//	std::cout << std::endl;
//	list.display();
//	
//
//}
#pragma endregion

#pragma region String
//int main()
//{ 
	/*SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "RU");
	LinkedList<std::string> list;
	list.push_back("Привет ");
	list.push_back("меня ");
	list.push_back("зовут ");
	list.push_back("Дима");
	std::cout << std::endl;
	std::cout << list;
	list.pop_back();
	std::cout << std::endl;
	std::cout << list;
	list.pop();
	std::cout << std::endl;
	std::cout << list;
	list.insert(2, "Дима");
	std::cout << std::endl;
	std::cout << list;
	list.Remove(2);
	std::cout << std::endl;
	std::cout << list;*/
//}
#pragma endregion

#pragma region Data
int main()
{
	LinkedList<Data>list({
		{2, 5, 2000}, 
		{3, 5, 2001}, 
		{4, 5, 1998}
		});
	std::cout << list;
}
#pragma endregion

