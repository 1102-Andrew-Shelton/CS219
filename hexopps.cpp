#include <string>
#include <cmath>
#include <iostream>
#include "hexopps.h"

long ConvertHexToDecimal(std::string hexFig) {
    long num = 0;
    int i = 0;
    char temp;

    for(i = 2; i < hexFig.size(); i++){
        temp = hexFig.at(i);

        switch(temp){
            case 'A':
                    num += (10  *pow(16, (hexFig.size() - i - 1)));
                    break;
            case 'B':
                    num += (11 * pow(16, (hexFig.size() - i - 1)));
                    break;
            case 'C':
                     num += (12  *pow(16, (hexFig.size() - i - 1)));
                    break;
            case 'D':
                     num += (13  *pow(16, (hexFig.size() - i - 1)));
                    break;
            case 'E':
                     num += (14  *pow(16, (hexFig.size() - i - 1)));
                    break;
            case 'F':
                     num += (15  *pow(16, (hexFig.size() - i - 1)));
                    break;
            default:
                    num += ((temp - 48) * pow(16, (hexFig.size() - i - 1)));
                    break;

        }

    }
        return num;
}


std::string ConvertDecimalToHex(long decimalFig){
        std::string hexNum;
        int remainder;

        for (int i = 0; (remainder != 0) || (decimalFig != 0); i++){
                remainder = decimalFig % 16;
                if(remainder < 10){
                        hexNum.insert(0, std::to_string(remainder));
                }else if(remainder == 10){
                        hexNum.insert(0, "A");
                
                }else if(remainder == 11){
                        hexNum.insert(0, "B");
                
                }else if(remainder == 12){
                        hexNum.insert(0, "C");
                
                }else if(remainder == 13){
                        hexNum.insert(0, "D");
               
                }else if(remainder == 14){
                        hexNum.insert(0, "E");
                
                }else if(remainder == 15){
                        hexNum.insert(0, "F");
                }
                remainder = 0;
        }

        hexNum.insert(0, "0x");

        return hexNum;
}


long Add(long num1, long num2){
        return (num1 + num2);
}