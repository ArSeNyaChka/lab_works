#include "bell.h"
#include "oddEvenSeparator.h"
#include "table.h"
#include "complex.h"
#include "stock.h"
#include <iostream>


int main() {
  std::cout << "Vvedite nomer zadan koroch (5 shtuk): ";
  int nomerZadania;
  std::cin >> nomerZadania;
  switch (nomerZadania) {
  case 1:
    {std::cout << "Ex. 1\n" "Skolko raz ding dong: ";
    int colichstvoDingDong;
    std::cin >> colichstvoDingDong;
    Bell bell;
    for (int i = 0; i < colichstvoDingDong; ++i) bell.sound();
    std::cout << '\n';}
    break;
  
  case 2:
    {OddEvenSeparator oes;
    for (int i = 0; i < 20; ++i) oes.add_number(i);
    oes.even();
    oes.odd();}
    break;
  
  case 3:
    {Table t(3, 4);
    t.set_value(1, 2, 123);
    t.print();}
    break;
  
  case 4:
    {Complex z1(1, 3);
    Complex z2(2, 4);
    Complex z3 = z1.mult(z2);
    z3.print();}
    break;
  case 5:
    Stock stock;
    stock.add(4, 8);
    stock.add(8, 10);
    stock.add(2, 28);
    std::cout << stock.getByW(3) << " " << stock.getByV(28) << '\n';
  }

}
