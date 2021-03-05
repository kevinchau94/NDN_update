#include <iostream>
#include <string>
#include <stdint.h>
#include <cstring>
#include <sstream>

//uint8_t param_CR;
uint8_t param_CR;
uint16_t param_BW;
uint8_t param_SF;
uint32_t param_CH;

int main () {
  
  std::string input;
  
  std::cout << "Please enter LoRa Parameters." << std::endl;
  
  //ask for and receive user input for CR
  std::cout << "Please enter the CR value (in format CR_#): ";
  std::getline(std::cin, input);
  std::stringstream ss (input);
  std::string temp;
  std::getline(ss, temp);
  uint64_t temp2 = stoul(temp, 0, 0);
  param_CR = static_cast<uint8_t>(temp2);
  //std::cout << "The value of CR entered was: " << input << std::endl;
  //param_CR = static_cast<uint8_t>(input);
  std::cout << "The value of CR entered was: " << param_CR << std::endl;
  
  /*
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
  */
  
  return 0;
}
