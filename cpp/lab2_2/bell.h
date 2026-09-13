#ifndef BellLib
#define BellLib

#include <iostream>


class Bell {
private:
  bool isTimeToDing = true;
public:
  void sound() {
    if (isTimeToDing) std::cout << "ding";
    else std::cout << "dong";
    isTimeToDing = !isTimeToDing;
  }
};


#endif
