#include <cstdio>
#include <iostream>
using namespace std;
class Circle {
 public:
  int maxCircle;
  int k;
  int n;
  int pos;
  int theif;
  int rotateUntilEnd() {
    // std::cout << "pos: " << this->pos << "\n";

    while (1) {
      this->pos = (this->pos + this->k) % (this->maxCircle);
      //   std::cout << "pos: " << this->pos << "\n";

      if (this->pos == 1) {
        break;
      }
      if (this->pos == this->theif) {
        this->n++;
        break;
      }

      this->n++;
    }

    return this->n;
  }

  Circle(int maxCircle, int k, int theif) {
    this->maxCircle = maxCircle;
    this->k = k;
    this->theif = theif;
    this->n = 1;
    this->pos = 1;
  }
};

int main() {
  int maxCircle, k, theif;
  scanf("%d %d %d", &maxCircle, &k, &theif);
  Circle circle(maxCircle, k, theif);
  int n = circle.rotateUntilEnd();
  std::cout << n;
  return 0;
}