#include "CInventory.h"
#include "CItem.h"

CItem CInventory::getItem(std::string& sName)
{
    return *m_itemList[sName];
}