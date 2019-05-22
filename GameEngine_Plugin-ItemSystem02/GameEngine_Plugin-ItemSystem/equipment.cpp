//	This include
#include "equipment.h"


//	Library includes


//	Local includes


//	Static variables



C_Equipment::C_Equipment()
{
	SetSize(0, 0);
}

C_Equipment::C_Equipment(const unsigned short& _Width, const unsigned short& _Height)
{
	SetSize(_Width, _Height);
}

C_Equipment::~C_Equipment()
{
	if (nullptr != m_pStats)
	{
		delete m_pStats;
	}
}
