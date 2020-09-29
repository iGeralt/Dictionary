#include"header.h"
vector <pair<string,string>>vocabulary::list;
void vocabulary::wlist()
{
  ifstream in_file("list.csv");
  string d;
  while(!in_file.eof())
  {
    getline(in_file,d);
    stringstream ss(d);
    vector <string> word;
    string meaning;
    string w;
    while(getline(ss,meaning,','))
    {
      word.push_back(meaning);
      w = word[0];
    }
    list.push_back(make_pair(w,meaning));
  }
  list.erase(list.end() - 1);
}
