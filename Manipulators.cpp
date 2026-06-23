#include <iostream>
#include <string>
#include<iomanip>
#include<cmath>
using namespace std;
ostream& setup(ostream& out){
   out << setprecision(3) << fixed << left << setw(10) << setfill('%') ;
   return out;
}
class complex
{
private:
   int x;
   int y;

public:
   complex(int a, int b) : x(a), y(b) {}
   complex(){}
   friend inline istream &operator>>(istream &in, complex &z);
   friend inline ostream &operator<<(ostream &out, complex &z);
   friend double modulas(complex& z){
      return sqrt(pow(z.x,2) + pow(z.y,2));
   }
};
inline istream &operator>>(istream &in, complex &z)
{
   double a, b;
   in >> a >> b;
   if (a == (int)a && b == (int)b)
   {
      z.x = a;
      z.y = b;
   }
   else
   {
      in.setstate(ios::failbit);
   }
   return in;
}
inline ostream &operator<<(ostream &out, complex &z)
{
   out << z.x << " + " << z.y << "i" << endl;
   return out;
}
int main()
{
   complex z1;
   while (!(cin >> z1))
   {
      cout << "Enter only integer" << endl;
      cin.clear();
   }
   cout << z1;
   cout << "MOD: " <<setup<< modulas(z1) << endl;
   return 0;
}