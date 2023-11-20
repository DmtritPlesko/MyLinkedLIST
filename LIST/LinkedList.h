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
		// �������� ������ ����
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

	//����������� �� ��������� ��� �������� 
	LinkedList()
	{
		Head = nullptr;
		Tail=nullptr;
		size = 0;
	}

	//������ �������������
	LinkedList(std::initializer_list<T>array)
	{
		for (auto x = array.begin(); x != array.end(); x++)
		{
			push_back(*(x));
		}
	}

	//���������� � ����� ����� 
	Node* push_back(T _value)
	{
		Node* new_node = new Node(_value);
		if (!size)//���� ������ ������� �� ������ � ����� ����������
		{
			this->Head = new_node;
			this->Tail = new_node;
		}
		else
		{
			//���� �� ������� �� ������ �������� �� ���� ����� � ����� ���������
			this->Tail->nextvalue = new_node;
			Tail = new_node;
		}
		//����������� ������
		this->size++;
		return new_node;
	}
	//����������� �� ������ � ����� ������� �����
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

	//������� �������� ����� ��������� ������� 
	Node* insert(size_t index,T _value)
	{
		Node* new_node = Head;
		Node* temp = new Node;
		if (index > size||index<0)//�������� ������ ������ ��� ����������� ������
		{
			//�� ����� 0
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
				//����� ����� ������ �� ��������� ������� 
				new_node = get(index-1);
				//��������� temp ��� �������� ������ �� ��������� ������� � ��� �������� ����� 
				temp->nextvalue = new_node->nextvalue;
				temp->value = _value;
				//����� ��� ��� � new_node ��� ������ 
				new_node->nextvalue = temp;
			}
		}
		return new_node;
	}
	//�������� �������� �� ��������� ������� 
	Node* Remove(size_t index)
	{
		Node* new_node = Head;
		Node* temp = new Node;
		if (index > size || index<0)//�������� ������ ������ ��� ����������� ������
		{
			//�� ����� 0
			new_node = 0;
		}
		else
		{
			//���� ������ ��������� �� ������ �� ������� �
			if (index==0)
			{
				pop();
			}
			//���� �������� ������ ��������� �� ����� �� ������� ���
			else if (index == size)
			{
				pop_back();
			}
			//���� ��������� ������ ��������� ����� ���� �� ���������� ��� � ��� ��������� �������� 
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
	//�������� ������ 
	Node* pop()
	{
		Node* new_node = Head;

		//����� ��������� �� ������ ������� 
		new_node = new_node->nextvalue;
		
		//� ��� �� �������� ��������� �� ����
		Head = new_node;
		this->size--;
		return 0;
	}

	//�������� ������ 
	Node* pop_back()
	{
		Node* new_node=new Node;
		//���� �
		if (Head->value==Tail->value)
		{
			pop();
		}
		else
		{
			new_node = get(size-2);
			//����� ����� �� �������� ����������� �����
			//delete Tail;
			//� ��� ��� �������� ����� ����������
			Tail = new_node;
			Tail->nextvalue = nullptr;
		}
		size--;
		return new_node;
	}


	//����� �� �����
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

