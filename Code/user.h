#include "header.h"
void user::usermenu()
{
  int x;
  while(1)
  {
    cout<<"\t\t\t\tUser Menu. "<<endl;
    cout<<"\nSelect an option to proceed.\n1.Search word's meaning."<<endl;
    cout<<"2.Display all the words and their meaning\n3.exit"<<endl;
    cout<<"Enter your choice : ";
    cin>>x;
    cout<<endl;
    if(x == 1)
    {
      ask_user();
    }
    if(x == 2)
    {
      display();
    }
    if(x == 3)
    {
      cout<<"\n\t\t\t\tTHANK YOU!"<<endl;
      break;
    }
  }
}
