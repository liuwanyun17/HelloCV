#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class FileHandler
{
    public:
    static string readfile(const string& path);
    static void  writefile(const string& path,const string &content); 

};