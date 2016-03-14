/*******************************************************************************
* Copyright 2016 HangZhou ���ݾ���Ƽ����޹�˾
* All right reserved
*
* �ļ����ƣ�buntu.h
*
* �ļ���ʶ��
* ժ    Ҫ��
*
*
* ��ǰ�汾��v1.1
* ��    �ߣ�lhb Steven
* ������ڣ�2016/3/14
* ���뻷����C:\Program Files (x86)\IAR Systems\Embedded Workbench 6.5\stm8        
*
* ��ʷ��Ϣ��
*******************************************************************************/
#include "buntu.h"

#define BUNTU_REAR1     PB_IDR_IDR4
#define BUNTU_REAR2     PB_IDR_IDR5
#define BUNTU_BEHIND1   PB_IDR_IDR6
#define BUNTU_BEHIND2   PB_IDR_IDR7
#define BUNTU_MODE      PB_IDR_IDR0
/**********************************************��������***************************************************** 
* ��������: void BuntuInit(void) 
* �������: void 
* ���ز���: void  
* ��    ��: ������ʼ��  
* ��    ��: by lhb_steven
* ��    ��: 2016/3/14
************************************************************************************************************/ 
void BuntuInit(void) { 
    PB_DDR_DDR4 = 0; //ǰ����
    PB_CR1_C14 = 0;
    PB_CR2_C24 = 0;
    
    PB_DDR_DDR5 = 0;//ǰ����
    PB_CR1_C15 = 0;
    PB_CR2_C25 = 0;
    
    PB_DDR_DDR6 = 0;//�󲦼�
    PB_CR1_C16 = 0;
    PB_CR2_C26 = 0;
    
    PB_DDR_DDR7 = 0;//�󲦼�
    PB_CR1_C17 = 0;
    PB_CR2_C27 = 0;
    
    PB_DDR_DDR0 = 0;//����
    PB_CR1_C10 = 0;
    PB_CR2_C20 = 0;
}

/**********************************************��������***************************************************** 
* ��������: u8 BuntuRead(void) 
* �������: void 
* ���ز���: u8  
* ��    ��: ��ȡ����״̬  
* ��    ��: by lhb_steven
* ��    ��: 2016/3/14
************************************************************************************************************/ 
u8 BuntuRead(void) { 
    static u16 count1 = 0;
    static u16 count2 = 0;
    static u16 count3 = 0;
    static u16 count4 = 0;
    static u16 count5 = 0;
    static u8 count_small1 = 0;
    static u8 count_small2 = 0;
    static u8 count_small3 = 0;
    static u8 count_small4 = 0;
    static u8 count_small5 = 0;
    if(BUNTU_REAR1 == 0) {
        if(count_small1 < 100) {
            count_small1++;
        } else {
            count_small1 = 0;
            if(count1 < 2000) {
                count1++;
            }
            if(count1 == 2000) {
                //��������
                return 0x01;
            }
        }
    } else {
        count_small1 = 0;
        count1 = 0;
    }
    
    if(BUNTU_REAR2 == 0) {
        if(count_small2 < 100) {
            count_small2++;
        } else {
            count_small2 = 0;
            if(count2 < 2000) {
                count2++;
            }
            if(count2 == 2000) {
                //��������
                return 0x02;
            }
        }
    } else {
        count_small2 = 0;
        count2 = 0;
    }
    
    if(BUNTU_BEHIND1 == 0) {
        if(count_small3 < 100) {
            count_small3++;
        } else {
            count_small3 = 0;
            if(count3 < 2000) {
                count3++;
            }
            if(count3 == 2000) {
                //��������
                return 0x03;
            }
        }
    } else {
        count_small3 = 0;
        count3 = 0;
    } 
    
    if(BUNTU_BEHIND2 == 0) {
        if(count_small4 < 100) {
            count_small4++;
        } else {
            count_small4 = 0;
            if(count4 < 2000) {
                count4++;
            }
            if(count4 == 2000) {
                //��������
                return 0x04;
            }
        }
    } else {
        count_small3 = 0;
        count3 = 0;
    }
    
    if(BUNTU_MODE == 0) {
        if(count_small5 < 100) {
            count_small5++;
        } else {
            count_small5 = 0;
            if(count5 < 2000) {
                count5++;
            }
            if(count5 == 2000) {
                //��������
                return 0x05;
            }
        }
    } else {
        count_small4 = 0;
        count4 = 0;
    }
    return 0x00;
}






