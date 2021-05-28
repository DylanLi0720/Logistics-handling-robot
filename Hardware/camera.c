#include "camera.h"
#include "main.h"

void readQR(void)
{
	HAL_UART_Transmit(&huart4,(uint8_t*)"R",1,100);
}	

void scanColor(void)
{
	HAL_UART_Transmit(&huart3,(uint8_t*)"S",1,100);
}


	