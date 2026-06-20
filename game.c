#include <stdio.h>

#define SIZE 15
#define WALL '#'
#define TREASURE 'T'
#define HEALTH PACK 'H'
#define KEY 'K'
#define LOCK DOOR 'D'

char map[SIZE][SIZE];

void initializemap()
{
	for(int i=0; i<SIZE; i++){
		for(int j=0; j<SIZE; j++){
			map[i][j] = ' ';
		}
	}
}

void createborders()
{
	for(int i=0; i<SIZE; i++){
		map[0][i] = '#';
		map[SIZE-1][i] = '#';
		map[i][0] = '#';
		map[i][SIZE-1] = '#';
	}
}

void printmap()
{
        for(int i=0; i<SIZE; i++){
                for(int j=0; j<SIZE; j++)
		{
			if(map[i][j] == ' ')
				printf(". ");
			else
			        printf("%c ",map[i][i]);
		}
                printf("\n");
	}
}

int main()
{
	initializemap();
	createborders();
	printmap();
	return 0;
}
