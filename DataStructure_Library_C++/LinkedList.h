#pragma once
template <class T>
class LinkedList
{

private:
	struct Node
	{
		T value;
		Node* next = nullptr;
	};

	Node *head; 
	Node *tail;
	int Size = 0;
	int ByteSize = 0;
	
public:
	LinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}

	~LinkedList()
	{
		DeleteLinkedList();
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

		Size += 1;
		ByteSize += sizeof(*temp);
	}

	int GetByteSize() const
	{
		return ByteSize;
	}

	int GetSize() const
	{
		return Size;
	}

	void PrintInfo()
	{
		std::cout << Size << + " Nodes" << std::endl;
		std::cout << ByteSize << +" Total Bytes" << std::endl;
	}

	void preAppend(T value)
	{
		Node* temp = new Node;

		temp->value = value;
		temp->next = nullptr;

		if (head == nullptr)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			
			temp->next = head;

			head = temp;			
		}

		Size += 1;
		ByteSize += sizeof(*temp);
	}



	
	void DeleteLinkedList()
	{

		Node* temp;
		temp = head;

		while (temp != nullptr)
		{			
			head = head->next;
			delete temp;
			temp = head;		
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