#ifndef ANIMAL_H
#define ANIMAL_H

#include "EnumSerializer.h"

class Animal
{
public:
	virtual void MakeNoise() = 0;

	std::string Serialize();
	static Animal* Deserialize(const std::string& type);

protected:
	ENUM_STRING_PAIR_ENABLED;
	enum class Type
	{
		Dog,
		Cat,
		ENUM_SIZE_LAST
	};

protected:
	Animal(Type t);
	virtual std::string SerializeDerived() = 0;
	virtual void DeserializeDerived(const std::string& s) = 0;

private:
	Type m_type;
};

#endif