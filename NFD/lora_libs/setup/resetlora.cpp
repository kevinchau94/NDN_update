// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main () 
{
  	string line;
  	int x=0;

	string val;
	string DB;
	string CR;
	string BW;
	string SF;
	string F;
	string P;
	string NA;


	int e =0;
	int i=0;
	bool error=false;
	int choice;
	int menu_choice;
	bool menu = false;

	ifstream myfile ("/home/pi/NDN_over_LoRa/NFD/lora_libs/setup/lora_config.txt");
  	if (myfile.is_open())
  	{
		  //get debug value
        while (getline(myfile, line))
		{
			switch (i){
				case 0: val = line; break;
				case 1: DB = line; break;
				case 2: CR = line; break;
				case 3: BW = line; break;
				case 4: SF = line; break;
				case 5: F = line; break;
				case 6: P = line; break;
				case 7: NA = line; break;
			}
			i++;
			
		}
		myfile.close();
	}
  	else {
		  cout << "Error: Unable to open file. Stop the program!";
		  return 0;
	}

	fstream newfile;
   	newfile.open("/home/pi/NDN_over_LoRa/NFD/lora_libs/setup/lora_config.txt",ios::out);  // open a file to perform write operation using file object
   	if(newfile.is_open())     //checking whether the file is open
   	{
		newfile<<"3\n";
		newfile<<DB<<"\n";
		newfile<<CR<<"\n";
		newfile<<BW<<"\n";
		newfile<<SF<<"\n";
		newfile<<F<<"\n";
		newfile<<P<<"\n";
		newfile<<NA<<"\n";
		newfile.close();		
	  }
	  else {cout<<"Unable to open file!\n";}

  return 0;
}