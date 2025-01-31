#include "function.h"

int ReturnUpDownKey(unsigned char input, int select)    // 방향키 위, 아래 
{
    if(input == UP_KEY && select > 0)   // 위
        return --select;

    else if(input == DOWN_KEY && select < 2)   // 아래
        return ++select;

    else
        return select;
}

void EndGame(int width, int height)
{
    int select = 0;
    int width_pos, height_pos;
    unsigned char input;
    
    // 종료화면 띄우기 위해 위치 설정
    width_pos = width/2 - 3;
    height_pos = height/2;
    printf("\033[%d;%dH", height_pos, width_pos);
    printf("EXIT GAME?");
    _getch();
}

void hideCursor()   // 커서 숨기기
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}