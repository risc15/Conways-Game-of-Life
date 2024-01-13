#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <conio.h>

#define SCREENWIDTH 40
#define SCREENHEIGHT 40
#define REFRESHRATE 50000

void initializeScreen(int screen[][SCREENWIDTH]);
void randomizeScreen(int screen[][SCREENWIDTH]);
void printScreen(int screen[][SCREENWIDTH]);
void printScreen2(int screen[][SCREENWIDTH]);
void processCell(int screen[][SCREENWIDTH], int screen2[][SCREENWIDTH]);
void processAnchorCell(int screen[][SCREENWIDTH], int screen2[][SCREENWIDTH]);
int copyScreen(int screen[][SCREENWIDTH], int screen2[][SCREENWIDTH]);

int main()
{
	// Set up double buffered screen using 2 arrays:
	int screen[SCREENHEIGHT][SCREENWIDTH];
	int screen2[SCREENHEIGHT][SCREENWIDTH];
	int screen3[SCREENHEIGHT][SCREENWIDTH];
	
	unsigned short screenSelect = 0;
	
	// Random number generator initialization:
	srand(time(NULL));
	
	// Initialize screens:
	randomizeScreen(screen);
	initializeScreen(screen2);
	initializeScreen(screen3);
	
	// Main loop:
	while(1) {
		// Check for input. conio.h gives us non-blocking input:
		if(kbhit()) {
			char key = getch();
			if(key == 'a') {
				randomizeScreen(screen);
				initializeScreen(screen2);
				initializeScreen(screen3);
			}
			if(key == 's') {
				screenSelect = 0;
			}
			if(key == 'd') {
				screenSelect = 1;
			}
			if(key == 'q') {
				return 0;
			}
			
		}
		
		// Display screen:
		if(screenSelect == 0) {
			printScreen(screen2);
		} else {
			printScreen2(screen3);
		}
		
		// Process cells:
		initializeScreen(screen3);
		processCell(screen, screen2);
		copyScreen(screen, screen2);
		processAnchorCell(screen2, screen3);
		usleep(REFRESHRATE);
	}
	
	return 0;
}

void initializeScreen(int screen[][SCREENWIDTH])
{
	for(int i = 0; i < SCREENHEIGHT; i++) {
		for(int j = 0; j < SCREENWIDTH; j++) {
			screen[i][j] = 0;
		}
	}
}

void randomizeScreen(int screen[][SCREENWIDTH])
{
	for(int i = 0; i < SCREENHEIGHT; i++) {
		for(int j = 0; j < SCREENWIDTH; j++) {
			if ((rand() % 10) == 0) {
				screen[i][j] = 1;
			} else {
				screen[i][j] = 0;
			}
		}
	}
}

void printScreen(int screen[][SCREENWIDTH])
{
	//system("cls");
	printf("\e[1;1H\e[2J");
	for(int k = 0; k < (SCREENWIDTH + 2); k++) {
		printf("%c%c", 178, 178);
	}
	
	for(int i = 0; i < SCREENHEIGHT; i++) {
		printf("\n");
		printf("%c%c", 178, 178);
		for(int j = 0; j < SCREENWIDTH; j++) {
			if(screen[i][j] == 0) {
				printf("  ");
			} else if(screen[i][j] == 1){
				printf("\033[32m%c%c\033[0m", 219, 219); // red =31
			} else {
				printf("\033[21m%c%c\033[0m", 219, 219);
			}
		}
		printf("%c%c", 178, 178);
	}
	printf("\n");
	
	for(int k = 0; k < (SCREENWIDTH + 2); k++) {
		printf("%c%c", 178, 178);
	}

}

void printScreen2(int screen[][SCREENWIDTH])
{
	//system("cls");
	printf("\e[1;1H\e[2J");
	for(int k = 0; k < (SCREENWIDTH + 2); k++) {
		printf("%c%c", 178, 178);
	}
	
	for(int i = 0; i < SCREENHEIGHT; i++) {
		printf("\n");
		printf("%c%c", 178, 178);
		for(int j = 0; j < SCREENWIDTH; j++) {
			if(screen[i][j] == 0) {
				printf("  ");
			} else {
				printf("\033[31m%c%c\033[0m", 219, 219); // red =31
			}
		}
		printf("%c%c", 178, 178);
	}
	printf("\n");
	
	for(int k = 0; k < (SCREENWIDTH + 2); k++) {
		printf("%c%c", 178, 178);
	}

}

