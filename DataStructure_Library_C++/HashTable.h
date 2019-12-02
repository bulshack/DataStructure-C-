#pragma once


template <typename K, typename V>
class hashtable
{
private:
	K key;
	V value;
	hashtable* next;
public:

	hashtable(const K& key, const V& value) :
		key(key), value(value), next(NULL)
	{

	}

	

	
	K getKey() const
	{
		return key;
	}

	V getValue() const
	{
		return value;
	}

	void setValue(V value)
	{
		hashtable::value = value;
	}

	hashtable *getNext() const
	{
		return next;
	}

	void setNext(hashtable* next)
	{
		hashtable::next = next;
	}


};

