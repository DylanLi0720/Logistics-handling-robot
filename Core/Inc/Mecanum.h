#ifndef __MECANUM__H_
#define __MECANUM__H_

#include "main.h"

#define LOW		(0)
#define HIGH	(1)

void transmit(uint8_t num,uint16_t pwm_val, uint16_t time);

void stop(void);
void forward(void);
void backward(void);
void leftward(void);
void rightward(void);
void frontTurnLeft();
void frontTurnBigLeft();
void frontTurnBigRight();
void frontTurnRight();
void tailTurnLeft();
void tailTurnBigLeft();
void tailTurnRight();
void tailTurnBigRight();
void turnAroundTopRightBigCorner(void);
void turnAroundLowerLeftCorner(void);
void turnAroundLowerLeftBigCorner(void);
void turnAroundTopLeftCorner(void);
void turnAroundTopLeftBigCorner(void);
void turnAroundLowerRightCorner(void);
void turnAroundLowerRightBigCorner(void);
void turnAroundTopRightCorner(void);
void counterclockwiseRotation(void);
void clockwiseRotation(void);

void getFrontLine(uint8_t *for_x1, uint8_t *for_x2, uint8_t *for_x3, uint8_t *for_x4);
void getBehindLine(uint8_t *beh_x1, uint8_t *beh_x2, uint8_t *beh_x3, uint8_t *beh_x4);
void getLeftLine(uint8_t *left_x1, uint8_t *left_x2, uint8_t *left_x3, uint8_t *left_x4);
void getRightLine(uint8_t *right_x1, uint8_t *right_x2, uint8_t *right_x3, uint8_t *right_x4);

void strightLineWalking(void);
void backLineWalking(void);
void leftwardLineWalking(void);
void rightwardLineWalking(void);

void clearValue(void);


#endif
