#include "Mecanum.h"
#include "main.h"
#include "gpio.h"
#include "tim.h"
#include "usart.h"
#include "stdio.h"
#include "stdlib.h"
#include "delay.h"

/*输出指令*/
void transmit(uint8_t num,uint16_t pwm_val, uint16_t time)
{  
	char temp[1];
//	Int_To_Str(num, temp);
	sprintf(temp,"%d",num);
	if(pwm_val < 2500 && pwm_val > 500 && time > 0 && time < 9999 && num >= 0 && num <= 4)
	{
		if(num==0)
		{
			HAL_UART_Transmit(&huart1,(uint8_t*)"#255P",5,100);
		}
		else
		{
			HAL_UART_Transmit(&huart1,(uint8_t*)"#00",3,100);
			HAL_UART_Transmit(&huart1,(uint8_t*)temp,1,100);
			HAL_UART_Transmit(&huart1,(uint8_t*)"P",1,100);
		}
		
		char pwm_val_res[5];
//    uint8_t pwm_val_for = (pwm_val&0xff00)>>8;
//    uint8_t pwm_val_bel = (pwm_val&0x00ff);
		snprintf(pwm_val_res,5,"%04d",pwm_val);
		HAL_UART_Transmit(&huart1,(uint8_t *)pwm_val_res,4,100);
//    HAL_UART_Transmit(&huart1,(uint8_t *)pwm_val_res,4,100);
    
		HAL_UART_Transmit(&huart1,(uint8_t*)"T",1,100);
		char time_res[5];
		uint8_t t = snprintf(time_res,5,"%04d",time);
		HAL_UART_Transmit(&huart1,(uint8_t*)time_res,4,100);
		HAL_UART_Transmit(&huart1,(uint8_t*)"!",1,100);
	}
  
}


/*小车停止*/
void stop(void)
{
  HAL_UART_Transmit(&huart1,(uint8_t*)"#001P1500T0200!",15,100);
  HAL_UART_Transmit(&huart1,(uint8_t*)"#002P1500T0200!",15,100);
  HAL_UART_Transmit(&huart1,(uint8_t*)"#003P1500T0200!",15,100);
  HAL_UART_Transmit(&huart1,(uint8_t*)"#004P1500T0200!",15,100);
}


/*小车前进*/
void forward(void)
{
	uint16_t pwm_val = 500;
	uint16_t time = wheel_time;
  if(pwm_val>=0&&pwm_val<=1000)
  {
	  transmit(1,1500+pwm_val,time);
      transmit(2,1500+pwm_val,time);
      transmit(3,1500+pwm_val,time);
      transmit(4,1500+pwm_val,time);
  }
}

void low_forward(void)
{
	uint16_t pwm_val = 400;
	uint16_t time = wheel_time;
  if(pwm_val>=0&&pwm_val<=1000)
  {
	  transmit(1,1500+pwm_val,time);
      transmit(2,1500+pwm_val,time);
      transmit(3,1500+pwm_val,time);
      transmit(4,1500+pwm_val,time);
  }
}

void lowlow_forward(void)
{
	uint16_t pwm_val = 150;
	uint16_t time = wheel_time;
  if(pwm_val>=0&&pwm_val<=1000)
  {
	  transmit(1,1500+pwm_val,time);
      transmit(2,1500+pwm_val,time);
      transmit(3,1500+pwm_val,time);
      transmit(4,1500+pwm_val,time);
  }
}
/*小车后退*/
void backward(void)
{
	uint16_t pwm_val = 400;
	uint16_t time = wheel_time;
  if(pwm_val>=0&&pwm_val<=1000)
  {
	  transmit(1,1500-pwm_val,time);
      transmit(2,1500-pwm_val,time);
      transmit(3,1500-pwm_val,time);
      transmit(4,1500-pwm_val,time);
  }
}

void low_backward(void)
{
	uint16_t pwm_val = 300;
	uint16_t time = wheel_time;
  if(pwm_val>=0&&pwm_val<=1000)
  {
	  transmit(1,1500-pwm_val,time);
      transmit(2,1500-pwm_val,time);
      transmit(3,1500-pwm_val,time);
      transmit(4,1500-pwm_val,time);
  }
}

/*小车左移*/
void leftward(void)
{
	uint16_t pwm_val = 500;
	uint16_t time = wheel_time;
    if(pwm_val>=0&&pwm_val<=1000)
	{
      transmit(1,1500-pwm_val,time);
      transmit(2,1500+pwm_val,time);
      transmit(3,1500+pwm_val,time);
      transmit(4,1500-pwm_val,time);
    }
}

/*小车右移*/
void rightward(void)
{
	uint16_t pwm_val = 300;
	uint16_t time = wheel_time;
	if(pwm_val>=0&&pwm_val<=1000)
	{
      transmit(1,1500+pwm_val,time);
      transmit(2,1500-pwm_val,time);
      transmit(3,1500-pwm_val,time);
      transmit(4,1500+pwm_val,time);
    }
}

/*车头左转*/
void frontTurnLeft()
{
	uint16_t pwm_val = 200;
	uint16_t time = wheel_time;
	if(pwm_val>=0&&pwm_val<=1000)
	{
		transmit(1,1500-pwm_val,time);
//		transmit(2,1500,time);
		transmit(3,1500+pwm_val,time);
//		transmit(4,1500,time);
    }
}

