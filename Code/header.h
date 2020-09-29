#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<termios.h>
#include<unistd.h>
#include<fstream>
#include<sstream>
#include<cstdlib>
#ifndef header_data
#define header_data
using namespace std;
class vocabulary
{
private:
  string sword;
public:
  static vector <pair<string,string>> list;
  void menu();
  void display();
  void search();
  void ask_user();
  void wlist();
  void write_to_file();
  vocabulary(){}
};

class user:public vocabulary
{
public:
  void usermenu();
};

//Admin class
class admin:public vocabulary
{
  string w; //word
  string m; //meaning
public:
  void adminmenu();
  void add();
  void delete_word();
  void modify_meaning();
};
#endif
