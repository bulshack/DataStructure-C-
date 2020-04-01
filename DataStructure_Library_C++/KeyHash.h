#pragma once

template <typename K>
struct KeyHash
{
public:
	unsigned long operator()(const K& key, int TABLE_SIZE) const
	{
		return (key) % TABLE_SIZE;
	}
};
