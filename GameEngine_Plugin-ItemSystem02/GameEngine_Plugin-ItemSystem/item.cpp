//	This include
#include "item.h"


//	Library includes


//	Local includes


//	Static variables



C_Item::C_Item()
{
	SetSize(0, 0);
}

C_Item::C_Item(const unsigned int& _ID)
{
	SetID(_ID);
}

C_Item::C_Item(const unsigned int& _Width, const unsigned int& _Height)
{
	SetSize(_Width, _Height);
}

C_Item::C_Item(const unsigned int& _Width, const unsigned int& _Height, const unsigned int& _ID)
{
	SetSize(_Width, _Height);
	SetID(_ID);
}

C_Item::C_Item(const unsigned int& _Width, const unsigned int& _Height, const unsigned int& _X, const unsigned int& _Y)
{
	SetSize(_Width, _Height);
	SetPosition(_X, _Y);
}

C_Item::C_Item(const unsigned int& _Width, const unsigned int& _Height, const unsigned int& _X, const unsigned int& _Y, const unsigned int& _ID)
{
	SetSize(_Width, _Height);
	SetPosition(_X, _Y);
	SetID(_ID);
}

C_Item::~C_Item()
{

}

void
C_Item::SetID(const unsigned int& _ID)
{
	m_iID = _ID;
}

const unsigned int&
C_Item::GetID()
{
	return m_iID;
}

void
C_Item::SetName(const std::string& _Name)
{
	m_sName = _Name;
}

const std::string&
C_Item::GetName()
{
	return m_sName;
}

void
C_Item::SetSize(const unsigned int& _Width, const unsigned int& _Height)
{
	m_rItemRegion.XSize = _Width;
	m_rItemRegion.YSize = _Height;
}

const unsigned int
C_Item::GetWidth()
{
	return m_rItemRegion.XSize;
}

const unsigned int
C_Item::GetHeight()
{
	return m_rItemRegion.YSize;
}

void
C_Item::SetPosition(const unsigned int& _X, const unsigned int& _Y)
{
	m_rItemRegion.XPos = _X;
	m_rItemRegion.YPos = _Y;
}

void
C_Item::ResetPosition()
{
	m_rItemRegion.XPos = 0;
	m_rItemRegion.YPos = 0;
}

const unsigned int
C_Item::GetXPos()
{
	return m_rItemRegion.XPos;
}

const unsigned int
C_Item::GetYPos()
{
	return m_rItemRegion.YPos;
}

void
C_Item::SetItemRegion(const ItemRegion _ItemRegion)
{
	m_rItemRegion = _ItemRegion;
}

const ItemRegion
C_Item::GetItemRegion()
{
	return m_rItemRegion;
}