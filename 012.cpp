/* There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time. Given N, write a function that returns the number of unique ways you can climb the staircase.
The order of the steps matters.

For example, if N is 4, then there are 5 unique ways:

    1, 1, 1, 1
    2, 1, 1
    1, 2, 1
    1, 1, 2
    2, 2

What if, instead of being able to climb 1 or 2 steps at a time, you could climb any number from a set of positive integers X?
For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time. */


#include<iostream>

using namespace std;

int factorial(int x){


    int fact=1;
    for(int i=1;i<=x;i++)fact*=i;
    return fact;


}

int climb_count(int N){
  int max_2= (N-(N%2))/2;
  int result=1;
//  cout<<"max_2 = "<<max_2<<endl;
  for(int i=1;i<=max_2;i++){

  result += factorial(N-i)/factorial(i)/factorial(N-2*i);
  //cout<<"At i = "<<i<<" cumulative result = "<<result<<endl;
  }
  return result;
}


int main(){
  int N=4;
  cout<<"Number of unique ways to climb = "<<climb_count(N)<<endl;
//  cout<<factorial(N);
}
