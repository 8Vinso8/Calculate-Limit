#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>

using namespace std;

long double Formula(long long int n)
{
  return 1 / (pow(2, sqrt(n)));
}

int CalculatePrecision(const string &e_str)
{
  int precision = 0;
  bool dotFound = false;
  for (char c : e_str)
  {
    if (dotFound)
      precision++;
    if (c == '.')
      dotFound = true;
  }
  return precision;
}

int main()
{
  string e_str;
  long double e;
  cout << "e = ";
  cin >> e_str;
  try
  {
    e = stod(e_str);
  }
  catch (const std::exception &except)
  {
    std::cerr << except.what() << '\n';
    return 0;
  }
  int precision = CalculatePrecision(e_str);
  int n = 1;
  long double sum = 0;
  long double current, previous;
  current = Formula(n);
  sum += current;
  n++;
  bool calculating = true;
  while (calculating)
  {
    previous = current;
    current = Formula(n);
    sum += current;
    if (abs(current - previous) < e)
      calculating = false;
    n++;
  }
  cout << fixed;
  cout << setprecision(precision);
  cout << "sum = " << sum << endl;
  return 0;
}
