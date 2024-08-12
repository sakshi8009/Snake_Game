#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;
int width = 20, height = 20, gameover;
int flag, hs = 2;
char snk;
int tailX[100],tailY[100];
int countTail=0;
int x, y, fruitx, fruity, frux, fruy, score, a, c, b;
void log()
{

    system("cls");
    printf("\n                                  /^\\/^\\                                             ");
    printf("\n                                _|__|  O|                                              ");
    printf("\n                       \\/     /~     \\_/ \\                                          ");
    printf("\n                        \\____|__________/  \\                                         ");
    printf("\n                               \\_______      \\                                       ");
    printf("\n                                       `\\     \\                 \\                   ");
    printf("\n                                         |     |                  \\                   ");
    printf("\n                                        /      /                    \\                 ");
    printf("\n                                       /     /                       \\\\              ");
    printf("\n                                     /      /                         \\ \\            ");
    printf("\n                                    /     /                            \\  \\          ");
    printf("\n                                  /     /             _----_            \\   \\        ");
    printf("\n                                 /     /           _-~      ~-_         |   |          ");
    printf("\n                                (      (        _-~    _--_    ~-_     _/   |          ");
    printf("\n                                 \\      ~-____-~    _-~    ~-_    ~-_-~    /          ");
    printf("\n                                   ~-_           _-~          ~-_       _-~            ");
    printf("\n                                      ~--______-~                ~-___-~               ");
    printf("\n\n\n\n");
    printf("********************************************************* SLITHER *******************************************************\n\n\n");
    //printf("PLAY THE SNAKE GAME");
}

