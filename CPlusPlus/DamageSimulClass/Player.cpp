#include "Player.h"
#include <iostream>
#include <conio.h>

void Player::StatusRender() 
{
    printf_s("�÷��̾� =====================================\n");
    printf_s("���ݷ� = %d \n", Att);
    printf_s("ü  �� = %d \n", Hp);
    printf_s("============================================\n");
}

void Player::Damage(int _Damage)
{
    Hp -= _Damage;
    int Input = 0;
    printf_s("�÷��̾ %d�������� �޾ҽ��ϴ�.\n", _Damage);
    Input = _getch();
    printf_s("�÷��̾�� %dü���� ���ҽ��ϴ�.\n", Hp);
    Input = _getch();
}

