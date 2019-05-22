//	This include
#include "debugdisplay.h"


//	Library includes
#include <iostream>


//	Local includes
#include "item.h"



void Print(std::string _Text)
{
	std::cout << _Text << std::endl;
}

void Print(const char* _Text)
{
	std::cout << _Text << std::endl;
}

void Print(std::vector<C_Item*> _Vector)
{
	for (unsigned int iX = 0; iX < _Vector.size(); ++iX)
	{
		std::cout << (nullptr == _Vector[iX] ? 0 : _Vector[iX]->GetID()) << std::endl;
	}
}

void Print(std::vector<std::vector<C_Item*>> _Vector)
{
	for (unsigned int iX = 0; iX < _Vector.size(); ++iX)
	{
		for (unsigned int iY = 0; iY < _Vector[iX].size(); ++iY)
		{
			std::cout << (nullptr == _Vector[iX][iY] ? 0 : _Vector[iX][iY]->GetID()) << ' ';
		}
		std::cout << std::endl;
	}
}

