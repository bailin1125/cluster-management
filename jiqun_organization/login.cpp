#include <sstream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <string>

#pragma warning(disable : 4996)
using namespace std;
const string change = "\\HIGH_POWER_XRD";




//注意编译12个程序，改变映射路径，以及管理员确认   

int main(int argc, char* argv[])
{
	int i = 0, j = 0;	
	string command[10];
	command[0] = "net use * /del /y";
	command[1]="net use Z: \\\\10.1.1.10\\";
	//cout << command[0] << endl;
	//cout << command[1] << endl;

	int flag = 0;
	string name;
	do
	{		
		cout << "please enter your user name:" << endl;
		cin >> name;
		cout << "your username is :" << name << endl;
		cout << "please type y or n to make sure" << endl;
		char sure[20] = { '\0' };
		cin >> sure;

		if (sure[0] == 'y' &&sure[1] == '\0')
		{
			flag = 1;
		}
		else if (sure[0] == 'n' &&sure[1] == '\0')
		{
			cout << "try another time" << endl;
			name.clear();
			continue;
		}
		else
		{
			cout << "please type y or n " << endl;
			cout << "try another time" << endl;
			name.clear();
			continue;
		}
	}while (flag == 0); 

	//这里要区分是不是管理员，是的话不能加后缀

	if (name == "tem_eds" || name == "sem_eds" || name == "sem" || name == "fib" || name == "ebsd_eds" || name == "xrf" || name == "xrd" || name == "xps" || name == "high_power_xrd" || name == "zem_3" || name == "hall" || name == "tem")
	{
		cout << "welcome the admin.!" << endl;
		for (int i = 0; i < name.length(); i++)
		{ 
			if (name[i] >= 'a'&&name[i] <= 'z')
			{
				name[i] = name[i] - 32;
			}			
		}
		//cout << name << endl;
		//system("pause");
		system(command[0].c_str());
		system((command[1] + name).c_str());
		//cout << command[0] << endl;
		//cout << command[1] + name << endl;
		cout << "all total work done! type enter to exit." << endl;
		system("pause");
		return 0;

	}
	else
	{
		name = name + change;
		system(command[0].c_str());
		system((command[1] + name).c_str());
		//cout << command[0] << endl;
		//cout << command[1]+name << endl;		
		cout << "all total work done! type enter to exit." << endl;
		system("pause");
		return 0;
	}
	
	
}