/*车头大左转*/
void frontTurnBigLeft()
{
	uint16_t pwm_val = 500;
	uint16_t time = wheel_time;
	if(pwm_val>=0&&pwm_val<=1000)
	{
		transmit(1,1500-pwm_val,time);
//		transmit(2,1500,time);
		transmit(3,1500+pwm_val,time);
//		transmit(4,1500,time);
    }
}

/*车头右转*/
void frontTurnRight()
{
	uint16_t pwm_val = 200;
	uint16_t time = wheel_time;
	if(pwm_val>=0&&pwm_val<=1000)
	{
      transmit(1,1500+pwm_val,time);
//      transmit(2,1500,time);
      transmit(3,1500-pwm_val,time);
//      transmit(4,1500,time);
    }
}

/*车头大右转*/
void frontTurnBigRight()
{
	uint16_t pwm_val = 500;
	uint16_t time = wheel_time;
	if(pwm_val>=0&&pwm_val<=1000)
	{
      transmit(1,1500+pwm_val,time);
//      transmit(2,1500,time);
      transmit(3,1500-pwm_val,time);
//      transmit(4,1500,time);
    }
}

/*车尾左转*/
void tailTurnLeft()
{
	uint16_t pwm_val = 200;
	uint16_t time = wheel_time;
	if(pwm_val>=0&&pwm_val<=1000)
	{
//		transmit(1,1500,time);
		transmit(2,1500+pwm_val,time);
//		transmit(3,1500,time);
		transmit(4,1500-pwm_val,time);
    }
}

/*车尾大左转*/
void tailTurnBigLeft()
{
	uint16_t pwm_val = 500;
	uint16_t time = wheel_time;
	if(pwm_val>=0&&pwm_val<=1000)
	{
//		transmit(1,1500,time);
		transmit(2,1500+pwm_val,time);
//		transmit(3,1500,time);
		transmit(4,1500-pwm_val,time);
    }
}

/*车尾右转*/
void tailTurnRight()
{
	uint16_t pwm_val = 200;
	uint16_t time = wheel_time;
	if(pwm_val>=0&&pwm_val<=1000)
	{
//		transmit(1,1500,time);
		transmit(2,1500-pwm_val,time);
//		transmit(3,1500,time);
		transmit(4,1500+pwm_val,time);
    }
}

/*车尾大右转*/
void tailTurnBigRight()
{
	uint16_t pwm_val = 500;
	uint16_t time = wheel_time;
	if(pwm_val>=0&&pwm_val<=1000)
	{
//		transmit(1,1500,time);
		transmit(2,1500-pwm_val,time);
//		transmit(3,1500,time);
		transmit(4,1500+pwm_val,time);
    }
}

/*绕左下角转动*/
void turnAroundLowerLeftCorner(void)
{
	uint16_t pwm_val = 300;
	uint16_t time = wheel_time;
	if(pwm_val>=0&&pwm_val<=1000)
	{
//		transmit(1,1500,time);
//		transmit(2,1500,time);
		transmit(3,1500+pwm_val,time);
		transmit(4,1500+pwm_val,time);
    }
}

/*绕左下角大转动*/
void turnAroundLowerLeftBigCorner(void)
{
	uint16_t pwm_val = 500;
	uint16_t time = wheel_time;
	if(pwm_val>=0&&pwm_val<=1000)
	{
//		transmit(1,1500,time);
//		transmit(2,1500,time);
		transmit(3,1500+pwm_val,time);
		transmit(4,1500+pwm_val,time);
    }
}
/*绕左上角转动*/
void turnAroundTopLeftCorner(void)
{
	uint16_t pwm_val = 300;
	uint16_t time = wheel_time;
	if(pwm_val>=0&&pwm_val<=1000)
	{
//		transmit(1,1500,time);
//		transmit(2,1500,time);
		transmit(3,1500-pwm_val,time);
		transmit(4,1500-pwm_val,time);
    }
}

/*绕左上角大转动*/
void turnAroundTopLeftBigCorner(void)
{
	uint16_t pwm_val = 500;
	uint16_t time = wheel_time;
	if(pwm_val>=0&&pwm_val<=1000)
	{
//		transmit(1,1500,time);
//		transmit(2,1500,time);
		transmit(3,1500-pwm_val,time);
		transmit(4,1500-pwm_val,time);
    }
}
/*绕右下角转动*/
void turnAroundLowerRightCorner(void)
{
	uint16_t pwm_val = 300;
	uint16_t time = wheel_time;
	if(pwm_val>=0&&pwm_val<=1000)
	{
		transmit(1,1500+pwm_val,time);
		transmit(2,1500+pwm_val,time);
//		transmit(3,1500,time);
//		transmit(4,1500,time);
    }
}

/*绕右下角转动*/
void turnAroundLowerRightBigCorner(void)
{
	uint16_t pwm_val = 500;
	uint16_t time = wheel_time;
	if(pwm_val>=0&&pwm_val<=1000)
	{
		transmit(1,1500+pwm_val,time);
		transmit(2,1500+pwm_val,time);
//		transmit(3,1500,time);
//		transmit(4,1500,time);
    }
}
/*绕右上角转动*/
void turnAroundTopRightCorner(void)
{
	uint16_t pwm_val = 300;
	uint16_t time = wheel_time;
	if(pwm_val>=0&&pwm_val<=1000)
	{
		transmit(1,1500-pwm_val,time);
		transmit(2,1500-pwm_val,time);
//		transmit(3,1500,time);
//		transmit(4,1500,time);
    }
}

