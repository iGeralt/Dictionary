#include "header.h"
#include "admin.h"
#include "password.h"
#include "list.h"
#include "user.h"

void vocabulary::display()
{
  cout<<"\t\t\t\tALL THE WORDS AND THEIR MEANING:"<<endl;
  for(int i=0;i<list.size();i++)
    cout<<list[i].first<<" : "<<list[i].second<<endl;
  cout<<"\n";
}

void vocabulary::search()
{
  int flag=0;
  for(int i=0;i<list.size();i++)
  {
    if(sword == list[i].first)
    {
      flag=1;
      cout<<"\n"<<list[i].first<<" : "<<list[i].second<<endl;
      break;
    }
  }
  if(flag == 0)
    {
      cout<<"Word not found."<<endl;

    }
}

void vocabulary::ask_user()
{
  char ans='y';
  cout<<"\t\t\t\tSearch meaning of the word"<<endl;
  while(ans == 'y' || ans == 'Y')
  {
    cout<<"\nEnter word whose meaning has to be found :";
    cin>>sword;
    transform(sword.begin(),sword.end(),sword.begin(),::tolower);
    search();
    cout<<"\nDo you want to search again?"<<endl;
    cout<<"press 'Y' for yes or press 'N' for no :"<<endl;
    cout<<"Enter your choice : ";
    cin>>ans;
    cout<<endl;
    if(ans == 'n' || ans == 'N')
    {
      break;
    }
  }
}

void vocabulary::menu()
{
  user customer;
  admin master;
  string password;
  const char *correct_password = "groupd";
  int x;
  system ("clear");
  cout<<"\t\t\t\t Main Menu "<<endl;
  while(1)
  {
    cout<<"Select any option.\n1.Admin\n2.User\n3.Exit "<<endl;
    cout<<"Enter your choice : ";
    cin>>x;
    cout<<endl;
    if(x == 1)
    {
      cin.ignore();
      while(1)
      {
        string password = getpass("Please enter the password: ",true); // Show asterisks
// to not show asterisks, replace true with false.
        if(password == correct_password)
        {
          cout << "Correct password" << endl;
          master.adminmenu();
          break;
        }
        else
        {
          cout << "Incorrect password. Try again" << endl;
        }
      }
    }
    if(x == 2)
    {
      customer.usermenu();
    }
    if(x == 3)
    {
      cout<<"See you again."<<endl;
      break;
    }
  }
}
int main()
{
  vocabulary opt;
  opt.wlist();
  opt.menu();
  return 0;
}
