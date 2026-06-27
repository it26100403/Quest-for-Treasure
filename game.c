#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15

char map[SIZE][SIZE];
int Trap[SIZE][SIZE];

typedef struct
{
    char name[50];
    int row;
    int col;
    int health;
    int score;
    int keys;
    char symbol;
} Player;

Player player1;
Player player2;

void initializeMap();
void placeWalls();
void placeTreasure();
void placeHealthPack();
void placeKeys();
void placeDoors();
void placeTraps();
void initializePlayers();
void placePlayers();
void printMap();

int main()
{
    srand(time(NULL));
    initializeMap();
    placeWalls();
    placeTreasure();
    placeHealthPack();
    placeKeys();
    placeDoors();
    placeTraps();
    initializePlayers();
    placePlayers();
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
            Trap[row][col] = 0;
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

void placeWalls()
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

void placeTraps()
{
    int row, col;
    int count =0;

    while(count<10)
    {
        row = rand() % SIZE;
        col = rand() % SIZE;

        if(map[row][col] == ' ' && Trap[row][col] == 0)
        {
            Trap[row][col] = 1;
            count++;
        }
    }
}

void initializePlayers()
{
    printf("Enter Player 1 Name: ");
    scanf("%s", player1.name);

    printf("Enter Player 2 Name: ");
    scanf("%s", player2.name);

    player1.health = 100;
    player1.score = 0;
    player1.keys = 0;
    player1.symbol = '1';

    player2.health = 100;
    player2.score = 0;
    player2.keys = 0;
    player2.symbol = '2';
}

void placePlayers()
{
    int row, col;

    // Place Player 1
    while(1)
    {
        row = rand() % SIZE;
        col = rand() % SIZE;

        if(map[row][col] == ' ')
        {
            player1.row = row;
            player1.col = col;
            map[row][col] = player1.symbol;
            break;
        }
    }

    // Place Player 2
    while(1)
    {
        row = rand() % SIZE;
        col = rand() % SIZE;

        if(map[row][col] == ' ')
        {
            player2.row = row;
            player2.col = col;
            map[row][col] = player2.symbol;
            break;
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
            if(map[row][col] == ' ')
            {
                printf(". ");
            }
            else
            {
                printf("%c ", map[row][col]);
            }
        }

        printf("\n");
    }
}
