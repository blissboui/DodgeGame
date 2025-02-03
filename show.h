#ifndef __SHOW_H__
#define __SHOW_H__
#include "function.h"


void ClearInputBuffer(void);
void Default();
void Show_GameMenu(int select);
void Show_Option(int select);

// 더블 버퍼링
void initBuffer();
void Show_GameArea(int width, int height);
void Show_Icon(int width, int height);
void moveIcon(int dx, int dy, int width, int height);
#endif