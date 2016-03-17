/*******************************************************************************
* Copyright 2016 HangZhou ���ݾ���Ƽ����޹�˾
* All right reserved
*
* �ļ����ƣ�main.c
*
* �ļ���ʶ����ɫLED
* ժ    Ҫ��������ʾ��
* ��ǰ�汾��v1.0
* ��    �ߣ�lhb Steven
* ������ڣ�2016/3/14
* ���뻷����C:\Program Files (x86)\IAR Systems\Embedded Workbench 6.5\stm8        
*
* ��ʷ��Ϣ��
*******************************************************************************/
#include "Eeprom.h"
#include "Com.h"
#include "Sys.h"
#include "buntu.h"
#include "Led.h"
#include "Menu.h"

int main( void )
{
    SysInit();
    EeepromInit();
    BuntuInit();
    LedInit();
    MenuInit();
   // ComInit();
    while(1) {
        MenuModeSet( BuntuRead() );/*
        switch( BuntuRead() ) {//��ȡ����״̬
            case 0x01:
            break;
            case 0x02:
            break;
            case 0x03:
            break;
            case 0x04:
            break;
            case 0x05:
            break;
            case 0x06:
            break;
            case 0x11://�󲦼�
                LedSetModeFlicker(1);
            break;
            case 0x12://�󲦼�
                LedSetModeFlicker(1);
            break;
            case 0x13:
                LedSetModeFlicker(1);
                ComSendCmdWatch(front,sub_stal,0x00,0x00);
            break;
            case 0x14:
            break;
            case 0x15:
            break;
            case 0x16:
            break;
            case 0x21:
            break;
            case 0x22:
            break;    
            case 0x23:
            break;    
            case 0x24:
            break;    
            case 0x25:
            break;    
            case 0x26:
            break; 
            case 0x30:
                LedSetModeFlicker(100);
            break;
            case 0x40:
                LedSetModeFlicker(1);
            break;
            default:
            break;
        }*/
        LedTimeService();//led��˸����
        if(ComGetFlag() == 0x80) {//ͨѶ����
            ComClearFlag();
            LedSetModeFlicker(1);
            switch(ComGetData(0)) {
                case front:
                switch(ComGetData(1)) {
                    case dce_gear:
    
                    break;
                }
                break;
                case behind: 
                switch(ComGetData(1)) {
                    case dce_gear:
    
                    break;
                }
                break;
                case dce_powe:

                break;
            }
        }
    }
}
