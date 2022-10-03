#include <math.h>
#include <iostream>
#include <iomanip>

long double Formula(long long int n){
  return (1 / pow(2, sqrt(n)));
}

using namespace std;
int main(){
  long double e = 0.0000001;
  long double b = 0.0;
  long double iter = e;
  long long int n = 1;
  long double Sn = 0;
  long long int count = 0;
  int max_allowed = 100;
  while(true){
    Sn += Formula(n);
    if (abs(Sn - b) < e)
      count++;
    else{
      b += iter;
      count = 0;
   }
    if (count == max_allowed)
      break;
    n++;
  }
  cout << fixed;
  cout << setprecision(7);
  cout << b << endl;
  return 0;
}
