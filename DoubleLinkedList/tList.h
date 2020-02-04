#pragma once
#include <iostream>
// Templated doubly-linked list
template<typename T>
class tList
{
	struct Node
	{
		T data;                     // data for the element stored
		Node * prev;                // pointer to node following this node
		Node * next;                // pointer to node following this node
	};

	Node * head;                    // pointer to head of linked list
	Node * tail;                    // pointer to tail of linked list

public:
	tList();                              // initializes head to null
	tList(const tList& other);            // copy-constructor
	tList& operator=(const tList &rhs);   // copy-assignment
	~tList();                             // delete all nodes upon destruction

	void push_front(const T& val);  // adds element to front (i.e. head)
	void pop_front();               // removes element from front
	void push_back(const T& val);   // adds element to back (i.e. before back)
	void pop_back();                // removes element from back

	T& front();                     // returns the element at the head
	const T& front() const;         // returns the element at the head (const)
	T& back();                      // returns the element at the tail
	const T& back() const;          // returns the element at the tail (const)

	void remove(const T& val);      // removes all elements equal to the given value

	bool empty() const;             // Returns true if there are no elements
	void clear();                   // Destroys every single node in the linked list
	void resize(size_t newSize);    // Resizes the linked list to contain the given number of elements
									// New elements are default-initialized
	size_t currentSize();

	void bubbleSort();				//Sorts the list


	class iterator
	{
		Node * cur;                                 // current node being operated upon

	public:
		iterator();                                 // initializes an empty iterator pointing to null
		iterator(Node * startNode);                 // initializes an iterator pointing to the given node

		bool operator==(const iterator& rhs) const; // returns true if the iterator points to the same node
		bool operator!=(const iterator& rhs) const; // returns false if the iterator does not point to the same node
		T& operator*();                             // returns a reference to the element pointed to by the current node
		const T& operator*() const;                 // returns a reference to the element pointed to by the current node
		iterator& operator++();                     // pre-increment (returns a reference to this iterator after it is incremented)
		iterator operator++(int);                   // post-increment (returns an iterator as it was before it was incremented)
		iterator& operator--();                     // pre-decrement (returns a reference to this iterator after it is decremented)
		iterator operator--(int);                   // post-decrement (returns an iterator as it was before it was decremented)
	};

	iterator begin();                               // returns an iterator pointing to the first element
	const iterator begin() const;                   // returns a const iterator pointing to the first element
	iterator end();                                 // returns an iterator pointing to one past the last element
	const iterator end() const;                     // returns a const iterator pointing to one past the last element
};

// initializes head to null
template<typename T>
inline tList<T>::tList()
{
	head = nullptr;
	tail = nullptr;
}

template<typename T>
inline tList<T>::tList(const tList & other)
{
}

template<typename T>
inline tList<T> & tList<T>::operator=(const tList & rhs)
{
	// TODO: insert return statement here
}

template<typename T>
inline tList<T>::~tList()
{
}

template<typename T>
inline void tList<T>::push_front(const T & val)
{
	Node* newVal = new Node();
	newVal->data = val;
	newVal->next = this->head;
	if (this->head != nullptr)
	{
		this->head->prev = newVal;
	}
	this->head = newVal;
	if (this->tail == nullptr)
	{
		this->tail = this->head;
	}
}

template<typename T>
inline void tList<T>::pop_front()
{
	if (this->head != nullptr)
	{
		Node* N = new Node();
		N = this->head;
		this->head = this->head->next;
		//this->head->prev = nullptr;
		delete(N);
	}
}

template<typename T>
inline void tList<T>::push_back(const T & val)
{
	Node* newVal = new Node();
	newVal->data = val;
	newVal->prev = this->tail;
	if (this->tail != nullptr)
	{
		this->tail->next = newVal;
	}
	this->tail = newVal;
	if (this->head == nullptr)
	{
		push_front(val);
		//this->head = this->tail;
	}
}

template<typename T>
inline void tList<T>::pop_back()
{
	if (this->tail != nullptr)
	{
		Node* N = new Node();
		N = this->tail;
		this->tail = this->tail->prev;
		this->tail->next = nullptr;
		delete(N);
	}
}


template<typename T>
inline T & tList<T>::front()
{
	// TODO: insert return statement here
	return this->head;
}

template<typename T>
inline const T & tList<T>::front() const
{
	// TODO: insert return statement here
	return this->head;
}

template<typename T>
inline T & tList<T>::back()
{
	// TODO: insert return statement here
}

template<typename T>
inline const T & tList<T>::back() const
{
	// TODO: insert return statement here
}

