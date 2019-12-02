#pragma once
template <class T>
class LinkedList
{
public:	
	struct Node
	{

		T value;
		Node* next = nullptr;
	};

	Node *head;
	Node *tail;
	
		

	LinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}

	void insert_node(T value)
	{
		Node *temp = new Node;

		temp->value = value;
		temp->next = nullptr;

		if (head == nullptr)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			tail = tail->next;
		}	
	}



	void Display()
	{
		Node* temp;
		temp = head;

		while (temp != nullptr)
		{
			
			std::cout << temp->value << "-->";

			temp =  temp->next;

			if (temp == nullptr)
			{
				std::cout << "NULL";
			}
		}
	}
};