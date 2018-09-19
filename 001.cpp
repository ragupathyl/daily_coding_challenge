/*This problem was recently asked by Google.

Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass? */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool check_sum(vector<int> x, int size, int k){

sort(x.begin(),x.end());
int l=0,r=size-1;
//for(auto i = x.begin(); i != x.end(); ++i) cout<<*i<<" ";
//cout<<endl;
auto i=x.begin();
while(l!=r){
  cout<<*(i+l)<<" "<<*(i+r)<<endl;
if(*(i+l)+*(i+r)==k) return true;
else if(*(i+l)+*(i+r)<k) l++;
else r--;
}
return false;
}

int main()
{
vector<int> x;
int input,size;

cin>> size;
for(int i=0;i<size;i++)
{
  cin>>input;
x.push_back(input);
//cout<<"   ok   "<<endl;
}

int k=10;
//cout<<"okay"<<endl;

cin>>k;

//cout<<k<<endl;

if(check_sum(x,size,k))
cout<<"true"<<endl;


//cout<<*i<<" ";

//cout<<endl;

}
