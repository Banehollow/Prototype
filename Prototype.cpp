//============================================================================
// Name        : Prototype.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <ctime>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

string PlayerName;
const string Actions [5] = {"Attack", "Run", "Hide", "Distract", "Wait"};
string Demons[3] = {"Bonechewer", "Hellraider", "Sionide"};
string Weapons[1] = {""};
string CurrentWeapon;
int Decision;
int MaxChoice;
bool Entry;
bool Game = true;
bool Glades = true;
bool Level2;
bool Level3;

//------------------Intermission Function, Verifying integer useage
bool DecisionCheck(bool &Entry, int &Decision, int &MaxChoice)
{
	cin>>Decision;
	for (cin.fail(); Decision < 1 || Decision > MaxChoice;  cin.clear())
	{
		while((cin.fail() && Decision < 1) || Decision > MaxChoice)
		{
		    cout << "?"<<endl;
		    cin.clear();
		    cin.ignore(256,'\n');
		    cin >> Decision;
		}

//		cin>>Decision;
//		cin.clear();
//		printf("No!\n");
//		continue;
//	}
	}

   return Entry = true;
}


//--------Intermission Function, verifies choices of player

void DeathRoad(string CurrentWeapon, bool Choice)
{
	Level2 = true;
	system("Pause");
	cout<<"You take the path to the right\n";

	while (Level2)
	{
	printf("What will you do now?\n");
	srand(time(0));
	printf("To your left, an old cabin sits enveloped in a throng of bushes and moss. You approach it, and find a door.\nThe wood is tattered and damp, and external metal dented, but seems to be unlodged.\n");
	printf("1. Open the door\n2. Continue down the path\n3. Leave.\n");

	MaxChoice = 3;
	DecisionCheck(Entry, Decision, MaxChoice);
		switch(Decision)
		{
		case 1 : std::cout<<"The door bursts open, and " << Demons[rand() % 3] << " is the last thing you see before you die...\n"; Level2 = false; Glades = false; Game = false;
		break;

		case 2 : printf("Off you go, into the void...\n"); system("Pause");
		break;

		case 3 : printf("You've taken the way of all flesh. Coward...\n"); Level2 = false; Glades = false;
		break;
		}
	}
	return;
}

void RottenVillage(string CurrentWeapon, bool Choice)
{
	Level2 = true;
	system("Pause");
	cout<<"You take the path to the left\n";

	while (Level2)
	{
	printf("What will you do now?\n");
	srand(time(0));
	printf("To your left, an old cabin sits enveloped in a throng of bushes and moss. You approach it, and find a door.\nThe wood is tattered and damp, and external metal dented, but seems to be unlodged.\n");
	printf("1. Open the door\n2. Continue down the path\n3. Leave.\n");

	MaxChoice = 3;
	DecisionCheck(Entry, Decision, MaxChoice);
		switch(Decision)
		{
		case 1 : std::cout<<"The door bursts open, and " << Demons[rand() % 3] << " is the last thing you see before you die...\n"; Level2 = false; Glades = false; Game = false;
		break;

		case 2 : printf("Off you go, into the void...\n"); system("Pause");
		break;

		case 3 : printf("You've taken the way of all flesh. Coward...\n"); Level2 = false; Glades = false;
		break;
		}
	}
	return;
}

//----------------Third Function, main Game, calls over 27 different functions
void Ruin(bool Choice)
{
	while (Game == true)
	{
		while (Glades == true)
		{
		printf("You are currently in the glades, with two roads ahead.");
		std::cout<<" The black forest provides only sheds of moonlight on the paths before you.\nThe two roads, on the left and right, wind into the darkness of the glades.\nThe path on your left bears rotted torch-posts beside it, with overgrown grass strung across the path. It has not been treaded in a long time.\nThe path to your right is a run-down road -- walked frequently -- with many trees and bushes withered around it.\n\n";
		std::cout<<"Which road shall you take?\n";
		std::cout<<"1. The left road.\n2. The right road.\n";

		MaxChoice = 2;
		DecisionCheck(Entry = false, Decision, MaxChoice);

			switch(Decision)
			{
			case 1 : RottenVillage(CurrentWeapon, Choice);
			break;

			case 2 : DeathRoad(CurrentWeapon, Choice);
			break;
			}
		}
		printf("Well there ya go...");
		system("Pause");
	}
	system("Pause");
	return;
}


//------------------Second Function, Verifying name syntax
bool NameCheck(bool &Entry, string &PlayerName)
{

   for (int i = 0; i < PlayerName.length(); i++)
   {

	   if (isdigit(PlayerName[i]) == true)
   	   {
	   	   return Entry = false;
   	   }
	   	   else if (i == PlayerName.length() - 1)
       {
    	   return Entry = true;
       }
   }

   return Entry = false;
}

//------------------First Function, Main Game Loop
int main() {
	printf("What is your name, acolyte?\n");
	cin>>PlayerName;
	NameCheck(Entry, PlayerName);

	if (Entry == false)
	{
		printf("No fancy code numbers!\n");
		system("Pause");
		main();
	}
	printf("Good, now what weapon do you choose?\n");
	cin >> CurrentWeapon;

	std::cout<< "The weapon you picked, is a: " << CurrentWeapon << "\n";
	system("Pause");
	Ruin(Entry);
	return 0;
}




