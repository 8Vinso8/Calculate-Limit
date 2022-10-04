#include <math.h>
#include <iostream>
#include <string>
#include <iomanip>

long double Formula(long long int n){
  return (1 / pow(2, sqrt(n)));
}

using namespace std;
int main(){
  cout << "Введите e: ";
  string e_str;
  cin >> e_str;
  cout << endl;
  int precision = e_str.length() - 2;
  long double e;
  try
  {
    e = stod(e_str);
  }
  catch(const std::exception& except)
  {
    std::cerr << except.what() << '\n';
    return 0;
  }
  long double b = 0.0;
  long double iter = e;
  long long int n = 1;
  long double Sn = 0;
  long long int count = 0;
  int max_allowed = 1000;
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
  cout << setprecision(precision);
  cout << b << endl;
  return 0;
}
