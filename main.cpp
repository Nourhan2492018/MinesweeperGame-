#include<iostream>
#include<iomanip>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<windows.h>
#include<fstream>

using namespace std;

struct the_player {
	string first_name;
	string last_name;
	float age;
	float score;
};

the_player player();
the_player the_score();

void topTen(the_player gamer);
void playAgain();
void information();
void ShowUp(int, int);
void MinePositions();
void putOrRemoveFlag();
bool WinGame();
void inputSymbol();
void CellNumber(int, int);
void PrintTable(char); // to make the shape of the outer shape
void GameTable();
void OpenCell();
void display();
void Game();

char Table[10][10];//the * of the table(game table visible to the player)
char PositionsOfMines[10][10]; //array
char Symbol; //(O) for open cell & (F) for put or remove flag

the_player gamer;
the_player gamers;

int starCount = 0;
int FlagCount = 10;
int MinesFlaggedCount = 0;

bool LoseGame = false;

time_t timeSinceStart = time(0);
time_t GameTime;

int main()
{
	Game();
	return 0;
}

void topTen()
{

	ofstream out("TopTen.txt");

	out << "Name" << setw(42) << "Age" << "\t" << "\t" << "\t" << "\t" << "The Score" << "\n";

	out << "______________________________________________________________________________________\n";
	out << "\n";
	for (int i = 0; i < 10; i++) {
		out << i + 1 << "- " << gamer.first_name << " " << gamer.last_name << setw(29) << gamer.age << setw(30);

		if ((gamers.score) >= 60)
			out << fixed << setprecision(2) << ((gamers.score) / 60.0) << " " << "Min\n";
		else
			out << (gamers.score) << " " << "Sec\n";
		out << endl;
	}
	out.close();

}

the_player the_score()
{
	GameTime = time(0);

	gamers.score = (GameTime - timeSinceStart);

	return gamers;

}

void display()
{

	cout << setw(65) << "MINESWEEPER\n";
	cout << "\n";
	cout << "Remember The Rules:-\n";
	cout << "Enter (O) To Open Cell & Put Its Coordinates (X)(Y)\n";
	cout << "Enter (F) To Put Or Remove Flag & Put The Cell Coordinates (X)(Y)\n";
	cout << "\n";
}

the_player player()
{

	system("color E");

	cout << setw(65) << "MINESWEEPER\n";
	cout << "Enter Your First Name :" << " ";
	cin >> gamer.first_name;
	cout << "\n";
	cout << "Enter Your Last Name :" << " ";
	cin >> gamer.last_name;
	cout << "\n";
	cout << "Enter  Your Age :" << " ";
	cin >> gamer.age;
	cout << "\n";
	cout << "\n";

	return gamer;
}

void playAgain()
{

	char s;
	cout << "To Play Again Press --> (P)\n";
	cin >> s;
	system("cls");
	if (s == 'p' || s == 'P') {
		Game();
	}
}

void information()
{
	system("color E");
	cout << setw(65) << "MINESWEEPER\n";
	cout << "\n";
	cout << "How To Play... (Instructions):-\n";
	cout << "\n";
	cout << setw(70) << "In Order To Win The Game, You Must Reveal All The cells\n"
		<< setw(71) << "That Do Not Have A Mine, Or To Flag All Cells With Mines\n"
		<< setw(73) << "It Is A Matter Of Personal Preference. If A Mine Is Shown,\n"
		<< setw(73) << "The Player Loses. --->> Remember A Number On A Cell Refers\n"
		<< setw(75) << "To The Number Of Mines That Are Currently Touching That Cell\n";
	cout << "\n";
	cout << "\n";

	cout << "Rules :-\n";
	cout << "\n";
	cout << setw(66) << "Enter (O) To Open Cell & Put Its Coordinates (X)(Y)\n"
		<< setw(80) << "Enter (F) To Put Or Remove Flag & Put The Cell Coordinates (X)(Y)\n";
	cout << "\n";
	cout << "\n";

	cout << "About :-\n";
	cout << "\n";
	cout << setw(45) << "It Is A C++ Program Written By\n"
		<< setw(45) << "Abdullah Afify & Amar Ashraf &\n"
		<< setw(44) << "Joseph Wagih & Fouad Mamdouh \n"
		<< setw(28) << "Mohamed Ahmed\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";

}

void MinePositions() ///put mines
{
	int counter = 0;
	srand(time(NULL));

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			PositionsOfMines[i][j] = '0';

	int i = 0, j = 0;

	while (counter < 10) {
		int i = rand() % 10;
		int j = rand() % 10;

		if (PositionsOfMines[i][j] == '0') {
			PositionsOfMines[i][j] = 'X';

			CellNumber(i - 1, j);
			CellNumber(i + 1, j);

			CellNumber(i, j - 1);
			CellNumber(i, j + 1);

			CellNumber(i - 1, j - 1);
			CellNumber(i - 1, j + 1);
			CellNumber(i + 1, j - 1);
			CellNumber(i + 1, j + 1);

			counter++;

		}

	}
}

