#ifndef StockLib
#define StockLib


class Stock {
private:
  struct Box {
    int id;
    int w;
    int v;
    Box *prevBox;
  };
  Box *lastBox;
  int nextBoxID;

  int getByField(int value, int Box::*field);

public:
  Stock() : lastBox(nullptr), nextBoxID(0) {}
  ~Stock();
  void add(int w, int v);
  int getByW(int);
  int getByV(int);
};


#endif