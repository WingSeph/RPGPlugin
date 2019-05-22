#ifndef __ITEMCONTAINER_H__
#define __ITEMCONTAINER_H__
//	Library includes
#include <vector>


//	Local includes
#include "utils.h"


//	Predeclarations
class C_Item;


class C_ItemContainer
{
public:
	C_ItemContainer();
	C_ItemContainer(const unsigned int& _Width, const unsigned int& _Height);
	virtual ~C_ItemContainer();

	bool SetSize(const unsigned int& _Width, const unsigned int& _Height);

	bool AddItem(C_Item* _Item, const unsigned int& _X, const unsigned int& _Y);

	bool RemoveItem(C_Item* _Item);

	const std::vector<C_Item*>& GetItemList();
	const std::vector<std::vector<C_Item*>>& GetInventory();


private:
	bool CheckItemSize(const ItemRegion& _ItemRegion);
	bool CheckLocation(const ItemRegion& _ItemRegion, C_Item* _Item = nullptr);
	void SetItemRegion(const ItemRegion& _ItemRegion, C_Item* _Item);
	void InsertItem(C_Item* _Item, const ItemRegion& _ItemRegion);
	void ShuffleRemove(C_Item* _Item, const ItemRegion& _ItemRegion);


protected:
	unsigned int m_iWidth = 0;
	unsigned int m_iHeight = 0;
	std::vector<std::vector<C_Item*>> m_vItemSlots;
	std::vector<C_Item*> m_vItems;


};

#endif