void processCell(int screen[][SCREENWIDTH], int screen2[][SCREENWIDTH])
{
	for(int i = 0; i < SCREENHEIGHT; i++) {
		for(int j = 0; j < SCREENWIDTH; j++) {
			int count = 0;
			// Top:
			if((screen[((i - 1) % SCREENHEIGHT + SCREENHEIGHT) % SCREENHEIGHT][j] >= 1)) {
				count++;
			}
			// Top right:
			if((screen[((i - 1) % SCREENHEIGHT + SCREENHEIGHT) % SCREENHEIGHT][((j + 1) % SCREENWIDTH + SCREENWIDTH) % SCREENWIDTH] >= 1)) {
				count++;
			}
			// Right:
			if((screen[i][((j + 1) % SCREENWIDTH + SCREENWIDTH) % SCREENWIDTH] >= 1)) {
				count++;
			}
			// Bottom Right:
			if((screen[((i + 1) % SCREENHEIGHT + SCREENHEIGHT) % SCREENHEIGHT][((j + 1) % SCREENWIDTH + SCREENWIDTH) % SCREENWIDTH] >= 1)) {
				count++;
			}
			// Bottom:
			if((screen[((i + 1) % SCREENHEIGHT + SCREENHEIGHT) % SCREENHEIGHT][j] >= 1)) {
				count++;
			}
			// Bottom left:
			if((screen[((i + 1) % SCREENHEIGHT + SCREENHEIGHT) % SCREENHEIGHT][((j - 1) % SCREENWIDTH + SCREENWIDTH) % SCREENWIDTH] >= 1)) {
				count++;
			}
			// Left:
			if((screen[i][((j - 1) % SCREENWIDTH + SCREENWIDTH) % SCREENWIDTH] >= 1)) {
				count++;
			}
			// Top Left:
			if((screen[((i - 1) % SCREENHEIGHT + SCREENHEIGHT) % SCREENHEIGHT][((j - 1) % SCREENWIDTH + SCREENWIDTH) % SCREENWIDTH] >= 1)) {
				count++;
			}
			
			// If the cell is alive:
			if(screen[i][j] >= 1) {
				switch(count) {
				case 0:
					screen2[i][j] = 0;	// Default 0
					break;
				case 1:
					screen2[i][j] = 0;	// 0
					break;
				case 2:
					screen2[i][j] = 1;	// 1
					break;
				case 3:
					screen2[i][j] = 1;	// 1
					break;
				case 4:
					screen2[i][j] = 0;	// 1
					break;
				case 5:
					screen2[i][j] = 0;	// 1
					break;
				default:
					screen2[i][j] = 0;	// 0
					break;
				}
			// If the cell is dead:
			} else {
				switch(count) {
				case 3:
					screen2[i][j] = 1;
					break;
				default:
					screen2[i][j] = 0;
				}
			}
		}
	}
}

void processAnchorCell(int screen[][SCREENWIDTH], int screen2[][SCREENWIDTH])
{
	for(int i = 0; i < SCREENHEIGHT; i++) {
		for(int j = 0; j < SCREENWIDTH; j++) {
			int count = 0;
			
			for(int k = (i - 1); k < (i - 1) + 3; k++) {
				for(int l = (j - 1); l < (j - 1) + 3; l++) {
					int actualRow = (k % SCREENHEIGHT + SCREENHEIGHT) % SCREENHEIGHT;
					int actualCol = (l % SCREENWIDTH + SCREENWIDTH) % SCREENWIDTH;
					if(screen[actualRow][actualCol] >= 1 && (i != 2 && j != 2)) {
						count++;
					}
				}
			}

			// If the cell is alive:
			if(screen[i][j] >= 1) {
				switch(count) {
				case 7:
					screen2[i][j] = 1;
					break;
				case 8:
					screen2[i][j] = 1;
					break;
				default:
					screen2[i][j] = 0;
					break;
				}
			}
		}
	}
}

int copyScreen(int screen[][SCREENWIDTH], int screen2[][SCREENWIDTH])
{
	for(int i = 0; i < SCREENHEIGHT; i++) {
		for(int j = 0; j < SCREENWIDTH; j++) {
			screen[i][j] = screen2[i][j];
		}
	}
}