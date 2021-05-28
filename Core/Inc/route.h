#ifndef __ROUTE_H
#define __ROUTE_H

#include "main.h"

extern uint8_t up1;
extern uint8_t up2;
extern uint8_t up3;

extern uint8_t down1;
extern uint8_t down2;
extern uint8_t down3;

extern uint8_t for_val;
extern uint8_t beh_val;
extern uint8_t left_val;
extern uint8_t right_val;

void QRCode();

void Take(uint8_t for_val,uint8_t beh_val,uint8_t left_val,uint8_t right_t,uint8_t times);

void putRough(uint8_t for_val,uint8_t beh_val,uint8_t left_val,uint8_t right_t,uint8_t times);

void TakeRough(uint8_t for_val,uint8_t beh_val,uint8_t left_val,uint8_t right_t,uint8_t times);

void putRes(uint8_t for_val,uint8_t beh_val,uint8_t left_val,uint8_t right_t,uint8_t times);

void back(uint8_t for_val,uint8_t beh_val,uint8_t left_val,uint8_t right_t);

#endif