void setup()
{
    gameover = 0;
    x = width / 2;
    y = height / 2;
    score = 0;

    a = rand() % 8;
    b = rand() % 7;
    c = rand() % 8;

lable1:
    fruitx = rand() % 20;
    if (fruitx == 0)
    {
        goto lable1;
    }
lable2:
    fruity = rand() % 20;
    if (fruity == 0)
    {
        goto lable2;
    }

lablea:
    frux = rand() % 20;
    if (frux == 0)
    {
        goto lablea;
    }
lableb:
    fruy = rand() % 20;
    if (fruy == 0)
    {
        goto lableb;
    }
}
void draw()
{
    int i, j;

    system("cls");
    for (i = 0; i < width; i++)
    {
        for (j = 0; j < height; j++)
        {

            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
            {
                printf("*");
            }
            else
            {
                if (i == x && j == y)
                {
                    printf("%c", snk);
                }
                else if (i == fruitx && j == fruity)
                {
                    printf("%d", a + b);
                }
                else if (i == frux && j == fruy)
                {
                    printf("%d", c);
                }
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }

    printf("the value of %d + %d = ?", a, b);
    printf("\n\nscore is %d", score);
}

void draw2()
{
    int i, j;

    system("cls");
    for (i = 0; i < width; i++)
    {
        for (j = 0; j < height; j++)
        {

            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
            {
                printf("*");
            }
            else
            {
                if (i == x && j == y)
                {
                    printf("0");
                }
                else if (i == fruitx && j == fruity)
                {
                    printf("*");
                }
                //else if (i == frux && j == fruy)
                // {
                //    printf("%d", c);
                //}
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }

    //printf("the value of %d + %d = ?", a, b);
    printf("\n\nscore is %d", score);
}

void input()
{

    if (kbhit())
    {
        switch (getch())
        {
        case 'a':
            flag = 1;
            break;
        case 's':
            flag = 2;
            break;
        case 'w':
            flag = 3;
            break;
        case 'd':
            flag = 4;
            break;
        case 'x':
            gameover = 1;
            break;
        default:
            break;
        }
    }
}

void input2()
{

    if (kbhit())
    {
        switch (getch())
        {
        case 'a':
            flag = 1;
            break;
        case 's':
            flag = 2;
            break;
        case 'w':
            flag = 3;
            break;
        case 'd':
            flag = 4;
            break;
        case 'x':
            gameover = 1;
            break;
        default:
            break;
        }
    }
}

void logic()
{
    switch (flag)
    {
    case 1:
        y--;
        break;
    case 2:
        x++;
        break;
    case 3:
        x--;
        break;
    case 4:
        y++;
        break;

    default:
        break;
    }
    if (x < 0 || x > width || y < 0 || y > height)
    {
        Beep(880, 100);
        system("cls");
        printf("\n********gameover*********\n score is %d", score);
        string st;
        if (score < hs)
        {
            printf("\n HIGHSCORE is:");
            ifstream in;
            in.open("highscore.txt");
            getline(in, st);
            in >> st;
            //printf("%s",st);
            cout << endl<< st;
            in.close();
        }
        if (hs < score)
        {
            hs = score;
            string st2;
            ofstream out;
            out.open("highscore.txt");
            printf("\ncongrats you made a new highscore\n Enter your name:");
            //scanf("%s",&st2);
            cin >> st2;
            //getline(st2,out);
            out << st2;
            out.close();
        }

        gameover = 1;
    }
    if (x == fruitx && y == fruity)
    {
        Beep(600, 100);

    lable3:
        fruitx = rand() % 20;
        if (fruitx == 0)
        {
            goto lable3;
        }
    lable4:
        fruity = rand() % 20;
        if (fruity == 0)
        {
            goto lable4;
        }
    lables:
        frux = rand() % 20;
        if (frux == 0)
        {
            goto lables;
        }
    labler:
        fruy = rand() % 20;
        if (fruy == 0)
        {
            goto labler;
        }
        score = score + 2;
        a = rand() % 17;
        b = rand() % 18;
        c = rand() % 20;
    }

    if (x == frux && y == fruy)
    {
        Beep(800, 100);
    lable5:
        fruitx = rand() % 20;
        if (fruitx == 0)
        {
            goto lable5;
        }
    lable6:
        fruity = rand() % 20;
        if (fruity == 0)
        {
            goto lable6;
        }
    lablem:
        frux = rand() % 20;
        if (frux == 0)
        {
            goto lablem;
        }
    lablen:
        fruy = rand() % 20;
        if (fruy == 0)
        {
            goto lablen;
        }
        score = score - 2;
        a = rand() % 17;
        b = rand() % 18;
        c = rand() % 20;
    }
}

void logic2()
{
    switch (flag)
    {
    case 1:
        y--;
        break;
    case 2:
        x++;
        break;
    case 3:
        x--;
        break;
    case 4:
        y++;
        break;
    default:
        break;
    }

    if (x < 0 || x >= width || y < 0 || y >= height)
    {
        Beep(880, 100);
        system("cls");
        printf("\n********gameover*********\n score is %d", score);
        
        gameover = 1;
        return;
    }

    if (x == fruitx && y == fruity)
    {
        Beep(600, 100);
        score += 2;
        
        
        while (true) {
            fruitx = rand() % width;
            fruity = rand() % height;
            if (fruitx != x || fruity != y)
                break;
        }

        
        a = rand() % 10;
        b = rand() % 10;
    }
}



int main()
{
    setup();
    log();
    int m, ip, n, q;
    string st1;
read:
    // printf("\nenter 1 for snake game 2 to exit");
    printf("\n1.PLAY THE SNAKE GAME WITH QUIZ");
    printf("                                          2.PLAY THE SNAKE GAME\n");
    printf("\n\n");
    printf("3.QUIT");
    printf("\n\n");
    printf("Enter Your Choice :");
    scanf("%d", &ip);

    switch (ip)
    {
    case 1:
    ch:
        printf("\nRULES:\n1. This is a snake game with quiz.You have to answer simple addition problems.\n");
        printf("2. There will be two options to select from , you will have to choose the correct one from the both\n");
        printf("3. If you choose the correct option your score will increase and if you choose the wrong option your score will decrease\n");
        printf("4. if the snake touches the wall game will end\n All the best !!!! ");
        printf("\nUse A D W S keys for movement of snake");
        printf("\nA for left\tD for right\tW for up\tS for down\n");
        printf("\nX for exit the game\n");
        

        printf("\nEnter the letter you want as snake\nEither 'a' or 'o' ");
        scanf("%c", &snk);
        if (snk == 'a' || snk == 'o')
        {

            while (!gameover)
            {
                draw();
                input();
                logic();
                Sleep(220);
                // for (m = 0; m < 10000; m++)
                // {
                //    for (n = 0; n < 10000; n++)
                {
                    /* code */
                }
                // }
            }
        }

        else
        {
            printf("\n invalid choice");
            system("cls");
            goto ch;
        }

        break;

    case 2:


        while (!gameover)
        {
            draw2();
            input2();
            logic2();
            Sleep(220);

        }

        break;
    
    case 3:
        exit;
        break;

    default:
        printf("\n Invalid choice:");
        goto read;
        break;
    }

    return 0;
}