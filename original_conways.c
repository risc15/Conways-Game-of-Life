#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <conio.h>

#define SCREENWIDTH 60
#define SCREENHEIGHT 40
#define REFRESHRATE 25000

void initializeScreen(int screen[][SCREENWIDTH]);
void randomizeScreen(int screen[][SCREENWIDTH]);
void printScreen(int screen[][SCREENWIDTH]);
void processCell(int screen[][SCREENWIDTH], int screen2[][SCREENWIDTH]);
int copyScreen(int screen[][SCREENWIDTH], int screen2[][SCREENWIDTH]);

int main()
{
	// Set up double buffered screen using 2 arrays:
	int screen[SCREENHEIGHT][SCREENWIDTH];
	int screen2[SCREENHEIGHT][SCREENWIDTH];
	
	// Random number generator initialization:
	srand(time(NULL));
	
	// Initialize screens:
	initializeScreen(screen);
	randomizeScreen(screen);
	initializeScreen(screen2);
	
	// Main loop:
	while(1) {
		// Check for input. conio.h gives us non-blocking input:
		if(kbhit()) {
			char key = getch();
			if(key == 'a') {
				randomizeScreen(screen);
				initializeScreen(screen2);
			}
			if(key == 'q') {
				return 0;
			}
			
		}
		
		// Display screen:
		printScreen(screen2);
		
		// Process cells:
		processCell(screen, screen2);
		copyScreen(screen, screen2);
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
	// Print top border:
	printf("\e[1;1H\e[2J");
	for(int k = 0; k < (SCREENWIDTH + 2); k++) {
		printf("%c%c", 178, 178);
	}
	
	// Print screen:
	for(int i = 0; i < SCREENHEIGHT; i++) {
		printf("\n");
		printf("%c%c", 178, 178);
		for(int j = 0; j < SCREENWIDTH; j++) {
			if(screen[i][j] == 0) {
				printf("  ");
			} else {
				printf("\033[31m%c%c\033[0m", 219, 219); // red = 31m.
			}
		}
		printf("%c%c", 178, 178);
	}
	printf("\n");
	
	// Print bottom border:
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
			if((screen[((i - 1) % SCREENHEIGHT + SCREENHEIGHT) % SCREENHEIGHT][j] == 1)) {
				count++;
			}
			// Top right:
			if((screen[((i - 1) % SCREENHEIGHT + SCREENHEIGHT) % SCREENHEIGHT][((j + 1) % SCREENWIDTH + SCREENWIDTH) % SCREENWIDTH] == 1)) {
				count++;
			}
			// Right:
			if((screen[i][((j + 1) % SCREENWIDTH + SCREENWIDTH) % SCREENWIDTH] == 1)) {
				count++;
			}
			// Bottom Right:
			if((screen[((i + 1) % SCREENHEIGHT + SCREENHEIGHT) % SCREENHEIGHT][((j + 1) % SCREENWIDTH + SCREENWIDTH) % SCREENWIDTH] == 1)) {
				count++;
			}
			// Bottom:
			if((screen[((i + 1) % SCREENHEIGHT + SCREENHEIGHT) % SCREENHEIGHT][j] == 1)) {
				count++;
			}
			// Bottom left:
			if((screen[((i + 1) % SCREENHEIGHT + SCREENHEIGHT) % SCREENHEIGHT][((j - 1) % SCREENWIDTH + SCREENWIDTH) % SCREENWIDTH] == 1)) {
				count++;
			}
			// Left:
			if((screen[i][((j - 1) % SCREENWIDTH + SCREENWIDTH) % SCREENWIDTH] == 1)) {
				count++;
			}
			// Top Left:
			if((screen[((i - 1) % SCREENHEIGHT + SCREENHEIGHT) % SCREENHEIGHT][((j - 1) % SCREENWIDTH + SCREENWIDTH) % SCREENWIDTH] == 1)) {
				count++;
			}
			
			// Rules:
			// If the cell is alive:
			if(screen[i][j] == 1) {
				switch(count) {
				case 2:
					screen2[i][j] = 1;	// 1
					break;
				case 3:
					screen2[i][j] = 1;	// 1
					break;
				default:
					screen2[i][j] = 0;	// 0
					break;
				}
			// If the cell is dead:
			} else if(screen[i][j] == 0) {
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

int copyScreen(int screen[][SCREENWIDTH], int screen2[][SCREENWIDTH])
{
	for(int i = 0; i < SCREENHEIGHT; i++) {
		for(int j = 0; j < SCREENWIDTH; j++) {
			screen[i][j] = screen2[i][j];
		}
	}
}