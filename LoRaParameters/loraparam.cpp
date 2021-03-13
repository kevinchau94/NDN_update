#include <iostream>
#include <string>
#include <stdint.h>
#include <cstring>
#include <sstream>

//uint8_t param_CR;
uint8_t* param_CR;
uint16_t* param_BW;
uint8_t* param_SF;
uint32_t* param_CH;
//int param_test;
std::string param_test;

int main () {
  
  //std::string input;
  
  //ask for and receive user input for CR
  //std::cout << "Please enter the CR value (in format CR_#): ";
  
  std::cin >> param_test;
  param_CR = new uint8_t[param_test.length() + 1];
  memcpy (param_CR, param_test.c_str(), param_test.length() + 1);
  
  std::cout << param_CR << std::endl;
  std::cout << typeid(param_CR).name() << std::endl;
  
  
  
  /*
  std::getline(std::cin, input);
  std::stringstream ss (input);
  std::string temp;
  std::getline(ss, temp);
  uint64_t temp2 = stoul(temp, 0, 0);
  param_CR = static_cast<uint8_t>(temp2);
  
  if (std::cin >> param_test){
    //param_CR = reinterpret_cast<const uint8_t>(input.c_str());
    std::cout << "The value of param_test entered was: " << param_test << std::endl;
  }
  */
  //std::cout << "The value of CR entered was: " << input << std::endl;
  //param_CR = static_cast<uint8_t>(input);
  //std::cout << "The value of CR entered was: " << param_CR << std::endl;
  
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
