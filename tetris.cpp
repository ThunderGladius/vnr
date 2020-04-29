#include<string.h>
#include<conio.h>
#include<iostream>
#include<time.h>
#include<stdlib.h>
#define FIELD_WIDTH 12
#define FIELD_HEIGHT 22
#define MINO_WIDTH 4
#define MINO_HEIGHT 4

using namespace std;


char field[FIELD_HEIGHT][FIELD_WIDTH];
char displayBuffer[FIELD_HEIGHT][FIELD_WIDTH];
int minoX = 5, minoY = 0;
int minoType = 0, minoAngle = 0;
bool esc = 0;


//MINO_TYPEとMINO_ANGLE
enum {
	MINO_TYPE_I,
	MINO_TYPE_O,
	MINO_TYPE_S,
	MINO_TYPE_Z,
	MINO_TYPE_J,
	MINO_TYPE_L,
	MINO_TYPE_T,
	MINO_TYPE_MAX
};
enum {
	MINO_ANGLE_0,
	MINO_ANGLE_90,
	MINO_ANGLE_180,
	MINO_ANGLE_270,
	MINO_ANGLE_MAX
};


//ミノの形
char minoShapes[MINO_TYPE_MAX][MINO_ANGLE_MAX][MINO_HEIGHT][MINO_WIDTH] = {
	//MINO_TYPE_I,
	{
		//MINO_ANGLE_0
		{
			0,1,0,0,
			0,1,0,0,
			0,1,0,0,
			0,1,0,0
		},
		//MINO_ANGLE_90
		{
			0,0,0,0,
			0,0,0,0,
			1,1,1,1,
			0,0,0,0
		},
		//MINO_ANGLE_180
		{
			0,0,1,0,
			0,0,1,0,
			0,0,1,0,
			0,0,1,0,
		},
		//MINO_ANGLE_270
		{
			0,0,0,0,
			1,1,1,1,
			0,0,0,0,
			0,0,0,0,
		}
	},
	//MINO_TYPE_O
	{
		//MINO_ANGLE_0
		{
			0,0,0,0,
			0,1,1,0,
			0,1,1,0,
			0,0,0,0
		},
		//MINO_ANGLE_90
		{
			0,0,0,0,
			0,1,1,0,
			0,1,1,0,
			0,0,0,0
		},
		//MINO_ANGLE_180
		{
			0,0,0,0,
			0,1,1,0,
			0,1,1,0,
			0,0,0,0
		},
		//MINO_ANGLE_270
		{
			0,0,0,0,
			0,1,1,0,
			0,1,1,0,
			0,0,0,0
		}
	},
	//MINO_TYPE_S
	{
		//MINO_ANGLE_0
		{
			0,0,0,0,
			0,1,1,0,
			1,1,0,0,
			0,0,0,0
		
		},
		//MINO_ANGLE_90
		{
			0,1,0,0,
			0,1,1,0,
			0,0,1,0,
			0,0,0,0

		},
		//MINO_ANGLE_180
		{
			0,0,0,0,
			0,1,1,0,
			1,1,0,0,
			0,0,0,0

		},
		//MINO_ANGLE_270
		{
			0,0,0,0,
			0,1,0,0,
			0,1,1,0,
			0,0,1,0,

		}
},
	//MINO_TYPE_Z
{
	//MINO_ANGLE_0
		{
			0,0,0,0,
			1,1,0,0,
			0,1,1,0,
			0,0,0,0

		},
		//MINO_ANGLE_90
		{
			0,0,0,0,
			0,0,1,0,
			0,1,1,0,
			0,1,0,0

		},
			//MINO_ANGLE_180
		{
			0,0,0,0,
			0,1,1,0,
			0,0,1,1,
			0,0,0,0

		},
			//MINO_ANGLE_270
		{
			0,0,0,0,
			0,0,1,0,
			0,1,1,0,
			0,1,0,0,

		}
},
	//MINO_TYPE_J
{
				//MINO_ANGLE_0
		{
			0, 0, 1, 0,
			0, 0, 1, 0,
			0, 1, 1, 0,
			0, 0, 0, 0

		},
					//MINO_ANGLE_90
		{
			0,0,0,0,
			1,1,1,0,
			0,0,1,0,
			0,0,0,0

		},
						//MINO_ANGLE_180
		{
			0,0,0,0,
			0,1,1,0,
			0,1,0,0,
			0,1,0,0

		},
						//MINO_ANGLE_270
		{
			0,0,0,0,
			0,1,0,0,
			0,1,1,1,
			0,0,0,0,

		}
},
	//MINO_TYPE_L
{
		//MINO_ANGLE_0
		{
			0,1,0,0,
			0,1,0,0,
			0,1,1,0,
			0,0,0,0
		
		},
		//MINO_ANGLE_90
		{
			0,0,0,0,
			0,0,1,0,
			1,1,1,0,
			0,0,0,0

		},
		//MINO_ANGLE_180
		{
			0,0,0,0,
			0,1,1,0,
			0,0,1,0,
			0,0,1,0

		},
		//MINO_ANGLE_270
		{
			0,0,0,0,
			0,1,1,1,
			0,1,0,0,
			0,0,0,0,

		}
},
		//MINO_TYPE_T
{
		//MINO_ANGLE_0
		{
			0,0,0,0,
			1,1,1,0,
			0,1,0,0,
			0,0,0,0
		
		},
		//MINO_ANGLE_90
		{
			0,0,0,0,
			0,1,0,0,
			0,1,1,0,
			0,1,0,0

		},
		//MINO_ANGLE_180
		{
			0,0,0,0,
			0,0,1,0,
			0,1,1,1,
			0,0,0,0

		},
		//MINO_ANGLE_270
		{
			0,0,1,0,
			0,1,1,0,
			0,0,1,0,
			0,0,0,0,

		}
}
};

