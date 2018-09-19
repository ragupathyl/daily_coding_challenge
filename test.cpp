
/*
#include<iostream>
#include<stdint.h>
#include<string>
using namespace std;
int main(){
  string a("abcdefgh");
  cout<<(char)(a[2]+a[3]);

}
*/


#include <iostream>
using std::cout;
using std::endl;

#include <algorithm>
#include <vector>
#include <iterator>

int main()
{
   int a[ 10 ] = { 10, 2, 17, 5, 16, 8, 13, 11, 20, 7 };
   std::vector< int > v( a, a + 10 ); // copy of a
   std::ostream_iterator< int > output( cout, " " );

   cout << "Vector v contains: ";
   std::copy( v.begin(), v.end(), output ); // display output vector

   std::vector< int >::iterator location;
   location = std::find( v.begin(), v.end(), 7 );

   if ( location != v.end() ) // found 16
      cout << "\n\nFound 16 at location " << ( location - v.begin() );
   else // 16 not found
      cout << "\n\n16 not found";

   cout << endl<<*v.end()<<endl<<*location;
   return 0;
}
