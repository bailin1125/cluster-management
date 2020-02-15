#include <sstream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <string>
//#include <unistd.h>

#pragma warning(disable : 4996)
using namespace std;
const int NUM = 200;

int aain(int argc, char* argv[])
{
	int i = 0, j = 0;
	char name1[200] = {"change"};
	char name2[200] = {"change_passwd"};
	cout << "the code is for multi change the user's passwd"<<endl<<"please chece if the user and passwd is corresponding!" << endl;
	for (i = 0; i < argc; i++)
	{
		if (i == 1)
		{
			for (j = 0; j < strlen(argv[i]); j++)
			{
				name1[j] = argv[i][j];
			}
			name1[strlen(argv[i])] = '\0';
		}
		if (i == 2)
		{
			for (j = 0; j < strlen(argv[i]); j++)
			{
				name2[j] = argv[i][j];
			}
			name2[strlen(argv[i])] = '\0';
		}		
	}	
	int num = 0;
	string user_list[NUM];
	string passwd_list[NUM];
	ifstream change;
	change.open(name1, ios::in);
	if (!change.is_open())
	{
		cout << "i can not find the change file!please check!" << endl;
		cout << "now the name is :" << name1 << endl;
		cin.get();
		return 0;
	}
	i = 0;
	while (change.good())
	{
		change >> user_list[i];		
		//cout << user_list[i] << endl;
		change >> passwd_list[i];
		//cout << passwd_list[i] << endl;
		num++;
		i++;
	}	
	cout << num - 1 << "users" << endl;
	//cin.get();
	change.close();
	FILE* com;
	string temp = "./ChPasswd2";
	for (i = 0; i < num - 1; i++)
	{
		string command = temp + " " + user_list[i] + " " + passwd_list[i];
		com = popen(command.c_str(), "r");
		pclose(com);
	}
	cout << "has changing the " << num - 1 << "user's passwd!" << endl;

	/*ifstream passwd;
	passwd.open(name2, ios::in);
	if (!user.is_open())
	{
		cout << "i can not find the user.list file!please check!" << endl;
		cout << "now the name is :" << name1 << endl;
		cin.get();
		return 0;
	}
	while (user.good())
	{
		user >> user_list[i];
		num[0]++;
	}
	user.close();*/



	
		
	

	cout << "all total work done!please type enter to exit" << endl;


	//cin.get();
	return 1;
}