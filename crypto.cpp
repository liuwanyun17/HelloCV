#include "../include/Crypto.h"
#include<iostream>
#include<string>
using namespace std;


char Crypto::enchar(char a,int key){
    int shift1=0;
    char shift2=' ';
    if (a >= 'A' && a <= 'Z') {             
             shift1 =((a -'A')+ key) % 26;  
             shift2 =shift1+'A' ;
             return shift2;
            
}
    else if (a>='a'&&a<='z'){
        shift1=((a-'a')+key)%26;
        shift2 =shift1+'a';
        return shift2;
    }
    
    else return a;
}
char Crypto::dechar(char a,int key){
    int shift1;
    char shift2;
    if (a >= 'A' && a <= 'Z') {             
             shift1 =((a -'A')-key) % 26;  
             shift2 =shift1+'A' ;
            return shift2;
}
    else if (a>='a'&&a<='z'){
        shift1=((a-'a')-key)%26;
        shift2 =shift1+'a';
        return shift2;
    }
    else return a;
    
}

string Crypto::encrypto (string &txt,int key){
    string result;
    for(char a:txt)
    {
        result+=enchar(a,key);

    }
    return result;
}
string Crypto::decrypto (string &txt,int key){
    string result;
    for(char a:txt){
        result+=dechar(a,key);
    }
    return result;
}