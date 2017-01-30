#include <myconio.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>

#define KB_UP 72
#define KB_DOWN 80
#define KB_LEFT 75
#define KB_RIGHT 77
#define KB_ESCAPE 27


int main(void){
    int posX = 15;
    int posY = 15;
    int posXObj;
    int posYObj;
    int velocityX = 0;
    int velocityY = 0;
    bool canSpawn = true;
    int score = 0;

    char readInput;
    int endGame;
    int recordEnd;

    for(endGame = 9999; recordEnd != endGame;)
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
