/* Given an integer k and a string s, find the length of the longest substring that contains at most k distinct characters.

For example, given s = "abcba" and k = 2, the longest substring with k distinct characters is "bcb".

asfdsdassdsafdasdf  k=3

starting_position = 4
max_count = 9
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

string substr_k(string str, int k){
        vector<char> char_list(k,'\0');

        vector<int> count(k,0);
        vector<int>::iterator l;
        vector<char>::iterator m;
        int position=0,current_pos=0,max_count=0;
        char letter;
        for(auto i=str.begin(); i!=str.end(); ++i) {
                letter=*i;
                cout<<endl<<"Processing letter : "<<letter<<endl;

                m=find(char_list.begin(),char_list.end(),letter);
                l=find(count.begin(),count.end(),0);

                if(m!=char_list.end()) {
                  count[m-char_list.begin()]++;
                  if(count[k-1]==0)max_count++;

                }
                else if(l!=count.end()) {
                        *l=1;
                        char_list[l-count.begin()]=letter;
                        max_count++;
                }

                else{
                        if((i-str.begin()-current_pos)>max_count) {
                                max_count=i-str.begin()-current_pos;
                                position=current_pos;
                        }
                        while(1) {

                                m=find(char_list.begin(),char_list.end(),str[current_pos]);
                                if(count[m-char_list.begin()]==1) {
                                        char_list[m-char_list.begin()]=letter;
                                        current_pos++;
                                        break;
                                }
                                else{
                                        count[m-char_list.begin()]--;
                                }
                                current_pos++;
                        }
                }
                cout<<"Character list : ";
                for(auto j=char_list.begin();j!=char_list.end();++j)cout<<*j<<" ";
                cout<<endl<<"Character count : ";
                for(auto j=count.begin();j!=count.end();++j)cout<<*j<<" ";
                cout<<endl;



        }
        return str.substr(position,max_count);

}

int main(){
        string str;
        int k;

        cout<<"Input string : ";
        getline(cin,str);

        cout<<"Input max number of unique letters : ";
        cin>>k;

        string substr = substr_k(str,k);
        cout<<endl<<"Max substring with "<<k<<" unique letters is "<<substr<< " with "<<substr.size()<<" letters"<<endl;




}