//描画処理
void display(int score) {
	memcpy(displayBuffer, field, sizeof(field));

	//バッファにミノを書き込む
	for (int i = 0; i < MINO_HEIGHT; i++) {
		for (int j = 0; j < MINO_WIDTH; j++) {
			displayBuffer[minoY + i][minoX + j] |= minoShapes[minoType][minoAngle][i][j];
		}
	}
	//バッファを基に描画処理
	for (int i = 0; i < FIELD_HEIGHT; i++) {
		for (int j = 0; j < FIELD_WIDTH; j++) {
			if (displayBuffer[i][j] == 1) cout << "□";
			else if (displayBuffer[i][j] == 2)cout << "■";
			else cout << "　";
		}
		cout <<endl;
	}
	cout << "score:" << score << endl;
}

//ミノの初期化
void resetMino() {
	minoX = 5;
	minoY = 0;
	minoType = rand() % MINO_TYPE_MAX;
	minoAngle = rand() % MINO_ANGLE_MAX;
}

//isHit
bool isHit(int _minoX, int _minoY, int _minoType, int _minoAngle) {
	for (int i = 0; i < MINO_HEIGHT; i++) {
		for (int j = 0; j < MINO_WIDTH; j++) {
			if (minoShapes[_minoType][_minoAngle][i][j]
				&& field[_minoY + i][_minoX + j]) return true;
		}
	}
	return false;
}

int main() {
	memset(field, 0, sizeof(field));
	
	//フィールド作成
	for (int i = 0; i < FIELD_HEIGHT; i++) {
		field[i][0] = 2;
		field[i][FIELD_WIDTH - 1] = 2;
	}
	for (int i = 0; i < FIELD_WIDTH; i++) {
		field[FIELD_HEIGHT - 1][i] = 2;
	}
	resetMino();

	time_t t = time(NULL);

	int yuka = 0,score = 0,linenum = 0;
	while (1) {
		
		//落下処理
			if (_kbhit()) {
				switch (_getch()) {

				case 'w': 
					while (1) {
						if (!isHit(minoX,
							minoY + 1,
							minoType,
							minoAngle)) minoY++;
						else break;
					}
					
					
				case 's': if (!isHit(minoX,
								minoY + 1,
								minoType,
								minoAngle)) minoY++;	break;
				case 'a':
					if(!isHit(minoX - 1,
								minoY,
								minoType,
								minoAngle )) minoX--;	break;
				case 'd':
					if (!isHit(minoX + 1,
								minoY,
								minoType,
								minoAngle)) minoX++;	break;
				case 0x20:
					if (!isHit(	minoX,
								minoY,
								minoType,
								(minoAngle + 1) % MINO_ANGLE_MAX))
						minoAngle = (minoAngle + 1) % MINO_ANGLE_MAX;
						break;
				}
				system("cls");
				display(score);
			}

			if (t != time(NULL)) {
				system("cls");
				t = time(NULL);
				
				if (isHit(minoX,
					minoY + 1,
					minoType,
					minoAngle)) {
					for (int i = 0; i < MINO_HEIGHT; i++) {
						for (int j = 0; j < MINO_WIDTH; j++) {
							field[minoY + i][minoX + j] |= minoShapes[minoType][minoAngle][i][j];
						}
					}
					resetMino();
				}
				else minoY++;

				//ライン消去処理
				linenum = 0;
				for (int i = 0; i < FIELD_HEIGHT - 1; i++) {
					bool lineFill = true;
					for (int j = 0; j < FIELD_WIDTH - 1; j++) {
						if (!field[i][j]) lineFill = false;
					}
					if (lineFill) {
						linenum++;

						for (int j = i ; 0 <= j; j--) {
							memcpy(field[j], field[j - 1], FIELD_WIDTH);

							//フィールド作成
							for (int i = 0; i < FIELD_HEIGHT; i++) {
								field[i][0] = 2;
								field[i][FIELD_WIDTH - 1] = 2;
							}
							for (int i = 0; i < FIELD_WIDTH; i++) {
								field[FIELD_HEIGHT - 1][i] = 2;
							}
						}
					}

				}
				if (linenum == 1) score += 40;
				else if (linenum == 2) score += 100;
				else if (linenum == 3) score += 300;
				else if (linenum == 4) score += 1200;
				display(score);
				for (int i = 0; i < FIELD_WIDTH; i++) {
					if (field[0][i] == 1) {
						system("cls");
						cout << "GAME OVER" << endl << "Your score is " << score << endl;
						esc = 1;
						break;

					}
				}
				if (esc) break;
			}
			if (esc) break;
			
	}

	
	_getch();
}
