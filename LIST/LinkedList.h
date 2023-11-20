#pragma once
#include<iostream>
template<typename T>
class LinkedList
{
private:
	class Node
	{
	public:
		T value;
		Node* nextvalue;
		Node()
		{

		}
		// Создание нового узла
		Node(T _value, Node* _nextvalue = nullptr)
		{
			this->value = _value;
			this->nextvalue = _nextvalue;
		}
	};
	Node* Head;
	Node* Tail;
	size_t size;
public:

	//конструктов по умолчанию для создания 
	LinkedList()
	{
		Head = nullptr;
		Tail=nullptr;
		size = 0;
	}

	//Список инициализации
	LinkedList(std::initializer_list<T>array)
	{
		for (auto x = array.begin(); x != array.end(); x++)
		{
			push_back(*(x));
		}
	}

	//добавления в конец Листа 
	Node* push_back(T _value)
	{
		Node* new_node = new Node(_value);
		if (!size)//если размер нулевой то голова и хвост одинаковые
		{
			this->Head = new_node;
			this->Tail = new_node;
		}
		else
		{
			//если не нулевой то голова остается на своём месте а хвост двигается
			this->Tail->nextvalue = new_node;
			Tail = new_node;
		}
		//увеличивыем размер
		this->size++;
		return new_node;
	}
	//ПРОБЕГАЕМСЯ ПО СПИСКУ И БЕРЕМ КОТОРЫЙ НУЖЕН
	Node* get(size_t index)
	{
		Node* new_node = Head;
		if (size == 0)
		{
			return new_node;
		}
		else
		{
			for (int i = 0; i < index; i++)
			{
				new_node = new_node->nextvalue;
			}
			return new_node;
		}
	}

	//вставка значения после введеного индекса 
	Node* insert(size_t index,T _value)
	{
		Node* new_node = Head;
		Node* temp = new Node;
		if (index > size||index<0)//введеный индекс больше чем изначальный размер
		{
			//то будет 0
			new_node = 0;
		}
		else
		{
			this->size++;
			if (!index)
			{
				temp->value = new_node->value;
				new_node->value = _value;
				temp->nextvalue = new_node->nextvalue;
				new_node->nextvalue = temp;
			}
			else
			{
				//иначе берем элмент по введеному индексу 
				new_node = get(index-1);
				//перменной temp даём значение ссылки на следующий элемент и его числовую форму 
				temp->nextvalue = new_node->nextvalue;
				temp->value = _value;
				//кладём все это в new_node для прыжка 
				new_node->nextvalue = temp;
			}
		}
		return new_node;
	}
	//удаление элемента по введеному индексу 
	Node* Remove(size_t index)
	{
		Node* new_node = Head;
		Node* temp = new Node;
		if (index > size || index<0)//введеный индекс больше чем изначальный размер
		{
			//то будет 0
			new_node = 0;
		}
		else
		{
			//если индекс указывает на голову то удаляем её
			if (index==0)
			{
				pop();
			}
			//если введеный индекс указывает на хвост то удаляем его
			else if (index == size)
			{
				pop_back();
			}
			//если введенный индекс находится между ними то пропускаем его а все следующие сдвигаем 
			else 
			{
				temp = get(index + 1);
				new_node = get(index - 1);
				new_node->nextvalue = temp;
			}
			this->size--;
		}
		return new_node;
	}
	//удаление головы 
	Node* pop()
	{
		Node* new_node = Head;

		//берем следующий от головы элемент 
		new_node = new_node->nextvalue;
		
		//и даём ей значение следующее от нуля
		Head = new_node;
		this->size--;
		return 0;
	}

	//удаление хвоста 
	Node* pop_back()
	{
		Node* new_node=new Node;
		//если о
		if (Head->value==Tail->value)
		{
			pop();
		}
		else
		{
			new_node = get(size-2);
			//когда дошли то обнуляем изначальный хвост
			//delete Tail;
			//и даём ему значение нашей переменной
			Tail = new_node;
			Tail->nextvalue = nullptr;
		}
		size--;
		return new_node;
	}


	//вывод на экран
	friend std::ostream& operator<<(std::ostream& tech,LinkedList& list)
	{
		for (size_t i = 0; i < list.size; i++)
		{
			tech << list.get(i)->value << " ";
		}
		return tech;
	}
	void display()
	{
		Node* new_node = Head;
		while (new_node != nullptr)
		{
			std::cout << new_node->value << " ";
			new_node = new_node->nextvalue;
		}
	}
};