/*绕右上角大转动*/
void turnAroundTopRightBigCorner(void)
{
	uint16_t pwm_val = 500;
	uint16_t time = wheel_time;
	if(pwm_val>=0&&pwm_val<=1000)
	{
		transmit(1,1500-pwm_val,time);
		transmit(2,1500-pwm_val,time);
//		transmit(3,1500,time);
//		transmit(4,1500,time);
    }
}
/*逆时针自转*/
void counterclockwiseRotation(void)
{
	uint16_t pwm_val = 300;
	uint16_t time = 1400;
	if(pwm_val>=0&&pwm_val<=1000)
	{
		transmit(1,1500-pwm_val,time);
		transmit(2,1500-pwm_val,time);
		transmit(3,1500+pwm_val,time);
		transmit(4,1500+pwm_val,time);
    }
}

/*顺时针旋转*/
void clockwiseRotation()
{
	uint16_t pwm_val = 300;
	uint16_t time = 1700;
	if(pwm_val>=0&&pwm_val<=1000)
	{
		transmit(1,1500+pwm_val,time);
		transmit(2,1500+pwm_val,time);
		transmit(3,1500-pwm_val,time);
		transmit(4,1500-pwm_val,time);
    }
}
/*获取前方传感器数据*/
void getFrontLine(uint8_t *for_x1, uint8_t *for_x2, uint8_t *for_x3, uint8_t *for_x4)
{
	*for_x1 = HAL_GPIO_ReadPin(GPIOD, for_x1_Pin);
	*for_x2 = HAL_GPIO_ReadPin(GPIOD, for_x2_Pin);
	*for_x3 = HAL_GPIO_ReadPin(GPIOD, for_x3_Pin);
	*for_x4 = HAL_GPIO_ReadPin(GPIOD, for_x4_Pin);
}

/*获取后方传感器数据*/
void getBehindLine(uint8_t *beh_x1, uint8_t *beh_x2, uint8_t *beh_x3, uint8_t *beh_x4)
{
	*beh_x1 = HAL_GPIO_ReadPin(GPIOD, beh_x1_Pin);
	*beh_x2 = HAL_GPIO_ReadPin(GPIOD, beh_x2_Pin);
	*beh_x3 = HAL_GPIO_ReadPin(GPIOD, beh_x3_Pin);
	*beh_x4 = HAL_GPIO_ReadPin(GPIOD, beh_x4_Pin);
}

/*获取左方传感器数据*/
void getLeftLine(uint8_t *left_x1, uint8_t *left_x2, uint8_t *left_x3, uint8_t *left_x4)
{
	*left_x1 = HAL_GPIO_ReadPin(GPIOD, left_x1_Pin);
	*left_x2 = HAL_GPIO_ReadPin(GPIOD, left_x2_Pin);
	*left_x3 = HAL_GPIO_ReadPin(GPIOD, left_x3_Pin);
	*left_x4 = HAL_GPIO_ReadPin(GPIOD, left_x4_Pin);
}

/*获取右方传感器数据*/
void getRightLine(uint8_t *right_x1, uint8_t *right_x2, uint8_t *right_x3, uint8_t *right_x4)
{
	*right_x1 = HAL_GPIO_ReadPin(GPIOD, right_x1_Pin);
	*right_x2 = HAL_GPIO_ReadPin(GPIOD, right_x2_Pin);
	*right_x3 = HAL_GPIO_ReadPin(GPIOD, right_x3_Pin);
	*right_x4 = HAL_GPIO_ReadPin(GPIOD, right_x4_Pin);
}


