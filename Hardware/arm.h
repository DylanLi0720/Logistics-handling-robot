#ifndef __ARM_H_
#define __ARM_H_

#include "main.h"

extern unsigned char DM_Speed_Position[10];    


void setSpeedPosition(uint8_t channel, uint8_t speed, uint16_t angle);
void GetRawMass();
void putRawMassToRoughMachine();
void putRawMassToSemiProcess();



#endif
