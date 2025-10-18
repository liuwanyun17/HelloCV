
#include<iostream>
#include<fstream>
#include<string>
#include "../include/FileHandler.h"
using namespace std;

string FileHandler::readfile(const string &path){
    ifstream file(path);
    string content((istreambuf_iterator<char>(file)),
                        istreambuf_iterator<char>());
    file.close();
    return content;
};
void FileHandler::writefile(const string &path ,const string &content){
    ofstream file(path);
    file<<content;
    file.close();  
};