/*前方巡线*/
void strightLineWalking(void)
{
	/*
	0000√
	0001√
	0011√
	0111√
	1000√
	1001√
	1011√
	1100√
	1101√
	1110√
	1111√
	*/
	uint8_t for_x1 = 1, for_x2 = 1, for_x3 = 1, for_x4 = 1;

	/*获取前方传感器的状态*/
	getFrontLine(&for_x1, &for_x2, &for_x3, &for_x4);	
	/*矫正车头方向*/
	if(for_x1 == LOW && for_x2 == LOW && for_x3 == LOW && for_x4 == LOW)//0000
	{
		forward();
	}
//	else if (for_x1 == LOW && for_x2 == LOW && for_x3 == LOW && for_x4 == HIGH)//0001
//	{
//		frontTurnBigRight();
//	}
	else if (for_x1 == LOW && for_x2 == LOW && for_x3 == HIGH && for_x4 == HIGH)//0011
	{
		frontTurnLeft();
	}
	else if (for_x1 == LOW && for_x2 == HIGH && for_x3 == HIGH && for_x4 == HIGH)//0111
	{
		frontTurnBigLeft();
	}
	else if (for_x1 == HIGH && for_x2 == LOW && for_x3 == LOW && for_x4 == LOW)//1000
	{
		frontTurnRight();
	}
	else if (for_x1 == HIGH && for_x2 == LOW && for_x3 == LOW && for_x4 == HIGH)//1001
	{
		forward();
	}
	else if (for_x1 == HIGH && for_x2 == LOW && for_x3 == HIGH && for_x4 == HIGH)//1011
	{
		frontTurnLeft();
	}
	else if (for_x1 == HIGH && for_x2 == HIGH && for_x3 == LOW && for_x4 == LOW)//1100
	{
		frontTurnRight();
	}
	else if (for_x1 == HIGH && for_x2 == HIGH && for_x3 == LOW && for_x4 == HIGH)//1101
	{
		frontTurnRight();
	}
	else if (for_x1 == HIGH && for_x2 == HIGH && for_x3 == HIGH && for_x4 == LOW)//1110
	{
		frontTurnBigRight();
	}
	else if (for_x1 == HIGH && for_x2 == HIGH && for_x3 == HIGH && for_x4 == HIGH)//1111
	{
		forward();
	}
	else
	{
	  transmit(1,1500+500,75);
      transmit(3,1500+500,75);
	}
#if 1
	
	uint8_t beh_x1 = 1, beh_x2 = 1, beh_x3 = 1, beh_x4 = 1;
	
	/*获取后方传感器状态*/
	getBehindLine(&beh_x1, &beh_x2, &beh_x3, &beh_x4);
	
	/*矫正车尾方向*/
//	if(beh_x1 == LOW && beh_x2 == LOW && beh_x3 == LOW && beh_x4 == LOW)//0000
//	{
//		forward();
//	}
	if (beh_x1 == LOW && beh_x2 == LOW && beh_x3 == LOW && beh_x4 == HIGH)//0001
	{
		tailTurnRight();
	}
	else if (beh_x1 == LOW && beh_x2 == LOW && beh_x3 == HIGH && beh_x4 == HIGH)//0011
	{
		tailTurnRight();
	}
	else if (beh_x1 == LOW && beh_x2 == HIGH && beh_x3 == HIGH && beh_x4 == HIGH)//0111
	{
		tailTurnBigRight();
	}
	else if (beh_x1 == HIGH && beh_x2 == LOW && beh_x3 == LOW && beh_x4 == LOW)//1000
	{
		tailTurnBigRight();
	}
//	else if (beh_x1 == HIGH && beh_x2 == LOW && beh_x3 == LOW && beh_x4 == HIGH)//1001
//	{
//		forward();
//	}
	else if (beh_x1 == HIGH && beh_x2 == LOW && beh_x3 == HIGH && beh_x4 == HIGH)//1011
	{
		tailTurnRight();
	}
	else if (beh_x1 == HIGH && beh_x2 == HIGH && beh_x3 == LOW && beh_x4 == LOW)//1100
	{
		tailTurnLeft();
	}
	else if (beh_x1 == HIGH && beh_x2 == HIGH && beh_x3 == LOW && beh_x4 == HIGH)//1101
	{
		tailTurnLeft();
	}
	else if (beh_x1 == HIGH && beh_x2 == HIGH && beh_x3 == HIGH && beh_x4 == LOW)//1110
	{
		tailTurnBigLeft();
	}
//	else if (beh_x1 == HIGH && beh_x2 == HIGH && beh_x3 == HIGH && beh_x4 == HIGH)//1111
//	{
//		forward();
//	}
	else
	{
      transmit(2,1500+500,75);
      transmit(4,1500+500,75);
	}
	
	#endif
}

