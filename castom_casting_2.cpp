#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

class A{
public:
  int x;
  A(int _x) : x(_x){}
};

class B{
public:
  int first, second;
  B(int _first, int _second) : first(_first), second(_second){}

  virtual operator A(){
    return A(first + second);
  }
};

class Cl : B{
public:
  int third;
  Cl(int _first, int _second, int _third) : B(_first, _second), third(_third){};
};

ostream& operator<<(ostream& out, A a){
  out << "Actually, it's A!\nx = " << a.x << endl;
  return out;
}
ostream& operator<<(ostream& out, B x){
  out << "Actually, it's B!\nfirst = " << x.first << endl << "second = " << x.second << endl;
  return out;
}

void foo1(A a, B b){ 
  cout << a << endl << b << endl;
}

void foo2(A a1, A* a2){ 
  cout << a1 << endl << *a2 << endl;
}

int main(){

  A a1{1};
  B b1{5, 7}; 
  Cl c2(-5, -7, 15);
  Cl *cptr = &c2;

  foo2(a1, reinterpret_cast<A*>(cptr));

  return 0;
}

