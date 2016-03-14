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

int main( void )
{
    SysInit();
    EeepromInit();
    BuntuInit();
    LedInit();
    ComInit();
    while(1) {
        BuntuRead();
        if(ComGetFlag() == 0x80) {
            ComClearFlag();
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
