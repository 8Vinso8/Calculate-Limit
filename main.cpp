#include <iostream>
#include <iomanip>
#include <math.h>

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

long double CalculateSum(long double e, long long int n)
{
  long double sum = 0;
  long double current, previous;
  current = Formula(n);
  sum += current;
  n++;
  while (true)
  {
    previous = current;
    current = Formula(n);
    sum += current;
    n++;
    if (abs(current - previous) < e)
      break;
  }
  return sum;
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
  catch (const exception &except)
  {
    cerr << except.what() << '\n';
    return 0;
  }
  long long int n = 1;
  cout << fixed;
  cout << setprecision(CalculatePrecision(e_str));
  cout << "sum = " << CalculateSum(e, n) << endl;
  return 0;
}
