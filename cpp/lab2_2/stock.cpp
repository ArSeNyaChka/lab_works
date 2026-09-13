#include "stock.h"


Stock::~Stock() {
  while (lastBox) {
    Box *prevBox = lastBox->prevBox;
    delete lastBox;
    lastBox = prevBox;
  }
}

void Stock::add(int w, int v) {
  Box *newBox = new Box{nextBoxID++, w, v, lastBox};
  lastBox = newBox;
}

int Stock::getByField(int value, int Box::*field) {
  if (!lastBox) return -1;

  if (lastBox->*field >= value) {
    int id = lastBox->id;
    Box *prevBox = lastBox->prevBox;
    delete lastBox;
    lastBox = prevBox;
    return id;
  }

  for (Box *box = lastBox; box->prevBox; box = box->prevBox) {
    if (box->prevBox->*field >= value) {
      int id = box->prevBox->id;
      Box *prevBox = box->prevBox->prevBox;
      delete box->prevBox;
      box->prevBox = prevBox;
      return id;
    }
  }

  return -1;
}

int Stock::getByW(int w) {
  return getByField(w, &Box::w);
}

int Stock::getByV(int v) {
  return getByField(v, &Box::v);
}

