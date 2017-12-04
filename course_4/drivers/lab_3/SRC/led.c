#include <aduc812.h>
#include <max.h>

static unsigned char old_led = 0;   // "�����������" ������� �����������

/**----------------------------------------------------------------------------
���������� ����� �����������
����:       n  - ���������� ����� ���������� ( �� 0 �� 7 )
            on - 1 - ��������, 0 ����� ���������
��������:   ������������ ������ � �������� ����������� ������ SV � �������
            ������� write_max. ��������� ����������� �������� � �������� old_led.
-----------------------------------------------------------------------------*/
void led( unsigned char n, unsigned char on )
{
unsigned char c;
unsigned char mask = 1;

    if( n > 7 ) return;

    c = old_led;

    mask <<= n;

    if( on )
        c |= mask;
    else
        c &= ~mask;         

    write_max( SV, c );     

    old_led = c;
}

/**----------------------------------------------------------------------------
��������� ������� �����������
����:       on - ���������� ������������. ������ ��� ���������� �������� �� ���� 
            ���������: 1 - ��������, 0 ����� ���������
��������:   ������������ ������ � �������� ����������� ������ SV � �������
            ������� write_max. ��������� ����������� �������� � �������� old_led.
-----------------------------------------------------------------------------*/

void leds( unsigned char on )
{
    write_max( SV, on );     

    old_led = on;
}
