#ifndef START_H
#define START_H

#include <fstream>


std::ifstream LoadFile(std::string fileName);
void Processor(std::ifstream inFile);
void displayFile(std::ifstream &inFile);
void startScreen();


#endif