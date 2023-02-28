#include <iostream>
#include <windows.h>
#include <fstream>
#include<conio.h>
#include<string>
using namespace std;

#define Screen_col 168

struct position { int ri, ci; };

enum Color { white, black };
void gotoRowCol(int rpos, int cpos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = cpos;
	scrn.Y = rpos;
	SetConsoleCursorPosition(hOuput, scrn);
}
void SetClr(int clr)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr);
}
void getRowColbyLeftClick(int& rpos, int& cpos)
{
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD Events;
	INPUT_RECORD InputRecord;
	SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
	do
	{
		ReadConsoleInput(hInput, &InputRecord, 1, &Events);
		if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
			rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
			break;
		}
	} while (true);
}
void Box(int size, int clr,int rpos,int cpos)
{
	int columns = cpos , row = rpos;
	int colcopy = columns;
	for (int ri = 0; ri < size; ri++)
	{

		for (int ci = 0; ci < size; ci++)
		{
			SetClr(clr);
			gotoRowCol(row, columns);
			cout << char(-37);
			columns++;
		}
		columns = colcopy;
		row++;
		cout << endl;

	}

}
void  King(int row, int col,int clr)
{
	SetClr(clr);

	
	for (int r = row; r < row + 5; r++)
	{
		gotoRowCol(r, col);
		cout << char(-37);

	}
	for (int c = col - 1; c < col + 2; c++)
	{
		gotoRowCol(row + 1, c);
		cout << char(-37);

	}

	for (int r = row + 3; r < row + 5; r++)
	{
		for (int c = col - 1; c < col + 2; c++)
		{
			gotoRowCol(r, c);
			cout << char(-37);
		}

	}
	for (int c = col - 2; c < col + 3; c++)
	{
		gotoRowCol(row + 4, c);
		cout << char(-37);

	}




}
void  Pawn(int row, int col,int clr)
{
	SetClr(clr);

	//r=5,c=10



	for (int r = row; r < row + 2; r++)
	{
		for (int c = col - 1; c < col + 2; c++)
		{
			gotoRowCol(r, c);
			cout << char(-37);
		}

	}


	for (int r = row; r < row + 4; r++)//r=row,r<row+5
	{
		gotoRowCol(r, col);

		cout << char(-37);
	}


	for (int c = col - 1; c < col + 2; c++)
	{
		gotoRowCol(row + 3, c);
		cout << char(-37);
	}



	for (int c = col - 2; c < col + 3; c++)
	{
		gotoRowCol(row + 4, c);
		cout << char(-37);

	}
}
void  GoldGen(int row, int col, int clr)
{
	SetClr(clr);

	//r=5,c=10


	gotoRowCol(row, col - 2);
	cout << char(-37);
	gotoRowCol(row, col);
	cout << char(-37);
	gotoRowCol(row, col + 2);
	cout << char(-37);



	for (int c = col - 1; c < col + 2; c++)
	{
		gotoRowCol(row + 1, c);
		cout << char(-37);
	}




	for (int r = row; r < row + 4; r++)//r=row,r<row+5
	{
		gotoRowCol(r, col);

		cout << char(-37);
	}


	for (int c = col - 1; c < col + 2; c++)
	{
		gotoRowCol(row + 3, c);
		cout << char(-37);
	}



	for (int c = col - 2; c < col + 3; c++)
	{
		gotoRowCol(row + 4, c);
		cout << char(-37);

	}
}
void  silverdGen(int row, int col, int clr)
{
	SetClr(clr);

	//r=5,c=10


	gotoRowCol(row, col - 2);
	cout << char(-37);

	gotoRowCol(row, col + 2);
	cout << char(-37);



	for (int c = col - 1; c < col + 2; c++)
	{
		gotoRowCol(row + 1, c);
		cout << char(-37);
	}




	for (int r = row + 1; r < row + 4; r++)//r=row,r<row+5
	{
		gotoRowCol(r, col);

		cout << char(-37);
	}


	for (int c = col - 1; c < col + 2; c++)
	{
		gotoRowCol(row + 3, c);
		cout << char(-37);
	}



	for (int c = col - 2; c < col + 3; c++)
	{
		gotoRowCol(row + 4, c);
		cout << char(-37);

	}
}
void  Bishop(int row, int col, int clr)
{
	SetClr(clr);

	//r=5,c=10


	gotoRowCol(row, col);
	cout << char(-37);


	for (int i = row + 1; i < row + 4; i++)
	{

		for (int c = col - 1; c < col + 2; c++)
		{
			gotoRowCol(i, c);
			cout << char(-37);
		}
	}



	for (int c = col - 2; c < col + 3; c++)
	{
		gotoRowCol(row + 4, c);
		cout << char(-37);

	}
}
void  Lance(int row, int col, int clr)
{
	SetClr(clr);

	for (int r = row; r < row + 4; r++)
	{
		gotoRowCol(r, col);
		cout << char(-37);
	}



	for (int c = col - 1; c < col + 2; c++)
	{
		gotoRowCol(row + 3, c);
		cout << char(-37);
	}


	for (int c = col - 2; c < col + 3; c++)
	{
		gotoRowCol(row + 4, c);
		cout << char(-37);

	}
}
void  Knight(int row, int col, int clr)
{
	SetClr(clr);

	for (int r = row; r < row + 4; r++)
	{
		gotoRowCol(r, col);
		cout << char(-37);
	}

	gotoRowCol(row+2, col-1);
	cout << char(-37);

	gotoRowCol(row + 1, col - 2);
	cout << char(-37);

	gotoRowCol(row + 1, col - 1);
	cout << char(-37);
	gotoRowCol(row + 1, col +2);
	cout << char(-37);
	gotoRowCol(row , col - 1);
	cout << char(-37);
	gotoRowCol(row , col + 1);
	cout << char(-37);


	
		gotoRowCol(row + 2, col);
		cout << char(-37);
	


	for (int c = col - 2; c < col + 3; c++)
	{
		gotoRowCol(row + 4, c);
		cout << char(-37);

	}
}
void Rook(int row, int col, int clr) {


	SetClr(clr);




	for (int r = row; r < row + 4; r++)
	{
		gotoRowCol(r, col);
		cout << char(-37);
	}

	for (int c = col - 2; c < col + 3; c++)
	{
		gotoRowCol(row + 1, c);
		cout << char(-37);
	}


	for (int c = col - 1; c < col + 2; c++)
	{
		gotoRowCol(row + 2, c);
		cout << char(-37);

	}



	for (int c = col - 2; c < col + 3; c++)
	{
		gotoRowCol(row + 4, c);
		cout << char(-37);

	}


}

void gotoRowCol1(int rpos, int cpos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = cpos;
	scrn.Y = rpos;
	SetConsoleCursorPosition(hOuput, scrn);
}
void SetClr1(int clr)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr);
}
void getRowColbyLeftClick1(int& rpos, int& cpos)
{
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD Events;
	INPUT_RECORD InputRecord;
	SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
	do
	{
		ReadConsoleInput(hInput, &InputRecord, 1, &Events);
		if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
			rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
			break;
		}
	} while (true);
}


void  WhiteKing1(int clr, int row, int col)
{
	SetClr1(clr);

	//r=5,c=10
	for (int r = row; r < row + 5; r++)//r=row,r<row+5
	{
		gotoRowCol1(r, col);
		cout << char(-37);

	}
	for (int c = col - 1; c < col + 2; c++)
	{
		gotoRowCol1(row + 1, c);
		cout << char(-37);

	}

	for (int r = row + 3; r < row + 6; r++)
	{
		for (int c = col - 1; c < col + 2; c++)
		{
			gotoRowCol1(r, c);
			cout << char(-37);
		}

	}
	for (int c = col - 2; c < col + 3; c++)
	{
		gotoRowCol1(row + 5, c);
		cout << char(-37);

	}
}

void  Pawn1(int clr, int row, int col)
{
	SetClr1(clr);

	//r=5,c=10



	for (int r = row; r < row + 2; r++)
	{
		for (int c = col - 1; c < col + 2; c++)
		{
			gotoRowCol1(r, c);
			cout << char(-37);
		}

	}


	for (int r = row; r < row + 5; r++)//r=row,r<row+5
	{
		gotoRowCol1(r, col);

		cout << char(-37);
	}


	for (int c = col - 1; c < col + 2; c++)
	{
		gotoRowCol1(row + 4, c);
		cout << char(-37);
	}



	for (int c = col - 2; c < col + 3; c++)
	{
		gotoRowCol1(row + 5, c);
		cout << char(-37);

	}
}
void  GoldGen1(int row, int col, int clr)
{
	SetClr1(clr);

	//r=5,c=10


	gotoRowCol1(row, col - 2);
	cout << char(-37);
	gotoRowCol1(row, col);
	cout << char(-37);
	gotoRowCol1(row, col + 2);
	cout << char(-37);



	for (int c = col - 1; c < col + 2; c++)
	{
		gotoRowCol1(row + 1, c);
		cout << char(-37);
	}




	for (int r = row; r < row + 5; r++)//r=row,r<row+5
	{
		gotoRowCol1(r, col);

		cout << char(-37);
	}


	for (int c = col - 1; c < col + 2; c++)
	{
		gotoRowCol1(row + 4, c);
		cout << char(-37);
	}



	for (int c = col - 2; c < col + 3; c++)
	{
		gotoRowCol1(row + 5, c);
		cout << char(-37);

	}
}
void  silverdGen1(int row, int col, int clr)
{
	SetClr1(clr);

	//r=5,c=10


	gotoRowCol1(row, col - 2);
	cout << char(-37);

	gotoRowCol1(row, col + 2);
	cout << char(-37);



	for (int c = col - 1; c < col + 2; c++)
	{
		gotoRowCol1(row + 1, c);
		cout << char(-37);
	}




	for (int r = row + 1; r < row + 5; r++)//r=row,r<row+5
	{
		gotoRowCol1(r, col);

		cout << char(-37);
	}


	for (int c = col - 1; c < col + 2; c++)
	{
		gotoRowCol1(row + 4, c);
		cout << char(-37);
	}



	for (int c = col - 2; c < col + 3; c++)
	{
		gotoRowCol1(row + 5, c);
		cout << char(-37);

	}
}

void  Bishop1(int row, int col, int clr)
{
	SetClr1(clr);

	//r=5,c=10


	gotoRowCol1(row, col);
	cout << char(-37);


	for (int i = row + 1; i < row + 5; i++)
	{

		for (int c = col - 1; c < col + 2; c++)
		{
			gotoRowCol1(i, c);
			cout << char(-37);
		}
	}



	for (int c = col - 2; c < col + 3; c++)
	{
		gotoRowCol1(row + 5, c);
		cout << char(-37);

	}
}

void  Lance1(int row, int col, int clr)
{
	SetClr1(clr);


	for (int r = row; r < row + 4; r++)
	{
		gotoRowCol1(r, col);
		cout << char(-37);
	}

	for (int c = col - 1; c < col + 2; c++)
	{
		gotoRowCol1(row + 4, c);
		cout << char(-37);
	}


	for (int c = col - 2; c < col + 3; c++)
	{
		gotoRowCol1(row + 5, c);
		cout << char(-37);

	}
}


void Rook1(int row, int col, int clr) {


	SetClr1(clr);




	for (int r = row; r < row + 4; r++)
	{
		gotoRowCol1(r, col);
		cout << char(-37);
	}

	for (int c = col - 2; c < col + 3; c++)
	{
		gotoRowCol1(row + 1, c);
		cout << char(-37);
	}


	for (int c = col - 1; c < col + 2; c++)
	{
		gotoRowCol1(row + 2, c);
		cout << char(-37);

	}

	for (int c = col - 1; c < col + 2; c++)
	{
		gotoRowCol1(row + 4, c);
		cout << char(-37);
	}


	for (int c = col - 2; c < col + 3; c++)
	{
		gotoRowCol1(row + 5, c);
		cout << char(-37);

	}


}

void S(int row, int col)
{
	SetClr1(15);
	int s = 5;
	for (int i = 0; i < s; i++)
	{
		gotoRowCol1(row, col - i);

		cout << char(-37);
	}
	Sleep(200);
	for (int i = 0; i < s; i++)
	{
		gotoRowCol1(row + i, col - s);

		cout << char(-37);
	}
	Sleep(200);

	for (int i = 0; i < s; i++)
	{
		gotoRowCol1(row + s, col - s + i);

		cout << char(-37);
	}
	Sleep(200);

	for (int i = 0; i < s; i++)
	{
		gotoRowCol1(row + s + i, col);

		cout << char(-37);
	}
	Sleep(200);

	for (int i = 0; i <= s; i++)
	{
		gotoRowCol1(row + s + s, col - i);

		cout << char(-37);
	}
	Sleep(200);


}
void H(int row, int col)
{
	SetClr1(11);
	int s = 5;

	for (int i = 0; i <= 2 * s; i++)
	{
		gotoRowCol1(row + i, col);

		cout << char(-37);
	}
	Sleep(200);

	for (int i = 0; i <= 2 * s; i++)
	{
		gotoRowCol1(row + i, col + s);

		cout << char(-37);
	}
	Sleep(200);

	for (int i = 0; i <= s; i++)
	{
		gotoRowCol1(row + s, col + i);

		cout << char(-37);
	}
	Sleep(200);


}
void O(int row, int col)
{
	SetClr1(15);
	int s = 5;
	for (int i = 0; i <= s; i++)
	{
		gotoRowCol1(row, col + i);

		cout << char(-37);
	}
	Sleep(200);

	for (int i = 0; i <= 2 * s; i++)
	{
		gotoRowCol1(row + i, col + s);

		cout << char(-37);
	}
	Sleep(200);

	for (int i = 0; i <= s; i++)
	{
		gotoRowCol1(row + s + s, col + s - i);

		cout << char(-37);
	}
	Sleep(200);

	for (int i = 0; i <= 2 * s; i++)
	{
		gotoRowCol1(row + s + s - i, col);

		cout << char(-37);
	}
	Sleep(200);

}
void G(int row, int col)
{
	SetClr1(11);
	int s = 5;
	for (int i = 0; i <= s; i++)
	{
		gotoRowCol1(row, col + i);

		cout << char(-37);
	}
	Sleep(200);

	for (int i = 0; i <= s; i++)
	{
		gotoRowCol1(row + s + i, col + s);

		cout << char(-37);
	}
	Sleep(200);

	for (int i = 0; i < s - 2; i++)
	{
		gotoRowCol1(row + s, col + s - i);

		cout << char(-37);
	}
	Sleep(200);

	for (int i = 0; i <= s; i++)
	{
		gotoRowCol1(row + s + s, col + s - i);

		cout << char(-37);
	}
	Sleep(200);

	for (int i = 0; i <= 2 * s; i++)
	{
		gotoRowCol1(row + s + s - i, col);

		cout << char(-37);
	}
	Sleep(200);

}
void I(int row, int col)
{
	SetClr1(15);
	int s = 5;
	for (int i = 0; i <= 2 * s; i++)
	{
		gotoRowCol1(row + s + s - i, col);

		cout << char(-37);
	}
	Sleep(200);
}
void Logo()
{

	int Nrpos = 42, Ncpos = 67;
	int rpos1 = 30;
	int rpos2 = 60;
	int cpos1 = 60; int cpos2 = 60;
	int clr1 = 15, clr2 = 11;

	Pawn1(clr1, rpos1, cpos1);
	GoldGen1(rpos1, cpos1 + 6, clr1);

	silverdGen1(rpos1, cpos1 + 12, clr1);
	Bishop1(rpos1, cpos1 + 18, clr1);
	WhiteKing1(clr1, rpos1, cpos1 + 24);

	Lance1(rpos1, cpos1 + 30, clr1);
	Rook1(rpos1, cpos1 + 36, clr1);


	Pawn1(clr2, rpos2, cpos2);
	GoldGen1(rpos2, cpos2 + 6, clr2);

	silverdGen1(rpos2, cpos2 + 12, clr2);
	Bishop1(rpos2, cpos2 + 18, clr2);
	WhiteKing1(clr2, rpos2, cpos2 + 24);

	Lance1(rpos2, cpos2 + 30, clr2);
	Rook1(rpos2, cpos2 + 36, clr2);
	Sleep(300);
	S(Nrpos, Ncpos);
	H(Nrpos, Ncpos + 3);
	O(Nrpos, Ncpos + 11);
	G(Nrpos, Ncpos + 19);
	I(Nrpos, Ncpos + 27);

	Sleep(300);
	SetClr1(15);

	gotoRowCol1(73, 63);
	cout << " ABDUL MOQEET (BSCS 22147)";
	Sleep(800);
}

void HIghlightedBox(int size,int outl_clr, int rpos, int cpos)
{
	int columns =cpos, row=rpos;
	int colcopy = columns;
	for (int ri = 0; ri < size; ri++)
	{

		for (int ci = 0; ci < size; ci++)
		{
			if (ri == 0 || ci == 0 || ri == size - 1 || ci == size - 1)
			{
				SetClr(outl_clr);

				gotoRowCol(row, columns);
				cout << char(-37);
				
			}
		
			columns++;
		}
		columns = colcopy;
		row++;
		cout << endl;

	}

}
void Rectangle(int row_size, int col_size, int clr,int rpos,int cpos)
{
	int columns = cpos , row = rpos;
	int colcopy = columns;
	for (int ri = 0; ri < row_size; ri++)
	{

		for (int ci = 0; ci < col_size; ci++)
		{
			SetClr(clr);
			gotoRowCol(row, columns);
			cout << char(-37);
			columns++;
		}
		columns = colcopy;
		row++;
		cout << endl;

	}

}

void UndoLogo()
{


	int rpos = 77, cpos = 150;

	Rectangle(10, 11, 0, rpos - 3, cpos - 2);
	SetClr(15);
	for (int r = 0; r < 6; r++)
	{
		for (int c = 0; c < 9; c++)
		{
			if (r == 0 || c == 8 || r == 5)
			{
				gotoRowCol(r + rpos, c + cpos);
				cout << char(-37);
			}
		}

	}

	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			if (r == c)
			{
				gotoRowCol(r + rpos, c + cpos);
				cout << char(-37);
			}
		}

	}

	rpos = rpos - 3;
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			if (r == 4 - c - 1)
			{
				gotoRowCol(r + rpos, c + cpos);
				cout << char(-37);
			}
		}

	}


}
void decor(int sizeOfBox,int dim)
{


	int hrs = sizeOfBox + sizeOfBox / 2;
	int hcs = sizeOfBox / 2 + 44;
	for (char i = 'a'; i <= 'i'; i++)

	{
		SetClr(15);
		gotoRowCol(hrs, hcs);
		cout << i;
		hrs = hrs + sizeOfBox;

	}

	hcs = sizeOfBox + 44 + sizeOfBox / 2;
	hrs = sizeOfBox / 2;
	for (int i = 1; i <= dim; i++)

	{
		SetClr(15);
		gotoRowCol(hrs, hcs);
		cout << i;
		hcs = hcs + sizeOfBox;

	}

}
void Grid(char** B, int dim, int sizeOfBox, int clr1, int clr2)