void low_strightLineWalking(void)
{
	uint8_t for_x1 = 1, for_x2 = 1, for_x3 = 1, for_x4 = 1;

	/*获取前方传感器的状态*/
	getFrontLine(&for_x1, &for_x2, &for_x3, &for_x4);	
	/*矫正车头方向*/
	if(for_x1 == LOW && for_x2 == LOW && for_x3 == LOW && for_x4 == LOW)//0000
	{
		low_forward();
	}
//	else if (for_x1 == LOW && for_x2 == LOW && for_x3 == LOW && for_x4 == HIGH)//0001
//	{
//		frontTurnBigRight();
//	}
	else if (for_x1 == LOW && for_x2 == LOW && for_x3 == HIGH && for_x4 == HIGH)//0011
	{
		frontTurnLeft();
	}
	else if (for_x1 == LOW && for_x2 == HIGH && for_x3 == HIGH && for_x4 == HIGH)//0111
	{
		frontTurnBigLeft();
	}
	else if (for_x1 == HIGH && for_x2 == LOW && for_x3 == LOW && for_x4 == LOW)//1000
	{
		frontTurnRight();
	}
	else if (for_x1 == HIGH && for_x2 == LOW && for_x3 == LOW && for_x4 == HIGH)//1001
	{
		low_forward();
	}
	else if (for_x1 == HIGH && for_x2 == LOW && for_x3 == HIGH && for_x4 == HIGH)//1011
	{
		frontTurnLeft();
	}
	else if (for_x1 == HIGH && for_x2 == HIGH && for_x3 == LOW && for_x4 == LOW)//1100
	{
		frontTurnRight();
	}
	else if (for_x1 == HIGH && for_x2 == HIGH && for_x3 == LOW && for_x4 == HIGH)//1101
	{
		frontTurnRight();
	}
	else if (for_x1 == HIGH && for_x2 == HIGH && for_x3 == HIGH && for_x4 == LOW)//1110
	{
		frontTurnBigRight();
	}
	else if (for_x1 == HIGH && for_x2 == HIGH && for_x3 == HIGH && for_x4 == HIGH)//1111
	{
		low_forward();
	}
	else
	{
	  transmit(1,1500+400,75);
      transmit(3,1500+400,75);
	}
#if 1
	
	uint8_t beh_x1 = 1, beh_x2 = 1, beh_x3 = 1, beh_x4 = 1;
	
	/*获取后方传感器状态*/
	getBehindLine(&beh_x1, &beh_x2, &beh_x3, &beh_x4);
	
	/*矫正车尾方向*/
//	if(beh_x1 == LOW && beh_x2 == LOW && beh_x3 == LOW && beh_x4 == LOW)//0000
//	{
//		forward();
//	}
	if (beh_x1 == LOW && beh_x2 == LOW && beh_x3 == LOW && beh_x4 == HIGH)//0001
	{
		tailTurnRight();
	}
	else if (beh_x1 == LOW && beh_x2 == LOW && beh_x3 == HIGH && beh_x4 == HIGH)//0011
	{
		tailTurnRight();
	}
	else if (beh_x1 == LOW && beh_x2 == HIGH && beh_x3 == HIGH && beh_x4 == HIGH)//0111
	{
		tailTurnBigRight();
	}
	else if (beh_x1 == HIGH && beh_x2 == LOW && beh_x3 == LOW && beh_x4 == LOW)//1000
	{
		tailTurnBigRight();
	}
//	else if (beh_x1 == HIGH && beh_x2 == LOW && beh_x3 == LOW && beh_x4 == HIGH)//1001
//	{
//		forward();
//	}
	else if (beh_x1 == HIGH && beh_x2 == LOW && beh_x3 == HIGH && beh_x4 == HIGH)//1011
	{
		tailTurnRight();
	}
	else if (beh_x1 == HIGH && beh_x2 == HIGH && beh_x3 == LOW && beh_x4 == LOW)//1100
	{
		tailTurnLeft();
	}
	else if (beh_x1 == HIGH && beh_x2 == HIGH && beh_x3 == LOW && beh_x4 == HIGH)//1101
	{
		tailTurnLeft();
	}
	else if (beh_x1 == HIGH && beh_x2 == HIGH && beh_x3 == HIGH && beh_x4 == LOW)//1110
	{
		tailTurnBigLeft();
	}
//	else if (beh_x1 == HIGH && beh_x2 == HIGH && beh_x3 == HIGH && beh_x4 == HIGH)//1111
//	{
//		forward();
//	}
	else
	{
	  transmit(2,1500+400,75);
      transmit(4,1500+400,75);
	}
	
	#endif
}

void lowlow_strightLineWalking(void)
{
	uint8_t for_x1 = 1, for_x2 = 1, for_x3 = 1, for_x4 = 1;

	/*获取前方传感器的状态*/
	getFrontLine(&for_x1, &for_x2, &for_x3, &for_x4);	
	/*矫正车头方向*/
	if(for_x1 == LOW && for_x2 == LOW && for_x3 == LOW && for_x4 == LOW)//0000
	{
		lowlow_forward();
	}
//	else if (for_x1 == LOW && for_x2 == LOW && for_x3 == LOW && for_x4 == HIGH)//0001
//	{
//		frontTurnBigRight();
//	}
	else if (for_x1 == LOW && for_x2 == LOW && for_x3 == HIGH && for_x4 == HIGH)//0011
	{
		frontTurnLeft();
	}
	else if (for_x1 == LOW && for_x2 == HIGH && for_x3 == HIGH && for_x4 == HIGH)//0111
	{
		frontTurnBigLeft();
	}
	else if (for_x1 == HIGH && for_x2 == LOW && for_x3 == LOW && for_x4 == LOW)//1000
	{
		frontTurnRight();
	}
	else if (for_x1 == HIGH && for_x2 == LOW && for_x3 == LOW && for_x4 == HIGH)//1001
	{
		lowlow_forward();
	}
	else if (for_x1 == HIGH && for_x2 == LOW && for_x3 == HIGH && for_x4 == HIGH)//1011
	{
		frontTurnLeft();
	}
	else if (for_x1 == HIGH && for_x2 == HIGH && for_x3 == LOW && for_x4 == LOW)//1100
	{
		frontTurnRight();
	}
	else if (for_x1 == HIGH && for_x2 == HIGH && for_x3 == LOW && for_x4 == HIGH)//1101
	{
		frontTurnRight();
	}
	else if (for_x1 == HIGH && for_x2 == HIGH && for_x3 == HIGH && for_x4 == LOW)//1110
	{
		frontTurnBigRight();
	}
	else if (for_x1 == HIGH && for_x2 == HIGH && for_x3 == HIGH && for_x4 == HIGH)//1111
	{
		lowlow_forward();
	}
	else
	{
	  transmit(1,1500+350,75);
      transmit(3,1500+350,75);
	}
#if 1
	
	uint8_t beh_x1 = 1, beh_x2 = 1, beh_x3 = 1, beh_x4 = 1;
	
	/*获取后方传感器状态*/
	getBehindLine(&beh_x1, &beh_x2, &beh_x3, &beh_x4);
	
	/*矫正车尾方向*/
//	if(beh_x1 == LOW && beh_x2 == LOW && beh_x3 == LOW && beh_x4 == LOW)//0000
//	{
//		forward();
//	}
	if (beh_x1 == LOW && beh_x2 == LOW && beh_x3 == LOW && beh_x4 == HIGH)//0001
	{
		tailTurnRight();
	}
	else if (beh_x1 == LOW && beh_x2 == LOW && beh_x3 == HIGH && beh_x4 == HIGH)//0011
	{
		tailTurnRight();
	}
	else if (beh_x1 == LOW && beh_x2 == HIGH && beh_x3 == HIGH && beh_x4 == HIGH)//0111
	{
		tailTurnBigRight();
	}
	else if (beh_x1 == HIGH && beh_x2 == LOW && beh_x3 == LOW && beh_x4 == LOW)//1000
	{
		tailTurnBigRight();
	}
//	else if (beh_x1 == HIGH && beh_x2 == LOW && beh_x3 == LOW && beh_x4 == HIGH)//1001
//	{
//		forward();
//	}
	else if (beh_x1 == HIGH && beh_x2 == LOW && beh_x3 == HIGH && beh_x4 == HIGH)//1011
	{
		tailTurnRight();
	}
	else if (beh_x1 == HIGH && beh_x2 == HIGH && beh_x3 == LOW && beh_x4 == LOW)//1100
	{
		tailTurnLeft();
	}
	else if (beh_x1 == HIGH && beh_x2 == HIGH && beh_x3 == LOW && beh_x4 == HIGH)//1101
	{
		tailTurnLeft();
	}
	else if (beh_x1 == HIGH && beh_x2 == HIGH && beh_x3 == HIGH && beh_x4 == LOW)//1110
	{
		tailTurnBigLeft();
	}
//	else if (beh_x1 == HIGH && beh_x2 == HIGH && beh_x3 == HIGH && beh_x4 == HIGH)//1111
//	{
//		forward();
//	}
	else
	{
	  transmit(2,1500+350,75);
      transmit(4,1500+350,75);
	}
	
	#endif
}

