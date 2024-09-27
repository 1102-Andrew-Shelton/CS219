#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdint.h>
#include <algorithm>
#include <string>

int main(){

    const std::string filename = "Programming-Project-1.txt";

    std::vector<std::string> operation, stringoper1, stringoper2; 
    std::vector<unsigned int> operand1, operand2;

    //Stores values and words in vector list to avoid having to account for white space.
    //Using unsingned int for both values to ensure that answer can't be negative.

    std::ifstream fileReader(filename, std::ios::in);

    //Opens the file and reads for input.

    while(fileReader.good()){
        std::string tempoperation;
        std::string tempop1, tempop2;

        //Creates temp strings to hold values in.

        unsigned int tempoper1, tempoper2;


        fileReader >> tempoperation >> tempop1 >> tempop2;

        //Reads in order and stores in order when fileReader is active. 'ADD', Op1, Op2

        stringoper1.push_back(tempop1);
        stringoper2.push_back(tempop2);

        std::istringstream(tempop1) >> std::hex >> tempoper1;
        std::istringstream(tempop2) >> std::hex >> tempoper2;

        operation.push_back(tempoperation);
        operand1.push_back(tempoper1);
        operand2.push_back(tempoper2);

        if(fileReader.eof()) break;
    }

    for(int i = 0; operation.size() > i; i++){
        if(operation.at(i) == "ADD"){

            uint32_t total = operand1.at(i) + operand2.at(i);

            std::string overflowed = "No";

            ulong o1 = static_cast<ulong>(operand1.at(i));
            ulong o2 = static_cast<ulong>(operand2.at(i));

            if (o1 + o2 > 4294967295){
                overflowed = "Yes";
            }

            std::ostringstream hexoutput;
            hexoutput << std::hex << total;
            std::string result = hexoutput.str();
            std::transform(result.begin(), result.end(), result.begin(), ::toupper);
            std::cout << stringoper1.at(i) << " + " << stringoper2.at(i) << " = 0x" << result << std::endl;
            std::cout << "Overflow: " << overflowed << std::endl;
        }
    }
    return 0;

}