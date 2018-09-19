/* This problem was asked by Stripe.

Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array.
 The array can contain duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

3 2 1 6 7 5   ---- 4
5 0 1 2 4  --------- 3

You can modify the input array in-place. */

#include <iostream>
#include <vector>

using namespace std;

int min_int(vector<int> A){
  int i,j=A.size()-1,tmp;
  for(i=0;i<j;i++){
    if(A[i]<1){
      tmp=A[i];
      A[i]=A[j];
      A[j]=tmp;
      j--;
      i--;
    }
  }
  for(int i=0;i<A.size();i++)cout<<A[i]<<" ";
  cout<<endl;
  cout<<"i="<<i<<endl;
  tmp=i;
  for(i=0;i<=tmp;i++){
    if(abs(A[i])-1<=tmp){
    A[abs(A[i])-1]= -1*abs(A[abs(A[i])-1]);
  }
  //  cout<<A[A[i]-1]<<" ";
  }
  cout<<endl;
  for(int i=0;i<A.size();i++)cout<<A[i]<<" ";
  cout<<endl;
  for(i=0;i<=tmp;i++){
    if(A[i]>0)return (i+1);
  }
  return (i+1);
}
int main(){
  vector<int> x;
  int input,size;

  cout<<"Input size of array "<<endl;
  cin>> size;
  cout<<"Input array elements "<<endl;
  for(int i=0;i<size;i++)
  {
    cin>>input;
  x.push_back(input);
}

cout<<min_int(x)<<endl;


}
