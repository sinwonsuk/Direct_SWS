#pragma once
#include <iostream>
#include <conio.h>

class Monster
{
public:
    inline int GetAtt()
    {
        return Att;
    }

    inline bool IsDeath()
    {
        return Hp <= 0;
    }

    // ����� ������ �и��� �Լ��� inlineȭ �ɼ� ����.
    void StatusRender();
    void Damage(int _Damage);

protected:
private:
    int Att = 10;
    int Hp = 100;
};
