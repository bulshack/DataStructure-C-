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

	Node* head;
	Node* tail;
	int Size = 0;
	int ByteSize = 0;
	friend class Iterator;

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
			tail->next = temp;
			tail = tail->next;
		}

		Size += 1;
		ByteSize += sizeof(*temp);
	}

	Node* GetHead() const
	{
		return head;
	}

	T GetHeadValue() const
	{
		return head->value;
	}

	Node* GetTail() const
	{
		return tail;
	}

	T GetTailValue() const
	{
		return tail->value;
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
		std::cout << Size << +" Nodes" << std::endl;
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

		if (head == nullptr)
		{
			return;
		}

		while (temp != nullptr)
		{
			std::cout << temp->value << "-->";

			temp = temp->next;

			if (temp == nullptr)
			{
				std::cout << "NULL";
			}
		}
	}

	void DeleteNodeByValue(T value)
	{
		Node* current = head;

		Node* BeforeCurrent = head;

		if (head == nullptr)
		{
			return;
		}

		while (current != nullptr)
		{
			if (current->value == value)
			{
				if (current == head)
				{
					BeforeCurrent = BeforeCurrent->next;
					head = BeforeCurrent;
					delete current;
					break;
				}
				else
				{
					BeforeCurrent->next = current->next;

					delete current;

					if (BeforeCurrent->next == nullptr)
					{
						tail = BeforeCurrent;
					}

					break;
				}
			}
			BeforeCurrent = current;
			current = current->next;
		}
	}

	void Reverse()
	{
		Node* current = head;

		Node* next = nullptr;

		Node* prev = nullptr;

		while (current != NULL)
		{
			next = current->next;

			if (next == NULL)
			{
				tail = next;
			}

			current->next = prev;

			prev = current;

			current = next;
		}

		head = prev;
	}
};