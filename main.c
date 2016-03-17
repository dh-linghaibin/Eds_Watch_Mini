/*******************************************************************************
* Copyright 2016 HangZhou 杭州久天科技有限公司
* All right reserved
*
* 文件名称：main.c
*
* 文件标识：三色LED
* 摘    要：不带显示屏
* 当前版本：v1.0
* 作    者：lhb Steven
* 完成日期：2016/3/14
* 编译环境：C:\Program Files (x86)\IAR Systems\Embedded Workbench 6.5\stm8        
*
* 历史信息：
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
        switch( BuntuRead() ) {//读取按键状态
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
            case 0x11://后拨加
                LedSetModeFlicker(1);
            break;
            case 0x12://后拨减
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
        LedTimeService();//led闪烁服务
        if(ComGetFlag() == 0x80) {//通讯服务
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
