
#include <iostream>
#include <fstream>
#include <string>
#include "start.h"
#include "hexopps.h"


void Start(){

    startScreen();

    try{
            Processor(LoadFile("Programming-Project-1.txt"));

    }
    catch(const char* msg){
        std::cout << msg;
    }
    
    catch(const std::exception &exc){
            std::cerr << exc.what();

    }
    std::cout << std::endl;
}

std::ifstream LoadFile(std::string fileName){
    std::ifstream inFile;
    std::string temp;
    int numLines;
    int numObj;

    inFile.open(fileName);
    if(inFile.fail()){
            throw("Failed to open \"" + fileName + "\"!");

    }
    for(numLines = 0; !inFile.eof(); numLines++){
        getline(inFile, temp);
    }

    inFile.close();
    inFile.open(fileName);

    for(numObj = 0; !inFile.eof(); numLines++){
        inFile >> temp;
        if((numObj % 3 == 0) && temp != "ADD"){
            throw ("\"" + fileName + "\" Not Formated Correctly!");

        }else if((numObj % 3 != 0) && (temp.substr(0,2) != "0x")){
            throw("\"" + fileName + "\" Not Formated Correctly! Any hex numbers must have 0x prefix");
        }
    for(int i = 0; i < temp.size(); i++){
        if(!isdigit(temp.at(i)) || temp.at(i) != 'A' || temp.at(i) != 'B' ||
				temp.at(i) != 'C' || temp.at(i) != 'D' || temp.at(i) != 'E' ||
				temp.at(i) != 'F'){
                    throw("Hex Numbers arn't formatted the right way. Please make sure characters are A-F and are uppercase.");
                
    
                }
        }
    }

    if((numObj % numLines) != 0){
        throw("\"" +fileName +"\"Not Formatted Correctly");
    }
    inFile.close();
    inFile.open(fileName);

    return inFile;

    }



void displayFile(std::ifstream &inFile){
        while(!inFile.eof()){
                std::string temp;
                inFile >> temp;
                std::cout << temp << std::endl;
        }
}


void Processor(std::ifstream inFile){

        std::string op;
        std::string arg1;
        std::string arg2;

        do{
            inFile >> op;
            inFile >> arg1;
            inFile >> arg2;
            if(op == "ADD"){
                std::cout << "Sum Of " << arg1 << "And " << arg2 << "-> " << ConvertDecimalToHex(Add(ConvertHexToDecimal(arg1), ConvertHexToDecimal(arg2)));
            }
            }while(!inFile.eof());
 }


void startScreen(){

    std::cout << "-------------------------" << std::endl;
    std::cout << "===Program assignment 1====" << std::endl;
    
}

