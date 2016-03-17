/*******************************************************************************
* Copyright 2016 HangZhou ���ݾ���Ƽ����޹�˾
* All right reserved
*
* �ļ����ƣ�Menu.c
*
* �ļ���ʶ��V
* ժ    Ҫ���˵��ں�
*
*
* ��ǰ�汾��V1.0
* ��    �ߣ�lhb Steven
* ������ڣ�2016/3/17
* ���뻷����C:\Program Files (x86)\IAR Systems\Embedded Workbench 6.5\stm8        
*
* ��ʷ��Ϣ��
*******************************************************************************/
#include "Menu.h"


typedef struct DataNode
{
    u8 mode;
    
} tDataNode;
/***********************************************��������*****************************************************
* ��    ��: caidan  
* ��    ��: by lhb_steven
* ��    ��: 2016/3/17
************************************************************************************************************/ 
tDataNode menu;
/**********************************************��������***************************************************** 
* ��������: void MenuInit(void) 
* �������: void 
* ���ز���: void  
* ��    ��: �˵�������ʼ��  
* ��    ��: by lhb_steven
* ��    ��: 2016/3/17
************************************************************************************************************/ 
void MenuInit(void) { 
    menu.mode = 0x00;
}
/**********************************************��������***************************************************** 
* ��������: void MenuModeSet(u8 cmd) 
* �������: u8 cmd 
* ���ز���: void  
* ��    ��: ������Ӧģʽ������Ӧ����  
* ��    ��: by lhb_steven
* ��    ��: 2016/3/17
************************************************************************************************************/ 
void MenuModeSet(u8 cmd) { 
    switch( cmd ) {
        case 0x01:
        break;
        case 0x02://�󲦳�������
        if(menu.mode == 0) {//��������
         
        } else if(1 == menu.mode) {//�����΢��ģʽ
            menu.mode = 2;
        }
        break;
        case 0x03://ǰ����������
        if(menu.mode == 0) {//��������
         
        } else if(1 == menu.mode) {//����ǰ��΢��ģʽ
            menu.mode = 3;
        }
        break;
        case 0x04:
        break;
        case 0x05:
        break;
        case 0x06:
        break;
        case 0x11://�󲦼�
        LedSetModeFlicker(1);
        if(menu.mode == 0) {//�ӵ�
        
        } else if(menu.mode == 2) {//��΢��
            
        } else if(menu.mode == 3) {//ǰ��΢��
        
        }
        break;
        case 0x12://�󲦼�
        LedSetModeFlicker(1);
        if(menu.mode == 0) {//�ӵ�
        
        } else if(menu.mode == 2) {//��΢��
            
        } else if(menu.mode == 3) {//ǰ��΢��
        
        }
        break;
        case 0x13://ǰ������
        LedSetModeFlicker(1);
        if(menu.mode == 0) {//ֻ��������ģʽ��ʱ��ſ��Ի���
            
        }
        //ComSendCmdWatch(front,sub_stal,0x00,0x00);
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
        case 0x30://����5s
        LedSetModeFlicker(100);
        break;
        case 0x40://����5s�ſ�
        if(menu.mode == 0) {
            menu.mode = 1;
        } else if(menu.mode == 1) {//�ص�����ģʽ
            menu.mode = 0;
        } else if(menu.mode == 2) {//���ú�΢����λֵ
            menu.mode = 0;
        } else if(menu.mode == 3) {//����ǰ��΢����λֵ
            menu.mode = 0;
        }
        LedSetModeFlicker(1);
        break;
        default:
        break;
    }
}




