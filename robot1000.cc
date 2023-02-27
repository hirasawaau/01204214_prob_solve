#include <iostream>
#include <string>

using namespace std;

class Robot {
 private:
  int X;
  int Y;

  void North() { this->Y++; }
  void South() { this->Y--; }
  void East() { this->X++; }
  void West() { this->X--; }
  void Reset() {
    this->X = 0;
    this->Y = 0;
  }

 public:
  Robot() {
    this->X = 0;
    this->Y = 0;
  }

  void Walk(char d) {
    switch (d) {
      case 'N':
        this->North();
        break;
      case 'S':
        this->South();
        break;
      case 'E':
        this->East();
        break;
      case 'W':
        this->West();
        break;
      case 'Z':
        this->Reset();
        break;
      default:
        break;
    }
  }

  void GetCoordinates() { cout << this->X << " " << this->Y << "\n"; }
};

int main() {
  Robot robot;
  string s;

  cin >> s;

  for (int i = 0; i < s.length(); i++) {
    robot.Walk(s[i]);
  }

  robot.GetCoordinates();
  return 0;
}