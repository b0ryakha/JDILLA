#pragma once

enum class Characteristic {
    Health, MaxHealth, Armor, MaxArmor, Speed, Xp, Lvl, MaxLvl
};

struct CCharacteristic
{
    float health = 0;
    float maxHealth = 0;

    float armor = 0;
    float maxArmor = 0;

    float speed = 0;
    float xp = 0;

    float lvl = 1;
    float maxLvl = 0;

    CCharacteristic() = delete;
    CCharacteristic(float maxHealth, float maxArmor, float speed, float maxLvl);
};