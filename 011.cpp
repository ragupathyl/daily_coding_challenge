/* Implement an autocomplete system. That is, given a query string s and a set of all possible query strings, return all strings in the set that have s as a prefix.

For example, given the query string de and the set of strings [dog, deer, deal], return [deer, deal].

Hint: Try preprocessing the dictionary into a more efficient data structure to speed up queries. */

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


vector<vector<string>> preprocessing(vector<string> dictionary){
  vector<vector<string>> dict(26);
  sort(dictionary.begin(),dictionary.end());
  char temp='a';
  string cpy;
  int count=0;
  for(auto i=dictionary.begin();i!=dictionary.end();i++){
    cpy.assign(*i);
    //cout<<cpy<<endl;
    if(cpy[0]==temp){
       //cout<<"push_back sequence"<<endl;
       dict[count].push_back(cpy);
     }
    else {
      temp = (char)(temp+1);
      //cout<<temp<<endl;
      count++;
      --i;
    }
  }
  return dict;
  }
vector<string> query(vector<vector<string>> dict, string Q){
   vector<string> result;
   string temp;
   int i=0,flag=1;
   int alphabet = (int)(Q[0]-'a');
     while(i<dict[alphabet].size()){
       temp = dict[alphabet][i];
       if(temp.compare(0,Q.size(),Q)==0){
         cout<<temp<<endl;
         result.push_back(temp);
         flag=0;
       }
       i++;

       if(temp.compare(0,Q.size(),Q)!=0 && flag==0)break;
     }
     return result;
}


int main(){
  vector<string> dictionary{"dog","deer","deal","dwindle"};
  vector<vector<string>> dict =  preprocessing(dictionary);
  string q("de");
/*  for(auto i=dict.begin();i!=dict.end();++i){
    cout<<"Words starting with : ";
  for(auto j=i->begin();j!=i->end();++j){
    cout<<*j<<"  ";}

    cout<<endl;
  }
  */

  vector<string> results = query(dict,q);
  cout<<"Query results : ";
  for(auto i=results.begin();i!=results.end();++i) cout<<*i<<"  ";
  cout<<endl;


}
