#include "Monster.h"
#include <iostream>
#include <conio.h>


// cpp������ ���� ���� inline 
/*inline*/ void Monster::StatusRender()
{
    printf_s("���� =====================================\n");
    printf_s("���ݷ� = %d \n", Att);
    printf_s("ü  �� = %d \n", Hp);
    printf_s("============================================\n");
}

/*inline */void Monster::Damage(int _Damage)
{
    Hp -= _Damage;
    int Input = 0;
    printf_s("���Ͱ� %d�������� �޾ҽ��ϴ�.\n", _Damage);
    Input = _getch();
    printf_s("���ʹ� %dü���� ���ҽ��ϴ�.\n", Hp);
    Input = _getch();
}