{
	bool check = 1;
	SetClr(clr2);
	if (sizeOfBox % 2 == 0)
	{
		sizeOfBox += 1;
	}


	int p1clr=11;
	int p2clr=0;
	int prom1clr=6;
	int prom2clr=5;

	int r = 0, c = 0;
	for (int bri = sizeOfBox; bri < sizeOfBox * dim + sizeOfBox; bri += sizeOfBox)
	{
		for (int bci = sizeOfBox + 44; bci < sizeOfBox * dim + sizeOfBox + 44; bci += sizeOfBox)
		{
			for (int ri = bri; ri < bri + sizeOfBox; ri++)
			{

				for (int ci = bci; ci < bci + sizeOfBox; ci++)
				{

					if (ri == (bri + sizeOfBox / 2+3) && ci == (bci + sizeOfBox / 2+3))
					{
						if (B[r][c] != '-')
						{
							
							if (B[r][c] == 'k')
							{
								King(ri-5, ci-3,p1clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							 if (B[r][c] == 'K')
							{
								King(ri - 5, ci - 3, p2clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'p')
							{
								Pawn(ri - 5, ci - 3, p1clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'P')
							{
								Pawn(ri - 5, ci - 3, p2clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'r')
							{
								Rook(ri - 5, ci - 3, p1clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'R')
							{
								Rook(ri - 5, ci - 3, p2clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'b')
							{
								Bishop(ri - 5, ci - 3, p1clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'B')
							{
								Bishop(ri - 5, ci - 3, p2clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'l')
							{
								Lance(ri - 5, ci - 3, p1clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'L')
							{
								Lance(ri - 5, ci - 3, p2clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'g')
							{
								GoldGen(ri - 5, ci - 3, p1clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'G')
							{
								GoldGen(ri - 5, ci - 3, p2clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 's')
							{
								silverdGen(ri - 5, ci - 3, p1clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'S')
							{
								silverdGen(ri - 5, ci - 3, p2clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'n')
							{
								Knight(ri - 5, ci - 3, p1clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'N')
							{
								Knight(ri - 5, ci - 3, p2clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'f')
							{
								Knight(ri - 5, ci - 3, prom1clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'F')
							{
								Knight(ri - 5, ci - 3, prom2clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'j')
							{
								Pawn(ri - 5, ci - 3, prom1clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'J')
							{
								Pawn(ri - 5, ci - 3, prom2clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'd')
							{
								Rook(ri - 5, ci - 3, prom1clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'D')
							{
								Rook(ri - 5, ci - 3, prom2clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'h')
							{
								Bishop(ri - 5, ci - 3, prom1clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'H')
							{
								Bishop(ri - 5, ci - 3, prom2clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'm')
							{
								silverdGen(ri - 5, ci - 3, prom1clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'M')
							{
								silverdGen(ri - 5, ci - 3, prom2clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'e')
							{
								Lance(ri - 5, ci - 3, prom1clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'E')
							{
								Lance(ri - 5, ci - 3, prom2clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}

							
						}
						else

						{
						
							gotoRowCol(ri, ci);

							cout << char(-37);
						}


						if (check == 1)
							SetClr(clr2);
						else SetClr(clr1);

					}
					else

					{
						gotoRowCol(ri, ci);

						cout << char(-37);
					}



				}

			}

			if ((bri + bci) % 2 == 0)
			{
				SetClr(clr1);
				check = 0;

			}
			else
			{
				SetClr(clr2);
				check = 1;
			}
			if (c == dim - 1)
				c = 0;
			else c++;
		}

		r++;
	}

	

	cout << endl << endl << endl << endl << "\n\t\t";



}
void SourceDest(char** B,char**wt,char**bk, int dim, int sizeOfBox, int clr1, int clr2,position Sc,position Dc,int cpos2,int cpos,char destpiece,int turn)
{
	bool check = 1;
	SetClr(clr2);
	if (sizeOfBox % 2 == 0)
	{
		sizeOfBox += 1;
	}

	
	
		


		if (cpos2 >= Screen_col - (sizeOfBox * 3) && cpos2 <= Screen_col - sizeOfBox)
		{

			{
				bool check = 1;
				SetClr(clr2);
				if (sizeOfBox % 2 == 0)
				{
					sizeOfBox += 1;
				}

				int p1clr = 11;
				int p2clr = 0;

				int r = 0, c = 0;
				for (int bri = sizeOfBox; bri < sizeOfBox * dim + sizeOfBox; bri += sizeOfBox)
				{
					for (int bci = Screen_col - sizeOfBox * 3; bci < Screen_col - sizeOfBox; bci += sizeOfBox)
					{
						for (int ri = bri; ri < bri + sizeOfBox; ri++)
						{

							for (int ci = bci; ci < bci + sizeOfBox; ci++)
							{
								if(r==Sc.ri&&c==Sc.ci)
								{
									if (ri == (bri + sizeOfBox / 2 + 3) && ci == (bci + sizeOfBox / 2 + 3))
									{

										{

											if (bk[r][c] == 'k')
											{
												King(ri - 5, ci - 3, p1clr);
												if (check == 1)
													SetClr(clr2);
												else SetClr(clr1);

												gotoRowCol(ri, ci);
												cout << char(-37);
											}
											else if (bk[r][c] == 'K')
											{
												King(ri - 5, ci - 3, p2clr);
												if (check == 1)
													SetClr(clr2);
												else SetClr(clr1);
												gotoRowCol(ri, ci);
												cout << char(-37);
											}
											else if (bk[r][c] == 'p')
											{
												Pawn(ri - 5, ci - 3, p1clr);
												if (check == 1)
													SetClr(clr2);
												else SetClr(clr1);

												gotoRowCol(ri, ci);
												cout << char(-37);
											}
											else if (bk[r][c] == 'P')
											{
												Pawn(ri - 5, ci - 3, p2clr);
												if (check == 1)
													SetClr(clr2);
												else SetClr(clr1);

												gotoRowCol(ri, ci);
												cout << char(-37);
											}
											else if (bk[r][c] == 'r')
											{
												Rook(ri - 5, ci - 3, p1clr);
												if (check == 1)
													SetClr(clr2);
												else SetClr(clr1);

												gotoRowCol(ri, ci);
												cout << char(-37);
											}
											else if (bk[r][c] == 'R')
											{
												Rook(ri - 5, ci - 3, p2clr);
												if (check == 1)
													SetClr(clr2);
												else SetClr(clr1);

												gotoRowCol(ri, ci);
												cout << char(-37);
											}
											else if (bk[r][c] == 'b')
											{
												Bishop(ri - 5, ci - 3, p1clr);
												if (check == 1)
													SetClr(clr2);
												else SetClr(clr1);

												gotoRowCol(ri, ci);
												cout << char(-37);
											}
											else if (bk[r][c] == 'B')
											{
												Bishop(ri - 5, ci - 3, p2clr);
												if (check == 1)
													SetClr(clr2);
												else SetClr(clr1);
												gotoRowCol(ri, ci);
												cout << char(-37);
											}
											else if (bk[r][c] == 'l')
											{
												Lance(ri - 5, ci - 3, p1clr);
												if (check == 1)
													SetClr(clr2);
												else SetClr(clr1);
												gotoRowCol(ri, ci);
												cout << char(-37);
											}
											else if (bk[r][c] == 'L')
											{
												Lance(ri - 5, ci - 3, p2clr);
												if (check == 1)
													SetClr(clr2);
												else SetClr(clr1);

												gotoRowCol(ri, ci);
												cout << char(-37);
											}
											else if (bk[r][c] == 'g')
											{
												GoldGen(ri - 5, ci - 3, p1clr);
												if (check == 1)
													SetClr(clr2);
												else SetClr(clr1);

												gotoRowCol(ri, ci);
												cout << char(-37);
											}
											else if (bk[r][c] == 'G')
											{
												GoldGen(ri - 5, ci - 3, p2clr);
												if (check == 1)
													SetClr(clr2);
												else SetClr(clr1);
												gotoRowCol(ri, ci);
												cout << char(-37);
											}
											else if (bk[r][c] == 's')
											{
												silverdGen(ri - 5, ci - 3, p1clr);
												if (check == 1)
													SetClr(clr2);
												else SetClr(clr1);

												gotoRowCol(ri, ci);
												cout << char(-37);
											}
											else if (bk[r][c] == 'S')
											{
												silverdGen(ri - 5, ci - 3, p2clr);
												if (check == 1)
													SetClr(clr2);
												else SetClr(clr1);

												gotoRowCol(ri, ci);
												cout << char(-37);
											}
											else if (bk[r][c] == 'n')
											{
												Knight(ri - 5, ci - 3, p1clr);
												if (check == 1)
													SetClr(clr2);
												else SetClr(clr1);

												gotoRowCol(ri, ci);
												cout << char(-37);
											}
											else if (bk[r][c] == 'N')
											{
												Knight(ri - 5, ci - 3, p2clr);
												if (check == 1)
													SetClr(clr2);
												else SetClr(clr1);

												gotoRowCol(ri, ci);
												cout << char(-37);
											}

											else

											{


												gotoRowCol(ri, ci);

												cout << char(-37);
											}

										}

									}
									else

									{


										gotoRowCol(ri, ci);

										cout << char(-37);
									}
									

									if (check == 1)
										SetClr(clr2);
									else SetClr(clr1);





								}
								



							}

						}




						if (check == 1)
						{
							SetClr(clr1);
							check = 0;
						}

						else
						{
							SetClr(clr2);
							check = 1;
						}



						if (c == 1)
							c = 0;
						else c++;
					}

					swap(clr1, clr2);

					SetClr(clr2);
					check = 1;


					r++;
				}
			


			}
		}






		else if (cpos2 >= sizeOfBox && cpos2 < sizeOfBox * 3 + 1)
		{

			{
				bool check = 1;
				SetClr(clr2);
				if (sizeOfBox % 2 == 0)
				{
					sizeOfBox += 1;
				}


				int p1clr = 11;
				int p2clr = 0;


				int r = 0, c = 0;
				for (int bri = sizeOfBox; bri < sizeOfBox * dim + sizeOfBox; bri += sizeOfBox)
				{
					for (int bci = sizeOfBox; bci < sizeOfBox * 3; bci += sizeOfBox)
					{
						for (int ri = bri; ri < bri + sizeOfBox; ri++)
						{

							for (int ci = bci; ci < bci + sizeOfBox; ci++)
							{
								if (r == Sc.ri && c == Sc.ci)
								{
									if (ri == (bri + sizeOfBox / 2 + 3) && ci == (bci + sizeOfBox / 2 + 3))
									{

										{
											if (check == 1 && clr1 == 4)

												SetClr(240);
											else if (check == 0 && clr1 == 4)
												SetClr(79);

											if (check == 1 && clr1 == 15)
												SetClr(79);
											else if (check == 0 && clr1 == 15)
												SetClr(240);






											if (wt[r][c] == 'k')
											{
												King(ri - 5, ci - 3, p1clr);
												if (check == 1)
													SetClr(clr2);
												else SetClr(clr1);

												gotoRowCol(ri, ci);
												cout << char(-37);
											}
											else if (wt[r][c] == 'K')
											{
												King(ri - 5, ci - 3, p2clr);
												if (check == 1)
													SetClr(clr2);
												else SetClr(clr1);

												gotoRowCol(ri, ci);
												cout << char(-37);
											}
											if (wt[r][c] == 'p')
											{
												Pawn(ri - 5, ci - 3, p1clr);
												if (check == 1)
													SetClr(clr2);
												else SetClr(clr1);

												gotoRowCol(ri, ci);
												cout << char(-37);
											}
											if (wt[r][c] == 'P')
											{
												Pawn(ri - 5, ci - 3, p2clr);
												if (check == 1)
													SetClr(clr2);
												else SetClr(clr1);

												gotoRowCol(ri, ci);
												cout << char(-37);
											}
											if (wt[r][c] == 'r')
											{
												Rook(ri - 5, ci - 3, p1clr);
												if (check == 1)
													SetClr(clr2);
												else SetClr(clr1);
												gotoRowCol(ri, ci);
												cout << char(-37);
											}
											if (wt[r][c] == 'R')
											{
												Rook(ri - 5, ci - 3, p2clr);
												if (check == 1)
													SetClr(clr2);
												else SetClr(clr1);

												gotoRowCol(ri, ci);
												cout << char(-37);
											}
											if (wt[r][c] == 'b')
											{
												Bishop(ri - 5, ci - 3, p1clr);
												if (check == 1)
													SetClr(clr2);
												else SetClr(clr1);

												gotoRowCol(ri, ci);
												cout << char(-37);
											}
											if (wt[r][c] == 'B')
											{
												Bishop(ri - 5, ci - 3, p2clr);
												if (check == 1)
													SetClr(clr2);
												else SetClr(clr1);

												gotoRowCol(ri, ci);
												cout << char(-37);
											}
											if (wt[r][c] == 'l')
											{
												Lance(ri - 5, ci - 3, p1clr);
												if (check == 1)
													SetClr(clr2);
												else SetClr(clr1);
												gotoRowCol(ri, ci);
												cout << char(-37);
											}
											if (wt[r][c] == 'L')
											{
												Lance(ri - 5, ci - 3, p2clr);
												if (check == 1)
													SetClr(clr2);
												else SetClr(clr1);

												gotoRowCol(ri, ci);
												cout << char(-37);
											}
											if (wt[r][c] == 'g')
											{
												GoldGen(ri - 5, ci - 3, p1clr);
												if (check == 1)
													SetClr(clr2);
												else SetClr(clr1);

												gotoRowCol(ri, ci);
												cout << char(-37);
											}
											if (wt[r][c] == 'G')
											{
												GoldGen(ri - 5, ci - 3, p2clr);
												if (check == 1)
													SetClr(clr2);
												else SetClr(clr1);

												gotoRowCol(ri, ci);
												cout << char(-37);
											}
											if (wt[r][c] == 's')
											{
												silverdGen(ri - 5, ci - 3, p1clr);
												if (check == 1)
													SetClr(clr2);
												else SetClr(clr1);
												gotoRowCol(ri, ci);
												cout << char(-37);
											}
											if (wt[r][c] == 'S')
											{
												silverdGen(ri - 5, ci - 3, p2clr);
												if (check == 1)
													SetClr(clr2);
												else SetClr(clr1);

												gotoRowCol(ri, ci);
												cout << char(-37);
											}
											if (wt[r][c] == 'n')
											{
												Knight(ri - 5, ci - 3, p1clr);
												if (check == 1)
													SetClr(clr2);
												else SetClr(clr1);
												gotoRowCol(ri, ci);
												cout << char(-37);
											}
											if (wt[r][c] == 'N')
											{
												Knight(ri - 5, ci - 3, p2clr);
												if (check == 1)
													SetClr(clr2);
												else SetClr(clr1);

												gotoRowCol(ri, ci);
												cout << char(-37);
											}

										}

									}

									else
									{



										gotoRowCol(ri, ci);

										cout << char(-37);

									}
										if (check == 1)
											SetClr(clr2);
										else SetClr(clr1);

									


								}

							}

						}




						if (check == 1)
						{
							SetClr(clr1);
							check = 0;
						}

						else
						{
							SetClr(clr2);
							check = 1;
						}



						if (c == 1)
							c = 0;
						else c++;
					}

					swap(clr1, clr2);

					SetClr(clr2);
					check = 1;


					r++;
				}
			}
		}



else
{
	int p1clr = 11;
	int p2clr = 0;
	int prom1clr = 6;
	int prom2clr = 5;

	int r = 0, c = 0;
	for (int bri = sizeOfBox; bri < sizeOfBox * dim + sizeOfBox; bri += sizeOfBox)
	{
		for (int bci = sizeOfBox + 44; bci < sizeOfBox * dim + sizeOfBox + 44; bci += sizeOfBox)
		{
			for (int ri = bri; ri < bri + sizeOfBox; ri++)
			{

				for (int ci = bci; ci < bci + sizeOfBox; ci++)
				{
					if (((r == Sc.ri && c == Sc.ci) || (r == Dc.ri && c == Dc.ci)))
					{
						if (ri == (bri + sizeOfBox / 2 + 3) && ci == (bci + sizeOfBox / 2 + 3))

						{

							if (B[r][c] == 'k')
							{
								King(ri - 5, ci - 3, p1clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'K')
							{
								King(ri - 5, ci - 3, p2clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'p')
							{
								Pawn(ri - 5, ci - 3, p1clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'P')
							{
								Pawn(ri - 5, ci - 3, p2clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'r')
							{
								Rook(ri - 5, ci - 3, p1clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'R')
							{
								Rook(ri - 5, ci - 3, p2clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'b')
							{
								Bishop(ri - 5, ci - 3, p1clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'B')
							{
								Bishop(ri - 5, ci - 3, p2clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'l')
							{
								Lance(ri - 5, ci - 3, p1clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'L')
							{
								Lance(ri - 5, ci - 3, p2clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'g')
							{
								GoldGen(ri - 5, ci - 3, p1clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'G')
							{
								GoldGen(ri - 5, ci - 3, p2clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 's')
							{
								silverdGen(ri - 5, ci - 3, p1clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'S')
							{
								silverdGen(ri - 5, ci - 3, p2clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'n')
							{
								Knight(ri - 5, ci - 3, p1clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'N')
							{
								Knight(ri - 5, ci - 3, p2clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'f')
							{
								Knight(ri - 5, ci - 3, prom1clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'F')
							{
								Knight(ri - 5, ci - 3, prom2clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'j')
							{
								Pawn(ri - 5, ci - 3, prom1clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'J')
							{
								Pawn(ri - 5, ci - 3, prom2clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'd')
							{
								Rook(ri - 5, ci - 3, prom1clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'D')
							{
								Rook(ri - 5, ci - 3, prom2clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'h')
							{
								Bishop(ri - 5, ci - 3, prom1clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'H')
							{
								Bishop(ri - 5, ci - 3, prom2clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'm')
							{
								silverdGen(ri - 5, ci - 3, prom1clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'M')
							{
								silverdGen(ri - 5, ci - 3, prom2clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'e')
							{
								Lance(ri - 5, ci - 3, prom1clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (B[r][c] == 'E')
							{
								Lance(ri - 5, ci - 3, prom2clr);
								if (check == 1)
									SetClr(15);
								if (check == 0)
									SetClr(8);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}


						}
						else

						{

							gotoRowCol(ri, ci);

							cout << char(-37);
						}


						if (check == 1)
							SetClr(clr2);
						else SetClr(clr1);

					}




				}

			}

			if ((bri + bci) % 2 == 0)
			{
				SetClr(clr1);
				check = 0;

			}
			else
			{
				SetClr(clr2);
				check = 1;
			}
			if (c == dim - 1)
				c = 0;
			else c++;
		}

		r++;
	}

	if (destpiece != '-')
	{


		if (turn == white)
		{

			{

				{
					bool check = 1;
					SetClr(clr2);
					if (sizeOfBox % 2 == 0)
					{
						sizeOfBox += 1;
					}


					int p1clr = 11;
					int p2clr = 0;


					int r = 0, c = 0;
					for (int bri = sizeOfBox; bri < sizeOfBox * dim + sizeOfBox; bri += sizeOfBox)
					{
						for (int bci = sizeOfBox; bci < sizeOfBox * 3; bci += sizeOfBox)
						{
							for (int ri = bri; ri < bri + sizeOfBox; ri++)
							{

								for (int ci = bci; ci < bci + sizeOfBox; ci++)
								{
									if (wt[r][c]!='-')
									{
										if (ri == (bri + sizeOfBox / 2 + 3) && ci == (bci + sizeOfBox / 2 + 3))
										{

											{
												if (check == 1 && clr1 == 4)

													SetClr(240);
												else if (check == 0 && clr1 == 4)
													SetClr(79);

												if (check == 1 && clr1 == 15)
													SetClr(79);
												else if (check == 0 && clr1 == 15)
													SetClr(240);






												if (wt[r][c] == 'k')
												{
													King(ri - 5, ci - 3, p1clr);
													if (check == 1)
														SetClr(clr2);
													else SetClr(clr1);

													gotoRowCol(ri, ci);
													cout << char(-37);
												}
												else if (wt[r][c] == 'K')
												{
													King(ri - 5, ci - 3, p2clr);
													if (check == 1)
														SetClr(clr2);
													else SetClr(clr1);

													gotoRowCol(ri, ci);
													cout << char(-37);
												}
												if (wt[r][c] == 'p')
												{
													Pawn(ri - 5, ci - 3, p1clr);
													if (check == 1)
														SetClr(clr2);
													else SetClr(clr1);

													gotoRowCol(ri, ci);
													cout << char(-37);
												}
												if (wt[r][c] == 'P')
												{
													Pawn(ri - 5, ci - 3, p2clr);
													if (check == 1)
														SetClr(clr2);
													else SetClr(clr1);

													gotoRowCol(ri, ci);
													cout << char(-37);
												}
												if (wt[r][c] == 'r')
												{
													Rook(ri - 5, ci - 3, p1clr);
													if (check == 1)
														SetClr(clr2);
													else SetClr(clr1);
													gotoRowCol(ri, ci);
													cout << char(-37);
												}
												if (wt[r][c] == 'R')
												{
													Rook(ri - 5, ci - 3, p2clr);
													if (check == 1)
														SetClr(clr2);
													else SetClr(clr1);

													gotoRowCol(ri, ci);
													cout << char(-37);
												}
												if (wt[r][c] == 'b')
												{
													Bishop(ri - 5, ci - 3, p1clr);
													if (check == 1)
														SetClr(clr2);
													else SetClr(clr1);

													gotoRowCol(ri, ci);
													cout << char(-37);
												}
												if (wt[r][c] == 'B')
												{
													Bishop(ri - 5, ci - 3, p2clr);
													if (check == 1)
														SetClr(clr2);
													else SetClr(clr1);

													gotoRowCol(ri, ci);
													cout << char(-37);
												}
												if (wt[r][c] == 'l')
												{
													Lance(ri - 5, ci - 3, p1clr);
													if (check == 1)
														SetClr(clr2);
													else SetClr(clr1);
													gotoRowCol(ri, ci);
													cout << char(-37);
												}
												if (wt[r][c] == 'L')
												{
													Lance(ri - 5, ci - 3, p2clr);
													if (check == 1)
														SetClr(clr2);
													else SetClr(clr1);

													gotoRowCol(ri, ci);
													cout << char(-37);
												}
												if (wt[r][c] == 'g')
												{
													GoldGen(ri - 5, ci - 3, p1clr);
													if (check == 1)
														SetClr(clr2);
													else SetClr(clr1);

													gotoRowCol(ri, ci);
													cout << char(-37);
												}
												if (wt[r][c] == 'G')
												{
													GoldGen(ri - 5, ci - 3, p2clr);
													if (check == 1)
														SetClr(clr2);
													else SetClr(clr1);

													gotoRowCol(ri, ci);
													cout << char(-37);
												}
												if (wt[r][c] == 's')
												{
													silverdGen(ri - 5, ci - 3, p1clr);
													if (check == 1)
														SetClr(clr2);
													else SetClr(clr1);
													gotoRowCol(ri, ci);
													cout << char(-37);
												}
												if (wt[r][c] == 'S')
												{
													silverdGen(ri - 5, ci - 3, p2clr);
													if (check == 1)
														SetClr(clr2);
													else SetClr(clr1);

													gotoRowCol(ri, ci);
													cout << char(-37);
												}
												if (wt[r][c] == 'n')
												{
													Knight(ri - 5, ci - 3, p1clr);
													if (check == 1)
														SetClr(clr2);
													else SetClr(clr1);
													gotoRowCol(ri, ci);
													cout << char(-37);
												}
												if (wt[r][c] == 'N')
												{
													Knight(ri - 5, ci - 3, p2clr);
													if (check == 1)
														SetClr(clr2);
													else SetClr(clr1);

													gotoRowCol(ri, ci);
													cout << char(-37);
												}

											}

										}


										if (check == 1)
											SetClr(clr2);
										else SetClr(clr1);

									}
									else

									{


										gotoRowCol(ri, ci);

										cout << char(-37);
									}



								}

							}




							if (check == 1)
							{
								SetClr(clr1);
								check = 0;
							}

							else
							{
								SetClr(clr2);
								check = 1;
							}



							if (c == 1)
								c = 0;
							else c++;
						}

						swap(clr1, clr2);

						SetClr(clr2);
						check = 1;


						r++;
					}
				}
			}





		}



		if(turn==black) {

			{

				{
					bool check = 1;
					SetClr(clr2);
					if (sizeOfBox % 2 == 0)
					{
						sizeOfBox += 1;
					}

					int p1clr = 11;
					int p2clr = 0;

					int r = 0, c = 0;
					for (int bri = sizeOfBox; bri < sizeOfBox * dim + sizeOfBox; bri += sizeOfBox)
					{
						for (int bci = Screen_col - sizeOfBox * 3; bci < Screen_col - sizeOfBox; bci += sizeOfBox)
						{
							for (int ri = bri; ri < bri + sizeOfBox; ri++)
							{

								for (int ci = bci; ci < bci + sizeOfBox; ci++)
								{
									if (bk[r][c]!='-')
									{
										if (ri == (bri + sizeOfBox / 2 + 3) && ci == (bci + sizeOfBox / 2 + 3))
										{

											{

												if (bk[r][c] == 'k')
												{
													King(ri - 5, ci - 3, p1clr);
													if (check == 1)
														SetClr(clr2);
													else SetClr(clr1);

													gotoRowCol(ri, ci);
													cout << char(-37);
												}
												else if (bk[r][c] == 'K')
												{
													King(ri - 5, ci - 3, p2clr);
													if (check == 1)
														SetClr(clr2);
													else SetClr(clr1);
													gotoRowCol(ri, ci);
													cout << char(-37);
												}
												else if (bk[r][c] == 'p')
												{
													Pawn(ri - 5, ci - 3, p1clr);
													if (check == 1)
														SetClr(clr2);
													else SetClr(clr1);

													gotoRowCol(ri, ci);
													cout << char(-37);
												}
												else if (bk[r][c] == 'P')
												{
													Pawn(ri - 5, ci - 3, p2clr);
													if (check == 1)
														SetClr(clr2);
													else SetClr(clr1);

													gotoRowCol(ri, ci);
													cout << char(-37);
												}
												else if (bk[r][c] == 'r')
												{
													Rook(ri - 5, ci - 3, p1clr);
													if (check == 1)
														SetClr(clr2);
													else SetClr(clr1);

													gotoRowCol(ri, ci);
													cout << char(-37);
												}
												else if (bk[r][c] == 'R')
												{
													Rook(ri - 5, ci - 3, p2clr);
													if (check == 1)
														SetClr(clr2);
													else SetClr(clr1);

													gotoRowCol(ri, ci);
													cout << char(-37);
												}
												else if (bk[r][c] == 'b')
												{
													Bishop(ri - 5, ci - 3, p1clr);
													if (check == 1)
														SetClr(clr2);
													else SetClr(clr1);

													gotoRowCol(ri, ci);
													cout << char(-37);
												}
												else if (bk[r][c] == 'B')
												{
													Bishop(ri - 5, ci - 3, p2clr);
													if (check == 1)
														SetClr(clr2);
													else SetClr(clr1);
													gotoRowCol(ri, ci);
													cout << char(-37);
												}
												else if (bk[r][c] == 'l')
												{
													Lance(ri - 5, ci - 3, p1clr);
													if (check == 1)
														SetClr(clr2);
													else SetClr(clr1);
													gotoRowCol(ri, ci);
													cout << char(-37);
												}
												else if (bk[r][c] == 'L')
												{
													Lance(ri - 5, ci - 3, p2clr);
													if (check == 1)
														SetClr(clr2);
													else SetClr(clr1);

													gotoRowCol(ri, ci);
													cout << char(-37);
												}
												else if (bk[r][c] == 'g')
												{
													GoldGen(ri - 5, ci - 3, p1clr);
													if (check == 1)
														SetClr(clr2);
													else SetClr(clr1);

													gotoRowCol(ri, ci);
													cout << char(-37);
												}
												else if (bk[r][c] == 'G')
												{
													GoldGen(ri - 5, ci - 3, p2clr);
													if (check == 1)
														SetClr(clr2);
													else SetClr(clr1);
													gotoRowCol(ri, ci);
													cout << char(-37);
												}
												else if (bk[r][c] == 's')
												{
													silverdGen(ri - 5, ci - 3, p1clr);
													if (check == 1)
														SetClr(clr2);
													else SetClr(clr1);

													gotoRowCol(ri, ci);
													cout << char(-37);
												}
												else if (bk[r][c] == 'S')
												{
													silverdGen(ri - 5, ci - 3, p2clr);
													if (check == 1)
														SetClr(clr2);
													else SetClr(clr1);

													gotoRowCol(ri, ci);
													cout << char(-37);
												}
												else if (bk[r][c] == 'n')
												{
													Knight(ri - 5, ci - 3, p1clr);
													if (check == 1)
														SetClr(clr2);
													else SetClr(clr1);

													gotoRowCol(ri, ci);
													cout << char(-37);
												}
												else if (bk[r][c] == 'N')
												{
													Knight(ri - 5, ci - 3, p2clr);
													if (check == 1)
														SetClr(clr2);
													else SetClr(clr1);

													gotoRowCol(ri, ci);
													cout << char(-37);
												}


											}

										}


										if (check == 1)
											SetClr(clr2);
										else SetClr(clr1);

									}
									else

									{


										gotoRowCol(ri, ci);

										cout << char(-37);
									}



								}

							}




							if (check == 1)
							{
								SetClr(clr1);
								check = 0;
							}

							else
							{
								SetClr(clr2);
								check = 1;
							}



							if (c == 1)
								c = 0;
							else c++;
						}

						swap(clr1, clr2);

						SetClr(clr2);
						check = 1;


						r++;
					}



				}
			}
		}



	}



}


if ((((cpos2 >= Screen_col - (sizeOfBox * 3) && cpos2 <= Screen_col - sizeOfBox)) || (cpos2 >= sizeOfBox && cpos2 < sizeOfBox * 3 + 1)) && ((cpos >= sizeOfBox + 44) && (cpos <= sizeOfBox * dim + sizeOfBox + 44)))
{
	int p1clr = 11;
	int p2clr = 0;
	int prom1clr = 6;
	int prom2clr = 5;
	int clr1 = 15; int clr2 = 8;

	int r = 0, c = 0;
	for (int bri = sizeOfBox; bri < sizeOfBox * dim + sizeOfBox; bri += sizeOfBox)
	{
		for (int bci = sizeOfBox + 44; bci < sizeOfBox * dim + sizeOfBox + 44; bci += sizeOfBox)
		{
			for (int ri = bri; ri < bri + sizeOfBox; ri++)
			{

				for (int ci = bci; ci < bci + sizeOfBox; ci++)
				{
					if (( (r == Dc.ri && c == Dc.ci)))
					{
						if (ri == (bri + sizeOfBox / 2 + 3) && ci == (bci + sizeOfBox / 2 + 3))

						{

							if (B[r][c] == 'k')
							{
								
								King(ri - 5, ci - 3, p1clr);
								if (check == 1)
									SetClr(clr1);
								if (check == 0)
									SetClr(clr2);

								gotoRowCol(ri, ci);
								cout << char(-37);
								gotoRowCol(bri, bci);
								cout << char(-37);
							}
							if (B[r][c] == 'K')
							{
								King(ri - 5, ci - 3, p2clr);
								if (check == 1)
									SetClr(clr1);
								if (check == 0)
									SetClr(clr2);

								gotoRowCol(ri, ci);
								cout << char(-37);
								gotoRowCol(bri, bci);
								cout << char(-37);
							}
							if (B[r][c] == 'p')
							{
								Pawn(ri - 5, ci - 3, p1clr);
								if (check == 1)
									SetClr(clr1);
								if (check == 0)
									SetClr(clr2);

								gotoRowCol(ri, ci);
								cout << char(-37);
								gotoRowCol(bri, bci);
								cout << char(-37);
							}
							if (B[r][c] == 'P')
							{
								Pawn(ri - 5, ci - 3, p2clr);
								if (check == 1)
									SetClr(clr1);
								if (check == 0)
									SetClr(clr2);

								gotoRowCol(ri, ci);
								cout << char(-37);
								gotoRowCol(bri, bci);
								cout << char(-37);
							}
							if (B[r][c] == 'r')
							{
								Rook(ri - 5, ci - 3, p1clr);
								if (check == 1)
									SetClr(clr1);
								if (check == 0)
									SetClr(clr2);

								gotoRowCol(ri, ci);
								cout << char(-37);
								gotoRowCol(bri, bci);
								cout << char(-37);
							}
							if (B[r][c] == 'R')
							{
								Rook(ri - 5, ci - 3, p2clr);
								if (check == 1)
									SetClr(clr1);
								if (check == 0)
									SetClr(clr2);

								gotoRowCol(ri, ci);
								cout << char(-37);
								gotoRowCol(bri, bci);
								cout << char(-37);
							}
							if (B[r][c] == 'b')
							{
								
								Bishop(ri - 5, ci - 3, p1clr);
								if (check == 1)
									SetClr(clr1);
								if (check == 0)
									SetClr(clr2);

								gotoRowCol(ri, ci);
								cout << char(-37);
								gotoRowCol(bri, bci);
								cout << char(-37);
								

							}
							if (B[r][c] == 'B')
							{
								Bishop(ri - 5, ci - 3, p2clr);
								if (check == 1)
									SetClr(clr1);
								if (check == 0)
									SetClr(clr2);

								gotoRowCol(ri, ci);
								cout << char(-37);
								gotoRowCol(bri, bci);
								cout << char(-37);
							}
							if (B[r][c] == 'l')
							{
								Lance(ri - 5, ci - 3, p1clr);
								if (check == 1)
									SetClr(clr1);
								if (check == 0)
									SetClr(clr2);
								gotoRowCol(ri, ci);
								cout << char(-37);
								gotoRowCol(bri, bci);
								cout << char(-37);
							}
							if (B[r][c] == 'L')
							{
								Lance(ri - 5, ci - 3, p2clr);
								if (check == 1)
									SetClr(clr1);
								if (check == 0)
									SetClr(clr2);

								gotoRowCol(ri, ci);
								cout << char(-37);
								gotoRowCol(bri, bci);
								cout << char(-37);
							}
							if (B[r][c] == 'g')
							{
								GoldGen(ri - 5, ci - 3, p1clr);
								if (check == 1)
									SetClr(clr1);
								if (check == 0)
									SetClr(clr2);

								gotoRowCol(ri, ci);
								cout << char(-37);
								gotoRowCol(bri, bci);
								cout << char(-37);
							}
							if (B[r][c] == 'G')
							{
								GoldGen(ri - 5, ci - 3, p2clr);
								if (check == 1)
									SetClr(clr1);
								if (check == 0)
									SetClr(clr2);

								gotoRowCol(ri, ci);
								cout << char(-37);
								gotoRowCol(bri, bci);
								cout << char(-37);
							}
							if (B[r][c] == 's')
							{
								silverdGen(ri - 5, ci - 3, p1clr);
								if (check == 1)
									SetClr(clr1);
								if (check == 0)
									SetClr(clr2);

								gotoRowCol(ri, ci);
								cout << char(-37);
								gotoRowCol(bri, bci);
								cout << char(-37);
							}
							if (B[r][c] == 'S')
							{
								silverdGen(ri - 5, ci - 3, p2clr);
								if (check == 1)
									SetClr(clr1);
								if (check == 0)
									SetClr(clr2);

								gotoRowCol(ri, ci);
								cout << char(-37);
								gotoRowCol(bri, bci);
								cout << char(-37);
							}
							if (B[r][c] == 'n')
							{
								Knight(ri - 5, ci - 3, p1clr);
								if (check == 1)
									SetClr(clr1);
								if (check == 0)
									SetClr(clr2);

								gotoRowCol(ri, ci);
								cout << char(-37);
								gotoRowCol(bri, bci);
								cout << char(-37);
							}
							if (B[r][c] == 'N')
							{
								Knight(ri - 5, ci - 3, p2clr);
								if (check == 1)
									SetClr(clr1);
								if (check == 0)
									SetClr(clr2);

								gotoRowCol(ri, ci);
								cout << char(-37);
								gotoRowCol(bri, bci);
								cout << char(-37);
							}
							if (B[r][c] == 'f')
							{
								Knight(ri - 5, ci - 3, prom1clr);
								if (check == 1)
									SetClr(clr1);
								if (check == 0)
									SetClr(clr2);

								gotoRowCol(ri, ci);
								cout << char(-37);
								gotoRowCol(bri, bci);
								cout << char(-37);
							}
							if (B[r][c] == 'F')
							{
								Knight(ri - 5, ci - 3, prom2clr);
								if (check == 1)
									SetClr(clr1);
								if (check == 0)
									SetClr(clr2);
								gotoRowCol(ri, ci);
								cout << char(-37);
								gotoRowCol(bri, bci);
								cout << char(-37);
							}
							if (B[r][c] == 'j')
							{
								Pawn(ri - 5, ci - 3, prom1clr);
								if (check == 1)
									SetClr(clr1);
								if (check == 0)
									SetClr(clr2);

								gotoRowCol(ri, ci);
								cout << char(-37);
								gotoRowCol(bri, bci);
								cout << char(-37);
							}
							if (B[r][c] == 'J')
							{
								Pawn(ri - 5, ci - 3, prom2clr);
								if (check == 1)
									SetClr(clr1);
								if (check == 0)
									SetClr(clr2);

								gotoRowCol(ri, ci);
								cout << char(-37);
								gotoRowCol(bri, bci);
								cout << char(-37);
							}
							if (B[r][c] == 'd')
							{
								Rook(ri - 5, ci - 3, prom1clr);
								if (check == 1)
									SetClr(clr1);
								if (check == 0)
									SetClr(clr2);

								gotoRowCol(ri, ci);
								cout << char(-37);
								gotoRowCol(bri, bci);
								cout << char(-37);
							}
							if (B[r][c] == 'D')
							{
								Rook(ri - 5, ci - 3, prom2clr);
								if (check == 1)
									SetClr(clr1);
								if (check == 0)
									SetClr(clr2);

								gotoRowCol(ri, ci);
								cout << char(-37);
								gotoRowCol(bri, bci);
								cout << char(-37);
							}
							if (B[r][c] == 'h')
							{
								Bishop(ri - 5, ci - 3, prom1clr);
								if (check == 1)
									SetClr(clr1);
								if (check == 0)
									SetClr(clr2);

								gotoRowCol(ri, ci);
								cout << char(-37);
								gotoRowCol(bri, bci);
								cout << char(-37);
							}
							if (B[r][c] == 'H')
							{
								Bishop(ri - 5, ci - 3, prom2clr);
								if (check == 1)
									SetClr(clr1);
								if (check == 0)
									SetClr(clr2);

								gotoRowCol(ri, ci);
								cout << char(-37);
								gotoRowCol(bri, bci);
								cout << char(-37);
							}
							if (B[r][c] == 'm')
							{
								silverdGen(ri - 5, ci - 3, prom1clr);
								if (check == 1)
									SetClr(clr1);
								if (check == 0)
									SetClr(clr2);

								gotoRowCol(ri, ci);
								cout << char(-37);
								gotoRowCol(bri, bci);
								cout << char(-37);
							}
							if (B[r][c] == 'M')
							{
								silverdGen(ri - 5, ci - 3, prom2clr);
								if (check == 1)
									SetClr(clr1);
								if (check == 0)
									SetClr(clr2);

								gotoRowCol(ri, ci);
								cout << char(-37);
								gotoRowCol(bri, bci);
								cout << char(-37);
							}
							if (B[r][c] == 'e')
							{
								Lance(ri - 5, ci - 3, prom1clr);
								if (check == 1)
									SetClr(clr1);
								if (check == 0)
									SetClr(clr2);

								gotoRowCol(ri, ci);
								cout << char(-37);
								gotoRowCol(bri, bci);
								cout << char(-37);
							}
							if (B[r][c] == 'E')
							{
								Lance(ri - 5, ci - 3, prom2clr);
								if (check == 1)
									SetClr(clr1);
								if (check == 0)
									SetClr(clr2);

								gotoRowCol(ri, ci);
								cout << char(-37);
								gotoRowCol(bri, bci);
								cout << char(-37);
							}


						}
						else

						{

							gotoRowCol(ri, ci);

							cout << char(-37);
						}


						if (check == 1)
							SetClr(clr1);
						else SetClr(clr2);

					}




				}

			}

			if ((bri + bci) % 2 == 0)
			{
				SetClr(clr1);
				check = 0;

			}
			else
			{
				SetClr(clr2);
				check = 1;
			}
			if (c == dim - 1)
				c = 0;
			else c++;
		}

		r++;
	}

}


}
void whiteGrid(char** wt, int dim, int sizeOfBox, int clr1, int clr2)
{
	bool check = 1;
	SetClr(clr2);
	if (sizeOfBox % 2 == 0)
	{
		sizeOfBox += 1;
	}


	int p1clr = 11;
	int p2clr = 0;
	

	int r = 0, c = 0;
	for (int bri = sizeOfBox; bri < sizeOfBox * dim + sizeOfBox; bri += sizeOfBox)
	{
		for (int bci = sizeOfBox; bci < sizeOfBox * 3; bci += sizeOfBox)
		{
			for (int ri = bri; ri < bri + sizeOfBox; ri++)
			{

				for (int ci = bci; ci < bci + sizeOfBox; ci++)
				{

					if (ri == (bri + sizeOfBox / 2+3) && ci == (bci + sizeOfBox / 2+3))
					{
						if (wt[r][c] != '-')
						{
							if (check == 1 && clr1 == 4)

								SetClr(240);
							else if(check==0 && clr1 == 4)
								SetClr(79);

							if (check == 1 && clr1 == 15)
								SetClr(79);
							else if (check == 0 && clr1 == 15)
								SetClr(240);

						


							

							if (wt[r][c] == 'k')
							{
								King(ri - 5, ci - 3, p1clr);
								if (check == 1)
									SetClr(clr2);
								else SetClr(clr1);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							else if (wt[r][c] == 'K')
							{
								King(ri - 5, ci - 3, p2clr);
								if (check == 1)
									SetClr(clr2);
								else SetClr(clr1);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (wt[r][c] == 'p')
							{
								Pawn(ri - 5, ci - 3, p1clr);
								if (check == 1)
									SetClr(clr2);
								else SetClr(clr1);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (wt[r][c] == 'P')
							{
								Pawn(ri - 5, ci - 3, p2clr);
								if (check == 1)
									SetClr(clr2);
								else SetClr(clr1);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (wt[r][c] == 'r')
							{
								Rook(ri - 5, ci - 3, p1clr);
								if (check == 1)
									SetClr(clr2);
								else SetClr(clr1);
								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (wt[r][c] == 'R')
							{
								Rook(ri - 5, ci - 3, p2clr);
								if (check == 1)
									SetClr(clr2);
								else SetClr(clr1);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (wt[r][c] == 'b')
							{
								Bishop(ri - 5, ci - 3, p1clr);
								if (check == 1)
									SetClr(clr2);
								else SetClr(clr1);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (wt[r][c] == 'B')
							{
								Bishop(ri - 5, ci - 3, p2clr);
								if (check == 1)
									SetClr(clr2);
								else SetClr(clr1);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (wt[r][c] == 'l')
							{
								Lance(ri - 5, ci - 3, p1clr);
								if (check == 1)
									SetClr(clr2);
								else SetClr(clr1);
								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (wt[r][c] == 'L')
							{
								Lance(ri - 5, ci - 3, p2clr);
								if (check == 1)
									SetClr(clr2);
								else SetClr(clr1);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (wt[r][c] == 'g')
							{
								GoldGen(ri - 5, ci - 3, p1clr);
								if (check == 1)
									SetClr(clr2);
								else SetClr(clr1);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (wt[r][c] == 'G')
							{
								GoldGen(ri - 5, ci - 3, p2clr);
								if (check == 1)
									SetClr(clr2);
								else SetClr(clr1);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (wt[r][c] == 's')
							{
								silverdGen(ri - 5, ci - 3, p1clr);
								if (check == 1)
									SetClr(clr2);
								else SetClr(clr1);
								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (wt[r][c] == 'S')
							{
								silverdGen(ri - 5, ci - 3, p2clr);
								if (check == 1)
									SetClr(clr2);
								else SetClr(clr1);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (wt[r][c] == 'n')
							{
								Knight(ri - 5, ci - 3, p1clr);
								if (check == 1)
									SetClr(clr2);
								else SetClr(clr1);
								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							if (wt[r][c] == 'N')
							{
								Knight(ri - 5, ci - 3, p2clr);
								if (check == 1)
									SetClr(clr2);
								else SetClr(clr1);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							
						}
						else

						{
							gotoRowCol(ri, ci);

							cout << char(-37);
						}


						if (check == 1)
							SetClr(clr2);
						else SetClr(clr1);

					}
					else

					{


						gotoRowCol(ri, ci);

						cout << char(-37);
					}



				}

			}



			
			if (check == 1)
			{
				SetClr(clr1);
				check = 0;
			}

			else 
			{
				SetClr(clr2);
				check = 1;
			}


			
			if (c == 1)
				c = 0;
			else c++;
		}

		swap(clr1, clr2);

		SetClr(clr2);
		check = 1;
		
		
		r++;
	}
}
void blackGrid(char** bk, int dim, int sizeOfBox, int clr1, int clr2)
{
	bool check = 1;
	SetClr(clr2);
	if (sizeOfBox % 2 == 0)
	{
		sizeOfBox += 1;
	}

	int p1clr = 11;
	int p2clr = 0;

	int r = 0, c = 0;
	for (int bri = sizeOfBox; bri < sizeOfBox * dim + sizeOfBox; bri += sizeOfBox)
	{
		for (int bci = Screen_col-sizeOfBox*3; bci < Screen_col -sizeOfBox ; bci += sizeOfBox)
		{
			for (int ri = bri; ri < bri + sizeOfBox; ri++)
			{

				for (int ci = bci; ci < bci + sizeOfBox; ci++)
				{

					if (ri == (bri + sizeOfBox / 2+3) && ci == (bci + sizeOfBox / 2+3))
					{
						if (bk[r][c] != '-')
						{
							
							if (bk[r][c] == 'k')
							{
								King(ri - 5, ci - 3, p1clr);
								if (check == 1)
									SetClr(clr2);
								else SetClr(clr1);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							else if (bk[r][c] == 'K')
							{
								King(ri - 5, ci - 3, p2clr);
								if (check == 1)
									SetClr(clr2);
								else SetClr(clr1);
								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							else if (bk[r][c] == 'p')
							{
								Pawn(ri - 5, ci - 3, p1clr);
								if (check == 1)
									SetClr(clr2);
								else SetClr(clr1);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							else if (bk[r][c] == 'P')
							{
								Pawn(ri - 5, ci - 3, p2clr);
								if (check == 1)
									SetClr(clr2);
								else SetClr(clr1);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							else if (bk[r][c] == 'r')
							{
								Rook(ri - 5, ci - 3, p1clr);
								if (check == 1)
									SetClr(clr2);
								else SetClr(clr1);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							else if (bk[r][c] == 'R')
							{
								Rook(ri - 5, ci - 3, p2clr);
								if (check == 1)
									SetClr(clr2);
								else SetClr(clr1);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							else if (bk[r][c] == 'b')
							{
								Bishop(ri - 5, ci - 3, p1clr);
								if (check == 1)
									SetClr(clr2);
								else SetClr(clr1);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							else if (bk[r][c] == 'B')
							{
								Bishop(ri - 5, ci - 3, p2clr);
								if (check == 1)
									SetClr(clr2);
								else SetClr(clr1);
								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							else if (bk[r][c] == 'l')
							{
								Lance(ri - 5, ci - 3, p1clr);
								if (check == 1)
									SetClr(clr2);
								else SetClr(clr1);
								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							else if (bk[r][c] == 'L')
							{
								Lance(ri - 5, ci - 3, p2clr);
								if (check == 1)
									SetClr(clr2);
								else SetClr(clr1);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							else if (bk[r][c] == 'g')
							{
								GoldGen(ri - 5, ci - 3, p1clr);
								if (check == 1)
									SetClr(clr2);
								else SetClr(clr1);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							else if (bk[r][c] == 'G')
							{
								GoldGen(ri - 5, ci - 3, p2clr);
								if (check == 1)
									SetClr(clr2);
								else SetClr(clr1);
								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							else if (bk[r][c] == 's')
							{
								silverdGen(ri - 5, ci - 3, p1clr);
								if (check == 1)
									SetClr(clr2);
								else SetClr(clr1);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							else if (bk[r][c] == 'S')
							{
								silverdGen(ri - 5, ci - 3, p2clr);
								if (check == 1)
									SetClr(clr2);
								else SetClr(clr1);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							else if (bk[r][c] == 'n')
							{
								Knight(ri - 5, ci - 3, p1clr);
								if (check == 1)
									SetClr(clr2);
								else SetClr(clr1);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}
							else if (bk[r][c] == 'N')
							{
								Knight(ri - 5, ci - 3, p2clr);
								if (check == 1)
									SetClr(clr2);
								else SetClr(clr1);

								gotoRowCol(ri, ci);
								cout << char(-37);
							}

							
						}
						else

						{
							gotoRowCol(ri, ci);

							cout << char(-37);
						}


						if (check == 1)
							SetClr(clr2);
						else SetClr(clr1);

					}
					else

					{


						gotoRowCol(ri, ci);

						cout << char(-37);
					}



				}

			}




			if (check == 1)
			{
				SetClr(clr1);
				check = 0;
			}

			else
			{
				SetClr(clr2);
				check = 1;
			}



			if (c == 1)
				c = 0;
			else c++;
		}

		swap(clr1, clr2);

		SetClr(clr2);
		check = 1;


		r++;
	}
}
void highlightCages( int dim, int sizeOfBox, int clr1, int clr2, position Sc, int cpos)
{
	bool check = 1;
	SetClr(clr2);
	if (sizeOfBox % 2 == 0)
	{
		sizeOfBox += 1;
	}



	if (cpos >= Screen_col - (sizeOfBox * 3) && cpos <= Screen_col - sizeOfBox)
	{
		int r = 0, c = 0;

		for (int bri = sizeOfBox; bri < sizeOfBox * dim + sizeOfBox; bri += sizeOfBox)
		{
			for (int bci = Screen_col - sizeOfBox * 3; bci < Screen_col - sizeOfBox; bci += sizeOfBox)
			{
				for (int ri = bri; ri < bri + sizeOfBox; ri++)
				{

					for (int ci = bci; ci < bci + sizeOfBox; ci++)
					{

						if ((r == Sc.ri && c == Sc.ci))
						{
							HIghlightedBox(sizeOfBox, 2, ri, ci);
							check = 0;
							break;
						}


				
					}

					if (check == 0)
						break;
				
				}

				if (check == 0)
					break;

				if (c == 1)
					c = 0;
				else c++;
			}

			if (check == 0)
				break;

			r++;
		}
	}






	if (cpos >= sizeOfBox && cpos < sizeOfBox * 3 + 1)
	{
		bool check = 1;
		int r = 0, c = 0;
		for (int bri = sizeOfBox; bri < sizeOfBox * dim + sizeOfBox; bri += sizeOfBox)
		{
			for (int bci = sizeOfBox; bci < sizeOfBox * 3; bci += sizeOfBox)
			{
				for (int ri = bri; ri < bri + sizeOfBox; ri++)
				{

					for (int ci = bci; ci < bci + sizeOfBox; ci++)
					{

						if (r == Sc.ri && c == Sc.ci)
						{
							HIghlightedBox(sizeOfBox, 2, ri, ci);
							
							check = 0;
							break;
						}


					}


					if (check == 0)
						break;
				}

				if (check == 0)
					break;
				if (c == 1)
					c = 0;
				else c++;
			}

			if (check == 0)
				break;

			r++;

		}
	}

}
void UnhighlightCages(int dim, int sizeOfBox, int clr1, int clr2, position Sc, int cpos)
{
	
	SetClr(clr2);
	if (sizeOfBox % 2 == 0)
	{
		sizeOfBox += 1;
	}



	if (cpos >= Screen_col - (sizeOfBox * 3) && cpos <= Screen_col - sizeOfBox)
	{
		bool check = 1;
		bool check2 = 1;
		int r = 0, c = 0;
		for (int bri = sizeOfBox; bri < sizeOfBox * dim + sizeOfBox; bri += sizeOfBox)
		{
			for (int bci = Screen_col - sizeOfBox * 3; bci < Screen_col - sizeOfBox; bci += sizeOfBox)
			{
				for (int ri = bri; ri < bri + sizeOfBox; ri++)
				{

					for (int ci = bci; ci < bci + sizeOfBox; ci++)
					{

						
						{
							if ((r == Sc.ri && c == Sc.ci))
							{
								if (check == 1)
									HIghlightedBox(sizeOfBox, clr2, ri, ci);
								else
									HIghlightedBox(sizeOfBox, clr1, ri, ci);

								check2 = 0;
								break;
							}
							if (check == 1)

								SetClr(clr2);
							else SetClr(clr1);

						}



					}

					if (check2 == 0)
						break;
				}


				if (check2 == 0)
					break;

				if (check == 1)
				{
					SetClr(clr1);
					check = 0;
				}

				else
				{
					SetClr(clr2);
					check = 1;
				}



				if (c == 1)
					c = 0;
				else c++;
			}
			if (check2 == 0)
				break;
			swap(clr1, clr2);

			SetClr(clr2);
			check = 1;


			r++;
		}
	}






	if (cpos >= sizeOfBox && cpos < sizeOfBox * 3 + 1)
	{
		bool check = 1;
		bool check2 = 1;
		SetClr(clr2);
		if (sizeOfBox % 2 == 0)
		{
			sizeOfBox += 1;
		}


		int p1clr = 11;
		int p2clr = 0;


		int r = 0, c = 0;
		for (int bri = sizeOfBox; bri < sizeOfBox * dim + sizeOfBox; bri += sizeOfBox)
		{
			for (int bci = sizeOfBox; bci < sizeOfBox * 3; bci += sizeOfBox)
			{
				for (int ri = bri; ri < bri + sizeOfBox; ri++)
				{

					for (int ci = bci; ci < bci + sizeOfBox; ci++)
					{

						

						if ((r == Sc.ri && c == Sc.ci))
						{
							if (check == 1)
								HIghlightedBox(sizeOfBox, clr2, ri, ci);
							else
								HIghlightedBox(sizeOfBox, clr1, ri, ci);

							check2 = 0;
							break;
						}
							if (check == 1)
					
								SetClr(clr2);
							else SetClr(clr1);


					}
				
					if (check2 == 0)
						break;
				}


				if (check2 == 0)
					break;

				if (check == 1)
				{
					SetClr(clr1);
					check = 0;
				}

				else
				{
					SetClr(clr2);
					check = 1;
				}



				if (c == 1)
					c = 0;
				else c++;
			}
			if (check2 == 0)
				break;
			swap(clr1, clr2);

			SetClr(clr2);
			check = 1;


			r++;
		}
	}
}
void Init(const char* fname, int**& A,char**& B, char**& wt, char**& bk, int& Turn, string Pnames[], int dim, int& choice,char***&U,char*** &UW, char*** &UK,int **&sArr,int **&dArr, char***& rep, char***& repW, char***& repK, int**& repsArr, int**& repdArr,int *&cposArr,int *&cpos2Arr, int*& repcposArr, int*& repcpos2Arr,char*&dp)
{
	cin.clear();

	int rect_col=20,rect_rows=10;
	Turn = black;
	int rpos, cpos;
	
	Logo();

	gotoRowCol(20, 10);
	Rectangle(rect_rows, rect_col, 15, 16, rect_col*3-rect_col / 2);
	Rectangle(rect_rows, rect_col, 1, 16, rect_col*5 - rect_col / 2);
	SetClr(240);
	gotoRowCol(21, rect_col * 3-4);
	cout << "NEW GAME";
	SetClr(31);

	gotoRowCol(21, rect_col * 5 - 4);
	cout << "LOAD GAME";
	
	SetClr(15);
	
	while(1)
	{
		getRowColbyLeftClick(rpos, cpos);
		if ((rpos >= 16 && rpos <= 26) && ((cpos >= (rect_col * 3) - rect_col / 2) && (cpos <= (rect_col * 3 - rect_col / 2) + rect_col)))
		{
			choice = 1;
			break;
		}

		else if ((rpos >= 16 && rpos <= 26) && (cpos >= (rect_col * 5) - rect_col / 2) && (cpos <= (rect_col * 5 - rect_col / 2) + rect_col))
		{
			choice = 2;
			break;
		}

	}

	system("cls");
	
	dp = new char[2000];
	cposArr = new int[2000];
	cpos2Arr = new int[2000];
	repcposArr = new int[2000];
	repcpos2Arr = new int[2000];
	//undo...................................
	
	U = new char**[2000];

	for (int r = 0; r < 2000; r++)
	{
		U[r] = new char* [dim];
		for(int c=0;c<dim;c++)
		{
			U[r][c] = new char [dim];
		}
	}

	UW = new char** [2000];

	for (int r = 0; r < 2000; r++)
	{
		UW[r] = new char* [dim];
		for (int c = 0; c < dim; c++)
		{
			UW[r][c] = new char[2];
		}
	}
	UK = new char** [2000];

	for (int r = 0; r < 2000; r++)
	{
		UK[r] = new char* [dim];
		for (int c = 0; c < dim; c++)
		{
			UK[r][c] = new char[2];
		}
	}

	sArr = new int* [2000];
	for (int i = 0; i < 2000; i++)
	{
		sArr[i] = new int[2];
	}

	dArr = new int* [2000];
	for (int i = 0; i < 2000; i++)
	{
		dArr[i] = new int[2];
	}
	

	//replay,............

	rep = new char** [2000];

	for (int r = 0; r < 2000; r++)
	{
		rep[r] = new char* [dim];
		for (int c = 0; c < dim; c++)
		{
			rep[r][c] = new char[dim];
		}
	}

	repW = new char** [2000];

	for (int r = 0; r < 2000; r++)
	{
		repW[r] = new char* [dim];
		for (int c = 0; c < dim; c++)
		{
			repW[r][c] = new char[2];
		}
	}
	repK = new char** [2000];

	for (int r = 0; r < 2000; r++)
	{
		repK[r] = new char* [dim];
		for (int c = 0; c < dim; c++)
		{
			repK[r][c] = new char[2];
		}
	}

	repsArr = new int* [2000];
	for (int i = 0; i < 2000; i++)
	{
		repsArr[i] = new int[2];
	}

	repdArr = new int* [2000];
	for (int i = 0; i < 2000; i++)
	{
		repdArr[i] = new int[2];
	}


	//....................................


	if (choice == 1)
		fname = "Text.txt";

	if (choice == 2)
	{
		fname = "Text1.txt";

	}
	ifstream Rdr(fname);

	//highlighter
	A = new int* [dim];
	for (int i = 0; i < dim; i++)
	{
		A[i] = new int[dim];
	}
	
	//board
	B = new char* [dim];
	for (int i = 0; i < dim; i++)
	{
		B[i] = new char[dim];
	}

	for (int ri = 0; ri < dim; ri++)
	{
		for (int ci = 0; ci < dim; ci++)
		{

			Rdr >> B[ri][ci];
		}
	}
	//white cage
	wt = new char* [10];
	for (int i = 0; i < 10; i++)
	{
		wt[i] = new char[2];
	}

	for (int ri = 0; ri < 10; ri++)
	{
		for (int ci = 0; ci < 2; ci++)
		{

			Rdr >> wt[ri][ci];
		}
	}
	//blackcage
	bk = new char* [10];
	for (int i = 0; i < 10; i++)
	{
		bk[i] = new char[2];
	}

	for (int ri = 0; ri < 10; ri++)
	{
		for (int ci = 0; ci < 2; ci++)
		{

			Rdr >> bk[ri][ci];
		}
	}
	string temp;
	getline(Rdr ,temp);

	
	
	if(choice==1)
	{

		for (int i = 0; i < 2; i++)
		{
			cout << "\n\tEnter player " << i + 1 << "Name: ";


			getline(cin, Pnames[i]);


		}
	}


	if (choice == 2)
	{

		for (int i = 0; i < 2; i++)
		{
			
			getline(Rdr, Pnames[i]);
			
		}

	}	



	if (choice == 2)
		Rdr >> Turn;




	system("cls");
}
void printBoard(int sizeOfBox, char** B, int dim)
{
	int sr = 0, sc = 0;
	int er = sr + sizeOfBox;
	int ec = sc + sizeOfBox;
	int mean = 0;
	int mean2 = 0;

	for (int ri = 0; ri < dim; ri++)
	{
		for (int ci = 0; ci < dim; ci++)
		{
			mean = (sr + er) / 2;
			mean2 = (sc + ec) / 2;

			if (B[ri][ci] != '-')
			{
				gotoRowCol(mean, mean2);
				cout << B[ri][ci];

				sc = ec;
				ec = sc + sizeOfBox;
			}
			else
				cout << " ";
		}

		cout << endl;
	}

}
void TurnMessageOnly(string Pnames[], int Turn, int sizeofbox)

{
	SetClr(15);
	gotoRowCol(sizeofbox / 2, Screen_col - sizeofbox * 3);
	cout << " " << Pnames[black] << " (P2)";
	cout << endl;

	SetClr(15);
	gotoRowCol(sizeofbox / 2, sizeofbox);
	cout << " " << Pnames[white] << " (P1)";
	cout << endl;


	SetClr(0);
	gotoRowCol(sizeofbox * 11, sizeofbox * 11);
	cout << "                              ";
	gotoRowCol(sizeofbox * 11 + 4, sizeofbox * 11 - 10);
	cout << "                              ";

	if (Turn == white)
	{
		SetClr(11);
		gotoRowCol(sizeofbox * 11, sizeofbox * 11);
		cout << " " << Pnames[Turn] << " 's Turn";
		SetClr(0);
		cout << "                    ";
		gotoRowCol(sizeofbox * 11 - 1, sizeofbox * 11);
		cout << "                                 ";
		gotoRowCol(sizeofbox * 11 + 2, sizeofbox * 11 - 7);
		cout << "                              ";
		gotoRowCol(sizeofbox * 11 + 5, sizeofbox * 11 - 10);
		cout << "                             ";
	}

	if (Turn == black)
	{
		SetClr(15);
		gotoRowCol(sizeofbox * 11, sizeofbox * 11);
		cout << " " << Pnames[Turn] << " 's Turn";
		SetClr(0);
		cout << "                ";
		gotoRowCol(sizeofbox * 11 - 1, sizeofbox * 11);
		cout << "                         ";
		gotoRowCol(sizeofbox * 11 + 2, sizeofbox * 11 - 7);
		cout << "                                   ";
		gotoRowCol(sizeofbox * 11 + 5, sizeofbox * 11 - 10);
		cout << "                             ";
	}


}
void TurnMessage(string Pnames[], int& Turn, int& c, int sizeofbox)

{


	SetClr(15);
	gotoRowCol(sizeofbox / 2, Screen_col - sizeofbox * 3);
	cout << " " << Pnames[black] << " (P2)";
	cout << endl;

	SetClr(15);
	gotoRowCol(sizeofbox / 2, sizeofbox);
	cout << " " << Pnames[white] << " (P1)";
	cout << endl;





	if (c == 1)
		Turn = (Turn + 1) % 2;

	if (c == 2)
		Turn = Turn;



	if (c == 0)
		Turn = (Turn + 1) % 2;

	SetClr(0);
	gotoRowCol(sizeofbox * 11, sizeofbox * 11);
	cout << "                              ";
	gotoRowCol(sizeofbox * 11+4, sizeofbox * 11-10);
	cout << "                              ";

	if (Turn == white)
	{
		SetClr(11);
		gotoRowCol(sizeofbox * 11, sizeofbox * 11);
		cout <<" " << Pnames[Turn] << " 's Turn";
		SetClr(0);
		cout << "                    ";
		gotoRowCol(sizeofbox * 11 - 1, sizeofbox * 11);
		cout << "                                 ";
		gotoRowCol(sizeofbox * 11 + 2, sizeofbox * 11 - 7);
		cout << "                              ";
		gotoRowCol(sizeofbox * 11 + 5, sizeofbox * 11 - 10);
		cout << "                             ";
	}

	if (Turn == black)
	{
		SetClr(15);
		gotoRowCol(sizeofbox * 11, sizeofbox * 11);
		cout << " " << Pnames[Turn] << " 's Turn";
		SetClr(0);
		cout << "                ";
		gotoRowCol(sizeofbox * 11 - 1, sizeofbox * 11);
		cout << "                         ";
		gotoRowCol(sizeofbox * 11 + 2, sizeofbox * 11 - 7);
		cout << "                                   ";
		gotoRowCol(sizeofbox * 11 + 5, sizeofbox * 11 - 10);
		cout << "                             ";
	}

	c = 0;
}
void Undo(char*** U, char**& B, int& indx, int& sdIndx, int dim, int sizeOfBox, position Sc, position Dc, int& turn, string Pnames[], char**& wt, char** &bk, char*** UW, char*** UK, int** sarr, int** darr, char destpiece, int cpos2, int copss, int* cpos2Arr, int* cposArr, char* dp,int rpos)
{

	
	int urpos = 77, ucpos = 150;
	int ud_choice = 0;

	if (rpos >= urpos - 3 && rpos <= urpos - 3 + 10 && copss >= ucpos - 2 && copss <= ucpos - 2 + 11)
	{

		ud_choice = 1;
		indx -= 2;
		sdIndx -= 1;
	
	}
	else
		ud_choice = 0;


	while (ud_choice == 1)
	{
		int rpos = 77, cpos = 150;
		if (indx < 0)
		{
			indx = 0;
			sdIndx = 0;
			break;
		}

		for (int r = 0; r < dim; r++)
		{

			for (int c = 0; c < dim; c++)
			{


				B[r][c] = U[indx][r][c];



			}

		}
		for (int r = 0; r < dim; r++)
		{

			for (int c = 0; c < 2; c++)
			{


				wt[r][c] = UW[indx][r][c];



			}

		}
		for (int r = 0; r < dim; r++)
		{

			for (int c = 0; c < 2; c++)
			{


				bk[r][c] = UK[indx][r][c];



			}

		}

		//Grid(B, dim, sizeOfBox, 8, 15);
		if (turn == black)
			whiteGrid(wt, dim, sizeOfBox, 8, 15);
		if (turn == white)
			blackGrid(bk, dim, sizeOfBox, 8, 15);

		Sc.ri = sarr[indx][0];
		Sc.ci = sarr[indx][1];

		Dc.ri = darr[indx][0];
		Dc.ci = darr[indx][1];

		copss = cposArr[indx - 1];
		cpos2 = cpos2Arr[indx - 1];
		destpiece = dp[indx - 1];
		SourceDest(B, wt, bk, dim, sizeOfBox, 8, 15, Dc, Sc, cpos2, copss, destpiece, turn);

		turn = ((turn + 1) % 2);
		TurnMessageOnly(Pnames, turn, sizeOfBox);

		indx--;
		sdIndx--;
		if (indx < 0)
		{
			indx = 0;
			sdIndx = 0;
			break;
		}
		getRowColbyLeftClick(urpos, ucpos);


		if (urpos >= rpos - 3 && urpos <= rpos - 3 + 10 && ucpos >= cpos - 2 && ucpos <= cpos - 2 + 11)
		{

			ud_choice = 1;

		}
		else
			ud_choice = 0;



	}

}

void SelectPosition(const string Msg, position& P, int dim, int sizeofbox, char** wt, char** bk,int &rpos,int&cpos, int& rpos2, int& cpos2, char***undoB, char**&B, int &UD_indx, int &sdIndx,position Sc, position Dc, int &Turn, string Pnames[], char**& Wt, char **&Bl, char ***undoW, char***undoK, int **Sc_Arr, int **Dc_Arr, char destpiece , int *cpos2Arr, int *cposArr, char*dp)
{


	//   int I; char C;
	   //

	   //
	   //
	   //cin >> C>>I;
	   //C = toupper(C);
	   //P.ri = C - 'A';
	   //P.ci = I - 1;
	P.ri = -999;
	P.ci = -999;
	
	if (sizeofbox % 2 == 0)
	{
		sizeofbox += 1;
	}

	rpos2 = rpos;
	cpos2 = cpos;

	//cout << "\n\nSelelct "<< Msg<<"Co-Ordinates(A1:I9) :";
	getRowColbyLeftClick(rpos, cpos);

	Undo(undoB, B, UD_indx, sdIndx, dim, sizeofbox, Sc, Dc, Turn, Pnames, Wt, Bl, undoW, undoK, Sc_Arr, Dc_Arr, destpiece, cpos2, cpos, cpos2Arr, cposArr, dp,rpos);
	
	if (rpos >= 77 - 3 && rpos <= 77 - 3 + 10 && cpos >= 150 - 2 && cpos <= 150 - 2 + 11)
		UD_indx++;

	if (cpos >= sizeofbox  && cpos < sizeofbox * 3 + 1)
	{

		for (int ri = sizeofbox, r = 0; ri <= sizeofbox * dim; ri += sizeofbox, r++)
		{

			for (int ci = sizeofbox, c = 0; ci <= sizeofbox *2; ci += sizeofbox, c++)
			{

				if (rpos > ri && rpos < ri + sizeofbox)
				{

					P.ri = r;
				}
				if (cpos > ci && cpos < ci + sizeofbox)
				{
					P.ci = c;
				}
			}
		}


	}

	else if (cpos >= Screen_col-(sizeofbox*3) && cpos <= Screen_col - sizeofbox)
	{

		for (int ri = sizeofbox, r = 0; ri <= sizeofbox * dim; ri += sizeofbox, r++)
		{

			for (int ci = Screen_col - (sizeofbox * 3), c = 0; ci <= Screen_col - sizeofbox; ci += sizeofbox, c++)
			{

				if (rpos > ri && rpos < ri + sizeofbox)
				{

					P.ri = r;
				}
				if (cpos > ci && cpos < ci + sizeofbox)
				{
					P.ci = c;
				}
			}
		}

	}


	else
	{ 	
		for (int ri = sizeofbox, r = 0; ri <= sizeofbox * dim; ri += sizeofbox, r++)
		{

			for (int ci = sizeofbox + 44, c = 0; ci <= sizeofbox * dim + 44; ci += sizeofbox, c++)
			{

				if (rpos > ri && rpos < ri + sizeofbox)
				{

					P.ri = r;
				}
				if (cpos > ci && cpos < ci + sizeofbox)
				{
					P.ci = c;
				}
			}
		}

	}


}
bool Isblack(char Sym)
{

	return Sym >= 'A' && Sym <= 'Z';

}
bool IsWhite(char Sym)
{

	return Sym >= 'a' && Sym <= 'z';

}
bool IsMyPiece(char Sym, int Turn)
{



	if (Turn == black)
	{

		if (Isblack(Sym))
			return true;
	}

	if (Turn == white)
	{

		if (IsWhite(Sym))
			return true;
	}

	return false;

}
bool IsvalidSrc(position Sr, int dim, char** B, int Turn,int rpos,int cpos,int sizeofbox,char**wt,char **bk)
{

	if (Sr.ri < 0 || Sr.ri > dim || Sr.ci<0 || Sr.ci>dim)



		return false;


	if (cpos >= sizeofbox && cpos < sizeofbox * 3 + 1)
	return IsMyPiece(wt[Sr.ri][Sr.ci], Turn);

	else if (cpos >= Screen_col - (sizeofbox * 3) && cpos <= Screen_col - sizeofbox)
		return IsMyPiece(bk[Sr.ri][Sr.ci], Turn);

	else 
		return IsMyPiece(B[Sr.ri][Sr.ci], Turn);



}
bool IsvalidDest(position Dc, int dim, char** B, int Turn,int cpos,int cpos2, int sizeofbox)
{
	if (Dc.ri < 0 || Dc.ri > dim || Dc.ci<0 || Dc.ci>dim)

		return false;

	//jo mainay abhi destination select ki ha agr wo white cage ya black cage ma se ha to false
	if (cpos >= sizeofbox && cpos < sizeofbox * 3 + 1)
	{
		return false;
	}

	else if (cpos >= Screen_col - (sizeofbox * 3) && cpos <= Screen_col - sizeofbox)
	{
		return false;
	}



	//agr jo mainay destination se phley position select ki thi(yani source) agr wo white ya black cage ma se ha

	if (cpos2 >= sizeofbox && cpos2 < sizeofbox * 3 + 1)
	{
		return(B[Dc.ri][Dc.ci] == '-');
	}

	else if (cpos2 >= Screen_col - (sizeofbox * 3) && cpos2 <= Screen_col - sizeofbox)
	{ 
		return(B[Dc.ri][Dc.ci] == '-');
	}
	
	else
	{

		if (!IsMyPiece(B[Dc.ri][Dc.ci], Turn))
		{
			return true;

		}
		return false;
	}
}
void UPdateBoard(position Sc, position Dc, char** B, char** wt, char** bk, int& wtc, int& wtr, int& bkc, int& bkr, int turn, int rpos2, int cpos2, int sizeofbox, char &destpiece,char &sourcepiece, int**& sarr, int**& darr,int &sdIndx, int** &repsarr, int** &repdarr, int &repsdIndx,int *&cposArr, int*& cpos2Arr,int cpos, int*& repcposArr, int*& repcpos2Arr,char*&dp)
{
	//undo....................
	destpiece = B[Dc.ri][Dc.ci];
	dp[sdIndx] = destpiece;
	sourcepiece = B[Sc.ri][Sc.ci];
	
	sarr[sdIndx][0]=Sc.ri;
	sarr[sdIndx][1] = Sc.ci;
	
	darr[sdIndx][0]=Dc.ri;
	darr[sdIndx][1] = Dc.ci;
	cpos2Arr[sdIndx] = cpos2;
	cposArr[sdIndx] = cpos;

	sdIndx++;
//replay....................
	repsarr[repsdIndx][0] = Sc.ri;
	repsarr[repsdIndx][1] = Sc.ci;

	repdarr[repsdIndx][0] = Dc.ri;
	repdarr[repsdIndx][1] = Dc.ci;

	repcpos2Arr[repsdIndx] = cpos2;
	repcposArr[repsdIndx] = cpos;


	repsdIndx++;
	//...................




	char P = B[Sc.ri][Sc.ci];

	bool check1 = 0;
	bool check2 = 0;


	//finding empty place for storing mari hui goti and depromoting it 
	if (turn == white)
	
	{

		for (int ri = sizeofbox, r = 0; ri <= sizeofbox * 9; ri += sizeofbox, r++)
		{

			for (int ci = sizeofbox, c = 0; ci <= sizeofbox * 2; ci += sizeofbox, c++)
			{
			
				if(wt[r][c]=='-')
				{
					wt[r][c] = tolower(B[Dc.ri][Dc.ci]);

					if (wt[r][c] == 'j')
					{
						wt[r][c] = 'p';
					}


					if (wt[r][c] == 'd')
					{
						wt[r][c] = 'r';
					}

					if (wt[r][c] == 'h')
					{
						wt[r][c] = 'b';
					}

					if (wt[r][c] == 'm')
					{
						wt[r][c] = 's';
					}

					if (wt[r][c] == 'f')
					{
						wt[r][c] = 'n';
					}

					if (wt[r][c] == 'e')
					{
						wt[r][c] = 'l';
					}


					check1 = 1;
					break;
				}
			}
			if (check1 == 1)
				break;
		}


	}

	if (turn == black)
	
	{

		for (int ri = sizeofbox, r = 0; ri <= sizeofbox * 9; ri += sizeofbox, r++)
		{

			for (int ci = Screen_col - (sizeofbox * 3), c = 0; ci <= Screen_col - sizeofbox; ci += sizeofbox, c++)
			{

				if (bk[r][c] == '-')

				{
					bk[r][c] = toupper(B[Dc.ri][Dc.ci]);
					if (bk[r][c] == 'J')
					{
						bk[r][c] = 'P';
					}


					if (bk[r][c] == 'D')
					{
						bk[r][c] = 'R';
					}

					if (bk[r][c] == 'H')
					{
						bk[r][c] = 'B';
					}

					if (bk[r][c] == 'M')
					{
						bk[r][c] = 'S';
					}

					if (bk[r][c] == 'F')
					{
						bk[r][c] = 'N';
					}

					if (bk[r][c] == 'E')
					{
						bk[r][c] = 'L';
					}
					check2 = 1;
					break;
				}
			}
		
			if (check2 == 1)
				break;
		}

	}


	//..................................(replacing with space)





	if (cpos2 >= sizeofbox && cpos2 < sizeofbox * 3 + 1)
	{
		P = wt[Sc.ri][Sc.ci];
		B[Dc.ri][Dc.ci] = P;
		wt[Sc.ri][Sc.ci] = '-';

		
	}
	else if (cpos2 >= Screen_col - (sizeofbox * 3) && cpos2 <= Screen_col - sizeofbox)
	{

		P = bk[Sc.ri][Sc.ci];
		B[Dc.ri][Dc.ci] = P;
		bk[Sc.ri][Sc.ci] = '-';

	}
	else
	{
		P = B[Sc.ri][Sc.ci];
		B[Dc.ri][Dc.ci] = P;
		B[Sc.ri][Sc.ci] = '-';

	}




	/*


	if (wtc == 2)
	{
		wtr++;
		wtc = 0;

	}
	if (bkc == 2)
	{
		bkr++;
		bkc = 0;

	}*/

}
void Header( int sizeofbox, string Pname[])
{

	/*SetClr(241);
	gotoRowCol(sizeofbox / 2, Screen_col - sizeofbox * 3);
	cout << Pname[black] << " (Black)";
	cout << endl;
	
	SetClr(244);
	gotoRowCol(sizeofbox / 2, sizeofbox);
	cout << Pname[white] << " (White)";
	cout << endl;*/


	//SetClr(15);


	//for (int ri = 0, r = sizeofbox; ri < 10; ri++, r += sizeofbox)
	//{
	//	for (int ci = 0, c = Screen_col - sizeofbox * 2; ci < 2; ci++, c += sizeofbox)
	//	{
	//		gotoRowCol(r, c);
	//		cout << bk[ri][ci];

	//	}
	//	cout << endl;

	//}

}
bool IsHorizontalMOve(position Sc, position Dc)
{
	return (Sc.ri == Dc.ri);
}
bool IsVerticalMOve(position Sc, position Dc)
{
	return (Sc.ci == Dc.ci);
}
bool IsForwardDigMove(position Sc, position Dc)
{

	return((Dc.ri < Sc.ri&& Dc.ci < Sc.ci) || (Dc.ri<Sc.ri&& Dc.ci>Sc.ci));


}
bool IsBackwardDigMove(position Sc, position Dc)
{

	return((Dc.ri > Sc.ri && Dc.ci < Sc.ci) || (Dc.ri > Sc.ri && Dc.ci > Sc.ci));


}
bool IsDiagonalMove(position Sc, position Dc)
{
	int delta_R = abs(Sc.ri - Dc.ri);
	int  delta_C = abs(Sc.ci - Dc.ci);

	return (delta_R == delta_C);
}
bool IsHorzPathClear(char** B, position Sc, position Dc)
{
	int sp = 0, ep = 0;

	if (Sc.ci < Dc.ci)
	{
		sp = Sc.ci + 1;	ep = Dc.ci - 1;
	}

	if (Sc.ci > Dc.ci)
	{
		sp = Dc.ci + 1;	ep = Sc.ci - 1;
	}

	for (int c = sp; c <= ep; c++)
	{

		if (B[Sc.ri][c] != '-')
			return false;
	}
	return true;

}
bool IsVertPathClear(char** B, position Sc, position Dc)
{
	int sp = 0, ep = 0;

	if (Sc.ri < Dc.ri)
	{
		sp = Sc.ri + 1;	ep = Dc.ri - 1;
	}

	if (Sc.ri > Dc.ri)
	{
		sp = Dc.ri + 1;	ep = Sc.ri - 1;
	}

	for (int r = sp; r <= ep; r++)
	{

		if (B[r][Sc.ci] != '-')
			return false;
	}
	return true;

}
bool IsDiagonal1_Pathclear(char** B, position Sc, position Dc)
{

	int Delta_r, sp, ep;


	Delta_r = abs(Sc.ri - Dc.ri);


	if (Sc.ri < Dc.ri)
	{

		for (int i = 1; i < Delta_r; i++)
		{

			if (B[Sc.ri + i][Sc.ci + i] != '-')
				return false;
		}
		return true;

	}
	else
	{
		for (int i = 1; i < Delta_r; i++)
		{

			if (B[Sc.ri - i][Sc.ci - i] != '-')
				return false;
		}

	}
}
bool IsDiagonal2_Pathclear(char** B, position Sc, position Dc)
{

	int Delta_r, sp, ep;


	Delta_r = abs(Sc.ri - Dc.ri);


	if (Sc.ri < Dc.ri)
	{

		for (int i = 1; i < Delta_r; i++)
		{

			if (B[Sc.ri + i][Sc.ci - i] != '-')
				return false;
		}
		return true;

	}
	else
	{
		for (int i = 1; i < Delta_r; i++)
		{

			if (B[Sc.ri - i][Sc.ci + i] != '-')
				return false;
		}

	}
}
bool IsDiagonal_Pathclear(char** B, position Sc, position Dc)
{
	if ((Sc.ri > Dc.ri && Sc.ci > Dc.ci) || (Sc.ri < Dc.ri && Sc.ci < Dc.ci))
		return IsDiagonal1_Pathclear(B, Sc, Dc);
	if ((Sc.ri < Dc.ri && Sc.ci > Dc.ci) || (Sc.ri > Dc.ri && Sc.ci < Dc.ci))
		return IsDiagonal2_Pathclear(B, Sc, Dc);

}
bool IsForwardKnightMove(position Sc, position Dc)
{
	int DeltaR = abs(Sc.ri - Dc.ri);
	int DeltaC = abs(Sc.ci - Dc.ci);

	return (Dc.ri < Sc.ri&& DeltaR == 2 && DeltaC == 1);


}
bool IsBackwardKnightMove(position Sc, position Dc)
{
	int DeltaR = abs(Sc.ri - Dc.ri);
	int DeltaC = abs(Sc.ci - Dc.ci);

	return (Dc.ri > Sc.ri && DeltaR == 2 && DeltaC == 1);


}
bool IsForwardMove(position Sc, position Dc)
{

	return (Dc.ri < Sc.ri&& Dc.ci == Sc.ci);
}
bool IsBackwardMove(position Sc, position Dc)
{
	return (Dc.ri > Sc.ri && Dc.ci == Sc.ci);


}
bool RookLegalty(char** B, position Sc, position Dc)
{


	return((IsHorzPathClear(B, Sc, Dc) && IsHorizontalMOve(Sc, Dc)) || (IsVerticalMOve(Sc, Dc) && IsVertPathClear(B, Sc, Dc)));



}
bool BishopLegalty(char** B, position Sc, position Dc)
{


	return(IsDiagonalMove(Sc, Dc) && IsDiagonal_Pathclear(B, Sc, Dc));

}
bool GoldGenLegalty(char** B, position Sc, position Dc)
{

	int DeltaR = abs(Sc.ri - Dc.ri);
	int DeltaC = abs(Sc.ci - Dc.ci);


	if (B[Sc.ri][Sc.ci] == 'g')
	{
		return(((RookLegalty(B, Sc, Dc))) || BishopLegalty(B, Sc, Dc));
	}

	if (B[Sc.ri][Sc.ci] == 'G')
	{
		return(((RookLegalty(B, Sc, Dc))) || BishopLegalty(B, Sc, Dc));
	}

}
bool PromtPawnLegalty(char** B, position Sc, position Dc)
{

	int DeltaR = abs(Sc.ri - Dc.ri);
	int DeltaC = abs(Sc.ci - Dc.ci);


	if (B[Sc.ri][Sc.ci] == 'j')
	{
		return((RookLegalty(B, Sc, Dc) && (DeltaR == 1 || DeltaC == 1)) || (IsForwardDigMove(Sc, Dc) && (DeltaR == 1 && DeltaC == 1)));
	}
	if (B[Sc.ri][Sc.ci] == 'J')
	{
		return((RookLegalty(B, Sc, Dc) && (DeltaR == 1 || DeltaC == 1)) || (IsBackwardDigMove(Sc, Dc) && (DeltaR == 1 && DeltaC == 1)));
	}
}
bool PromtSilverLegalty(char** B, position Sc, position Dc)
{

	
	int DeltaR = abs(Sc.ri - Dc.ri);
	int DeltaC = abs(Sc.ci - Dc.ci);


	if (B[Sc.ri][Sc.ci] == 'm')
	{
		return(((RookLegalty(B, Sc, Dc) && (DeltaR == 1 || DeltaC == 1))) ||( IsForwardDigMove(Sc, Dc)) && (DeltaR == 1 && DeltaC == 1));
	}

	if (B[Sc.ri][Sc.ci] == 'M')
	{
		return((RookLegalty(B, Sc, Dc)&& (DeltaR == 1 || DeltaC == 1)) ||( IsBackwardDigMove(Sc, Dc)) && (DeltaR == 1 && DeltaC == 1));
	}


}
bool promtKnightLegalty(char** B, position Sc, position Dc)
{

	int DeltaR = abs(Sc.ri - Dc.ri);
	int DeltaC = abs(Sc.ci - Dc.ci);


	if (B[Sc.ri][Sc.ci] == 'f')
	{
		return(((RookLegalty(B, Sc, Dc) && (DeltaR == 1 || DeltaC == 1))) || (IsForwardDigMove(Sc, Dc)) && (DeltaR == 1 && DeltaC == 1));
	}

	if (B[Sc.ri][Sc.ci] == 'F')
	{
		return((RookLegalty(B, Sc, Dc) && (DeltaR == 1 || DeltaC == 1)) || (IsBackwardDigMove(Sc, Dc)) && (DeltaR == 1 && DeltaC == 1));
	}


}
bool PromtLanceLegalty(char** B, position Sc, position Dc)
{

	


	int DeltaR = abs(Sc.ri - Dc.ri);
	int DeltaC = abs(Sc.ci - Dc.ci);


	if (B[Sc.ri][Sc.ci] == 'e')
	{
		return(((RookLegalty(B, Sc, Dc) && (DeltaR == 1 || DeltaC == 1))) || (IsForwardDigMove(Sc, Dc)) && (DeltaR == 1 && DeltaC == 1));
	}

	if (B[Sc.ri][Sc.ci] == 'E')
	{
		return((RookLegalty(B, Sc, Dc) && (DeltaR == 1 || DeltaC == 1)) || (IsBackwardDigMove(Sc, Dc)) && (DeltaR == 1 && DeltaC == 1));
	}

}
bool SilverGenLegalty(char** B, position Sc, position Dc)

{
	int DeltaR = abs(Sc.ri - Dc.ri);


	if (B[Sc.ri][Sc.ci] == 's')
	{
		return((BishopLegalty(B, Sc, Dc) || IsForwardMove(Sc, Dc)) && DeltaR == 1);
	}

	if (B[Sc.ri][Sc.ci] == 'S')
	{
		return((BishopLegalty(B, Sc, Dc) || IsBackwardMove(Sc, Dc)) && DeltaR == 1);
	}



}
bool LanceLegalty(char** B, position Sc, position Dc)
{
	if (B[Sc.ri][Sc.ci] == 'l')
	{
		return((IsForwardMove(Sc, Dc) && IsVertPathClear(B, Sc, Dc)));
	}

	if (B[Sc.ri][Sc.ci] == 'L')
	{
		return((IsBackwardMove(Sc, Dc) && IsVertPathClear(B, Sc, Dc)));
	}




}
bool KnightLegalty(char** B, position Sc, position Dc)
{


	if (B[Sc.ri][Sc.ci] == 'n')
	{
		return(IsForwardKnightMove(Sc, Dc));
	}

	if (B[Sc.ri][Sc.ci] == 'N')
	{
		return(IsBackwardKnightMove(Sc, Dc));
	}



}
bool PawnLegalty(char** B, position Sc, position Dc)
{

	int DeltaR = abs(Sc.ri - Dc.ri);


	if (B[Sc.ri][Sc.ci] == 'p')
	{
		return((IsForwardMove(Sc, Dc) && IsVertPathClear(B, Sc, Dc)) && DeltaR == 1);
	}

	if (B[Sc.ri][Sc.ci] == 'P')
	{
		return((IsBackwardMove(Sc, Dc) && IsVertPathClear(B, Sc, Dc)) && DeltaR == 1);
	}



}
bool KingLegalty(char** B, position Sc, position Dc)
{
	int DeltaR = abs(Sc.ri - Dc.ri);
	int DeltaC = abs(Sc.ci - Dc.ci);
	return((BishopLegalty(B, Sc, Dc) && DeltaR == 1) || ((DeltaC == 1 || DeltaR == 1) && RookLegalty(B, Sc, Dc)));

}
bool DragonLegalty(char** B, position Sc, position Dc)
{


	int DeltaR = abs(Sc.ri - Dc.ri);
	int DeltaC = abs(Sc.ci - Dc.ci);
	return((BishopLegalty(B, Sc, Dc) && DeltaR == 1) || RookLegalty(B, Sc, Dc));

}
bool HorseLegalty(char** B, position Sc, position Dc)
{


	int DeltaR = abs(Sc.ri - Dc.ri);
	int DeltaC = abs(Sc.ci - Dc.ci);

	return((BishopLegalty(B, Sc, Dc)  || ((DeltaC == 1 || DeltaR == 1) && RookLegalty(B, Sc, Dc))));



}
void Savegame(const char* fname,char***&U,int &indx, char** B, int dim, int turn, char** wt, char** bk,string Pnames[])

{
	ofstream Rdr2(fname);

	for (int ri = 0; ri < dim; ri++)
	{
		for (int ci = 0; ci < dim; ci++)
		{

			Rdr2 << B[ri][ci];
		}
		Rdr2 << endl;

	}

	for (int ri = 0; ri < 10; ri++)
	{
		for (int ci = 0; ci < 2; ci++)
		{

			Rdr2 << wt[ri][ci];
		}
		Rdr2 << endl;
	}

	for (int ri = 0; ri < 10; ri++)
	{
		for (int ci = 0; ci < 2; ci++)
		{

			Rdr2 << bk[ri][ci];
		}
		Rdr2 << endl;
	}


	Rdr2<< Pnames[0]<<endl;
	
	Rdr2<< Pnames[1]<<endl;


	Rdr2 << turn;



}
void loadundo( char***& U, char***& UW, char***& UK, int& indx, char** B, int dim, int turn, char** wt, char** bk, string Pnames[])

{
	

	for (int r = 0; r < dim; r++)
	{

		for (int c = 0; c < dim; c++)
		{


			U[indx][r][c] = B[r][c];



		}

	}

	for (int r = 0; r < dim; r++)
	{

		for (int c = 0; c < dim; c++)
		{


			UW[indx][r][c] = wt[r][c];



		}

	}

	for (int r = 0; r < dim; r++)
	{

		for (int c = 0; c < dim; c++)
		{


			UK[indx][r][c] = bk[r][c];



		}

	}

	indx++;

}
void loadreplay(char***& rep, char***& repW, char***& repK, int& repindx, char** B, int dim, int turn, char** wt, char** bk, string Pnames[])

{


	for (int r = 0; r < dim; r++)
	{

		for (int c = 0; c < dim; c++)
		{


			rep[repindx][r][c] = B[r][c];



		}

	}

	for (int r = 0; r < dim; r++)
	{

		for (int c = 0; c < dim; c++)
		{


			repW[repindx][r][c] = wt[r][c];



		}

	}

	for (int r = 0; r < dim; r++)
	{

		for (int c = 0; c < dim; c++)
		{


			repK[repindx][r][c] = bk[r][c];



		}

	}

	repindx++;

}
bool IslegalMove(char** B,char**wt,char**bk,int sizeofbox, position Sc, position Dc,int rpos,int cpos)
{

	if (cpos >= sizeofbox && cpos < sizeofbox * 3 + 1)
	{
		if(wt[Sc.ri][Sc.ci]=='p')
		{
			for (int ri = 0; ri < 9;ri++)
			{
				if (B[ri][Dc.ci] == 'p')
					return false;
			}
		
			if (Dc.ri == 0)
				return false;
		
		}
		if (wt[Sc.ri][Sc.ci] == 'l')
		{
			if (Dc.ri == 0)
				return false;
		}

		if (wt[Sc.ri][Sc.ci] == 'n')
		{
			if (Dc.ri == 0 || Dc.ri == 1)
				return false;
			
		}

		if(wt[Sc.ri][Sc.ci]=='p')
		{
			
			{
				if (B[Dc.ri-1][Dc.ci] == 'K')
					return false;
			}
		
		
		}
		return true;
	}
	

	else if (cpos >= Screen_col - (sizeofbox * 3) && cpos <= Screen_col - sizeofbox)
	{
		if (bk[Sc.ri][Sc.ci] == 'P')
		{
			for (int ri = 0; ri < 9; ri++)
			{
				if (B[ri][Dc.ci] == 'P')
					return false;
			}
		
			if (Dc.ri == 8)
				return false;

		}
		if (bk[Sc.ri][Sc.ci] == 'L')
		{
			if (Dc.ri == 8)
				return false;
		}

		if (bk[Sc.ri][Sc.ci] == 'N')
		{
			if (Dc.ri == 8 || Dc.ri == 7)
				return false;
		}
		if (bk[Sc.ri][Sc.ci] == 'P')
		{

			{
				if (B[Dc.ri + 1][Dc.ci] == 'k')
					return false;
			}


		}
		return true;
	}

	


	else
	{
			if (B[Sc.ri][Sc.ci] == 'r' || B[Sc.ri][Sc.ci] == 'R')
				return(RookLegalty(B, Sc, Dc));

		if (B[Sc.ri][Sc.ci] == 'b' || B[Sc.ri][Sc.ci] == 'B')
			return(BishopLegalty(B, Sc, Dc));


		if (B[Sc.ri][Sc.ci] == 'G' || B[Sc.ri][Sc.ci] == 'g')
			return(GoldGenLegalty(B, Sc, Dc));


		if (B[Sc.ri][Sc.ci] == 'S' || B[Sc.ri][Sc.ci] == 's')
			return(SilverGenLegalty(B, Sc, Dc));

		if (B[Sc.ri][Sc.ci] == 'L' || B[Sc.ri][Sc.ci] == 'l')
			return(LanceLegalty(B, Sc, Dc));


		if (B[Sc.ri][Sc.ci] == 'P' || B[Sc.ri][Sc.ci] == 'p')
			return(PawnLegalty(B, Sc, Dc));


		if (B[Sc.ri][Sc.ci] == 'N' || B[Sc.ri][Sc.ci] == 'n')
			return(KnightLegalty(B, Sc, Dc));


		if (B[Sc.ri][Sc.ci] == 'K' || B[Sc.ri][Sc.ci] == 'k')
			return(KingLegalty(B, Sc, Dc));
	
	
		if (B[Sc.ri][Sc.ci] == 'J' || B[Sc.ri][Sc.ci] == 'j')
			return(PromtPawnLegalty(B, Sc, Dc));
		if (B[Sc.ri][Sc.ci] == 'M' || B[Sc.ri][Sc.ci] == 'm')
			return(PromtSilverLegalty(B, Sc, Dc));
		if (B[Sc.ri][Sc.ci] == 'F' || B[Sc.ri][Sc.ci] == 'f')
			return(promtKnightLegalty(B, Sc, Dc));
		if (B[Sc.ri][Sc.ci] == 'E' || B[Sc.ri][Sc.ci] == 'e')
			return(PromtLanceLegalty(B, Sc, Dc));
	
		if (B[Sc.ri][Sc.ci] == 'H' || B[Sc.ri][Sc.ci] == 'h')
			return(HorseLegalty(B, Sc, Dc));
		if (B[Sc.ri][Sc.ci] == 'D' || B[Sc.ri][Sc.ci] == 'd')
			return(DragonLegalty(B, Sc, Dc));
	
	}

}
int Interface(const string msg)

{
	int rpos = 0, cpos = 0;
	int prom = 0;

	cin.clear();
	int rect_col = 20, rect_rows = 10;
	gotoRowCol(20, 10);
	Rectangle(rect_rows, rect_col, 15, 20, rect_col * 3 - rect_col / 2);
	Rectangle(rect_rows, rect_col, 1, 20, rect_col * 5 - rect_col / 2);
	SetClr(15);

	gotoRowCol(12, rect_col * 3 - 2);

	cout << "WOULD YOU LIKE TO PROMOTE YOUR " << msg<<" ?";
	SetClr(240);
	gotoRowCol(25, rect_col * 3 - 4);
	cout << "PROMOTE";
	SetClr(31);

	gotoRowCol(25, rect_col * 5 - 4);
	cout << "SHUT UP";

	SetClr(15);

	while (1)
	{
		getRowColbyLeftClick(rpos, cpos);
		if ((rpos >= 20 && rpos <= 30) && ((cpos >= (rect_col * 3) - rect_col / 2) && (cpos <= (rect_col * 3 - rect_col / 2) + rect_col)))
		{
			prom = 1;
			break;
		}

		else if ((rpos >= 20 && rpos <= 30) && (cpos >= (rect_col * 5) - rect_col / 2) && (cpos <= (rect_col * 5 - rect_col / 2) + rect_col))
		{
			prom = 2;
			break;
		}

	}


	system("cls");

	return prom;


}
bool ReplayMsg()
{
	int rpos = 0, cpos = 0;

	cin.clear();
	int rect_col = 20, rect_rows = 10;
	gotoRowCol(20, 10);
	Rectangle(rect_rows, rect_col, 15, 20, rect_col * 3 - rect_col / 2);
	Rectangle(rect_rows, rect_col, 1, 20, rect_col * 5 - rect_col / 2);
	SetClr(15);

	gotoRowCol(12, rect_col * 3 - 2);

	cout << "WANNA SEE A REPLAY OF YOUR GAME ?" ;
	SetClr(240);
	gotoRowCol(25, rect_col * 3 - 1);
	cout << "YES";
	SetClr(31);

	gotoRowCol(25, rect_col * 5 - 4);
	cout << "SHUT UP";

	SetClr(15);

	while (1)
	{
		getRowColbyLeftClick(rpos, cpos);
		if ((rpos >= 20 && rpos <= 30) && ((cpos >= (rect_col * 3) - rect_col / 2) && (cpos <= (rect_col * 3 - rect_col / 2) + rect_col)))
		{
			system("cls");
			return 1;
			break;
		}

		else if ((rpos >= 20 && rpos <= 30) && (cpos >= (rect_col * 5) - rect_col / 2) && (cpos <= (rect_col * 5 - rect_col / 2) + rect_col))
		{
			system("cls");
			return 0;
			break;
		}

	}


	system("cls");

	

}
bool Promotion(int dim,char**B,position Sc,position Dc,int turn,int cpos2,int sizeofbox)
{
	


	if (cpos2 >= sizeofbox && cpos2 < sizeofbox * 3 + 1)
	{
		
		return false;
	}

	else if (cpos2 >= Screen_col - (sizeofbox * 3) && cpos2 <= Screen_col - sizeofbox)
	{
		return false;

	}


	else if(turn==white)

	{
		if(Dc.ri== 0)
		{
			if (B[Dc.ri][Dc.ci] == 'p')
			{
				{
					B[Dc.ri][Dc.ci] = 'j';

				}
				return true;
			}
			if (B[Dc.ri][Dc.ci] == 'l')
			{
				
				{
					B[Dc.ri][Dc.ci] = 'e';
				}
				return true;
			}
		
		}
		//for (int ri = 0; ri < 3; ri++)
		{
			//for (int ci = 0; ci < dim; ci++)
			if(Dc.ri<3&&Dc.ri>=0)
			{



				if (B[Dc.ri][Dc.ci] == 'p')
				{
					system("cls");
					if (Interface("PAWN") == 1)
					{
						B[Dc.ri][Dc.ci] = 'j';

					}
					return true;
				}


				if (B[Dc.ri][Dc.ci] == 'r')
				{
					system("cls");
					if (Interface("ROOK") == 1)
					{
						B[Dc.ri][Dc.ci] = 'd';
					
						
					}
					return true;
				}

				if (B[Dc.ri][Dc.ci] == 'b')
				{
					system("cls");

					if (Interface("BISHOP") == 1)
					{
						B[Dc.ri][Dc.ci] = 'h';
					}
					return true;
				}

				if (B[Dc.ri][Dc.ci] == 's')
				{
					system("cls");
					if (Interface("SILVER GENERAL") == 1)
					{
						B[Dc.ri][Dc.ci] = 'm';
					}
					return true;
				}

				if (B[Dc.ri][Dc.ci] == 'n')
				{
					system("cls");
					if (Interface("NIGHT") == 1)
					{
						B[Dc.ri][Dc.ci] = 'f';
					}
					return true;
				}

				if (B[Dc.ri][Dc.ci] == 'l')
				{
					system("cls");
					if (Interface("LANCE") == 1)
					{
						B[Dc.ri][Dc.ci] = 'e';
					}
					return true;
				}
			}

		}
	
		return false;

	}

	else

	{
		//for (int ri = 6; ri < 9; ri++)
		{
			//for (int ci = 0; ci < dim; ci++)
		
			if(Dc.ri<9&&Dc.ri>=6)
			{
				if (Dc.ri == 8)
				{
					if (B[Dc.ri][Dc.ci] == 'P')
					{
						{
							B[Dc.ri][Dc.ci] = 'J';

						}
						return true;
					}
				
					if (B[Dc.ri][Dc.ci] == 'L')
					{
						{
							B[Dc.ri][Dc.ci] = 'E';
						}
						return true;
					}
				
				}
				if (B[Dc.ri][Dc.ci] == 'P')
				{
					system("cls");
					if (Interface("PAWN") == 1)
					{
						B[Dc.ri][Dc.ci] = 'J';

					}
					return true;
				}

				if (B[Dc.ri][Dc.ci] == 'R')
				{
					system("cls");
					if (Interface("ROOK") == 1)
					{
						B[Dc.ri][Dc.ci] = 'D';
					}
					return true;
				}

				if (B[Dc.ri][Dc.ci] == 'B')
				{
					system("cls");

					if (Interface("BISHOP") == 1)
					{
						B[Dc.ri][Dc.ci] = 'H';
					}
					return true;
				}

				if (B[Dc.ri][Dc.ci] == 'S')
				{
					system("cls");
					if (Interface("SILVER GENERAL") == 1)
					{
						B[Dc.ri][Dc.ci] = 'M';
					}
					return true;
				}

				if (B[Dc.ri][Dc.ci] == 'N')
				{
					system("cls");
					if (Interface("NIGHT") == 1)
					{
						B[Dc.ri][Dc.ci] = 'F';
					}
					return true;
				}

				if (B[Dc.ri][Dc.ci] == 'L')
				{
					system("cls");
					if (Interface("LANCE") == 1)
					{
						B[Dc.ri][Dc.ci] = 'E';
					}
					return true;
				}
			}

		}

		return false;

	}
	

	return false;


}
bool Check(int dim, char** B, int Turn, position Dc, position Sc, int cpos, int cpos2, int sizeofbox, int rpos, char** wt, char** bk )
{
	cpos2 = -999;
	cpos =- 999;

	for (int sri = 0; sri < dim; sri++)
	{
		for (int sci = 0; sci < dim; sci++)
		{
			Sc.ri = sri, Sc.ci = sci;

			for (int dri = 0; dri < dim; dri++)
			{
				if (!IsvalidSrc(Sc, dim, B, Turn, rpos, cpos, sizeofbox, wt, bk))
				{
					break;
				}

				for (int dci = 0; dci < dim; dci++)
				{
					Dc.ri = dri, Dc.ci = dci;
					if (IsvalidDest(Dc, dim, B, Turn, cpos, cpos2, sizeofbox) && (IslegalMove(B, wt, bk, sizeofbox, Sc, Dc, rpos, cpos)))
					{
						if (B[Dc.ri][Dc.ci] == 'k' || B[Dc.ri][Dc.ci] == 'K')
							return true;
		
					
					
					
					}
				}
			}
		}
	}
	return false;
}
bool CheckNew(int dim, char** B, int Turn, position Dc, position Sc, int cpos, int cpos2, int sizeofbox, int rpos, char** wt, char** bk, position &Sc_store)
{
	cpos=-999;
	cpos2=-999;
	for (int sri = 0; sri < dim; sri++)
	{
		for (int sci = 0; sci < dim; sci++)
		{
			Sc.ri = sri, Sc.ci = sci;

			for (int dri = 0; dri < dim; dri++)
			{
				if (!IsvalidSrc(Sc, dim, B, Turn, rpos, cpos, sizeofbox, wt, bk))
				{
					break;
				}

				for (int dci = 0; dci < dim; dci++)
				{
					Dc.ri = dri, Dc.ci = dci;
					if (IsvalidDest(Dc, dim, B, Turn, cpos, cpos2, sizeofbox) && (IslegalMove(B, wt, bk, sizeofbox, Sc, Dc, rpos, cpos)))
					{
						if (B[Dc.ri][Dc.ci] == 'k' || B[Dc.ri][Dc.ci] == 'K')
						{
							Sc_store=Sc;
							return true;
						}




					}
				}
			}
		}
	}
	return false;
}
bool Checklegalty(int dim, char** B, int Turn, position Dc, position Sc, int cpos, int cpos2, int sizeofbox, int rpos, char** wt, char** bk)
{
	char p;
	char** A;
	A = new char* [dim];
	for (int i = 0; i < dim; i++)
	{
		A[i] = new char[dim];
	}
	for (int ri = 0; ri < dim; ri++)
	{
		for (int ci = 0; ci < dim; ci++)
		{
			A[ri][ci] = B[ri][ci];

		}


	}
	char** W;
	W = new char* [10];
	for (int i = 0; i < 10; i++)
	{
		W[i] = new char[2];
	}
	for (int ri = 0; ri < 10; ri++)
	{
		for (int ci = 0; ci < 2; ci++)
		{
			W[ri][ci] = wt[ri][ci];

		}


	}
	char** L;
	L = new char* [10];
	for (int i = 0; i < 10; i++)
	{
		L[i] = new char[2];
	}
	for (int ri = 0; ri < 10; ri++)
	{
		for (int ci = 0; ci < 2; ci++)
		{
			L[ri][ci] = bk[ri][ci];

		}


	}

	int bStart= Screen_col - (sizeofbox * 3);
	int bEnd= Screen_col - sizeofbox;

	position tempSc = Sc; //jo abhi source select kia
	position tempDc = Dc;
	if ((Check(dim, B, ((Turn + 1) % 2), Dc, Sc, cpos, cpos2, sizeofbox, rpos, wt, bk)))
	{


		if (cpos2 >= sizeofbox && cpos2 < sizeofbox * 3 + 1)
		{
		
			if (A[tempDc.ri][tempDc.ci] == '-')
			{
				p = W[tempDc.ri][tempDc.ci];
				A[tempDc.ri][tempDc.ci] = W[tempSc.ri][tempSc.ci];
				W[tempSc.ri][tempSc.ci] = '-';
				if ((!Check(dim, A, ((Turn + 1) % 2), Dc, Sc, cpos, cpos2, sizeofbox, rpos, wt, bk)))
				{

					for (int i = 0; i < 10; i++)
					{
						delete L[i];
					}
					delete L;
					L = nullptr;

					for (int i = 0; i < dim; i++)
					{
						delete A[i] ;
					}
					delete A;
					A = nullptr;

					for (int i = 0; i < 10; i++)
					{
						delete  W[i];
					}
					delete W;
					W = nullptr;


					return true;

				}
				
				else 
				{
					for (int i = 0; i < 10; i++)
					{
						delete L[i];
					}
					delete L;
					L = nullptr;

					for (int i = 0; i < dim; i++)
					{
						delete A[i];
					}
					delete A;
					A = nullptr;

					for (int i = 0; i < 10; i++)
					{
						delete  W[i];
					}
					delete W;
					W = nullptr;

					return false;
				}
				
			
			
			}
			

		}

		else if (cpos2 >= Screen_col - (sizeofbox * 3) && cpos2 <= Screen_col - sizeofbox)
		{
			
			if(A[tempDc.ri][tempDc.ci]=='-')
			{

				
				A[tempDc.ri][tempDc.ci] = L[tempSc.ri][tempSc.ci];
				L[tempSc.ri][tempSc.ci] = '-';
				if ((!Check(dim, A, ((Turn + 1) % 2), Dc, Sc, cpos, cpos2, sizeofbox, rpos, wt, bk)))
				{
					for (int i = 0; i < 10; i++)
					{
						delete L[i];
					}
					delete L;
					L = nullptr;

					for (int i = 0; i < dim; i++)
					{
						delete A[i];
					}
					delete A;
					A = nullptr;

					for (int i = 0; i < 10; i++)
					{
						delete  W[i];
					}
					delete W;
					W = nullptr;

					return true;
				}
				else 
				{
					for (int i = 0; i < 10; i++)
					{
						delete L[i];
					}
					delete L;
					L = nullptr;

					for (int i = 0; i < dim; i++)
					{
						delete A[i];
					}
					delete A;
					A = nullptr;

					for (int i = 0; i < 10; i++)
					{
						delete  W[i];
					}
					delete W;
					W = nullptr;

					return false;
				}
			
			}

		
		
		}
		else
		{
			p = A[tempDc.ri][tempDc.ci];
			A[tempDc.ri][tempDc.ci] = A[tempSc.ri][tempSc.ci];
			A[tempSc.ri][tempSc.ci] = '-';
			if ((!Check(dim, A, ((Turn + 1) % 2), Dc, Sc, cpos, cpos2, sizeofbox, rpos, wt, bk)))
			{
				for (int i = 0; i < 10; i++)
				{
					delete L[i];
				}
				delete L;
				L = nullptr;

				for (int i = 0; i < dim; i++)
				{
					delete A[i];
				}
				delete A;
				A = nullptr;

				for (int i = 0; i < 10; i++)
				{
					delete  W[i];
				}
				delete W;
				W = nullptr;
				
				return true;
			}
			else
			{
				for (int i = 0; i < 10; i++)
				{
					delete L[i];
				}
				delete L;
				L = nullptr;

				for (int i = 0; i < dim; i++)
				{
					delete A[i];
				}
				delete A;
				A = nullptr;

				for (int i = 0; i < 10; i++)
				{
					delete  W[i];
				}
				delete W;
				W = nullptr;
				return false;
			}
		}


		

	}
	else
	{
		//self check



		p = A[tempDc.ri][tempDc.ci];
		A[tempDc.ri][tempDc.ci] = A[tempSc.ri][tempSc.ci];
		A[tempSc.ri][tempSc.ci] = '-';
		if ((Check(dim, A, ((Turn + 1) % 2), Dc, Sc, cpos, cpos2, sizeofbox, rpos, wt, bk)))
		{
			for (int i = 0; i < 10; i++)
			{
				delete L[i];
			}
			delete L;
			L = nullptr;

			for (int i = 0; i < dim; i++)
			{
				delete A[i];
			}
			delete A;
			A = nullptr;

			for (int i = 0; i < 10; i++)
			{
				delete  W[i];
			}
			delete W;
			W = nullptr;

			return false;
		}
		

		for (int i = 0; i < 10; i++)
		{
			delete L[i];
		}
		delete L;
		L = nullptr;

		for (int i = 0; i < dim; i++)
		{
			delete A[i];
		}
		delete A;
		A = nullptr;

		for (int i = 0; i < 10; i++)
		{
			delete  W[i];
		}
		delete W;
		W = nullptr;

		return true;

	}




	return true;
}
void Highlight(int ** &A,char** B, position sc, position dc, int turn, char** wt, char** bk, int sizeofbox, int rpos, int cpos,int dim ,int cpos2,position Sc_store)
{



	char p;
	for(int ri=0;ri<9;ri++)
	{
		for(int ci=0;ci<9;ci++)
		{
			dc.ri = ri, dc.ci = ci;
			if (IslegalMove(B, wt, bk, sizeofbox, sc, dc, rpos, cpos) && IsvalidDest(dc, dim, B, turn, cpos2,cpos, sizeofbox)&& Checklegalty(dim, B, turn, dc, sc, cpos, cpos2, sizeofbox, rpos, wt, bk))
				A[ri][ci] = 1;
			else 	A[ri][ci] = 0;
		}
	}

	if ((Check(dim, B, ((turn + 1) % 2), dc, sc, cpos, cpos2, sizeofbox, rpos, wt, bk)))
	{

		for (int ri = 0; ri < 9; ri++)
		{
			for (int ci = 0; ci < 9; ci++)
			{
				dc.ri = ri, dc.ci = ci;
				if (IslegalMove(B, wt, bk, sizeofbox, sc, dc, rpos, cpos) && IsvalidDest(dc, dim, B, turn, cpos2, cpos, sizeofbox))
				{


					if(Checklegalty(dim,B,turn,dc,sc,cpos,cpos2,sizeofbox,rpos,wt,bk))
					{
						A[ri][ci] = 1;
					}
					else 	A[ri][ci] = 0;
				}
				
				else 	A[ri][ci] = 0;
			}
		}
	}

	if ((cpos > sizeofbox * 4) && (cpos < (Screen_col - sizeofbox * 4)))
	{
		A[Sc_store.ri][Sc_store.ci] = 1;

	}
	
	else 
	A[Sc_store.ri][Sc_store.ci]=0;

}
void Highlighter(int** A, char** B, int dim, int sizeOfBox, int clr1, int clr2,position Sc)
{
	bool check = 1;
	SetClr(clr2);
	if (sizeOfBox % 2 == 0)
	{
		sizeOfBox += 1;
	}


	

	int count = 0;
	int r = 0, c = 0;
	for (int bri = sizeOfBox; bri < sizeOfBox * dim + sizeOfBox; bri += sizeOfBox)
	{
		for (int bci = sizeOfBox + 44; bci < sizeOfBox * dim + sizeOfBox + 44; bci += sizeOfBox)
		{
			for (int ri = bri; ri < bri + sizeOfBox; ri++)
			{

				for (int ci = bci; ci < bci + sizeOfBox; ci++)
				{

			
						if (A[r][c] == 1 && count==0)
						{
							if(B[r][c]=='-')
							
								
								HIghlightedBox(sizeOfBox, 5, ri, ci);

							else if ((Sc.ri == r && Sc.ci == c) && A[r][c] == 1)
								HIghlightedBox(sizeOfBox, 2, ri, ci);

							else
								HIghlightedBox(sizeOfBox, 4, ri, ci);

								
								count++;
						
						}
						

				}

			}

			
			if (c == dim - 1)
				c = 0;
			else c++;
			
			count = 0;
		}

		r++;
	}





}
void UnHighlighter(int** A, char** B, int dim, int sizeOfBox, int clr1, int clr2)
{
	bool check = 1;
	SetClr(clr2);
	if (sizeOfBox % 2 == 0)
	{
		sizeOfBox += 1;
	}




	int count = 0;
	int r = 0, c = 0;
	for (int bri = sizeOfBox; bri < sizeOfBox * dim + sizeOfBox; bri += sizeOfBox)
	{
		for (int bci = sizeOfBox + 44; bci < sizeOfBox * dim + sizeOfBox + 44; bci += sizeOfBox)
		{
			for (int ri = bri; ri < bri + sizeOfBox; ri++)
			{

				for (int ci = bci; ci < bci + sizeOfBox; ci++)
				{


					if (A[r][c] == 1 && count == 0)
					{
						


							if (check == 1)
						
								HIghlightedBox(sizeOfBox, clr2, ri, ci);
							else
								HIghlightedBox(sizeOfBox, clr1, ri, ci);

						


						count++;

					}


				}

			}

			if ((bri + bci) % 2 == 0)
			{
				SetClr(clr1);
				check = 0;

			}
			else
			{
				SetClr(clr2);
				check = 1;
			}
			if (c == dim - 1)
				c = 0;
			else c++;
			count = 0;
		}

		r++;
	}





}
void KingUnHighlight( char** B, int dim, int sizeOfBox, int clr1, int clr2,int Turn,position Sc_Store)
{
	bool check = 1;
	
	if (sizeOfBox % 2 == 0)
	{
		sizeOfBox += 1;
	}




	int count = 0;
	int r = 0, c = 0;
	for (int bri = sizeOfBox; bri < sizeOfBox * dim + sizeOfBox; bri += sizeOfBox)
	{
		for (int bci = sizeOfBox + 44; bci < sizeOfBox * dim + sizeOfBox + 44; bci += sizeOfBox)
		{
			for (int ri = bri; ri < bri + sizeOfBox; ri++)
			{

				for (int ci = bci; ci < bci + sizeOfBox; ci++)
				{


					if (Turn == white)
					{
						if ((B[r][c] == 'K' || (r == Sc_Store.ri && c == Sc_Store.ci)) && count == 0)
						{
							if (check == 1)

							{

								HIghlightedBox(sizeOfBox, clr2, ri, ci);

								count++;

							}
							else
							{

								HIghlightedBox(sizeOfBox, clr1, ri, ci);

								count++;
							}



						}

					}
					if (Turn == black)
					{
						if ((B[r][c] == 'k' || (r == Sc_Store.ri && c == Sc_Store.ci)) && count == 0)
						{

							if (check == 1)

							{

								HIghlightedBox(sizeOfBox, clr2, ri, ci);

								count++;

							}
							else
							{

								HIghlightedBox(sizeOfBox, clr1, ri, ci);

								count++;

							}
						
						}
				
					}

				}

			}

			if ((bri + bci) % 2 == 0)
			{
				
				check = 0;

			}
			else
			{
				
				check = 1;
			}
			if (c == dim - 1)
				c = 0;
			else c++;
			count = 0;
		}

		r++;
	}





}
void KingHighlight( char** B, int dim, int sizeOfBox,int Turn,int clr1,int clr2,position Sc_store)
{


	bool check = 1;

	if (sizeOfBox % 2 == 0)
	{
		sizeOfBox += 1;
	}

	int count = 0;
	int r = 0, c = 0;
	for (int bri = sizeOfBox; bri < sizeOfBox * dim + sizeOfBox; bri += sizeOfBox)
	{
		for (int bci = sizeOfBox + 44; bci < sizeOfBox * dim + sizeOfBox + 44; bci += sizeOfBox)
		{
			for (int ri = bri; ri < bri + sizeOfBox; ri++)
			{

				for (int ci = bci; ci < bci + sizeOfBox; ci++)
				{

					if(Turn==white)
					{
						if (B[r][c] == 'K' && count == 0)
						{
					
								HIghlightedBox(sizeOfBox, clr1, ri, ci);

							count++;

						}
						if ((r == Sc_store.ri && c == Sc_store.ci) && count == 0)
						{

							HIghlightedBox(sizeOfBox, clr2, ri, ci);

							count++;

						}
					}

					if (Turn == black)
					{
						if (B[r][c] == 'k' && count == 0)
						{
							
								HIghlightedBox(sizeOfBox, clr1, ri, ci);

							count++;

						}
						if ((r == Sc_store.ri && c == Sc_store.ci) && count == 0)
						{

							HIghlightedBox(sizeOfBox, clr2, ri, ci);

							count++;

						}
					
					
					}

				}

			}


			if (c == dim - 1)
				c = 0;
			else c++;

			count = 0;
		}

		r++;
	}





}
bool CheckMate(int dim, char** B, int Turn, position Dc, position Sc, int cpos, int cpos2, int sizeofbox, int rpos, char** wt, char** bk)
{

	cpos = -999;
	cpos2 = -999;
	if ((Check(dim, B, ((Turn + 1) % 2), Dc, Sc, cpos, cpos2, sizeofbox, rpos, wt, bk)))
	{
		for (int sri = 0; sri < dim; sri++)
		{
			for (int sci = 0; sci < dim; sci++)
			{
				Sc.ri = sri, Sc.ci = sci;

					for (int dri = 0; dri < dim; dri++)
					{
						if (!IsvalidSrc(Sc, dim, B, Turn, rpos, cpos, sizeofbox, wt, bk))
						{
							break;
						}

						for (int dci = 0; dci < dim; dci++)
						{
							Dc.ri = dri, Dc.ci = dci;
							if (IsvalidDest(Dc, dim, B, Turn, cpos, cpos2, sizeofbox) && (IslegalMove(B, wt, bk, sizeofbox, Sc, Dc, rpos, cpos)&& Checklegalty(dim, B, Turn, Dc, Sc, cpos, cpos2, sizeofbox, rpos, wt, bk)))
							{
								
									return false;
							}
							
						
						}

					}

			}

		}


		return true;
	
	}



	
}
void CheckMateMsg(string Pnames[], int dim, char** B, int Turn, position Dc, position Sc, int cpos, int cpos2, int sizeofbox, int rpos, char** wt, char** bk)
{

	if (CheckMate(dim, B, Turn, Dc, Sc, cpos, cpos2, sizeofbox, rpos, wt, bk))
	{
		SetClr(0);
		gotoRowCol(sizeofbox * 11, sizeofbox * 11);
		cout << "                                  ";
		SetClr(15);
		gotoRowCol(sizeofbox * 11, sizeofbox * 11);
		cout << "CHECK Mate!";
		gotoRowCol(sizeofbox * 11 + 4, sizeofbox * 11 - 5);
		cout << "!!!!! " << Pnames[Turn ] << " Wins !!!!!";
		
	}
	
}
void CheckMsg(string Pnames[], int dim, char** B, int Turn, position Dc, position Sc, int cpos, int cpos2, int sizeofbox, int rpos, char** wt, char** bk)
{

	if (CheckMate(dim, B, ((Turn + 1) % 2), Dc, Sc, cpos, cpos2, sizeofbox, rpos, wt, bk))
	{
		SetClr(0);
		gotoRowCol(sizeofbox * 11, sizeofbox * 11);
		cout << "                                  ";
		SetClr(15);
		gotoRowCol(sizeofbox * 11, sizeofbox * 11);
		cout << "CHECK Mate!";
		gotoRowCol(sizeofbox * 11 + 4, sizeofbox * 11 - 5);
		cout << "!!!!! " << Pnames[Turn] << " Wins !!!!!";
	}
	else if (Check(dim, B, Turn, Dc, Sc, cpos, cpos2, sizeofbox, rpos, wt, bk))
	{
		SetClr(0);
		gotoRowCol(sizeofbox * 11, sizeofbox * 11);
		cout << "                                  ";
		SetClr(15);
		gotoRowCol(sizeofbox * 11-1, sizeofbox * 11);
		cout << "CHECK!";
		gotoRowCol(sizeofbox * 11 + 2, sizeofbox * 11 - 5);
		cout << "Be Aware " << Pnames[(Turn + 1) % 2]<<" !";
		gotoRowCol(sizeofbox * 11 + 5, sizeofbox * 11 - 10);
		cout << "(Press Any Key To Continue)";

		_getch();

	}
}
void CheckMsg2(string Pnames[], int dim, char** B, int Turn, position Dc, position Sc, int cpos, int cpos2, int sizeofbox, int rpos, char** wt, char** bk)
{

	{
		SetClr(0);
		gotoRowCol(sizeofbox * 11, sizeofbox * 11);
		cout << "                                  ";
		SetClr(15);
		gotoRowCol(sizeofbox * 11, sizeofbox * 11);
		cout << "CHECK Mate!";
		gotoRowCol(sizeofbox * 11 + 4, sizeofbox * 11 - 5);
		cout << "!!!!! " << Pnames[Turn] << " Wins !!!!!";
	}

}
void Replay(char*** Rep, char**& B, int& repindx, int& repsdIndx, int dim, int sizeOfBox, position Sc, position Dc, int& turn, string Pnames[], char** wt, char** bk, char*** repUW, char*** repUK, int** repsarr, int** repdarr, char destpiece, int cpos2, int copss,int *cposArr,int *cpos2Arr)
{

	int start = 0;
	if (ReplayMsg() == 1)
	{
		UndoLogo();
		decor(sizeOfBox, dim);
		
		

		while (start <= repindx)
		{



			for (int r = 0; r < dim; r++)
			{

				for (int c = 0; c < dim; c++)
				{


					B[r][c] = Rep[start][r][c];



				}

			}

			for (int r = 0; r < dim; r++)
			{

				for (int c = 0; c < 2; c++)
				{


					wt[r][c] = repUW[start][r][c];



				}

			}
			for (int r = 0; r < dim; r++)
			{

				for (int c = 0; c < 2; c++)
				{


					bk[r][c] = repUK[start][r][c];



				}

			}

			if (start == 0)
			{

				UndoLogo();
				decor(sizeOfBox, dim);
				Grid(B, dim, sizeOfBox, 8, 15);
				whiteGrid(wt, dim, sizeOfBox, 8, 15);
				blackGrid(bk, dim, sizeOfBox, 8, 15);


			}

			//Grid(B, dim, sizeOfBox, 8, 15);
			if (turn == black &&start<repindx)
				whiteGrid(wt, dim, sizeOfBox, 8, 15);
			if (turn == white &&start < repindx)
				blackGrid(bk, dim, sizeOfBox, 8, 15);
			//if (start > 0)
			{
				//start--;
				Sc.ri = repsarr[start][0];
				Sc.ci = repsarr[start][1];

				Dc.ri = repdarr[start][0];
				Dc.ci = repdarr[start][1];
				//start++;


				copss = cposArr[start];
				cpos2 = cpos2Arr[start];
				
				SourceDest(B, wt, bk, dim, sizeOfBox, 8, 15, Sc, Dc, cpos2, copss, destpiece, turn);
			}
			/*Grid(B, dim, sizeOfBox, 8, 15);
			whiteGrid(wt, dim, sizeOfBox, 8, 15);
			blackGrid(bk, dim, sizeOfBox, 8, 15);*/


			turn = ((turn + 1) % 2);
			TurnMessageOnly(Pnames, turn, sizeOfBox);

			start++;

			Sleep(300);

		}
	}
	
	else	
	{
		system("cls");
	
	
	}


}

int main()
{
	cin.clear();
	SetClr(15);
	int dim = 9;
	int** A;
	int choice = 0;
	int rpos=0, cpos=0;
	int rpos2=rpos, cpos2=rpos;
	char** B;
	char** Wt;	char** Bl;
	int Turn;
	char*** undoB;
	char*** undoW;
	char*** undoK;
	int** Sc_Arr;
	int ** Dc_Arr;

	char*** RepB;
	char*** RepW;
	char*** RepK;
	int** Rep_Sc_Arr;
	int** Rep_Dc_Arr;
	char* dp;
	char destpiece{};
	char sourcepiece;
	int UD_indx=0;
	int sdIndx = 0;
	int* cposArr;
	int* cpos2Arr;
	int* repcposArr;
	int* repcpos2Arr;
	int repUD_indx = 0;
	int Rep_sdIndx = 0;
	string Pnames[100]{};
	int wtc = 0; int wtr = 0;
	int bkc = 0; int bkr = 0;
	position Sc{}, Dc{};
	int sizeOfBox = 7;
	const int nop = 2;
	string Array[nop];
	int rs = 77, cs = 150;
	position Sc_store{};

	int tr = 0;


	
	Init("Text.txt",A,B, Wt, Bl, Turn, Pnames, dim, choice,undoB,undoW,undoK,Sc_Arr,Dc_Arr,RepB,RepW,RepK,Rep_Sc_Arr,Rep_Dc_Arr,cposArr,cpos2Arr, repcposArr, repcpos2Arr,dp);
	Grid(B, dim, sizeOfBox, 8, 15);
	UndoLogo();
	decor(sizeOfBox, dim);
	whiteGrid(Wt, dim, sizeOfBox, 8, 15);
	blackGrid(Bl, dim, sizeOfBox, 8, 15);
	TurnMessage(Pnames, Turn, choice, sizeOfBox);
	
	while (1) {
		
		
		loadundo(undoB, undoW, undoK, UD_indx, B, dim, Turn, Wt, Bl, Pnames);
		if (CheckNew(dim, B, Turn, Dc, Sc, cpos, cpos2, sizeOfBox, rpos, Wt, Bl, Sc_store))
		{
			KingHighlight(B, dim, sizeOfBox, Turn, 4, 2, Sc_store);
			CheckMsg(Pnames, dim, B, Turn, Dc, Sc, cpos, cpos2, sizeOfBox, rpos, Wt, Bl);
			KingUnHighlight(B, dim, sizeOfBox, 8, 15, Turn, Sc_store);
			if (CheckMate(dim, B, (Turn + 1) % 2, Dc, Sc, cpos, cpos2, sizeOfBox, rpos, Wt, Bl))
			{
				KingHighlight(B, dim, sizeOfBox, (Turn), 6, 2, Sc_store);
				loadreplay(RepB, RepW, RepK, repUD_indx, B, dim, Turn, Wt, Bl, Pnames);
				Savegame("Text1.txt", undoB,UD_indx,B, dim, Turn, Wt, Bl, Pnames);
				_getch();
				break;
			}
		}
		
		do
		{
			do
			{
				do
				{
					do {
						SelectPosition("Source ", Sc, dim, sizeOfBox, Wt, Bl, rpos, cpos, rpos2, cpos2, undoB, B, UD_indx, sdIndx, Sc, Dc, Turn, Pnames, Wt, Bl, undoW, undoK, Sc_Arr, Dc_Arr, destpiece, cpos2Arr, cposArr, dp);
					} while (!IsvalidSrc(Sc, dim, B, Turn, rpos, cpos, sizeOfBox, Wt, Bl));

					//Grid(B, dim, sizeOfBox, 8, 15);
					highlightCages(dim, sizeOfBox, 8, 15, Sc, cpos);
					Highlight(A, B, Sc, Dc, Turn, Wt, Bl, sizeOfBox, rpos, cpos, dim, cpos2,Sc);
					Highlighter(A, B, dim, sizeOfBox, 8, 15, Sc);
					
					
					SelectPosition("Destination ", Dc, dim, sizeOfBox, Wt, Bl, rpos, cpos, rpos2, cpos2, undoB, B, UD_indx, sdIndx, Sc, Dc, Turn, Pnames, Wt, Bl, undoW, undoK, Sc_Arr, Dc_Arr, destpiece, cpos2Arr, cposArr, dp);
					UnhighlightCages(dim, sizeOfBox, 8, 15, Sc, cpos2);
					UnHighlighter(A, B, dim, sizeOfBox, 8, 15);

				} while (!IsvalidDest(Dc, dim, B, Turn, cpos, cpos2, sizeOfBox));

			} while (!IslegalMove(B, Wt, Bl, sizeOfBox, Sc, Dc, rpos2, cpos2));
		
		}
		while (!Checklegalty(dim,B,Turn,Dc,Sc,cpos,cpos2,sizeOfBox,rpos,Wt,Bl));

		

		UPdateBoard(Sc, Dc, B, Wt, Bl, wtc, wtr, bkc, bkr, Turn,rpos2,cpos2,sizeOfBox,destpiece,sourcepiece,Sc_Arr,Dc_Arr,sdIndx, Rep_Sc_Arr, Rep_Dc_Arr, Rep_sdIndx,cposArr,cpos2Arr,cpos, repcposArr, repcpos2Arr,dp);
		
		if (Promotion(dim, B, Sc, Dc, Turn, cpos2, sizeOfBox))
		{
			Grid(B, dim, sizeOfBox, 8, 15);
			UndoLogo();
			decor(sizeOfBox, dim);
			blackGrid(Bl, dim, sizeOfBox, 8, 15);
			whiteGrid(Wt, dim, sizeOfBox, 8, 15);
		}

		SourceDest(B,Wt,Bl, dim, sizeOfBox, 8, 15,Sc,Dc,cpos2,cpos,destpiece,Turn);

		//blackGrid(Bl, dim, sizeOfBox, 8, 15);
		//whiteGrid(Wt, dim, sizeOfBox, 8, 15);
	
		if (CheckNew(dim, B, Turn, Dc, Sc, cpos, cpos2, sizeOfBox, rpos, Wt, Bl,Sc_store))
		{
			KingHighlight(B, dim, sizeOfBox, Turn,4,2,Sc_store);
			CheckMsg(Pnames, dim, B, Turn, Dc, Sc, cpos, cpos2, sizeOfBox, rpos, Wt, Bl);
			KingUnHighlight(B, dim, sizeOfBox,  8,15,Turn,Sc_store);
			if (CheckMate(dim, B, (Turn + 1)%2, Dc, Sc, cpos, cpos2, sizeOfBox, rpos, Wt, Bl))
			{
				KingHighlight(B, dim, sizeOfBox, (Turn), 6, 2, Sc_store);
				loadreplay(RepB, RepW, RepK, repUD_indx, B, dim, Turn, Wt, Bl, Pnames);
				Savegame("Text1.txt", undoB,UD_indx,B, dim, Turn, Wt, Bl, Pnames);
				_getch();
				break;
			}
		}
		TurnMessage(Pnames, Turn, choice, sizeOfBox);
		if (CheckMate(dim, B, Turn, Dc, Sc, cpos, cpos2, sizeOfBox, rpos, Wt, Bl))
		{
			KingHighlight(B, dim, sizeOfBox, ((Turn + 1)%2), 6, 2, Sc_store);
			CheckMsg2(Pnames, dim, B, ((Turn + 1) % 2), Dc, Sc, cpos, cpos2, sizeOfBox, rpos, Wt, Bl);
			loadreplay(RepB, RepW, RepK, repUD_indx, B, dim, Turn, Wt, Bl, Pnames);
			Savegame("Text1.txt", undoB, UD_indx, B, dim, Turn, Wt, Bl, Pnames);
			_getch();
			break;
		}


		Savegame("Text1.txt", undoB, UD_indx, B, dim, Turn, Wt, Bl, Pnames);
		
		//Undo(undoB, B, UD_indx, sdIndx, dim, sizeOfBox, Sc, Dc, Turn, Pnames, Wt, Bl, undoW, undoK, Sc_Arr, Dc_Arr, destpiece, cpos2, cpos, cpos2Arr, cposArr, dp);
		loadreplay(RepB, RepW, RepK, repUD_indx, B, dim, Turn, Wt, Bl, Pnames);
	
		
	}


	system("cls");


	Replay(RepB, B, repUD_indx, Rep_sdIndx, dim, sizeOfBox, Sc, Dc, Turn, Pnames, Wt, Bl, RepW, RepK, Rep_Sc_Arr, Rep_Dc_Arr, destpiece, cpos2,cpos,repcpos2Arr, repcposArr);


	_getch();
	return 0;
	
}




