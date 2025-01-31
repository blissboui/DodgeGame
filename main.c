#include "function.h"
#include "show.h"
#include "struct.h"

int main(void)
{
    int selectMenu = 0, selectOption = 0, currentMenu = 0;
    int areaSize = 0;  // 게임범위 크기
    int areaSizeWidth = SIZE_1_WIDTH, areaSizeHeight = SIZE_1_HEIGHT;   // 기본값

    unsigned char input;
    POSITION posCurrent = {0, 0};

    hideCursor();

    while(1)
    {
        if(currentMenu != START_MENU){
        switch(currentMenu)
        {

        case MAIN_MENU:
            system("cls");
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
            system("cls");
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
            system("cls");
            Show_GameArea(SIZE_1_WIDTH, SIZE_1_HEIGHT);
            printf("\033[%d;%dH", posCurrent.ypos, posCurrent.xpos);
            printf("BB");
        }

        else if(currentMenu == START_MENU && areaSize == SIZE_2)
        {
            system("cls");
            Show_GameArea(SIZE_2_WIDTH, SIZE_2_HEIGHT);
            printf("\033[%d;%dH", posCurrent.ypos, posCurrent.xpos);
            printf("BB");
        }

        else if(currentMenu == START_MENU && areaSize == SIZE_3)
        {
            system("cls");
            Show_GameArea(SIZE_3_WIDTH, SIZE_3_HEIGHT);
            printf("\033[%d;%dH", posCurrent.ypos, posCurrent.xpos);
            printf("BB");
        }

        if(kbhit()) // 키 입력이 있으면
        {
            if(_getch() == ESC_KEY)
            {
                EndGame(areaSizeWidth, areaSizeHeight);
                currentMenu = MAIN_MENU;
            }
            else
            {
                input = _getch();
                if(input == 0 || input == 224)
                {
                    input = _getch();
                    if(input == UP_KEY && posCurrent.ypos > 0)
                    {
                        posCurrent.ypos++;
                    }
                    else if(input == LEFT_KEY && posCurrent.xpos > 0)
                    {
                        posCurrent.xpos--;
                    }
                    else if(input == DOWN_KEY && posCurrent.ypos < areaSizeHeight)
                    {
                        posCurrent.ypos--;
                    }
                    else if(input == RIGHT_KEY && posCurrent.xpos < areaSizeWidth)
                    {
                        posCurrent.xpos++;
                    }
                }
            }
        }
    }

    return 0;
}

