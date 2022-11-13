#pragma once

#include <map>
#include <unordered_map>
#include <string>

#include "CItem.h"

class CInventory
{
private:
    std::unordered_map<std::string, CItem*> m_itemList;
public:

    CItem getItem(std::string& sName);
    void addItem(CItem& item);
    void removeItem(std::string& sName);
};