/*后方巡线*/
void backLineWalking(void)
{
	uint8_t for_x1 = 1, for_x2 = 1, for_x3 = 1, for_x4 = 1;

	/*获取前方传感器的状态*/
	getFrontLine(&for_x1, &for_x2, &for_x3, &for_x4);	
	/*矫正车头方向*/
//	if(for_x1 == LOW && for_x2 == LOW && for_x3 == LOW && for_x4 == LOW)//0000
//	{
//		backward();
//	}
	if (for_x1 == LOW && for_x2 == LOW && for_x3 == LOW && for_x4 == HIGH)//0001
	{
		frontTurnBigRight();
	}
	else if (for_x1 == LOW && for_x2 == LOW && for_x3 == HIGH && for_x4 == HIGH)//0011
	{
		frontTurnRight();
	}
	else if (for_x1 == LOW && for_x2 == HIGH && for_x3 == HIGH && for_x4 == HIGH)//0111
	{
		frontTurnBigLeft();
	}
//	else if (for_x1 == HIGH && for_x2 == LOW && for_x3 == LOW && for_x4 == LOW)//1000
//	{
//		frontTurnRight();
//	}
//	else if (for_x1 == HIGH && for_x2 == LOW && for_x3 == LOW && for_x4 == HIGH)//1001
//	{
//		backward();
//	}
	else if (for_x1 == HIGH && for_x2 == LOW && for_x3 == HIGH && for_x4 == HIGH)//1011
	{
		frontTurnLeft();
	}
	else if (for_x1 == HIGH && for_x2 == HIGH && for_x3 == LOW && for_x4 == LOW)//1100
	{
		frontTurnRight();
	}
	else if (for_x1 == HIGH && for_x2 == HIGH && for_x3 == LOW && for_x4 == HIGH)//1101
	{
		frontTurnRight();
	}
	else if (for_x1 == HIGH && for_x2 == HIGH && for_x3 == HIGH && for_x4 == LOW)//1110
	{
		frontTurnBigRight();
	}
//	else if (for_x1 == HIGH && for_x2 == HIGH && for_x3 == HIGH && for_x4 == HIGH)//1111
//	{
//		backward();
//	}
//	else
//		backward();
	uint8_t beh_x1 = 1, beh_x2 = 1, beh_x3 = 1, beh_x4 = 1;
	
	/*获取后方传感器状态*/
	getBehindLine(&beh_x1, &beh_x2, &beh_x3, &beh_x4);
	
	/*矫正车尾方向*/
	if(beh_x1 == LOW && beh_x2 == LOW && beh_x3 == LOW && beh_x4 == LOW)//0000
	{
		backward();
	}
//	else if (beh_x1 == LOW && beh_x2 == LOW && beh_x3 == LOW && beh_x4 == HIGH)//0001
//	{
//		tailTurnRight();
//	}
	else if (beh_x1 == LOW && beh_x2 == LOW && beh_x3 == HIGH && beh_x4 == HIGH)//0011
	{
		tailTurnRight();
	}
	else if (beh_x1 == LOW && beh_x2 == HIGH && beh_x3 == HIGH && beh_x4 == HIGH)//0111
	{
		tailTurnBigRight();
	}
//	else if (beh_x1 == HIGH && beh_x2 == LOW && beh_x3 == LOW && beh_x4 == LOW)//1000
//	{
//		tailTurnBigRight();
//	}
	else if (beh_x1 == HIGH && beh_x2 == LOW && beh_x3 == LOW && beh_x4 == HIGH)//1001
	{
		backward();
	}
	else if (beh_x1 == HIGH && beh_x2 == LOW && beh_x3 == HIGH && beh_x4 == HIGH)//1011
	{
		tailTurnRight();
	}
	else if (beh_x1 == HIGH && beh_x2 == HIGH && beh_x3 == LOW && beh_x4 == LOW)//1100
	{
		tailTurnLeft();
	}
	else if (beh_x1 == HIGH && beh_x2 == HIGH && beh_x3 == LOW && beh_x4 == HIGH)//1101
	{
		tailTurnLeft();
	}
	else if (beh_x1 == HIGH && beh_x2 == HIGH && beh_x3 == HIGH && beh_x4 == LOW)//1110
	{
		tailTurnBigLeft();
	}
	else if (beh_x1 == HIGH && beh_x2 == HIGH && beh_x3 == HIGH && beh_x4 == HIGH)//1111
	{
		backward();
	}
	else
		backward();
}
	


