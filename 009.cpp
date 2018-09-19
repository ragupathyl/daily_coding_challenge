/*   Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative.

For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10, since we pick 5 and 5.

Follow-up: Can you do this in O(N) time and constant space?  */

#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int NA_sum(vector<int> A){
  int left_sum=0, right_sum=0;

  for(int i=0;i<A.size()-1;i=i+2){
    if(A[i]<0)A[i]=0;
    if(A[i+1]<0)A[i+1]=0;
    right_sum=max(left_sum,right_sum)+A[i+1];
    left_sum+= A[i];

  }
  if (A.size()%2){
    if(A[A.size()-1]<0)A[A.size()-1]=0;
    left_sum+=A[A.size()-1];
  }
  return max(left_sum,right_sum);
}

int main(){
  vector<int> A;
  int input,size;

  cout<<"Input size of array: ";
  cin>>size;

  cout<<"Input array elements: "<< endl;
  for(int i=0;i<size;i++){
    cin>>input;
    A.push_back(input);
  }

 cout<<"Max Non-adjacent sum = "<< NA_sum(A)<<endl;
}
