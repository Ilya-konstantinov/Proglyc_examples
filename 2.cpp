#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

void foo(int x, int &y){}

int main(){

  double a;
  int k;
  foo(a, k); // Неявное привидение

  foo((int)a, k); // Явное приведение C-style
  foo(int(a), k); // Явное приведение functional-style 
  foo(static_cast<int>(a), static_cast<int&>(k)); // Так, как должно быть

  cout << ' ' << string(5, '-') << "int" << string(5,'-') << endl;
  cout << '2' + 5 << endl;
  cout << '5' - '2' << endl; // Да, при выводе вот это выражение
  cout << 5 + '2' << endl;
  cout << '5' - 2 << endl;
  cout << ' ' << string(5, '-') << "char" << string(5,'-') << endl;
  char c[3];
  c[0] = '2' + 5;
  c[1] = 5 + '2';
  c[2] = '5' - 2; // И вот это равны, толькое первое -- int, а это char
  cout << c[0] << endl << c[1] << endl << c[2] << endl;
  cout << ' ' << string(5, '-') << "+" << string(5,'-') << endl;
  return 0;
}
