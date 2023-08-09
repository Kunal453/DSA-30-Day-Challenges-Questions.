// Reverse a string using recursion.
# include <iostream>
using namespace std;

void Reverse( string &str, int left, int right){
  if(lrft >= right){
    return; // Base case: stop recursion when left index crosses right index
  }
  // swap charater from left to right in tstring
swap( str[left], str[right]);
  // Recursively call the function with updated string
 
Reverse( str , left + 1, right-1);
}
int main(){
  string input ;
  cin >> input;
  Reverse(input, 0, input.length() -1);
  cout << "Reverse string is: " << input << endl;
  return  0;
}

// ==================================================================================
/*
Enter the string  :Pratham
Reverse string is :mahtarP
*/
