#pragma once
#include<iostream>
#include<string>
using namespace std;

class Crypto
{
    public:
    static string encrypto(const string &txt,int key);
    static string decrypto(const string &txt,int key);
    static char enchar(char a,int key);
    static char dechar(char a,int key);
};

