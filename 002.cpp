/*This problem was asked by Uber.

Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?  */

#include <iostream>
#include <vector>

using namespace std;

vector<int> func(vector<int> A){
  vector<int> x(A.size(),1);
  int temp=1;
  cout<<A.size()<<endl;
  for(int i=0;i<A.size();i++){
    x[i] = temp;
    cout<<temp<<" ";
    temp *= A[i];

  }
  cout<<endl;
 temp = 1;
  for(int i=A.size()-1;i>=0;i--){
  x[i] *= temp;
      cout<<temp<<" ";
    temp *= A[i];
  }
  cout<<endl;

  return x;

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


vector<int> prod = func(x);

for(auto i=prod.begin();i!=prod.end();i++)
cout<<*i<<" ";
cout<<endl;


}
