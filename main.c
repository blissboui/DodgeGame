#include "function.h"
#include "show.h"
#include "struct.h"
#include <stdio.h>



int main(void)
{
    int selectMenu = 0, selectOption = 0, currentMenu = 0;
    int areaSize = 0;  // 게임범위 크기
    int areaSizeWidth = SIZE_1_WIDTH, areaSizeHeight = SIZE_1_HEIGHT;   // 기본값
    const int moveDelay = 200;  // (ms)
    clock_t lastMoveTime = 0;

    unsigned char input;
    //POSITION posCurrent = {0, 0};

    initBuffer();

    hideCursor();

    while(1)
    {
        if(currentMenu != START_MENU){
        switch(currentMenu)
        {

        case MAIN_MENU:
            // system("cls");
            Show_GameMenu(selectMenu);

            input = _getch();

            if(input == 0 || input == 224)
            {
                input = _getch();    // 방향키 값 받기
                selectMenu = ReturnUpDownKey(input, selectMenu);
            }
            else if(input == ENTER_KEY)
            {
                switch (selectMenu)
                {
                case START_GAME:
                    currentMenu = START_MENU;
                    break;
                
                case OPTION:
                    currentMenu = OPTION_MENU;
                    break;

                case EXIT_GAME:
                    return 0;

                default:
                    break;
                }
                selectMenu = 0;
            }
            break;

        case OPTION_MENU:   // 게임범위 크기 설정
            // system("cls");
            Show_Option(selectOption);

            input = _getch();
            if(input == 0 || input == 224)
            {
                input = _getch();
                selectOption = ReturnUpDownKey(input, selectOption);
            }
            else if(input == ENTER_KEY)
            {
                switch (selectOption)
                {
                case SIZE_1:
                    currentMenu = MAIN_MENU;
                    areaSize = SIZE_1;
                    areaSizeWidth = SIZE_1_WIDTH;
                    areaSizeHeight = SIZE_1_HEIGHT;
                    break;

                case SIZE_2:
                    currentMenu = MAIN_MENU;
                    areaSize = SIZE_2;
                    areaSizeWidth = SIZE_2_WIDTH;
                    areaSizeHeight = SIZE_2_HEIGHT;
                    break;

                case SIZE_3:
                    currentMenu = MAIN_MENU;
                    areaSize = SIZE_3;
                    areaSizeWidth = SIZE_3_WIDTH;
                    areaSizeHeight = SIZE_3_HEIGHT;
                    break;
            
                default:
                    break;
                }
            }
            break;
        }
        }

        // 게임 start
        if(currentMenu == START_MENU && areaSize == SIZE_1)
        {

        }

        else if(currentMenu == START_MENU && areaSize == SIZE_2)
        {

        }

        else if(currentMenu == START_MENU && areaSize == SIZE_3)
        {

        }

        if(kbhit()) // 키 입력이 있으면
        {
            input = _getch();
            if(input == ESC_KEY)
            {
                EndGame(areaSizeWidth, areaSizeHeight);
                currentMenu = MAIN_MENU;
            }
            else if(input == 0 || input == 224)
            {
                input = _getch();
                clock_t currentTime = clock();  // 현재 시간
                if((currentTime - lastMoveTime) > moveDelay)
                {
                    if(input == UP_KEY)
                    {

                    }
                    else if(input == LEFT_KEY)
                    {

                    }
                    else if(input == DOWN_KEY)
                    {
  
                    }
                    else if(input == RIGHT_KEY)
                    {

                    }
                    // if (GetAsyncKeyState(VK_UP) & 0x8000 && posCurrent.ypos > 0) posCurrent.ypos--;
                    // if (GetAsyncKeyState(VK_LEFT) & 0x8000 && posCurrent.xpos > 0) posCurrent.xpos--;
                    // if (GetAsyncKeyState(VK_DOWN) & 0x8000 && posCurrent.ypos < areaSizeHeight) posCurrent.ypos++;
                    // if (GetAsyncKeyState(VK_RIGHT) & 0x8000 && posCurrent.xpos < areaSizeWidth) posCurrent.xpos++;

                    lastMoveTime = currentTime;
                }
            }
        }

    }

    return 0;
}

