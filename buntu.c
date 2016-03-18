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
#include "Delay.h"

#define BUNTU_REAR1     PB_IDR_IDR5
#define BUNTU_REAR2     PB_IDR_IDR4
#define BUNTU_BEHIND1   PB_IDR_IDR7
#define BUNTU_BEHIND2   PB_IDR_IDR6
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
    static u8 mode_count = 0;//ģʽ
    if(BUNTU_REAR1 == 0) {//�󲦰�ť1
        if(count_small1 < 100) {
            count_small1++;
        } else {
            count_small1 = 0;
            if(count1 < 3000) {
                count1++;
            }
            if(count1 == 2000) {
                //��������
                if(count2 > 1500) {//���Ű���Ҫͬʱ���²���Ч
                    if(mode_count == 0) {//δ����һ���µ�ģʽ
                        return 0x01;
                    }
                }
            }
        }
    } else {
        if( (count1 > 50)&&(count1 < 1500) ) {
            count1 = 0;
            //return 0x11;
        } else if(count1 > 1500) {//ֻҪ��һ���ɿ��ͽ���
            count1 = 0;
            return 0x21;
        }
        count_small1 = 0;
        count1 = 0;
    }
    
    if(BUNTU_REAR2 == 0) {//�󲦰�ť2   
        if(count_small2 < 100) {
            count_small2++;
        } else {
            count_small2 = 0;
            if(count2 < 3000) {
                count2++;
            }
            if(count2 == 2000) {
                //��������
                if(count1 == 0) {//С�İ������ܰ���
                    if(mode_count == 0) {//δ����һ���µ�ģʽ
                        return 0x02;    
                    }
                }
            }
        }
    } else {
        //��� �� ���� ���
        if(mode_count == 0) {
            if( ( (count1 > 50)&&(count1 < 1500) ) && ( (count2 > 50)&&(count2 < 1500) ) ) {
                count1 = 0;
                count2 = 0;
                return 0x11;
            } else if( (count2 > 50)&&(count2 < 1500) ) {//�󲦿��ٷſ�
                count2 = 0;
                return 0x12;
            } else if(count2 > 2000) {
                count2 = 0;
                return 0x22;
            }
        }
        count_small2 = 0;
        count2 = 0;
    }
    
    if(BUNTU_BEHIND1 == 0) {//ǰ����ť1
        if(count_small3 < 100) {
            count_small3++;
        } else {
            count_small3 = 0;
            if(count3 < 3000) {
                count3++;
            }
            if(count3 == 2000) {
                //��������
                return 0x03;
            }
        }
    } else {
        if(mode_count == 0) {
            if( (count3 > 50)&&(count3 < 1500) ) {
                count3 = 0;
                return 0x13;
            } else if(count3 > 1500) {
                count3 = 0;
                return 0x23;
            }
        }
        count_small3 = 0;
        count3 = 0;
    } 
    
    if(BUNTU_BEHIND2 == 0) {//ǰ����ť2
        if(count_small4 < 100) {
            count_small4++;
        } else {
            count_small4 = 0;
            if(count4 < 3000) {
                count4++;
            }
            if(count4 == 2000) {
                //��������
                return 0x04;
            }
        }
    } else {
        count_small4 = 0;
        count4 = 0;
    }
    
    if(BUNTU_MODE == 0) {//ģʽ����
        if(count_small5 < 100) {
            count_small5++;
        } else {
            count_small5 = 0;
            if(count5 < 3000) {
                count5++;
            }
            if(count5 == 2000) {
                //��������
                //return 0x05;
                return 0x30;
            }
        }
    } else {
        if(count5 > 2000) {
            count_small5 = 0;
            count5 = 0;
            return 0x40;
        }
        count_small5 = 0;
        count5 = 0;
    }
    //��ϰ���
    if( (count3 > 1500) && (count2 > 1500) ) {//���Ű���ͬʱ����
        if(mode_count < 200) {
            mode_count++;
        } else {
            return 0x30;
        }
    } else {
        if(mode_count == 200) {
            mode_count = 0;
            return 0x40;
        }
    }
    return 0x00;
}
/**********************************************��������***************************************************** 
* ��������: void BuntuSleep(void) 
* �������: void 
* ���ز���: void  
* ��    ��: ˯��ʡ��  
* ��    ��: by lhb_steven
* ��    ��: 2016/3/18
************************************************************************************************************/ 
void BuntuSleep(void) { 
    PB_CR2_C24 = 1;
    PB_CR2_C25 = 1;
    PB_CR2_C26 = 1;
    PB_CR2_C27 = 1;
    PB_CR2_C20 = 1;
    DelayMs(100);
    MCUSLEEP
}
/**********************************************��������***************************************************** 
* ��������: void BuntuOpen(void) 
* �������: void 
* ���ز���: void  
* ��    ��: �˳�����״̬  
* ��    ��: by lhb_steven
* ��    ��: 2016/3/18
************************************************************************************************************/ 
void BuntuOpen(void) { 
    PB_CR2_C24 = 0;
    PB_CR2_C25 = 0;
    PB_CR2_C26 = 0;
    PB_CR2_C27 = 0;
    PB_CR2_C20 = 0;
    EXTI_SR1 = 0xff;
}

#pragma vector=8
__interrupt void EXTIB6_IRQHandler(void)
{
    INTOFF
    BuntuOpen();
    INTEN
    return;
}

#pragma vector=13
__interrupt void EXTIB1_IRQHandler(void)
{
    INTOFF
    BuntuOpen();
    INTEN
    return;
}
#pragma vector=14
__interrupt void EXTIB2_IRQHandler(void)
{
    INTOFF
    BuntuOpen();
    INTEN
    return;
}
#pragma vector=15
__interrupt void EXTIB3_IRQHandler(void)
{
    INTOFF
    BuntuOpen();
    INTEN
    return;
}
#pragma vector=16
__interrupt void EXTIB4_IRQHandler(void)
{
    INTOFF
    BuntuOpen();
    INTEN
    return;
}
#pragma vector=17
__interrupt void EXTIB5_IRQHandler(void)
{
    INTOFF
    BuntuOpen();
    INTEN
    return;
}

#pragma vector=9
__interrupt void EXTIB7_IRQHandler(void)
{
    INTOFF
    BuntuOpen();
    INTEN
    return;
}

#pragma vector=10
__interrupt void EXTIB8_IRQHandler(void)
{
    INTOFF
    BuntuOpen();
    INTEN
    return;
}

#pragma vector=11
__interrupt void EXTIB9_IRQHandler(void)
{
    INTOFF
    BuntuOpen();
    INTEN
    return;
}

#pragma vector=18
__interrupt void EXTIB10_IRQHandler(void)
{
    INTOFF
    BuntuOpen();
    INTEN
    return;
}

#pragma vector=19
__interrupt void EXTIB11_IRQHandler(void)
{
    INTOFF
    BuntuOpen();
    INTEN
    return;
}

#pragma vector=20
__interrupt void EXTIB12_IRQHandler(void)
{
    INTOFF
    BuntuOpen();
    INTEN
    return;
}

#pragma vector=21
__interrupt void EXTIB13_IRQHandler(void)
{
    INTOFF
    BuntuOpen();
    INTEN
    return;
}

#pragma vector=22
__interrupt void EXTIB14_IRQHandler(void)
{
    INTOFF
    BuntuOpen();
    INTEN
    return;
}

