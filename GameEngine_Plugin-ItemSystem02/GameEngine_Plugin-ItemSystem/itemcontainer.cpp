//	This include
#include "itemcontainer.h"


//	Library includes
#include <iostream>


//	Local includes
#include "item.h"


//	Static variables


C_ItemContainer::C_ItemContainer()
{
	SetSize(0, 0);
}

C_ItemContainer::C_ItemContainer(const unsigned int& _Width, const unsigned int& _Height)
{
	//	Set the size of the item container
	SetSize(_Width, _Height);
}

C_ItemContainer::~C_ItemContainer()
{
	
}

bool
C_ItemContainer::SetSize(const unsigned int& _Width, const unsigned int& _Height)
{
	if (END == _Width)
	{
		m_iWidth = END - 1;
	}
	else
	{
		m_iWidth = _Width;
	}
	if (END == _Height)
	{
		m_iHeight = END - 1;
	}
	else
	{
		m_iHeight = _Height;
	}
	for (unsigned int iX = 0; iX < m_iWidth; ++iX)
	{
		m_vItemSlots.push_back(std::vector<C_Item*>());
		for (unsigned int iY = 0; iY < m_iHeight; ++iY)
		{
			m_vItemSlots.back().push_back(nullptr);
		}
	}
	return 1;
}

bool
C_ItemContainer::AddItem(C_Item* _Item, const unsigned int& _X, const unsigned int& _Y)
{
	ItemRegion rItemRegion(_Item->GetWidth(), _Item->GetHeight(), _X, _Y);
	//	Check if item size is valid and if the location is free
	if (0 == CheckItemSize(rItemRegion) || 0 == CheckLocation(rItemRegion))
	{
		std::cout << "Item does no fit in position" << std::endl;
		return 0;
	}
	else
	{
		InsertItem(_Item, rItemRegion);
	}
	return 1;
}

bool
C_ItemContainer::RemoveItem(C_Item* _Item)
{
	//	Check if item is in the location
	if (CheckLocation(_Item->GetItemRegion(), _Item))
	{
		//	Remove the item
		ShuffleRemove(_Item, _Item->GetItemRegion());
		return 1;
	}
	return 0;
}

bool
C_ItemContainer::CheckItemSize(const ItemRegion& _ItemRegion)
{
	//	Check if the item fits within the inventory
	if (m_iWidth < _ItemRegion.XPos + _ItemRegion.XSize || m_iHeight < _ItemRegion.YPos + _ItemRegion.YSize)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

bool
C_ItemContainer::CheckLocation(const ItemRegion& _ItemRegion, C_Item* _Item)
{
	for (unsigned short sX = _ItemRegion.XPos; sX < _ItemRegion.XPos + _ItemRegion.XSize; ++sX)
	{
		for (unsigned short sY = _ItemRegion.YPos; sY < _ItemRegion.YPos + _ItemRegion.YSize; ++sY)
		{
			if (_Item != m_vItemSlots[sX][sY])
			{
				//	If Item is not where it should be return false
				return 0;
			}
		}
	}
	//	Item is in location, return true
	return 1;
}

void
C_ItemContainer::SetItemRegion(const ItemRegion& _ItemRegion, C_Item* _Item)
{
	for (unsigned short sX = _ItemRegion.XPos; sX < _ItemRegion.XPos + _ItemRegion.XSize; ++sX)
	{
		for (unsigned short sY = _ItemRegion.YPos; sY < _ItemRegion.YPos + _ItemRegion.YSize; ++sY)
		{
			//	Set the array to have Pointers to the Item in the area it's stored in the ItemContainer
			m_vItemSlots[sX][sY] = _Item;
		}
	}
}

void
C_ItemContainer::InsertItem(C_Item* _Item, const ItemRegion& _ItemRegion)
{
	//	Add item to the Item Vector
	m_vItems.push_back(_Item);
	//	Set the position values of the Item's ItemRegion
	_Item->SetPosition(_ItemRegion.XPos, _ItemRegion.YPos);
	//	Set the positions in the array to point to the Item added
	SetItemRegion(_ItemRegion, _Item);
}

void
C_ItemContainer::ShuffleRemove(C_Item* _Item, const ItemRegion& _ItemRegion)
{
	bool bItemExists = false;
	for (unsigned int iX = 0; iX < m_vItems.size(); ++iX)
	{
		if (_Item == m_vItems[iX])
		{
			//	If item is not the back move the back to it's position
			if (m_vItems[iX] != m_vItems.back())
			{
				m_vItems[iX] = m_vItems.back();
			}
			//	Pop the back as it was either the item to be removed or a duplicate
			m_vItems.pop_back();
			bItemExists = true;
		}
	}
	//	Remove the item from the inventory array
	if (true == bItemExists)
	{
		//	Remove the pointers from the Vector
		SetItemRegion(_ItemRegion, nullptr);
	}
}

const std::vector<C_Item*>&
C_ItemContainer::GetItemList()
{
	return m_vItems;
}

const std::vector<std::vector<C_Item*>>&
C_ItemContainer::GetInventory()
{
	return m_vItemSlots;
}