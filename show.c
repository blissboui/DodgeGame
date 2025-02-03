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

void Show_GameArea(int width, int height)
{
  DWORD bytesWritten;
  CHAR_INFO buffer[width * height];
  COORD bufferSize = {width, height};
  COORD bufferCoord = {0, 0};
  SMALL_RECT writeRegion = {0, 0, width - 1, height - 1};

  for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {

            if(y == 1 || y == height - 2) 
                buffer[y * width + x].Char.AsciiChar = '-';
            
            else if(x == 1 || x == width - 2) 
                buffer[y * width + x].Char.AsciiChar = '|';

            // else if(x == 0 && y == 0)
            //     buffer[y * width + x].Char.AsciiChar = '┌';

            // else if(x == width - 1 && y == 0)
            //     buffer[y * width + x].Char.AsciiChar = '┐';
            
            // else if(x == 0 && y == height - 1)
            //     buffer[y * width + x].Char.AsciiChar = '└';
            
            // else if(x == width - 1 && y == height - 1)
            //     buffer[y * width + x].Char.AsciiChar = '┘';
                
            else 
                buffer[y * width + x].Char.AsciiChar = ' ';


                buffer[y * width + x].Attributes = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
        }
    }

    WriteConsoleOutput(hBuffer[activeBuffer], buffer, bufferSize, bufferCoord, &writeRegion);
}

void Show_Icon(int width, int height) 
{
    DWORD bytesWritten;
    CHAR_INFO buffer[width * height];
    COORD bufferSize = {width, height};
    COORD bufferCoord = {0, 0};
    SMALL_RECT writeRegion = {0, 0, width - 1, height - 1};

    // 아이콘 그리기
    buffer[iconPos.Y * width + iconPos.X].Char.AsciiChar = ICON;
    buffer[iconPos.Y * width + iconPos.X].Attributes = FOREGROUND_RED | FOREGROUND_INTENSITY;

    // 후면 버퍼에 아이콘 추가
    WriteConsoleOutput(hBuffer[activeBuffer], buffer, bufferSize, bufferCoord, &writeRegion);
}

void moveIcon(int dx, int dy, int width, int height) 
{
    // 아이콘 위치 이동
    int newX = iconPos.X + dx;
    int newY = iconPos.Y + dy;

    // 범위 체크
    if (newX > 0 && newX < width - 1) iconPos.X = newX;
    if (newY > 0 && newY < height - 1) iconPos.Y = newY;
}