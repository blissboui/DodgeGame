 #include "function.h"

void Show_GameMenu(int select)
{
    char * menu[] = {
      "Game Start",
      "Option",
      "Exit"
      };
    int menuLen = sizeof(menu) / sizeof(menu[0]);

    printf("\n [ Dodge Game ] \n");
    for(int i = 0 ; i < menuLen ; i++)
    {
        if(i == select)
            printf(" > %s\n", menu[i]);

        else
            printf("   %s\n", menu[i]);
    }
}

void Show_Option(int select)
{
    char * option[] = {
      "10 x 10",
      "30 x 30",
      "50 x 50"
      };
    int optionLen = sizeof(option) / sizeof(option[0]);
    
    printf("\n [ Game Option ] \n");
    for(int i = 0 ; i < optionLen ; i++)
    {
        if(i == select)
            printf(" > %s\n", option[i]);

        else
            printf("   %s\n", option[i]);
    }
}

void ClearInputBuffer(void) // 입력 버퍼 비우기
{
    while (getchar() != '\n');
}

void Default()  // 잘못 입력 됐을 때
{
    printf("please enter it correctly.");
    getch();
    ClearInputBuffer();
}

void initBuffer() 
{
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    hBuffer[0] = CreateConsoleScreenBuffer(GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    hBuffer[1] = CreateConsoleScreenBuffer(GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hBuffer[activeBuffer]);  // 초기 화면 설정
}

