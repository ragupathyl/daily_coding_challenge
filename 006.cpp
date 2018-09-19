/*
An XOR linked list is a more memory efficient doubly linked list.
Instead of each node holding next and prev fields, it holds a field named both, which is an XOR of the next node and the previous node.

Implement an XOR linked list; it has an add(element) which adds the element to the end, and a get(index) which returns the node at index.

If using a language that has no pointers (such as Python), you can assume you have access to get_pointer and dereference_pointer functions that converts between nodes and memory addresses.

*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <stdint.h>

using namespace std;

struct node{
  int value;
  uintptr_t both;
};


class XOR_list{
private:
node* start;
node* end;
//node x;

//node* traversal(node* last_address, node* current_address){
//  return (^ )
//}
public:
XOR_list(int element1=0, int element2=0){
   node* x=new node;
   node* y=new node;
   x->value=element1;
   x->both = (uintptr_t)y;
   y->value=element2;
   y->both = (uintptr_t)x;


  start=x;
  end=y;
  cout<<start<<" "<<end<<endl;
}
void add(int element){

  node *temp= new node;
  temp->value=element;
  temp->both = (uintptr_t)end;
  end->both = (uintptr_t)end->both ^ (uintptr_t)temp;
  end = temp;
  cout<<start<<endl;
  cout<<end<<endl;
  //cout<<start<<endl;

}


node* get(int index){
  int count=2;
  node* tmp = (node*)start->both;
  node* prev;
  node* prev_address = start;
  if(index==1)return start;

  //if(index=2)return tmp;
  while(count<index){
    prev = tmp;
    tmp = (node*)(tmp->both ^ (uintptr_t)prev_address);
    prev_address = prev;
    count++;

  }
  //cout<<tmp<<"->";
  return tmp;

}
};

int main(){
  //vector<int> x;
  int input,size;
 XOR_list blah;
  cout<<"Input size of array "<<endl;
  cin>> size;
  cout<<"Input array elements "<<endl;
  for(int i=0;i<size;i++)
  {
    cin>>input;
  blah.add(input);
}

for(int i=1;i<=(size+2);i++)
{
cout<<blah.get(i)->value<<" -> ";
}
cout<<endl;
}
