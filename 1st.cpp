
#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
  int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int size = sizeof(array) / sizeof(array[0]);
  int k = 4;
  sort(array, array + size);
  cout << k << "th largest element in the given array is" << array[size - k] << endl;
  return 0;
}



