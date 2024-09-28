//Author: Andrew Shelton
//Class: CS219
//Purpose: To add two hex numbers together through the use of conversion.


#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdint.h>
#include <algorithm>
#include <string>



using namespace std;

int main(){

    const string filename = "Programming-Project-1.txt";

    vector<std::string> operation, stringoper1, stringoper2; 
    vector<unsigned int> operand1, operand2;

    //Stores values and words in vector list to avoid having to account for white space.
    //Using unsingned int for both values to ensure that answer can't be negative.

    ifstream fileReader(filename, ios::in);

    //Opens the file and reads for input.

    while(fileReader.good()){
        string tempoperation;
        string tempop1, tempop2;

        //Creates temp strings to hold values in.

        unsigned int tempoper1, tempoper2;


        fileReader >> tempoperation >> tempop1 >> tempop2;

        //Reads in order and stores in order when fileReader is active. 'ADD', Op1, Op2

        stringoper1.push_back(tempop1);
        stringoper2.push_back(tempop2);
        //The push_back operation pushes the string values into the temp values at the end. This is so the code can get a proper read of the values.

        istringstream(tempop1) >> hex >> tempoper1;
        istringstream(tempop2) >> hex >> tempoper2;
        //Converts the values stored in temp variables into hex and then stores them again in temp by the use of the hex keyword.

        operation.push_back(tempoperation);
        operand1.push_back(tempoper1);
        operand2.push_back(tempoper2);

    

        if(fileReader.eof()) break;

        //Ends program once the file reaches the end.
    }

    for(int i = 0; operation.size() > i; i++){
        if(operation.at(i) == "ADD"){

            uint32_t total = operand1.at(i) + operand2.at(i);

            //Uses uint32_t to store the total in 32 bits after the program takes two values and adds them together.

            string overflowed = "No";

            ulong o1 = static_cast<ulong>(operand1.at(i));
            ulong o2 = static_cast<ulong>(operand2.at(i));

            if (o1 + o2 > 4294967295){
                overflowed = "Yes";
            }

            //Checks if both values added together will create an overflow by use of ulong and it's 64 bit limit which is 4,294,967,295.
            //If the statement is false, then the program will respond with it's default "No".

            ostringstream hexoutput;
            hexoutput << hex << total;
            //Creates a variable that stores the converted total inside of it.
            string result = hexoutput.str();
            transform(result.begin(), result.end(), result.begin(), ::toupper);
            //Make sure that all values printed out will be upercase letters instead of lowercase.

            cout << stringoper1.at(i) << " + " << stringoper2.at(i) << " = 0x" << result << endl;
            cout << "Overflow: " << overflowed << endl;
            //Displays the result of the overflow statement being true or not.
        }
    }
    return 0;

}

//end of program. (for now).