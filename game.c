#include <stdio.h>

#define SIZE 15
#define WALL '#'
#define TREASURE 'T'
#define HEALTH 'H'
#define KEY 'K'
#define DOOR 'D'

char map[SIZE][SIZE];

void initializeMap()
{

    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            map[i][j] = ' ';
        }
    }
}

void createBorders()
{

    for(int i=0;i<SIZE;i++)
    {
        map[0][i] = '#';
        map[SIZE-1][i] = '#';
        map[i][0] = '#';
        map[i][SIZE-1] = '#';
    }
}

void printMap()
{

    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            printf("%c ", map[i][j]);
        }

        printf("\n");
    }
}

int main()
{
    initializeMap();
    createBorders();
    printMap();

    return 0;
}
