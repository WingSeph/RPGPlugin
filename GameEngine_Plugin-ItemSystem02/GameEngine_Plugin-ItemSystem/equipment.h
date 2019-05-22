#ifndef __EQUIPMENT_H__
#define __EQUIPMENT_H__
//	Library includes


//	Local includes
#include "item.h"


class C_Stats;


class C_Equipment : public C_Item
{
public:
	C_Equipment();
	C_Equipment(const unsigned short& _Width, const unsigned short& _Height);
	virtual ~C_Equipment();

	
private:


protected:
	C_Stats* m_pStats = nullptr;


};

#endif