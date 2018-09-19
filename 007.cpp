/* Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.

For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.

You can assume that the messages are decodable. For example, '001' is not allowed. */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int decode(string A){
  int count=1,flag =0;
for(int i=0;i<(A.length()-1);i=i+2){
  switch(A[i]){
  case '1':
    count*=2;
    break;
  case '2':
  if((A[i+1]>='0')&&(A[i+1]<='6'))count*=2;
    break;
}
}
for(int i=1;i<(A.length());i=i+2){
  switch(A[i]){
  case '1':
    count*=2;
    flag=1;
    break;
  case '2':
  if((A[i+1]>='0')&&(A[i+1]<='6')){
    count*=2;
    flag=1;
  }
    break;
}
}
return count-1*flag;
}

int main(){
  string message;
  cout<<"Input message to be decoded:"<<endl;

  getline(cin,message);

  cout<<"Number of ways to decode: "<<decode(message);
}
