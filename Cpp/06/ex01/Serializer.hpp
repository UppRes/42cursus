#pragma once

#include <iostream>

struct Data;

class Serializer
{
	public:

		static uintptr_t serialize(Data *);
		static Data* deserialize(uintptr_t);

		Serializer();
		Serializer(const std::string &);
		Serializer(Serializer &);
		~Serializer();

		Serializer &operator=(const Serializer &);
};