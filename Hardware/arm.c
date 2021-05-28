#include "arm.h"

unsigned char DM_Speed_Position[10] = {0xff, 0x01, 0x00, 0x01, 0x00, 0xff, 0x02, 0x00, 0xdc, 0x05};  //通道0，速度=1，位置90度


/**
  * @brief  设置单个舵机的速度和角度
  * @param  channel: 舵机通道号0~15
  * @param  speed: 转动速度1~20
  * @param	angle: 舵机角度0~180
  * @retval None
  */
void setSpeedPosition(uint8_t channel, uint8_t speed, uint16_t angle)
{
	uint16_t position = (uint16_t) (angle * 1.0 * 2000 / 180 + 500);
//	uint32_t position = angle;
	/*使用串口1设置速度*/
	
	DM_Speed_Position[2] = channel;
	DM_Speed_Position[3] = speed;
	
	/*使用串口1设置位置*/
	
	DM_Speed_Position[7] = channel;
	
	DM_Speed_Position[8] = (position % 256);
	DM_Speed_Position[9] = (position / 256);
	HAL_UART_Transmit(&huart2, DM_Speed_Position, 10, 0xffff);//设置通道，速度，位置 
		
}

/**
  * @brief  拿取原料区的三个物料
  * @param  None
  * @retval None
  */
void GetRawMass()
{
	setSpeedPosition(0,4,90);
	delay_ms(2000);
	setSpeedPosition(1,4,90);
	delay_ms(2000);
	setSpeedPosition(2,4,90);
	delay_ms(2000);
	setSpeedPosition(3,4,90);
	delay_ms(2000);
	setSpeedPosition(4,4,90);
	delay_ms(2000);
}

void putRawMassToRoughMachine()
{	
	setSpeedPosition(0,4,60);
	delay_ms(2000);
	setSpeedPosition(1,4,60);
	delay_ms(2000);
	setSpeedPosition(2,4,60);
	delay_ms(2000);
	setSpeedPosition(3,4,60);
	delay_ms(2000);
	setSpeedPosition(4,4,60);
	delay_ms(2000);
}

void putRawMassToSemiProcess()
{
	
}