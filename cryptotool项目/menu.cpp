#include "../include/Menu.h"
#include "../include/Crypto.h"
#include "../include/FileHandler.h"
#include<iostream>
using namespace std;

void Menu::showmenu(){
    cout<<"欢迎来到我的cryptotool"<<endl;
    cout<<"请选择你需要的服务"<<endl;
    cout<<"A.加密文本"<<endl;
    cout<<"B.解密文本"<<endl;
    cout<<"C.加密文件"<<endl;
    cout<<"D.解密文件"<<endl;
    char choice;
    cin>>choice;
    cin.ignore();
    
    switch(choice){
        case 'A':
        encryptotxt();
        break;
        case 'B':
        decryptotxt();
        break;
        case 'C':
        encryptofile();
        break;
        case 'D':
        decryptofile();
        break;
        default:
        cout<<"输入错误，请重新输入"<<endl;
        break;
    }
};
void  Menu::encryptotxt(){
    cout<<"请输入你要加密的文本"<<endl;
    string beforetxt;
    getline(cin, beforetxt);
    cout<<"请输入密钥"<<endl;
    int key;
    cin>>key;
    string aftertxt=Crypto::encrypto(beforetxt,key);
    cout<<"加密后的文本是:"<<aftertxt<<endl;
};
void Menu::decryptotxt(){
    cout<<"请输入你要解密的文本"<<endl;
    string beforetxt;
    getline(cin, beforetxt);
    cout<<"请输入密钥"<<endl;
   int key;
    cin>>key;
    string aftertxt=Crypto::decrypto(beforetxt,key);
    cout<<"解密后的文本是:"<<aftertxt<<endl;
};
void Menu::encryptofile(){
    cout<<"请输入你要加密的文件路径"<<endl;
    string beforepath;
    string afterpath;
  
    getline(cin, beforepath);
    cout<<"请输入密钥"<<endl;
    int key;
    cin>>key;
    string content=FileHandler::readfile(beforepath);
    string aftercontent=Crypto::encrypto (content,key);
    afterpath="encrypted.txt";
    FileHandler::writefile(afterpath,aftercontent);
    
    cout<<"加密后的文件以保存至"<<afterpath<<endl;
    
};
void Menu::decryptofile(){
    cout<<"请输入你要解密的文件路径"<<endl;
    string beforepath;
    string afterpath;
     
     getline(cin, beforepath);
    cout<<"请输入密钥"<<endl;
    int key;
    cin>>key;
    string content=FileHandler::readfile(beforepath);
    string aftercontent=Crypto::decrypto (content,key);
    afterpath="decrypted.txt";
    FileHandler::writefile(afterpath,aftercontent);
    
    cout<<"解密后的文件以保存至"<<afterpath<<endl;
    
};