/*左方巡线*/
void leftwardLineWalking(void)
{
	
	
	uint8_t left_x1 = 1, left_x2 = 1, left_x3 = 1, left_x4 = 1;
	uint8_t right_x1 = 1, right_x2 = 1, right_x3 = 1, right_x4 = 1;
	
	/*获取左方传感器的状态*/
	getLeftLine(&left_x1, &left_x2, &left_x3, &left_x4);
	
	/*矫正左端车身*/
	if(left_x1 == LOW && left_x2 == LOW && left_x3 == LOW && left_x4 == LOW)//0000
	{
		leftward();
	}
	else if (left_x1 == LOW && left_x2 == LOW && left_x3 == LOW && left_x4 == HIGH)//0001
	{
		turnAroundTopRightCorner();
	}
	else if (left_x1 == LOW && left_x2 == LOW && left_x3 == HIGH && left_x4 == HIGH)//0011
	{
		turnAroundTopRightCorner();
	}
	else if (left_x1 == LOW && left_x2 == HIGH && left_x3 == HIGH && left_x4 == HIGH)//0111
	{
		turnAroundTopRightBigCorner();
	}
	else if (left_x1 == HIGH && left_x2 == LOW && left_x3 == LOW && left_x4 == LOW)//1000
	{
		turnAroundLowerRightCorner();
	}
	else if (left_x1 == HIGH && left_x2 == LOW && left_x3 == LOW && left_x4 == HIGH)//1001
	{
		leftward();
	}
	else if (left_x1 == HIGH && left_x2 == LOW && left_x3 == HIGH && left_x4 == HIGH)//1011
	{
		turnAroundTopRightCorner();
	}
	else if (left_x1 == HIGH && left_x2 == HIGH && left_x3 == LOW && left_x4 == LOW)//1100
	{
		turnAroundLowerRightCorner();
	}
	else if (left_x1 == HIGH && left_x2 == HIGH && left_x3 == LOW && left_x4 == HIGH)//1101
	{
		turnAroundLowerRightCorner();
	}
	else if (left_x1 == HIGH && left_x2 == HIGH && left_x3 == HIGH && left_x4 == LOW)//1110
	{
		turnAroundLowerRightBigCorner();
	}
	else if (left_x1 == HIGH && left_x2 == HIGH && left_x3 == HIGH && left_x4 == HIGH)//1111
	{
		leftward();
	}
	else
		leftward();
	
	
	/*获取右方传感器的状态*/
	getRightLine(&right_x1, &right_x2, &right_x3, &right_x4);
	
	/*矫正端右身*/
//	if(right_x1 == LOW && right_x2 == LOW && right_x3 == LOW && right_x4 == LOW)//0000
//	{
//		leftward();
//	}
	if (right_x1 == LOW && right_x2 == LOW && right_x3 == LOW && right_x4 == HIGH)//0001
	{
		turnAroundLowerLeftCorner();
	}
	else if (right_x1 == LOW && right_x2 == LOW && right_x3 == HIGH && right_x4 == HIGH)//0011
	{
		turnAroundLowerLeftCorner();
	}
	else if (right_x1 == LOW && right_x2 == HIGH && right_x3 == HIGH && right_x4 == HIGH)//0111
	{
		turnAroundLowerLeftBigCorner();
	}
	else if (right_x1 == HIGH && right_x2 == LOW && right_x3 == LOW && right_x4 == LOW)//1000
	{
		turnAroundTopLeftCorner();
	}
//	else if (right_x1 == HIGH && right_x2 == LOW && right_x3 == LOW && right_x4 == HIGH)//1001
//	{
//		leftward();
//	}
	else if (right_x1 == HIGH && right_x2 == LOW && right_x3 == HIGH && right_x4 == HIGH)//1011
	{
		turnAroundLowerLeftCorner();
	}
	else if (right_x1 == HIGH && right_x2 == HIGH && right_x3 == LOW && right_x4 == LOW)//1100
	{
		turnAroundTopLeftCorner();
	}
	else if (right_x1 == HIGH && right_x2 == HIGH && right_x3 == LOW && right_x4 == HIGH)//1101
	{
		turnAroundTopLeftCorner();
	}
	else if (right_x1 == HIGH && right_x2 == HIGH && right_x3 == HIGH && right_x4 == LOW)//1110
	{
		turnAroundTopLeftBigCorner();
	}
//	else if (right_x1 == HIGH && right_x2 == HIGH && right_x3 == HIGH && right_x4 == HIGH)//1111
//	{
//		leftward();
//	}
//	else
//		leftward();
}

