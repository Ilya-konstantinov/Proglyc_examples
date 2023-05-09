#include <iostream>

using std::cout;
using std::endl;

class A{
public:
  int x;
  A(int _x) : x(_x) {}

  friend std::ostream& operator<<(std::ostream&, A);
};

// Если пояснять быстро -- магия, которая позволяет выводить пользовательский класс через cout
std::ostream& operator<<(std::ostream& out, A a){ 
  out << a.x;
  return out;
}

class B : A{
public:
  int y;
  B(int _x, int _y) : A(_x), y(_y) {}

  operator A() const { // Предупреждение "converting 'B' to a base class 'A' will never use a type conversion operator [-Wclass-conversion]"
    cout << "Явное преобразование\n";
    return x;
  }

  A make(){
    return this->operator A();
  }
};

int main(){
  A t1{1};
  B t2{3,4};
  std::cout << t2.make() << std::endl; // Добросовестно возвращает тип A // И он РАБОТАЕТ!

  A tt1 = (A)t2; // Ошибка "не допускается преобразование в недоступный базовый класс "A"" // А он НЕ РАБОТАЕТ!
  
  A* tt2 = reinterpret_cast<A*>(&t2); 
  std::cout << *tt2;
}

// Философия C++ -- она такова и больше некакова...