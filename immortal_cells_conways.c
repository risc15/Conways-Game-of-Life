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
	
	unsigned short screenSelect = 0;
	
	// Random number generator initialization:
	srand(time(NULL));
	
	// Initialize screens:
	initializeScreen(screen);
	randomizeScreen(screen);
	initializeScreen(screen2);
		// screen[20][20] = 2;
		// screen[21][20] = 2;
		// screen[21][21] = 2;
		// screen[20][21] = 2;
		// screen[24][20] = 2;
		// screen[25][20] = 2;
		// screen[25][21] = 2;
		// screen[24][21] = 2;
		
		// screen[20][36] = 2;
		// screen[21][36] = 2;
		// screen[21][37] = 2;
		// screen[20][37] = 2;
		// screen[24][36] = 2;
		// screen[25][36] = 2;
		// screen[25][37] = 2;
		// screen[24][37] = 2;
		
		// screen[22][25] = 2;
		// screen[23][25] = 2;
		// screen[22][32] = 2;
		// screen[23][32] = 2;
		
		// screen[17][25] = 2;
		// screen[18][25] = 2;
		// screen[27][25] = 2;
		// screen[28][25] = 2;
		
		// screen[17][32] = 2;
		// screen[18][32] = 2;
		// screen[27][32] = 2;
		// screen[28][32] = 2;
		
		// screen[17][33] = 2;
		// screen[28][33] = 2;
		// screen[17][24] = 2;
		// screen[28][24] = 2;
		
		// screen[18][23] = 2;
		// screen[19][23] = 2;
		// screen[20][23] = 2;
		// screen[21][23] = 2;
		// screen[22][23] = 2;
		// screen[23][23] = 2;
		// screen[24][23] = 2;
		// screen[25][23] = 2;
		// screen[26][23] = 2;
		// screen[27][23] = 2;
		
		// screen[18][34] = 2;
		// screen[19][34] = 2;
		// screen[20][34] = 2;
		// screen[21][34] = 2;
		// screen[22][34] = 2;
		// screen[23][34] = 2;
		// screen[24][34] = 2;
		// screen[25][34] = 2;
		// screen[26][34] = 2;
		// screen[27][34] = 2;
		
		// screen[21][26] = 1;
		// screen[24][26] = 1;
		// screen[22][27] = 1;
		// screen[23][27] = 1;
		// screen[21][28] = 1;
		// screen[24][28] = 1;
		// screen[21][29] = 1;
		// screen[24][29] = 1;
		// screen[22][30] = 1;
		// screen[23][30] = 1;
		// screen[21][31] = 1;
		// screen[24][31] = 1;
		// screen[22][28] = 1;
		// screen[22][29] = 1;
		// screen[23][28] = 1;
		// screen[23][29] = 1;
	
	// Main loop:
	while(1) {
		// Check for input. conio.h gives us non-blocking input:
		if(kbhit()) {
			char key = getch();
			if(key == 'a') {
				randomizeScreen(screen);
				initializeScreen(screen2);
				// screen[20][20] = 2;
				// screen[21][20] = 2;
				// screen[21][21] = 2;
				// screen[20][21] = 2;
				// screen[24][20] = 2;
				// screen[25][20] = 2;
				// screen[25][21] = 2;
				// screen[24][21] = 2;
				
				// screen[20][36] = 2;
				// screen[21][36] = 2;
				// screen[21][37] = 2;
				// screen[20][37] = 2;
				// screen[24][36] = 2;
				// screen[25][36] = 2;
				// screen[25][37] = 2;
				// screen[24][37] = 2;
				
				// screen[22][25] = 2;
				// screen[23][25] = 2;
				// screen[22][32] = 2;
				// screen[23][32] = 2;
				
				// screen[17][25] = 2;
				// screen[18][25] = 2;
				// screen[27][25] = 2;
				// screen[28][25] = 2;
				
				// screen[17][32] = 2;
				// screen[18][32] = 2;
				// screen[27][32] = 2;
				// screen[28][32] = 2;
				
				// screen[17][33] = 2;
				// screen[28][33] = 2;
				// screen[17][24] = 2;
				// screen[28][24] = 2;
				
				// screen[18][23] = 2;
				// screen[19][23] = 2;
				// screen[20][23] = 2;
				// screen[21][23] = 2;
				// screen[22][23] = 2;
				// screen[23][23] = 2;
				// screen[24][23] = 2;
				// screen[25][23] = 2;
				// screen[26][23] = 2;
				// screen[27][23] = 2;
				
				// screen[18][34] = 2;
				// screen[19][34] = 2;
				// screen[20][34] = 2;
				// screen[21][34] = 2;
				// screen[22][34] = 2;
				// screen[23][34] = 2;
				// screen[24][34] = 2;
				// screen[25][34] = 2;
				// screen[26][34] = 2;
				// screen[27][34] = 2;
				
				// screen[21][26] = 1;
				// screen[24][26] = 1;
				// screen[22][27] = 1;
				// screen[23][27] = 1;
				// screen[21][28] = 1;
				// screen[24][28] = 1;
				// screen[21][29] = 1;
				// screen[24][29] = 1;
				// screen[22][30] = 1;
				// screen[23][30] = 1;
				// screen[21][31] = 1;
				// screen[24][31] = 1;
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
			if ((rand() % 16) == 0) {
				screen[i][j] = 1;
			} else if ((rand() % 1000) == 0) {
				screen[i][j] = 2;
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
			} else if(screen[i][j] == 1){
				printf("\033[33m%c%c\033[0m", 219, 219); // red = 31m.
			} else {
				printf("\033[31m%c%c\033[0m", 219, 219);
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
				case 8:
					screen2[i][j] = 1;
					break;
				default:
					screen2[i][j] = 0;
				}
			// Special cells:
			} else {
				screen2[i][j] = 2;
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