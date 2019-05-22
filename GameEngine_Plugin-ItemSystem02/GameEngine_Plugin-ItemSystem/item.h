#ifndef __ITEM_H__
#define __ITEM_H__
//	Library includes
#include <string>


//	Local includes
#include "utils.h"



class C_Item
{
public:
	C_Item();
	C_Item(const unsigned int& _ID);
	C_Item(const unsigned int& _Width, const unsigned int& _Height);
	C_Item(const unsigned int& _Width, const unsigned int& _Height, const unsigned int& _ID);
	C_Item(const unsigned int& _Width, const unsigned int& _Height, const unsigned int& _X, const unsigned int& _Y);
	C_Item(const unsigned int& _Width, const unsigned int& _Height, const unsigned int& _X, const unsigned int& _Y, const unsigned int& _ID);

	C_Item(const std::string& _Name);
	C_Item(const unsigned int& _ID, const std::string& _Name);
	C_Item(const unsigned int& _Width, const unsigned int& _Height, const std::string& _Name);
	C_Item(const unsigned int& _Width, const unsigned int& _Height, const unsigned int& _ID, const std::string& _Name);
	C_Item(const unsigned int& _Width, const unsigned int& _Height, const unsigned int& _X, const unsigned int& _Y, const std::string& _Name);
	C_Item(const unsigned int& _Width, const unsigned int& _Height, const unsigned int& _X, const unsigned int& _Y, const unsigned int& _ID, const std::string& _Name);

	virtual ~C_Item();

	void SetID(const unsigned int& _ID);
	const unsigned int& GetID();

	void SetName(const std::string& _Name);
	const std::string& GetName();

	void SetSize(const unsigned int& _Width, const unsigned int& _Height);

	const unsigned int GetWidth();
	const unsigned int GetHeight();

	void SetPosition(const unsigned int& _X, const unsigned int& _Y);
	void ResetPosition();

	const unsigned int GetXPos();
	const unsigned int GetYPos();

	void SetItemRegion(const ItemRegion _ItemRegion);
	const ItemRegion GetItemRegion();


private:


protected:
	std::string m_sName = std::string();
	unsigned int m_iID = END;
	ItemRegion m_rItemRegion = ItemRegion();


};

#endif