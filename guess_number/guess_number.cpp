// guess_the_number.cpp : Defines the entry point for the console application.
// Created by Robert Volarić, my first application ever

#include <ctime>
#include <cstdlib>
#include "stdafx.h"
#include <string>
#include <iostream>
#include "conio.h"
#include <time.h>
#include <iomanip>
#include <algorithm>
#include <windows.h>


using namespace std;


int tenNum, gnum; //secret number 0-10
string invalid = "Invalid input !";
int range(string myRange)
{
	int a;
	if (myRange == "1") { a = 11; }
	else if (myRange == "2") { a = 101; }
	else if (myRange == "3") { a = 1001; }
	else { return 0; }
	int numTen;
	srand(time(NULL));
	numTen = rand() % a;
	return numTen;
}


string players(string playerNames)
{

	char tab2[1024];
	strncpy_s(tab2, playerNames.c_str(), sizeof(tab2));
	tab2[sizeof(tab2) - 1] = 0;


	int i = 0;

	char c;
	while (tab2[i])
	{
		c = tab2[i];
		putchar(toupper(c));
		i++;
	}

	string str(tab2);
	return str;
}
string chooseRange, cont;



int main()
{

	int choosePlayer = 1;
	string numPlayer, playerOne, playerTwo, playerThree, playerFour, playerNames;
	cout << "Welcome to play GUESS THE NUMBER !" << endl << "Created by Robert Volarich.\n\n";
	while (choosePlayer == 1)
	{
		int loop_1 = 1, playerOneScore = 0, playerTwoScore = 0, playerThreeScore = 0, playerFourScore = 0;
		int playerOneTry = 1;
		cout << "Choose the number of players (1-4): ";
		cin >> numPlayer;


		if (numPlayer == "1")
		{

			cout << "\nEnter the name of player: ";
			cin >> playerOne;
			while (loop_1 == 1)
			{
				cout << "\nChoose the range (1-3): \n\n";
				cout << "1. 0-10 ( inclusive )\n2. 0-100 ( inclusive)\n3. 0-1000 ( inclusive)";
				cin >> chooseRange;
				if ((chooseRange == "1") || (chooseRange == "2") || (chooseRange == "3"))
				{
					tenNum = range(chooseRange);  //calls rangeTen function //
					loop_1 = 2;
				}
				else { cout << "\nInvalid input !\n"; }


			}

			cout << "\nGenerating secret number";

			for (int i(0); i < 5; i++)
			{
				cout << ". "; Sleep(200);
			}
			cout << "\nThe secret number has been generated.\n";

			for (int i(0); i < 2; i++)
			{
				Beep(800, 250);
			}

			while (playerOneScore < 3)
			{
			tenRange:

				cout << "\n" << playerOne << ", guess the number: ";
				cin >> gnum;
				if (gnum < tenNum)
				{
					cout << "\nYou are low !\n";
					playerOneTry += 1;
				}
				else if (gnum > tenNum)
				{
					if (chooseRange == "1")
					{
						if (gnum >= 0 && gnum < 11)
						{
							cout << "\nYou are high !\n";
							playerOneTry += 1;
						}
						else { cout << "\nInvalid input !\n"; goto tenRange; }
					}
					if (chooseRange == "2")
					{
						if (gnum >= 0 && gnum < 101)
						{
							cout << "\nYou are high !\n";
							playerOneTry += 1;
						}
						else { cout << "\nInvalid input !\n"; goto tenRange; }
					}
					if (chooseRange == "3")
					{
						if (gnum >= 0 && gnum < 1001)
						{
							cout << "\nYou are high !\n";
							playerOneTry += 1;
						}
						else { cout << "\nInvalid input !\n"; goto tenRange; }
					}
				}
				else if (gnum == tenNum)
				{
					Beep(698.46, 150); Beep(987.77, 150);
					playerOneScore += 1;
					cout << "\nYOU GUESSED THE NUMBER !!!!";
					cout << "\n\n\n" << setw(18) << "SCORE\n\n" << playerOne << ": " << playerOneScore;
					cout << "\nNumber of tryouts: " << playerOneTry << endl;
					playerOneTry = 1;
					tenNum = range(chooseRange);  //calls rangeTen function //
					cout << endl;
				}
				else if (gnum >10)
				{
					cout << "\nInvalid input !\n";
				}
			}

			cout << setw(17) << "THE END\n\n";
		playerOneGoto:
			cout << "\nTry again ? (y/n): ";
			cin >> cont;
			if (cont == "y")
			{
				loop_1 = 1; playerOneScore = 0;
#define windows 1
				system("cls");
			}
			else if (cont == "n")
			{
				cout << "\n\n" << setw(55) << "Thank you for playing GUESS THE NUMBER";
				loop_1 = 2;
				Sleep(1500);
				return 0;
			}
			else
			{
				cout << "\nInvalid input !\n";
				goto playerOneGoto;
			}
		}
		else if (numPlayer == "2")                                 //TWO PLAYER START
		{
			cout << "\nEnter the name of 1st player: ";
			cin >> playerOne;
			cout << "Enter the name of 2nd player: ";
			cin >> playerTwo;
			int i = 1;
			while (loop_1 == 1)
			{
				cout << "\nChoose the range (1-3): \n\n";
				cout << "1. 0-10 ( inclusive )\n2. 0-100 ( inclusive)\n3. 0-1000 ( inclusive)";
				cin >> chooseRange;
				if ((chooseRange == "1") || (chooseRange == "2") || (chooseRange == "3"))
				{
					tenNum = range(chooseRange);  //calls rangeTen function //
					loop_1 = 2;
				}
				else { cout << "\nInvalid input !\n"; }

			}


			cout << "\nGenerating secret number";

			for (int i(0); i < 5; i++)
			{
				cout << ". "; Sleep(200);
			}
			cout << "\nThe secret number has been generated.\n";

			for (int i(0); i < 2; i++)
			{
				Beep(800, 250);
			}

		TwotenRange:


			while ((playerOneScore < 3) && (playerTwoScore < 3))
			{

				if (i % 2 == 1)
				{
					cout << "\n" << playerOne << ", guess the number: ";
					cin >> gnum;

				}
				else
				{
					cout << "\n" << playerTwo << ", guess the number: ";
					cin >> gnum;

				}
				if (gnum < tenNum)
				{
					cout << "\nYou are low !\n";
					i += 1;
				}
				else if (gnum > tenNum)
				{
					if (chooseRange == "1")
					{
						if (gnum >= 0 && gnum < 11)
						{
							cout << "\nYou are high !\n";
							i += 1;
						}
						else { cout << "\nInvalid input !\n"; goto TwotenRange; }
					}
					if (chooseRange == "2")
					{
						if (gnum >= 0 && gnum < 101)
						{
							cout << "\nYou are high !\n";
							i += 1;
						}
						else { cout << "\nInvalid input !\n"; goto TwotenRange; }
					}
					if (chooseRange == "3")
					{
						if (gnum >= 0 && gnum < 1001)
						{
							cout << "\nYou are high !\n";
							i += 1;
						}
						else { cout << "\nInvalid input !\n"; goto TwotenRange; }
					}
				}
				else if (gnum == tenNum)
				{
					if (i % 2 == 1)
					{
						playerOneScore += 1;
						cout << endl;
						string a = players(playerOne);
						cout << " GUESSED THE NUMBER !!!!";
						if (playerOneScore == 3)
						{
							i += 1;
							goto end;
						}
						Beep(698.46, 150); Beep(987.77, 150);
						i += 1;
					}
					else
					{
						playerTwoScore += 1;
						cout << endl;
						string a = players(playerTwo);
						cout << " GUESSED THE NUMBER !!!!";
						if (playerTwoScore == 3)
						{
							i += 1;
							goto end;
						}
						Beep(698.46, 150); Beep(987.77, 150);
						i += 1;
					}

				end:
					cout << "\n\n\n" << setw(18) << "SCORE\n\n";
					cout << playerOne << ": " << playerOneScore << endl;
					cout << playerTwo << ": " << playerTwoScore << endl;


					tenNum = range(chooseRange);  //calls rangeTen function //
					cout << endl;
				}
				else
				{
					cout << "\nInvalid input !\n";
				}
			}


			if (i % 2 == 0)
			{
				cout << endl;
				string a = players(playerOne);
				cout << " WINS THE GAME !";
				Beep(987.77, 100); Beep(698.46, 100); Beep(466.16, 100); Beep(698.46, 100); Beep(987.77, 100);
			}
			else
			{
				cout << endl;
				string a = players(playerTwo);
				cout << " WINS THE GAME !";
				Beep(987.77, 100); Beep(698.46, 100); Beep(466.16, 100); Beep(698.46, 100); Beep(987.77, 100);
			}
		playerTwoGoto:
			cout << "\n\nTry again ? (y/n): ";
			cin >> cont;
			cout << "\n\n";
			if (cont == "y")
			{
				loop_1 = 2; playerOneScore = 0;
#define windows 1
				system("cls");
			}
			else if (cont == "n")
			{
				cout << "\n\n" << setw(55) << "Thank you for playing GUESS THE NUMBER";
				loop_1 = 2;
				Sleep(1500);
				return 0;
			}
			else
			{
				cout << "\nInvalid input !\n";
				goto playerTwoGoto;
			}

		}
		else if (numPlayer == "3")                           //THREE PLAYER START
		{
			cout << "\nEnter the name of 1st player: ";
			cin >> playerOne;
			cout << "Enter the name of 2nd player: ";
			cin >> playerTwo;
			cout << "Enter the name of 3nd player: ";
			cin >> playerThree;
			int i = 1;
			while (loop_1 == 1)
			{
				cout << "\nChoose the range (1-3): \n\n";
				cout << "1. 0-10 ( inclusive )\n2. 0-100 ( inclusive)\n3. 0-1000 ( inclusive)";
				cin >> chooseRange;
				if ((chooseRange == "1") || (chooseRange == "2") || (chooseRange == "3"))
				{
					tenNum = range(chooseRange);  //calls rangeTen function //
					loop_1 = 2;
				}
				else { cout << "\nInvalid input !\n"; }

			}

			cout << "\nGenerating secret number";

			for (int i(0); i < 5; i++)
			{
				cout << ". "; Sleep(200);
			}
			cout << "\nThe secret number has been generated.\n";

			for (int i(0); i < 2; i++)
			{
				Beep(800, 250);
			}

		ThreetenRange:


			while ((playerOneScore < 3) && (playerTwoScore < 3) && (playerThreeScore < 3))
			{

				if (i % 3 == 1)
				{
					cout << "\n" << playerOne << ", guess the number: ";
					cin >> gnum;

				}
				else if (i % 3 == 0)
				{
					cout << "\n" << playerThree << ", guess the number: ";
					cin >> gnum;

				}
				else
				{
					cout << "\n" << playerTwo << ", guess the number: ";
					cin >> gnum;

				}
				if (gnum < tenNum)
				{
					cout << "\nYou are low !\n";
					i += 1;
				}
				else if (gnum > tenNum)
				{
					if (chooseRange == "1")
					{
						if (gnum >= 0 && gnum < 11)
						{
							cout << "\nYou are high !\n";
							i += 1;
						}
						else { cout << "\nInvalid input !\n"; goto ThreetenRange; }
					}
					if (chooseRange == "2")
					{
						if (gnum >= 0 && gnum < 101)
						{
							cout << "\nYou are high !\n";
							i += 1;
						}
						else { cout << "\nInvalid input !\n"; goto ThreetenRange; }
					}
					if (chooseRange == "3")
					{
						if (gnum >= 0 && gnum < 1001)
						{
							cout << "\nYou are high !\n";
							i += 1;
						}
						else { cout << "\nInvalid input !\n"; goto ThreetenRange; }
					}
				}
				else if (gnum == tenNum)
				{
					if (i % 3 == 1)
					{
						playerOneScore += 1;
						cout << endl;
						string a = players(playerOne);
						cout << " GUESSED THE NUMBER !!!!";
						if (playerOneScore == 3)
						{

							goto end3;
						}
						Beep(698.46, 150); Beep(987.77, 150);

					}
					else if (i % 3 == 0)
					{
						playerThreeScore += 1;
						cout << endl;
						string a = players(playerThree);
						cout << " GUESSED THE NUMBER !!!!";
						if (playerThreeScore == 3)
						{

							goto end3;
						}
						Beep(698.46, 150); Beep(987.77, 150);

					}
					else
					{
						playerTwoScore += 1;
						cout << endl;
						string a = players(playerTwo);
						cout << " GUESSED THE NUMBER !!!!";
						if (playerTwoScore == 3)
						{

							goto end3;
						}
						Beep(698.46, 150); Beep(987.77, 150);

					}
				end3:
					cout << "\n\n\n" << setw(18) << "SCORE\n\n";
					cout << playerOne << ": " << playerOneScore << endl;
					cout << playerTwo << ": " << playerTwoScore << endl;
					cout << playerThree << ": " << playerThreeScore << endl;

					tenNum = range(chooseRange);  //calls rangeTen function //
					cout << endl;
				}
				else
				{
					cout << "\nInvalid input !\n";
				}
			}


			if (i % 3 == 0)
			{

				cout << endl;
				string a = players(playerThree);
				cout << " WINS THE GAME !";
				Beep(987.77, 100); Beep(698.46, 100); Beep(466.16, 100); Beep(698.46, 100); Beep(987.77, 100);
			}
			else if (i % 3 == 1)
			{

				cout << endl;
				string a = players(playerOne);
				cout << " WINS THE GAME !";
				Beep(987.77, 100); Beep(698.46, 100); Beep(466.16, 100); Beep(698.46, 100); Beep(987.77, 100);
			}
			else
			{
				cout << endl;
				string a = players(playerTwo);
				cout << " WINS THE GAME !";
				Beep(987.77, 100); Beep(698.46, 100); Beep(466.16, 100); Beep(698.46, 100); Beep(987.77, 100);
			}
		playerThreeGoto:
			cout << "\n\nTry again ? (y/n): ";
			cin >> cont;
			if (cont == "y")
			{
				loop_1 = 2; playerOneScore = 0;
#define windows 1
				system("cls");
			}
			else if (cont == "n")
			{
				cout << "\n\n" << setw(55) << "Thank you for playing GUESS THE NUMBER";
				loop_1 = 2;
				Sleep(1500);
				return 0;
			}
			else
			{
				cout << "\nInvalid input !\n";
				goto playerThreeGoto;
			}

		}


		else if (numPlayer == "4")                               // FOUR PLAYER START
		{
			cout << "\nEnter the name of 1st player: ";
			cin >> playerOne;
			cout << "Enter the name of 2nd player: ";
			cin >> playerTwo;
			cout << "Enter the name of 3nd player: ";
			cin >> playerThree;
			cout << "Enter the name of 3nd player: ";
			cin >> playerFour;

			while (loop_1 == 1)
			{
				cout << "\nChoose the range (1-3): \n\n";
				cout << "1. 0-10 ( inclusive )\n2. 0-100 ( inclusive)\n3. 0-1000 ( inclusive)";
				cin >> chooseRange;
				if ((chooseRange == "1") || (chooseRange == "2") || (chooseRange == "3"))
				{
					tenNum = range(chooseRange);  //calls rangeTen function //
					loop_1 = 2;
				}
				else { cout << "\nInvalid input !\n"; }

			}

			cout << "\nGenerating secret number";

			for (int i(0); i < 5; i++)
			{
				cout << ". "; Sleep(200);
			}
			cout << "\nThe secret number has been generated.\n";

			for (int i(0); i < 2; i++)
			{
				Beep(800, 250);
			}

		FourtenRange:

			int i;
			while ((playerOneScore < 3) && (playerTwoScore < 3) && (playerThreeScore < 3) && (playerFourScore < 3))
			{
				int s(1);

				for (i = 1; i < 5; i++)
				{
					if (i == 1)
					{
						cout << "\n" << playerOne << ", guess the number: ";
						cin >> gnum;

						goto exitLoop;
					}
					else if (i == 2)
					{
						cout << "\n" << playerTwo << ", guess the number: ";
						cin >> gnum;
						goto exitLoop;

					}
					else if (i == 3)
					{
						cout << "\n" << playerThree << ", guess the number: ";
						cin >> gnum;
						goto exitLoop;

					}
					else if (i == 4)
					{
						cout << "\n" << playerFour << ", guess the number: ";
						cin >> gnum;
						goto exitLoop;

					}


				exitLoop:
					if (gnum < tenNum)
					{
						cout << "\nYou are low !\n";
						if (i == 4)
						{
							i = 0;
						}
					}
					else if (gnum > tenNum)
					{
						if (chooseRange == "1")
						{
							if (gnum >= 0 && gnum < 11)
							{
								cout << "\nYou are high !\n";
								if (i == 4)
								{
									i = 0;
								}
							}
							else { cout << "\nInvalid input !\n"; goto FourtenRange; }
						}
						if (chooseRange == "2")
						{
							if (gnum >= 0 && gnum < 101)
							{
								cout << "\nYou are high !\n";
								if (i == 4)
								{
									i = 0;
								}
							}
							else { cout << "\nInvalid input !\n"; goto FourtenRange; }
						}
						if (chooseRange == "3")
						{
							if (gnum >= 0 && gnum < 1001)
							{
								cout << "\nYou are high !\n";
								if (i == 4)
								{
									i = 0;
								}
							}
							else { cout << "\nInvalid input !\n"; goto FourtenRange; }
						}
					}


					else if (gnum == tenNum)
					{
						if (i == 1)
						{
							playerOneScore += 1;
							cout << endl;
							string a = players(playerOne);
							cout << " GUESSED THE NUMBER !!!!";
							if (playerOneScore == 3)
							{

								goto end4;
							}
							Beep(698.46, 150); Beep(987.77, 150);
							i += 1;
						}
						else if (i == 2)
						{
							playerTwoScore += 1;
							cout << endl;
							string a = players(playerTwo);
							cout << " GUESSED THE NUMBER !!!!";
							if (playerTwoScore == 3)
							{

								goto end4;
							}
							Beep(698.46, 150); Beep(987.77, 150);
							i += 1;
						}
						else if (i == 3)
						{
							playerThreeScore += 1;
							cout << endl;
							string a = players(playerThree);
							cout << " GUESSED THE NUMBER !!!!";
							if (playerThreeScore == 3)
							{

								goto end4;
							}
							Beep(698.46, 150); Beep(987.77, 150);
							i += 1;
						}
						else if (i == 4)
						{
							playerFourScore += 1;
							cout << endl;
							string a = players(playerFour);
							cout << " GUESSED THE NUMBER !!!!";
							if (playerFourScore == 3)
							{

								goto end4;
							}
							Beep(698.46, 150); Beep(987.77, 150);
							i += 1;
						}
					end4:
						cout << "\n\n\n" << setw(18) << "SCORE\n\n";
						cout << playerOne << ": " << playerOneScore << endl;
						cout << playerTwo << ": " << playerTwoScore << endl;
						cout << playerThree << ": " << playerThreeScore << endl;
						cout << playerFour << ": " << playerFourScore << endl;

						if (playerOneScore == 3) { break; }
						if (playerTwoScore == 3) { break; }
						if (playerThreeScore == 3) { break; }
						if (playerFourScore == 3) { i = 4; break; }
						tenNum = range(chooseRange);  //calls rangeTen function //
						cout << endl;
					}

					else
					{
						cout << "\nInvalid input !\n";
					}
				}

			}


			if (i == 1)
			{

				cout << endl;
				string a = players(playerOne);
				cout << " WINS THE GAME !";
				Beep(987.77, 100); Beep(698.46, 100); Beep(466.16, 100); Beep(698.46, 100); Beep(987.77, 100);
			}
			if (i == 2)
			{

				cout << endl;
				string a = players(playerTwo);
				cout << " WINS THE GAME !";
				Beep(987.77, 100); Beep(698.46, 100); Beep(466.16, 100); Beep(698.46, 100); Beep(987.77, 100);
			}
			if (i == 3)
			{
				cout << endl;
				string a = players(playerThree);
				cout << " WINS THE GAME !";
				Beep(987.77, 100); Beep(698.46, 100); Beep(466.16, 100); Beep(698.46, 100); Beep(987.77, 100);
			}
			if (i == 4)
			{
				cout << endl;
				string a = players(playerFour);
				cout << " WINS THE GAME !";
				Beep(987.77, 100); Beep(698.46, 100); Beep(466.16, 100); Beep(698.46, 100); Beep(987.77, 100);
			}

		playerFourGoto:
			cout << "\n\nTry again ? (y/n): ";
			cin >> cont;
			if (cont == "y")
			{
				loop_1 = 2; playerOneScore = 0;
#define windows 1
				system("cls");
			}
			else if (cont == "n")
			{
				cout << "\n\n" << setw(55) << "Thank you for playing GUESS THE NUMBER";
				loop_1 = 2;
				Sleep(1500);
				return 0;
			}
			else
			{
				cout << "\nInvalid input !\n";
				goto playerFourGoto;
			}

		}

		else
		{
			cout << "\nInvalid input !\n\n";
			choosePlayer = 1;
		}
	}


}