#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15

char map[SIZE][SIZE];

void initializeMap();
void placewalls();
void placeTreasure();
void placeHealthPack();
void placeKeys();
void placeDoors();
void printMap();

int main()
{
    srand(time(NULL));
    initializeMap();
    placewalls();
    placeTreasure();
    placeHealthPack();
    placeKeys();
    placeDoors();
    printMap();

    return 0;
}

void initializeMap()
{
    int row, col;

    for(row = 0; row < SIZE; row++)
    {
        for(col = 0; col < SIZE; col++)
        {
            map[row][col] = ' ';
        }
    }
    // Border walls
    for(row = 0; row < SIZE; row++)
    {
        map[row][0] = '#';
        map[row][SIZE - 1] = '#';
    }

    for(col = 0; col < SIZE; col++)
    {
        map[0][col] = '#';
        map[SIZE - 1][col] = '#';
    }


}

void placewalls()
{
    int row, col;
    int count = 0;

    while(count<30)
    {
        row = rand() % SIZE;
        col = rand() % SIZE;

        if(map[row][col] == ' ')
        {
            map[row][col] = '#';
            count++;
        }
    }
}

void placeTreasure()
{
   int row, col;
    int count = 0;

    while(count<12)
    {
        row = rand() % SIZE;
        col = rand() % SIZE;

        if(map[row][col] == ' ')
        {
            map[row][col] = 'T';
            count++;
        }
    }

}

void placeHealthPack()
{
    int row, col;
    int count = 0;

    while(count<5)
    {
        row = rand() % SIZE;
        col = rand() % SIZE;

        if(map[row][col] == ' ')
        {
            map[row][col] = 'H';
            count++;
        }
    }
}

void placeKeys()
{
    int row, col;
    int count = 0;

    while(count<3)
    {
        row = rand() % SIZE;
        col = rand() % SIZE;

        if(map[row][col] == ' ')
        {
            map[row][col] = 'K';
            count++;
        }
    }
}

void placeDoors()
{
    int row, col;
    int count = 0;

    while(count<3)
    {
        row = rand() % SIZE;
        col = rand() % SIZE;

        if(map[row][col] == ' ')
        {
            map[row][col] = 'D';
            count++;
        }
    }
}
void printMap()
{
    int row, col;

    for(row = 0; row < SIZE; row++)
    {
        for(col = 0; col < SIZE; col++)
        {
            printf("%c ", map[row][col]);
        }

        printf("\n");
    }
}
