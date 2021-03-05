#include <iostream>
#include <string> 

uint8_t * param_CR[8];
uint16_t param_BW;
uint8_t param_SF;
uint32_t param_CH;

int main () {
  
  std::cout << "Please enter LoRa Parameters." << std::endl;
  
  //ask for and receive user input for CR
  std::cout << "Please enter the CR value (in format CR_#): ";
  std::cin >> param_CR;
  std::cout << "The value of CR entered was: " << param_CR << std::endl;
  //ask for and receive user input for BW 
  std::cout << "Please enter the BW value (in format BW_#): ";
  std::cin >> param_BW;
  std::cout << "The value of BW entered was: " << param_BW << std::endl;
  //ask for and receive user input for SF 
  std::cout << "Please enter the SF value (in format SF_#): ";
  std::cin >> param_SF;
  std::cout << "The value of SF entered was: " << param_SF << std::endl;
  //ask for and receive user input for CH 
  std::cout << "Please enter the CH value (in format CH_#_#): ";
  std::cin >> param_CH;
  std::cout << "The value of CH entered was: " << param_CH << std::endl;
  
  return 0;
}