template<typename T>
inline void tList<T>::remove(const T & val)
{
	if (this->head != nullptr)
	{
		Node* curNode = this->head;
		while (this->head->data == val && curNode != nullptr)
		{
			pop_front();
			curNode = this->head;
		}
		while (curNode != nullptr)
		{
			if (curNode->data == val)
			{
				if (curNode == this->tail)
				{
					this->tail = this->tail->prev;
				}
				curNode->prev->next = curNode->next;
				if (curNode->next != nullptr)
				{
					curNode->next->prev = curNode->prev;
				}
			}
			curNode = curNode->next;
		}
	}
}

// Returns true if there are no elements
template<typename T>
inline bool tList<T>::empty() const 
{
	if (this->head == nullptr && this->tail == nullptr)
	{
		return true;
	}
	return false;
}

template<typename T>
inline void tList<T>::clear()
{
	while (this->head != nullptr)
	{
		pop_back();
	}
}

template<typename T>
inline void tList<T>::resize(size_t newSize)
{
	size_t size = this->currentSize();
	size_t sizeDifferent = 0;


	if (size > newSize)
	{
		sizeDifferent = size - newSize;
		sizeDifferent++;
		for (size_t i = 0; i < sizeDifferent; i++)
		{
			pop_back();
		}
	}
	else if (size < newSize)
	{
		sizeDifferent = newSize - size;
		sizeDifferent++;
		for (size_t i = 0; i < sizeDifferent; i++)
		{
			push_back(0);
		}
	}
}

template<typename T>
inline size_t tList<T>::currentSize()
{
	iterator endOfList = iterator(this->tail);

	iterator beginingOfList =  begin();
	size_t size = 0;
	while (beginingOfList != endOfList)
	{
		size++;
		beginingOfList++;
	}
	return size;
}

template<typename T>
inline void tList<T>::bubbleSort()
{
	Node* temp = this->tail;
	Node* curNode = this->tail;
	Node* prevNode = this->tail->prev;
	size_t size = this->currentSize();
	for (size_t i = 0; i < size-1; i++)
	{
		temp = this->tail;
		curNode = this->tail;
		prevNode = this->tail->prev;
		for (size_t j = size - 1; j >= i + 1; j--)
		{
			if ((curNode->data < prevNode->data) && prevNode != nullptr)
			{
				Node* tempNode = new Node;
				tempNode->next = prevNode->next;
				tempNode->prev = prevNode->prev;
				prevNode->next = curNode->next;
				prevNode->prev = curNode->prev;
				curNode->next = tempNode->next;
				curNode->prev = tempNode->prev;
				delete(tempNode);
				if (temp == this->tail)
				{
					this->tail = prevNode;
				}
				curNode = temp;
				prevNode = curNode->prev;
			}
			temp = temp->prev;
			curNode = curNode->prev;
			prevNode = prevNode->prev;
		}
	}
}

template<typename T>
inline typename tList<T> :: iterator tList<T>::begin()
{
	// = this->head;
	return iterator(this->head);
}

template<typename T>
inline const typename tList<T> ::iterator tList<T>::begin() const
{
	//cur = this->head;
	return iterator(this->head);
}

template<typename T>
inline typename tList<T> ::iterator tList<T>::end()
{
	//this->cur = this->tail->next;
	return iterator();
}

template<typename T>
inline const typename tList<T> ::iterator tList<T>::end() const
{
	//this->cur = this->tail->next;
	return iterator();
}

template<typename T>
inline tList<T>::iterator::iterator()
{
	cur = nullptr;
}

template<typename T>
inline tList<T>::iterator::iterator(Node * startNode)
{
	cur = startNode;
}

template<typename T>
inline bool tList<T>::iterator::operator==(const iterator & rhs) const
{
	if (this->cur == rhs->cur)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
inline bool tList<T>::iterator::operator!=(const iterator & rhs) const
{
	if (this->cur != rhs.cur)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
inline T & tList<T>::iterator::operator*()
{
	// TODO: insert return statement here
	return iterator();
}

template<typename T>
inline const T & tList<T>::iterator::operator*() const
{
	// TODO: insert return statement here
	return iterator();
}


template<typename T>
inline typename tList<T> ::iterator  & tList<T>::iterator::operator++()
{
	this->cur = this->cur->next;
	return iterator();
	// TODO: insert return statement here
}

template<typename T>
inline typename tList<T> ::iterator tList<T>::iterator::operator++(int)
{
	this->cur = this->cur->next;
	return iterator();
}

template<typename T>
inline typename tList<T> ::iterator & tList<T>::iterator::operator--()
{
	this->cur = this->cur->prev;
	return iterator();
	// TODO: insert return statement here
}

template<typename T>
inline typename tList<T> ::iterator tList<T>::iterator::operator--(int)
{
	this->cur = this->cur->prev;
	return iterator();
}
