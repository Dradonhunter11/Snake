#include <myconio.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>

#define KB_UP 72
#define KB_DOWN 80
#define KB_LEFT 75
#define KB_RIGHT 77
#define KB_ESCAPE 27


int menu(bool playgame)
{
    int timeout;
    char readInput;
    int posYMenu = 5;
    bool quit;
    bool flash;

    printf("----------------------------- \n");
    printf("|           SNAKE           | \n");
    printf("----------------------------- \n");
    gotoxy(5, 5);
    printf("Play");
    gotoxy(5, 7);
    printf("Quit");

    for(timeout = 0; timeout != 9999;)
    {

        if(kbhit())
        {
            readInput = getch();
            switch(readInput)
            {
            case KB_UP :
                posYMenu = 5;
                gotoxy(3, posYMenu);
                printf(">");
                gotoxy(3, 7);
                printf(" ");
                break;
            case KB_DOWN :
                posYMenu = 7;
                gotoxy(3, 5);
                printf(" ");
                gotoxy(3, posYMenu);
                printf(">");
                break;
            case KB_LEFT :
                if(posYMenu == 5)
                {
                    playgame = true;
                }
                if(posYMenu == 7)
                {
                    playgame = false;
                }

                timeout = 9999;
                break;
            }
        }
    }
    return playgame;

}


int main(void){
    int posX = 15;
    int posY = 15;
    int posXObj;
    int posYObj;
    int velocityX = 0;
    int velocityY = 0;
    bool canSpawn = true;
    bool playgame;
    int score = 0;

    char readInput;
    int endGame;
    int recordEnd;

    playgame = menu(playgame);

    if(playgame)
    {
        for(endGame = 9999; recordEnd != endGame || !playgame;)
        {
        if(kbhit())
        {
            readInput = getch();
            switch(readInput)
            {
            case KB_LEFT :
                velocityX = -1;
                velocityY = 0;
                break;
            case KB_RIGHT :
                velocityX = 1;
                velocityY = 0;
                break;
            case KB_DOWN :
                velocityY = 1;
                velocityX = 0;
                break;
            case KB_UP :
                velocityY = -1;
                velocityX = 0;
                break;
            case KB_ESCAPE :
                recordEnd = 9999;
                break;
            }
        }
        switch(posY)
        {
        case 3 :
            velocityY = 1;
            velocityX = 0;
            break;
        case 22 :
            velocityY = -1;
            velocityX = 0;
            break;
        }

        switch(posX)
        {
        case 10 :
            velocityX = 1;
            velocityY = 0;
            break;
        case 30 :
            velocityX = -1;
            velocityY = 0;
            break;
        }


        clrscr();

        gotoxy(9, 2);
        printf("----------------------");
        gotoxy(9, 23);
        printf("----------------------");

        for(int y=2; y<24; y++)
        {
            gotoxy(9, y);
            printf("|");
        }

        for(int y=2; y<24; y++)
        {
            gotoxy(31, y);
            printf("|");
        }


        gotoxy(9, 1);
        printf("Your score : %d", score);

        if(canSpawn){
            posXObj = rand()%20 + 10;
            posYObj = rand()%3 + 10;
            canSpawn = false;
        }

        if(!canSpawn){
            gotoxy(posXObj, posYObj);
            printf("X");
        }


        if(posXObj == posX && posYObj == posY){
            canSpawn = true;
            posYObj = 0;
            posXObj = 0;
            score++;
        }

        posY += velocityY;
        posX += velocityX;
        gotoxy(posX,posY);
        printf("O");

        Sleep(100);

    }


    }
}
