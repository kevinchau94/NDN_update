// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <sys/stat.h>
#include <cstring>
using namespace std;

int main () 
{
	string filepath = "/usr/local/LoRa Configuration/lora_config.txt";
  	string line;
  	int x=0;

	string val; //Change?
	string DB; //Debug messages
	string CR; //Coding Rate
	string BW; //Bandwidth
	string SF; // Spreading Factor
	string F; // Frequency
	string P; // Power
	string NA; //Node Address
	string HM; //Header Mode
	string TC; //Temperature cal

	string initial_val; //Change?
	string initial_DB; //Debug messages
	string initial_CR; //Coding Rate
	string initial_BW; //Bandwidth
	string initial_SF; // Spreading Factor
	string initial_F; // Frequency
	string initial_P; // Power
	string initial_NA; //Node Address
	string initial_HM; //Header Mode
	string initial_TC; //Temperature cal
	string Node;

	bool change = false; //does the lora need to update?

	int e =0;
	int i=0;
	bool error=false;
	int choice;
	int menu_choice;
	bool menu = false; //Main menu
	bool menu2 = false; //menu
	bool initial = false;

	//Open the file to be read
	ifstream myfile (filepath); 
  	if (myfile.is_open())
  	{
		  //get debug value
        while (getline(myfile, line))
		{
			switch (i){
				case 0: val = line; initial_val = line; break;
				case 1: DB = line; initial_DB = line; break;
				case 2: CR = line; initial_CR = line; break;
				case 3: BW = line; initial_BW = line; break;
				case 4: SF = line; initial_SF = line; break;
				case 5: F = line; initial_F = line; break;
				case 6: P = line; initial_P = line; break;
				case 7: NA = line; Node =line; initial_NA = line; break;
				case 8: HM = line; initial_HM = line; break;
				case 9: TC = line; initial_TC = line; break;
			}
			i++;
			
		}
		myfile.close();
	}
  	else {
		  cout << "Error: Unable to open file... Stopping the program!\n";
		  return 0;
	}

		cout<<"\n***************************************************************************************\n";
		cout<<"\n				NDN over LoRa Configuration\n";
		cout<<"\n***************************************************************************************\n";
		cout<<"\n";
		cout<<"	***Giving any value not listed in the menu will result in default settings.***\n";
		cout<<"\n";
		cout<<"About: \n";
		cout<<"   Quick Modes - Quick lora setups, no need to specify values. \n";
		cout<<"\n";
		cout<<"   Primary Settings - Coding rate, spreading factor, bandwidth, frequency, or output power. \n";
		cout<<"     *** These can affect more than what is described below. Can create error. *** \n";
		cout<<"	Coding Rate (CR)- Decreases error but increases time-on-air. \n";
		cout<<"	Spreading Factor (SF)- Increases range but significantly increases time-on-air. \n";
		cout<<"	Bandwidth - Decreases time-on-air significantly but decreases range slightly. \n";
		cout<<"	Frequency - Changes frequency. This must be the same value on communicating LoRas. \n";
		cout<<"	Output Power - Determines the output power of the transmitting signal. \n";
		cout<<"\n";
		cout<<"   Secondary Settings - Messages, node address, header mode, temperature offset. \n";
		cout<<"	Message Settings - Set how many messages popup for the LoRa. Debug purposes. \n";
		cout<<"	Node Address - Override the node address. This is normally not needed. \n";
		cout<<"	Header Mode - Determines if custom values for CR is needed. Increases time-on-air. \n";
		cout<<"	  *** Header mode is more complex than described. Recommended to leave 'on' *** \n";
		cout<<"	Temperature Offset - Must be manually set to correct the LoRa temperature. \n";
		cout<<"\n";

    	while(menu==false)
    	{
		
			//cout<<"________________________________\n";
			cout<<"\nMain Menu: \n";
			cout<<"	1 - Quick Modes\n";
			cout<<"	2 - Primary Settings\n";
			cout<<"	3 - Secondary Settings\n";
			cout<<"	4 - Exit\n";
			cout<<"Enter your choice for the LoRa setup: ";
			cin>> choice;
			cin.clear();


			switch (choice){
				case 1: //Quick modes
					menu2=false;
					while(menu2==false){
						cout<<"\nQuick Modes: \n";
						cout<<"	1 - Default (Average)\n";
						cout<<"	2 - Longest Range (Slow speed)\n";
						cout<<"	3 - Fastest speed (Shorter Range)\n";
						cout<<"	4 - Exit Quick Modes\n";
						cout<<"Enter your choice for the LoRa setup: ";
						cin>> choice;
						cin.clear();

						switch (choice){
						case 1:

							menu2 = true;
							menu = true;
							val = "1";
							CR = "7";
							BW = "500";
							SF = "8";
							F = "21";
							P = "4";

							cout << "Set the 'default' settings: \n";
							cout<<"\n";
							cout << "	The Coding Rate setting is: CR_7" << endl;
							cout << "	The Bandwidth setting is: BW_500" << endl;
							cout << "	The Spreading Factor setting is: SF_8" << endl;
							cout << "	The channel and frequency settings are: CH_12_900 (915 MHz)"  << endl;
							cout << "	The Power setting is: 'M'" << endl;
							cout << "	The Node Address is: " <<Node<< endl;
						break;
						case 2:
							menu2 = true;
							menu = true;
							val = "1";
							CR = "8";
							BW = "125";
							SF = "12";
							F = "21";
							P = "4";

							cout << "Set the 'Long Range' settings: \n";
							cout<<"\n";
							cout << "	The Coding Rate setting is: CR_8" << endl;
							cout << "	The Bandwidth setting is: BW_125" << endl;
							cout << "	The Spreading Factor setting is: SF_12" << endl;
							cout << "	The channel and frequency settings are: CH_12_900 (915 MHz)"  << endl;
							cout << "	The Power setting is: 'M'" << endl;
							cout << "	The Node Address is: " <<Node<< endl;
						break;
						case 3:
							menu2 = true;
							menu = true;
							val = "1";
							CR = "5";
							BW = "500";
							SF = "6";
							F = "21";
							P = "4";

							cout << "Set the 'Fast Speed' settings: \n";
							cout<<"\n";
							cout << "	The Coding Rate setting is: CR_5" << endl;
							cout << "	The Bandwidth setting is: BW_500" << endl;
							cout << "	The Spreading Factor setting is: SF_6" << endl;
							cout << "	The channel and frequency settings are: CH_12_900 (915 MHz)"  << endl;
							cout << "	The Power setting is: 'M'" << endl;
							cout << "	The Node Address is: " <<Node<< endl;
						break;
						case 4:
							menu2=true;
						break;
						}
					}

				break;


			case 2://Enter Main values for LoRa
				menu2=false;
				i =0; //reset the i for menu spot
				while(menu2==false)
				{
					cout<<"\nPrimary Settings: \n";
					cout<<"	1 - Set Coding Rate     	Current Value: CR_" << CR <<endl;
					cout<<"	2 - Set Bandwidth       	Current Value: BW_" << BW <<endl;
					cout<<"	3 - Set Spreading Factor	Current Value: SF_" << SF <<endl;
					cout<<"	4 - Set Frequency       	Current Value: " << F <<endl;
					cout<<"	5 - Set Power           	Current Value: " << P <<endl;
					cout<<"	6 - Exit Primary Settings\n";
					cout<<"Enter your choice for the LoRa setup: ";
					cin>> choice;
					cin.clear();

					switch (choice)
					{

					case 1: //set coding rate
						cout<<"\n***This setting only takes effect if the header is 'OFF'*** \n";
						cout<<"Set Coding Rate: (Greater values = greater success but slower speeds)\n";
						cout<<"	5 - CR_5 \n";
						cout<<"	6 - CR_6 \n";
						cout<<"	7 - CR_7 (Default)\n";
						cout<<"	8 - CR_8 \n";
						cout<<"	0 - Back \n";
						cout<<"Please pick a value: ";
						cin>> menu_choice;
						cin.clear();
						switch (menu_choice)
						{
							case 5: CR = "5"; break; //newfile<<"5\n"; break;
							case 6: CR = "6"; break; //newfile<<"6\n"; break;
							case 7: CR = "7"; break; //newfile<<"7\n"; break;
							case 8: CR = "8"; break; //newfile<<"8\n"; break;
							case 0: break; //newfile<<"8\n"; break;
							default: cout<<"***Defaulted***\n"; CR = "7"; break; //newfile<<"7\n"; break;
						}
					break;

					case 2: //set BW
						cout<<"\nSet Bandwidth: (Greater values = much greater speeds but slightly shorter range)\n";
						cout<<"	125 - BW_125 kHz\n";
						cout<<"	250 - BW_250 kHz\n";
						cout<<"	500 - BW_500 kHz (Default)\n";
						cout<<"	0 - Back \n";
						cout<<"Please pick a value: ";
						cin>> menu_choice;
						cin.clear();
						switch (menu_choice)
						{
							case 125: BW = "125"; break; //newfile<<"125\n"; break;
							case 250: BW = "250"; break; //newfile<<"250\n"; break;
							case 500: BW = "500"; break; //newfile<<"500\n"; break;
							case 0:  break; //Go back to previous menu
							default: cout<<"***Defaulted***\n"; BW = "500"; break; //newfile<<"500\n"; break;
						}
					break;

					case 3: //set SF
						cout<<"\nSet Spreading Factor: (Greater values = much greater range but slower speeds)\n";
						cout<<"	6 - SF_6 \n";
						cout<<"	7 - SF_7 \n";
						cout<<"	8 - SF_8 \n";
						cout<<"	9 - SF_9 \n";
						cout<<"	10 - SF_10 (Default)\n";
						cout<<"	11 - SF_11 \n";
						cout<<"	12 - SF_12 \n";
						cout<<"	0 - Back \n";
						cout<<"Please pick a value: ";
						cin>> menu_choice;
						cin.clear();
						switch (menu_choice)
						{
							case 6: SF = "6"; break; 
							case 7: SF = "7"; break; 
							case 8: SF = "8"; break;
							case 9: SF = "9"; break;
							case 10: SF = "10"; break;
							case 11: SF = "11"; break; 
							case 12: SF = "12"; break; 
							case 0:  break; //Go back to previous menu
							default: cout<<"***Defaulted***\n"; SF = "10"; break; //newfile<<"10\n"; break;
						}
					break;

					case 4: //set Freq
						// Select frequency channel
						cout<<"\nSet Channel and Frequency: \n";
						cout<<"	1 - CH_10_868	(865.20MHz)\n";
						cout<<"	2 - CH_11_868	(865.50MHz)\n";
						cout<<"	3 - CH_12_868	(865.80MHz)\n";
						cout<<"	4 - CH_13_868	(866.10MHz)\n";
						cout<<"	5 - CH_14_868	(866.40MHz)\n";
						cout<<"	6 - CH_15_868	(866.70MHz)\n";
						cout<<"	7 - CH_16_868	(867.00MHz)\n";
						cout<<"	8 - CH_17_868	(868.00MHz)\n";
						cout<<"	9 - CH_00_900	(903.08MHz)\n";
						cout<<"	10 - CH_01_900	(905.24MHz)\n";
						cout<<"	11 - CH_02_900	(907.40MHz)\n";
						cout<<"	12 - CH_03_900	(909.56MHz)\n";
						cout<<"	13 - CH_04_900	(911.72MHz)\n";
						cout<<"	14 - CH_05_900	(913.88MHz)\n";
						cout<<"	15 - CH_06_900	(916.04MHz)\n";
						cout<<"	16 - CH_07_900	(918.20MHz)\n";
						cout<<"	17 - CH_08_900	(920.36MHz)\n";
						cout<<"	18 - CH_09_900	(922.52MHz)\n";
						cout<<"	19 - CH_10_900	(924.68MHz)\n";
						cout<<"	20 - CH_11_900	(926.84MHz)\n";
						cout<<"	21 - CH_12_900	(915.00MHz)	(Default)\n";
						cout<<"	0 - Back \n";
						cout<<"Please pick a value: ";
						cin>> menu_choice;
						cin.clear();
						switch (menu_choice)
						{
							case 1: F = "1"; break;
							case 2: F = "2"; break;
							case 3: F = "3"; break; 
							case 4: F = "4"; break; 
							case 5: F = "5"; break; 
							case 6: F = "6"; break; 
							case 7: F = "7"; break; 
							case 8: F = "8"; break; 
							case 9: F = "9"; break; 
							case 10: F = "10"; break; 
							case 11: F = "11"; break; 
							case 12: F = "12"; break; 
							case 13: F = "13"; break; 
							case 14: F = "14"; break; 
							case 15: F = "15"; break; 
							case 16: F = "16"; break; 
							case 17: F = "17"; break; 
							case 18: F = "18"; break; 
							case 19: F = "19"; break; 
							case 20: F = "20"; break; 
							case 21: F = "21"; break; 
							case 0:  break; //Go back to previous menu
							default: cout<<"***Defaulted***\n"; F = "21"; break; 
						}
					break;

					case 5: //set Power
						// Select output power (Max, High or Low)
						cout<<"\nSet Power: \n";
						//cout<<"Current Value: ("<<P<<")\n";
						cout<<"	1 - 'Min'	(-1 dBm)\n";
						cout<<"	2 - 'Low'	(+4 dBm)\n";
						cout<<"	3 - 'High'	(+9 dBm)\n";
						cout<<"	4 - 'Max'	(+14 dBm)	(Default) \n";
						cout<<"	5 - 'Xmax'	(+20 dBm)	*Only on supported modules \n";
						cout<<"	0 - Back \n";
						cout<<"Please pick a value: ";
						cin>> menu_choice;
						cin.clear();
						switch (menu_choice)
						{
							case 1: P = "1"; break;
							case 2: P = "2"; break;
							case 3: P = "3"; break;
							case 4: P = "4"; break;
							case 5: P = "5"; break; 
							case 0:  break; //Go back to previous menu
							default: cout<<"***Defaulted***\n"; P = "4"; break; 
						}
						
					break;

					default:
						menu2 = true;
					break;

					NA = Node;
					}
				}
				
			break;
			case 3:
				menu2=false;
				while(menu2==false){
					cout<<"\nSecondary Settings:       \n";
					cout<<"	1 - Message Settings       	Current Value: " << DB <<endl;
					cout<<"	2 - Set Node Address       	Current Value: " << NA <<endl;
					cout<<"	3 - Set Header (ON/OFF)    	Current Value: " << HM <<endl;
					cout<<"	4 - Set Temperature Offset 	Current Value: " << TC <<endl;
					cout<<"	5 - Exit Secondary Settings\n";
					cout<<"Enter your choice for the LoRa setup: ";
					cin>> choice;
					cin.clear();

					switch (choice){
						case 1://set Debug
							cout<<"\nMessage Settings: \n";
							cout<<"	0 - OFF \n";
							cout<<"	1 - Minimum (Default)\n";
							cout<<"	2 - Info \n";
							cout<<"	3 - All \n";
							cout<<"Please pick a value: ";
							cin>> menu_choice;
							cin.clear();
							switch (menu_choice)
							{
								case 0: DB = "0"; break; 
								case 1: DB = "1"; break; 
								case 2: DB = "2"; break; 
								case 3: DB = "3"; break; 
								default: cout<<"***Defaulted***\n"; DB = "1"; break; 
							}
						break;

						case 2://set Node
							cout<<"Set Node Address (1-10) \n";
							cout<<"Please enter a value: ";
							cin>> menu_choice;
							cin.clear();
							switch (menu_choice)
							{
								case 1: NA = "1"; break; //newfile<<"1\n"; break;
								case 2: NA = "2"; break; //newfile<<"2\n"; break;
								case 3: NA = "3"; break; //newfile<<"3\n"; break;
								case 4: NA = "4"; break; //newfile<<"4\n"; break;
								case 5: NA = "5"; break; //newfile<<"5\n"; break;
								case 6: NA = "6"; break; //newfile<<"5\n"; break;
								case 7: NA = "7"; break; //newfile<<"5\n"; break;
								case 8: NA = "8"; break; //newfile<<"5\n"; break;
								case 9: NA = "9"; break; //newfile<<"5\n"; break;
								case 10: NA = "10"; break; //newfile<<"5\n"; break;
								default: cout<<"***Defaulted***\n"; NA = Node; break; //newfile<<"3\n"; break;
							}
						break;

						case 3://set Node
							cout<<"Set Header ON/OFF \n";
							cout<<"	0 - OFF \n";
							cout<<"	1 - ON	(Default)\n";
							cout<<"Please pick a value: ";
							cin>> menu_choice;
							cin.clear();
							switch (menu_choice)
							{
								case 1: HM = "1"; break; //newfile<<"1\n"; break;
								case 0: HM = "0"; break; //newfile<<"2\n"; break;
								default: cout<<"***Defaulted***\n"; HM = 1; break; //newfile<<"3\n"; break;
							}
						break;

						case 4://set Node
							cout<<"Set Temperature Offset \n";
							cout<<"Please enter a value: ";
							cin>> menu_choice;
							cin.clear();
							switch (menu_choice)
							{
								case 1: TC = "1"; break; 
								case 2: TC = "2"; break; 
								case 3: TC = "3"; break; 
								case 4: TC = "4"; break; 
								case 5: TC = "5"; break; 
								case 6: TC = "6"; break; 
								case 7: TC = "7"; break; 
								case 8: TC = "8"; break; 
								case 9: TC = "9"; break; 
								case 10: TC = "10"; break; 
								case 11: TC = "11"; break;
								case 12: TC = "12"; break;
								case 13: TC = "13"; break;
								case 14: TC = "14"; break;
								case 15: TC = "15"; break;
								case 16: TC = "16"; break;
								case 17: TC = "17"; break;
								case 18: TC = "18"; break;
								case 19: TC = "19"; break;
								case 20: TC = "20"; break;
								default: cout<<"***Defaulted***\n"; break; 
							}
							cout<<"Is this a negative offset? \n";
							cout<<"	0 - No \n";
							cout<<"	1 - Yes \n";
							cout<<"Please enter a value: ";
							cin>> menu_choice;
							cin.clear();
							switch (menu_choice)
							{
								case 1: TC = "-"+TC; break;
							}
						break;
						default:
							menu2 = true;
						break;
					}
				}
			break;
			case 4:
				menu = true;
			break;
			default:
				cout << "\n***Invalid choice! Resorting to last setup.\n";
				initial = true;
				menu = true;
				return 0;
			break;
			
			}
		
		}

		//check if the file needs to be updated
		if (val != initial_val) change = true;
		else if (DB != initial_DB) change = true;
		else if (CR != initial_CR) change = true;
		else if (BW != initial_BW) change = true;
		else if (SF != initial_SF) change = true;
		else if (F != initial_F) change = true;
		else if (P != initial_P) change = true;
		else if (NA != initial_NA) change = true;
		else if (HM != initial_HM) change = true;
		else if (TC != initial_TC) change = true;

		if (change == true)
		{
			fstream newfile;
			newfile.open(filepath,ios::out);  // open a file to perform write operation using file object

			//Write set values
			if (initial == false && newfile.is_open())
			{
				newfile<<"1\n";
				newfile<<DB<<"\n";
				newfile<<CR<<"\n";
				newfile<<BW<<"\n";
				newfile<<SF<<"\n";
				newfile<<F<<"\n";
				newfile<<P<<"\n";
				newfile<<NA<<"\n";
				newfile<<HM<<"\n";
				newfile<<TC<<"\n";
				newfile.close();
			}

			else {cout<<"Unable to open file!\n";}
		}

  return 0;
}