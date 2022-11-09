#pragma once

#include "CEntity.h"

class CPlayer : public CEntity
{
private:

    float m_fExp;
    unsigned short int m_iLevel;

public:
    void listenInput();

    CPlayer();
    ~CPlayer();
};