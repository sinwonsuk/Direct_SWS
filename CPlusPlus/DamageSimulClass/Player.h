#pragma once

// Ŭ���� ��ü�� �̹� ���� ����� ������ ���� �ִ�.
class Player
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

    void StatusRender();
    void Damage(int _Damage);

protected:
private:
    // ������ 
    int Att = 10;
    int Hp = 100;
};

// Player NewPlayer;