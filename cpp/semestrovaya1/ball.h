#ifndef ballLib
#define ballLib

#include <ostream>
#include <string>

enum class BallType {
  Basketball,
  Football,
  Volleyball,
  Rugby,
  Golf,
  Tennis,
  Count
};

const inline char *ballTypeCharConstants[] = {
  "Basketball",
  "Football",
  "Volleyball",
  "Rugby",
  "Golf",
  "Tennis"
};

struct Ball {
  BallType type;
  std::string color;
  std::string brand;
  float coast;
  int quantity;
};

// Вовзращает строку соответствующую значению перечисления BallType
inline std::string ballTypeToString(BallType bt) {
  return ballTypeCharConstants[(int)bt];
}

#endif