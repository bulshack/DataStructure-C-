#pragma once
#include "Libraries.h"
template <typename K, typename V, typename F = KeyHash<K>>

class HashMap {
public:
	HashMap(int size)
	{
		//construct zero initialized hash table of size
		TABLE_SIZE = size;

		table = new hashtable <K, V> * [TABLE_SIZE]();
	}

	~HashMap()
	{
		//destroy all

		for (size_t i = 0; i < TABLE_SIZE; ++i)
		{
			hashtable<K, V>* entry = table[i];

			while (entry != NULL)
			{
				hashtable<K, V>* prev = entry;
				entry = entry->getNext();
				delete prev;
			}
			table[i] = NULL;
		}

		delete[] table;
	}

	bool get(const K& key, V& value)
	{
		unsigned long hashValue = hashFunc(key, TABLE_SIZE);
		hashtable<K, V>* entry = table[hashValue];

		while (entry != NULL)
		{
			if (entry->getKey() == key)
			{
				value = entry->getValue();
				return true;
			}

			entry = entry->getNext();
		}

		return false;
	}

	void put(const K& key, const V& value)
	{
		unsigned long hashValue = hashFunc(key, TABLE_SIZE);

		hashtable<K, V>* prev = NULL;

		hashtable<K, V>* entry = table[hashValue];

		while (entry != NULL && entry->getKey() != key)
		{
			prev = entry;
			entry = entry->getNext();
		}

		if (entry == NULL)
		{
			entry = new hashtable<K, V>(key, value);

			if (prev == NULL)
			{
				table[hashValue] = entry;
			}
			else
			{
				entry->setNext(entry);
			}
		}
		else
		{
			entry->setValue(value);
		}
	}

	void remove(const K& key)
	{
		unsigned long hashValue = hashFunc(key, TABLE_SIZE);
		hashtable<K, V>* prev = NULL;
		hashtable<K, V>* entry = table[hashValue];

		while (entry != NULL && entry->getKey() != key)
		{
			prev = entry;
			entry = entry->getNext();
		}

		if (entry == NULL)
		{
			return;
		}
		else
		{
			if (prev == NULL)
			{
				table[hashValue] = entry->getNext();
			}
			else
			{
				prev->setNext(entry->getNext());
			}
			delete entry;
		}
	}

private:
	//Hash Table
	hashtable <K, V>** table;
	F hashFunc;
	int TABLE_SIZE;
};
