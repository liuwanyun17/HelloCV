## 一.项目结构
cryptotool/



├── CMakeLists.txt          

├── include/                

│   ├── Crypto.h

│   ├── FileHandler.h

│   └── Menu.h

├── src/                    

│   ├── crypto.cpp

│   ├── filehandler.cpp

│   ├── menu.cpp

│   └── main.cpp

└── build/            

## 二.头文件，源文件
:::color1
头文件：  
头文件是一个 **接口** 或 **契约**。它向其他源文件宣告：“我这里有哪些功能可以使用”，而不暴露这些功能是如何具体实现的，例如函数声明，类，结构体声明，宏定义等。

源文件：

核心功能：

函数定义： 提供函数声明的具体实现代码。

类成员函数定义： 实现类中声明的成员函数的具体逻辑。

全局变量定义： 为全局变量分配内存。



:::

下面是我的头文件和源文件,以及一些分析

```plain
#pragma once
#include<iostream>
#include<string>
using namespace std;

class Crypto
{
    public:
    static string encrypto(string &txt,int key);
    static string decrypto(string &txt,int key);
    static char enchar(char a,int key);
    static char dechar(char a,int key);
};
```

分析：1.封装一个crypto类，并在头文件中声明

 2.函数形参与实参之间的传递

     使用值传递 - 会产生字符串拷贝，使用引用传递 - 避免拷贝，提高性能，<font style="color:#DF2A3F;">所以这里采用引用传递</font>

<font style="color:#000000;">3.encrypto/decrypto加密/解密函数，将使用者输入的txt文本即字符串，通过凯撒密码算法加密/解密,并最后返回处理后的字符串</font>

4.enchar/dechar函数，将使用者输入的字符串的每一个字符遍历后进行凯撒密码处理，并返回





```plain
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
```

分析：1.封装一个filehandler类，用于处理文件读取，并将处理后的字符串写入另一个文件（通过给出文件地址实现）

2.include<fstream>:引入了 C++ 标准库中的文件输入输出功能，能够对文件进行读写操作.

包含的主要类

`ifstream` - 用于从文件读取数据（输入文件流）

`ofstream` - 用于向文件写入数据（输出文件流）

`fstream` - 既可读又可写的文件流



```plain
#pragma once
#include<iostream>
#include<string>
using namespace std;

class Menu
{
    public:
    void showmenu();
    void encryptotxt();
    void decryptotxt();
    void encryptofile();
    void decryptofile();
    

};
```

分析：1.封装一个menu类，用于开启一个与使用者通过命令行互动的菜单窗口，实现不同密码功能的选择

2.shoumenu用于显示主要的互动

3.下面三个分别调用类的成员函数，实现不同的处理



下面是函数的具体实现——源文件

```plain
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
```

分析：1.因为类crypto封装在头文件中，该源文件在定义函数时要加类名访问，所以需包含crypto.h头文件

             2.算法解析：if条件句判断是否为字母

                                       字符转换为数字 ASCII码加减key

                                        %26处理key大于26的情况

                                         数字在转化为字符，并返回字符

```plain
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

```

分析：1.同样包含filehandler头文件

             2.文件读写功能的实现

             3.<font style="color:#DF2A3F;">file.close()很重要</font>

```plain
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
    cin.ignore();
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
   cin.ignore();
    getline(cin, beforetxt);
    cout<<"请输入密钥"<<endl;
   int key;
    cin>>key;
    string aftertxt=Crypto::decrypto(beforetxt,key);#include "../include/Menu.h"
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
    cin.ignore();
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
   cin.ignore();
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
    cin.ignore();
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
    cin.ignore();
    string content=FileHandler::readfile(beforepath);
    string aftercontent=Crypto::decrypto (content,key);
    afterpath="decrypted.txt";
    FileHandler::writefile(afterpath,aftercontent);
    
    cout<<"解密后的文件以保存至"<<afterpath<<endl;
    
};

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
    cin.ignore();
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
    cin.ignore();
    string content=FileHandler::readfile(beforepath);
    string aftercontent=Crypto::decrypto (content,key);
    afterpath="decrypted.txt";
    FileHandler::writefile(afterpath,aftercontent);
    
    cout<<"解密后的文件以保存至"<<afterpath<<endl;
    
};

```

分析：menu源文件包含前面所有的头文件

         选择功能以后跳转到相应的函数，完成使用者输出输入的工作

```plain
#include<iostream>
#include "../include/Menu.h"
using namespace std;

int main(){
    Menu my_menu;
    my_menu.showmenu();
    return 0;
}
```

分析：主函数:实例出一个menu对象



## 三.用cmake创建
代码都写好了，现在用 CMake 构建项目

### 1.CMakeLists.txt编写
写了个简易版

```plain
cmake_minimum_required(VERSION 3.10)
project(Cryptotool)

include_directories(.)

add_executable(Cryptotool 
    src/main.cpp
    src/menu.cpp 
    src/crypto.cpp
    src/filehandler.cpp
    include/Crypto.h
    include/FileHandler.h
    include/Menu.h
)
```

### 2.构建
在项目目录里执行以下

```plain
mkdir build
cd build
```

创建一个build目录

然后在build目录下运行cmake

```plain
cmake ..
```

编译 在build文件夹里

```plain
make
```

### 3.运行测试
运行程序,build下

```plain
./Cryptotool
```

## 四.实践记录
项目文件夹概览

![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760791896499-02403619-655e-43a2-ab46-084f4b55173d.png)

运行结果

![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760791951801-52ad11f2-5abc-4cab-821d-cf2c9fdd4b0e.png)![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760791951717-0972e163-afc3-45cd-8e74-f59bdacaa743.png)![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760791951929-b4651b6b-62d4-4883-aad8-6b4af53ff47d.png)![](https://cdn.nlark.com/yuque/0/2025/png/61384029/1760791951853-b6fca63a-f01b-4657-8e84-866820b2e44c.png)