/*右方巡线*/
void rightwardLineWalking(void)
{
	
	uint8_t left_x1 = 1, left_x2 = 1, left_x3 = 1, left_x4 = 1;
	uint8_t right_x1 = 1, right_x2 = 1, right_x3 = 1, right_x4 = 1;
	
	/*获取左方传感器的状态*/
	getLeftLine(&left_x1, &left_x2, &left_x3, &left_x4);
	
	/*矫正左端车身*/
	if(left_x1 == LOW && left_x2 == LOW && left_x3 == LOW && left_x4 == LOW)//0000
	{
		rightward();
	}
	else if (left_x1 == LOW && left_x2 == LOW && left_x3 == LOW && left_x4 == HIGH)//0001
	{
		turnAroundTopRightCorner();
	}
	else if (left_x1 == LOW && left_x2 == LOW && left_x3 == HIGH && left_x4 == HIGH)//0011
	{
		turnAroundTopRightCorner();
	}
	else if (left_x1 == LOW && left_x2 == HIGH && left_x3 == HIGH && left_x4 == HIGH)//0111
	{
		turnAroundTopRightCorner();
	}
	else if (left_x1 == HIGH && left_x2 == LOW && left_x3 == LOW && left_x4 == LOW)//1000
	{
		turnAroundLowerRightCorner();
	}
	else if (left_x1 == HIGH && left_x2 == LOW && left_x3 == LOW && left_x4 == HIGH)//1001
	{
		rightward();
	}
	else if (left_x1 == HIGH && left_x2 == LOW && left_x3 == HIGH && left_x4 == HIGH)//1011
	{
		turnAroundTopRightCorner();
	}
	else if (left_x1 == HIGH && left_x2 == HIGH && left_x3 == LOW && left_x4 == LOW)//1100
	{
		turnAroundLowerRightCorner();
	}
	else if (left_x1 == HIGH && left_x2 == HIGH && left_x3 == LOW && left_x4 == HIGH)//1101
	{
		turnAroundLowerRightCorner();
	}
	else if (left_x1 == HIGH && left_x2 == HIGH && left_x3 == HIGH && left_x4 == LOW)//1110
	{
		turnAroundLowerRightCorner();
	}
	else if (left_x1 == HIGH && left_x2 == HIGH && left_x3 == HIGH && left_x4 == HIGH)//1111
	{
		rightward();
	}
	else
		rightward();
	
	
	/*获取右方传感器的状态*/
	getRightLine(&right_x1, &right_x2, &right_x3, &right_x4);
	
	/*矫正端右身*/
	if(right_x1 == LOW && right_x2 == LOW && right_x3 == LOW && right_x4 == LOW)//0000
	{
		rightward();
	}
	else if (right_x1 == LOW && right_x2 == LOW && right_x3 == LOW && right_x4 == HIGH)//0001
	{
		turnAroundLowerLeftCorner();
	}
	else if (right_x1 == LOW && right_x2 == LOW && right_x3 == HIGH && right_x4 == HIGH)//0011
	{
		turnAroundLowerLeftCorner();
	}
	else if (right_x1 == LOW && right_x2 == HIGH && right_x3 == HIGH && right_x4 == HIGH)//0111
	{
		turnAroundLowerLeftBigCorner();
	}
	else if (right_x1 == HIGH && right_x2 == LOW && right_x3 == LOW && right_x4 == LOW)//1000
	{
		turnAroundTopLeftCorner();
	}
	else if (right_x1 == HIGH && right_x2 == LOW && right_x3 == LOW && right_x4 == HIGH)//1001
	{
		rightward();
	}
	else if (right_x1 == HIGH && right_x2 == LOW && right_x3 == HIGH && right_x4 == HIGH)//1011
	{
		turnAroundLowerLeftCorner();
	}
	else if (right_x1 == HIGH && right_x2 == HIGH && right_x3 == LOW && right_x4 == LOW)//1100
	{
		turnAroundTopLeftCorner();
	}
	else if (right_x1 == HIGH && right_x2 == HIGH && right_x3 == LOW && right_x4 == HIGH)//1101
	{
		turnAroundTopLeftCorner();
	}
	else if (right_x1 == HIGH && right_x2 == HIGH && right_x3 == HIGH && right_x4 == LOW)//1110
	{
		turnAroundTopLeftCorner();
	}
	else if (right_x1 == HIGH && right_x2 == HIGH && right_x3 == HIGH && right_x4 == HIGH)//1111
	{
		rightward();
	}
	else
		rightward();
	if (right_x1 == LOW && right_x2 == HIGH && right_x3 == HIGH && right_x4 == HIGH &&
		left_x1 == HIGH && left_x2 == LOW && left_x3 == LOW && left_x4 == HIGH)//左边为1001，右边为0111这一特殊情况
	{
		turnAroundLowerLeftBigCorner();
	}
}

/*清除所有巡线数值*/
void clearValue(void)
{
	for_x1_val = 0;
	for_x2_val = 0;
	for_x3_val = 0;
	for_x4_val = 0;
	beh_x1_val = 0;
	beh_x2_val = 0;
	beh_x3_val = 0;
	beh_x4_val = 0;
	left_x1_val = 0;
	left_x2_val = 0;
	left_x3_val = 0;
	left_x4_val = 0;
	right_x1_val = 0;
	right_x2_val = 0;
	right_x3_val = 0;
	right_x4_val = 0;
}