void CellNumber(int i, int j)
{
	if (i >= 0 && i < 10 && j >= 0 && j < 10 && PositionsOfMines[i][j] != 'X') {
		PositionsOfMines[i][j]++; //increasing the numbers of the table (0,1,2..)
	}

}

void GameTable()
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			Table[i][j] = '*';
			starCount++;
		}
	}
}

void PrintTable(char arr[10][10])
{
	cout << "    ";

	for (int i = 0; i < 10; i++)
		cout << setw(3) << i;
	cout << "\n" << "  ";

	for (int i = 0; i < 33; i++)  //33(_)to make a horizontal line
		cout << "_";
	cout << "\n";

	for (int i = 0; i < 10; i++) {
		cout << setw(3) << i << "|"; // 10 (|)to make a vertical line

		for (int j = 0; j < 10; j++)
			cout << setw(3) << arr[i][j];
		cout << "\n";
	}
}

void OpenCell()
{
	int i, j;

	do {
		cin >> i >> j;
	} while (i < 0 || i > 9 || j < 0 || j > 9);


	if (PositionsOfMines[i][j] == 'X') {
		Table[i][j] = 'X';
		LoseGame = true;

		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				if (PositionsOfMines[i][j] == 'X')
					Table[i][j] = 'X';
	}
	else
		ShowUp(i, j);
}

void putOrRemoveFlag()
{

	int i, j;

	do {
		cin >> i >> j;
	} while (i < 0 || i > 9 || j < 0 || j > 9);


	if (Table[i][j] == '*') {
		Table[i][j] = 'F';
		FlagCount--;

		if (PositionsOfMines[i][j] == 'X')
			MinesFlaggedCount++;
	}
	else if (Table[i][j] == 'F') {
		Table[i][j] = '*';
		FlagCount++;

		if (PositionsOfMines[i][j] == 'X')
			MinesFlaggedCount--;
	}
}


void inputSymbol()
{
	cout << "Enter Symbol(O)or(F) & Coordinates (X)(Y)\n";
	cin >> Symbol;

	switch (Symbol) {
	case'o':
	case'O':OpenCell();
		break;
	case'f':
	case'F':putOrRemoveFlag();
		break;
	default:
		inputSymbol();
	}
}

void ShowUp(int i, int j)
{
	if (Table[i][j] == '*' && PositionsOfMines[i][j] != 'X' && i >= 0 && i < 10 && j >= 0 && j < 10) {
		Table[i][j] = PositionsOfMines[i][j];

		if (PositionsOfMines[i][j] == '0') {

			ShowUp(i, j - 1);
			ShowUp(i, j + 1);

			ShowUp(i - 1, j - 1);
			ShowUp(i + 1, j - 1);
			ShowUp(i + 1, j + 1);
			ShowUp(i - 1, j + 1);

			ShowUp(i - 1, j);
			ShowUp(i + 1, j);

			starCount--;
		}
	}
}

bool WinGame()
{
	if (FlagCount == 0 && MinesFlaggedCount == 10 || starCount == 10 && FlagCount == 10 || starCount + (10 - FlagCount) == 10)
		return 1;
	else
		return 0;
}

void Game()
{
	LoseGame = false;

	player();
	system("cls");

	information();
	system("pause");
	system("cls");

	timeSinceStart = time(0);


	GameTable();
	MinePositions();

	while (!LoseGame && !WinGame()) {

		the_score();

		display();
		PrintTable(Table);

		GameTime = time(0);
		cout << "\n" << "Flags :" << FlagCount << "\n";
		cout << "\n";
		cout << "Mine Flagged :" << MinesFlaggedCount << "\n";
		cout << "\n";
		cout << "Time :";
		if ((GameTime - timeSinceStart) >= 60)
			cout << fixed << setprecision(2) << ((GameTime - timeSinceStart) / 60.0) << " " << "Min\n";
		else
			cout << (GameTime - timeSinceStart) << " " << "Sec\n";
		cout << "\n";

		inputSymbol();
		system("cls");

		starCount = 100;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (Table[i][j] == '1' || Table[i][j] == '2' || Table[i][j] == '0')
					starCount--;
			}
		}
		starCount = starCount - (10 - FlagCount);


	}
	if (LoseGame) {
		cout << setw(65) << "MINESWEEPER\n";
		PrintTable(Table);
		cout << "\n" << setw(65) << "GAME OVER" << "\n";

	}
	if (WinGame()) {
		cout << setw(65) << "MINESWEEPER\n";
		PrintTable(Table);
		cout << setw(73) << "CONGRATULATIOS YOU WIN " << "\n";
		cout << setw(68) << "Time To Complete :";
		if ((GameTime - timeSinceStart) >= 60)
			cout << fixed << setprecision(2) << ((GameTime - timeSinceStart) / 60.0) << " " << "Min\n";
		else
			cout << (GameTime - timeSinceStart) << " " << "Sec\n";
	}
	topTen();
	playAgain();

}