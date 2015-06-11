#include "led.h"
#include "delay.h"
#include "key.h"
#include "tpad.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"	 
#include "flash.h"
#include "sram.h"
#include "malloc.h"
#include "string.h"
#include "mmc_sd.h"
#include "ff.h"
#include "exfuns.h"
#include "fontupd.h"
#include "text.h"
#include "piclib.h"
#include "string.h"
#include "usmart.h"
#include "fattester.h"
#include "piclib.h"
#include "vs10xx.h"
#include "mp3player.h"
#include "audiosel.h"
#include "recorder.h"

/*
 * STM32-TEA-Encryption-Recorder
 * https://github.com/lincanbin/STM32-TEA-Encryption-Recorder
 *
 * Copyright 2015, Canbin Lin(lincanbin@hotmail.com)
 * http://www.94cb.com/
 *
 * Licensed under the Apache License, Version 2.0:
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * A STM32 encryption recorder that use Tiny Encryption Algorithm. 
 */


 int main(void)
 {	 
	delay_init();	    	 //延时函数初始化	  
	NVIC_Configuration(); 	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(9600);	 	//串口初始化为9600
 	LED_Init();			     //LED端口初始化
	TPAD_Init();		//初始化触摸按键
	LCD_Init();				//LCD初始化
	KEY_Init();	 			//按键初始化
	Audiosel_Init();	//初始化音源选择
	usmart_dev.init(72);//usmart初始化
 	mem_init(SRAMIN);	//初始化内部内存池	
 	VS_Init();	  

 	exfuns_init();					//为fatfs相关变量申请内存  
  	f_mount(0,fs[0]); 		 		//挂载SD卡 
 	f_mount(1,fs[1]); 				//挂载FLASH.
	POINT_COLOR=RED;      
 	while(font_init()) 				//检查字库
	{	    
		LCD_ShowString(60,50,200,16,16,"Font Error!");
		delay_ms(200);				  
		LCD_Fill(60,50,240,66,WHITE);//清除显示	     
	}
 	Show_Str(60,50,200,16,"Author: Canbin",16,0);				    	 
	Show_Str(60,70,200,16,"TEA加密录音机",16,0);				    	 
	Show_Str(60,90,200,16,"lincanbin@hotmail.com",16,0);				    	 
	Show_Str(60,110,200,16,"2015年6月11日",16,0);
	Show_Str(60,130,200,16,"KEY0:REC/PAUSE",16,0);
	Show_Str(60,150,200,16,"KEY2:STOP&SAVE",16,0);
	Show_Str(60,170,200,16,"KEY_UP:AGC+ KEY1:AGC-",16,0);
	Show_Str(60,190,200,16,"TPAD:Play The File",16,0);
	while(1)
	{
		Audiosel_Set(0);	//MP3通道
 		LED1=0; 	  
		Show_Str(60,210,200,16,"存储器测试...",16,0);
		VS_Ram_Test();	    
		Show_Str(60,210,200,16,"正弦波测试...",16,0); 	 	 
 		VS_Sine_Test();	   
		Show_Str(60,210,200,16,"<<WAV录音机>>",16,0); 		 
		LED1=1;
		recoder_play();
	}    					  
}


