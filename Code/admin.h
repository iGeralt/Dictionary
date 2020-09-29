#include"header.h"
void vocabulary::write_to_file()
{
  ofstream out_file("list.csv");
  for(int i=0;i<list.size();i++)
  {
    out_file<<list[i].first<<","<<list[i].second<<endl;
  }
}
void admin::add()
{
  char ans='y';
  int x; // to take option from user
  cout<<"\t\t\t\tAdd new word and its meaning in the dictionary "<<endl;
  while(ans == 'y')
  {
    int flag=0;
    cout<<"\nEnter the word :";
    cin>>w;
    transform(w.begin(),w.end(),w.begin(),::tolower);
    for(int i=0;i<list.size();i++)
    {
      if(w == list[i].first)
      {
        flag=1;
        cout<<"\nWord is already present"<<endl;
        cout<<"\nDo you want to add another word:"<<endl;
        cout<<"Press 'Y' for yes or press 'N' for no"<<endl;
        cout<<"Enter your choice : ";
        cin>>ans;
        cout<<endl;
        if(ans == 'y' || ans == 'Y')
        {
          break;
        }
        if(ans == 'n' || ans == 'N')
        {
          break;
        }
      }
    }
    if(flag == 0)
    {
      cout<<"Enter the meaning:";
      cin.ignore();
      getline(cin,m);
      transform(m.begin(),m.end(),m.begin(),::tolower);
      list.insert(list.begin(),make_pair(w,m));
      sort(list.begin(),list.end());
      write_to_file();
      cout<<"\nSelect an option to continue:\n1.Display all words and their and meaning."<<endl;
      cout<<"2.Add another word.\n3.Exit"<<endl;
      cout<<"Enter your choice : ";
      cin>>x;
      cout<<endl;
      if(x == 1)
      {
        display();
        break;
      }
      if(x == 2)
      {
        continue;
      }
      if(x == 3)
      {
        break;
      }
    }
  }
}

void admin::delete_word()
{
  string ans;
  cout<<"Delete word and its meaning "<<endl;
  int flag=0;
  cout<<"\nEnter the word which has to be deleted :";
  cin>>w;
  transform(w.begin(),w.end(),w.begin(),::tolower);
  for(int i=0;i<list.size();i++)
  {
    if(w == list[i].first)
    {
      flag=1;
      list.erase(list.begin()+i);
      write_to_file();
      cout<<"\nWord and its meaning deleted."<<endl;
      cout<<"\nSelect an option to continue:\n1.Display all the words."<<endl;
      cout<<"2.Delete another word.\n3.exit"<<endl;
      cout<<"Enter your choice : ";
      cin>>ans;
      cout<<endl;
      if(ans == "1")
      {
        display();
        break;
      }
      if(ans == "2")
      {
        delete_word();
        break;
      }
      if(ans == "3")
      {
        break;
      }
    }
  }
  if(flag == 0)
  {
    cout<<"\nWord not found."<<endl;
    cout<<"\nDo you want to try again."<<endl;
    cout<<"Press 'Y' for yes or press 'N' for no"<<endl;
    cout<<"Enter your choice : ";
    cin>>ans;
    cout<<endl;
    if(ans == "y" || ans == "Y")
    {
      delete_word();
    }
    if(ans == "n" || ans == "N")
    {
      cout<<"Going back to Admin menu."<<endl;
    }
  }
}
void admin::modify_meaning()
{
  string ans;
  cout<<"\t\t\t\t Modify the meaning of existing word "<<endl;
  int flag=0;
  cout<<"\nEnter the word whose meaning has to be modified : ";
  cin>>w;
  transform(w.begin(),w.end(),w.begin(),::tolower);
  for(int i=0;i<list.size();i++)
  {
    if(w == list[i].first)
    {
      flag = 1;
      cout<<"Enter new meaning of the word : ";
      cin.ignore();
      getline(cin,m);
      transform(m.begin(),m.end(),m.begin(),::tolower);
      list[i].second=m;
      write_to_file();
      cout<<"\nMeaning of the word has been changed."<<endl;
      cout<<"\nSelect an option to continue:\n1.Display all the words."<<endl;
      cout<<"2.Modify again.\n3.exit"<<endl;
      cout<<"Enter your choice : ";
      cin>>ans;
      cout<<endl;
      if(ans == "1")
      {
        display();
        break;
      }
      if(ans == "2")
      {
        modify_meaning();
        break;
      }
      if(ans == "3")
      {
        break;
      }
    }
  }
  if(flag == 0)
  {
    cout<<"\nWord not found."<<endl;
    cout<<"\nDo you want to try again."<<endl;
    cout<<"Press 'Y' for yes or press 'N' for no"<<endl;
    cout<<"Enter your choice : ";
    cin>>ans;
    cout<<endl;
    if(ans == "y" || ans == "Y")
    {
      modify_meaning();
    }
    if(ans == "n" || ans == "N")
    {
      cout<<"Going back to Admin menu."<<endl;
    }
  }
}
void admin::adminmenu()
{
  int x;
  while(1)
  {
    cout<<"\t\t\t\tAdmin Menu "<<endl;
    cout<<"\n1.Search the meaning of the word.\n2.Display all the words and its meaning."<<endl;
    cout<<"3.Add new word and its meaning.\n4.Modify the meaning of existing word."<<endl;
    cout<<"5.Delete the word and its meaning.\n6.Exit"<<endl;
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
      add();
    }
    if(x == 4)
    {
      modify_meaning();
    }
    if(x == 5)
    {
      delete_word();
    }
    if(x == 6)
    {
        break;
    }
  }
}
