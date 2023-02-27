#include <cstdio>
#include <vector>
using namespace std;

class Decoder {
 private:
  vector<int> encoded;
  int N;

 public:
  Decoder(vector<int> encoded, int N) {
    this->encoded = encoded;
    this->N = N;
  }
  Decoder decodeI() {
    vector<int> decoded;
    // First
    if (this->encoded[0] == this->N + 1) {
      decoded.push_back(1);
    } else if (this->encoded[0] == this->N - 1) {
      decoded.push_back(0);
    }
    // i+1 until N
    for (int i = 1; i < this->N; i++) {
      if (this->encoded[i] == this->encoded[i - 1] + 1) {
        decoded.push_back(1);
      } else if (this->encoded[i] == this->encoded[i - 1] - 1) {
        decoded.push_back(0);
      }
    }
    return Decoder(decoded, this->N);
  }

  Decoder decodeII() {
    vector<int> decoded;
    // First
    decoded.push_back(this->encoded[0]);
    // i+1 until N
    for (int i = 1; i < this->N; i++) {
      int y_more = decoded[i - 1] + 1;
      int y_less = decoded[i - 1] - 1;

      if (encoded[i] == y_more + (2 * decoded[i - 1])) {
        decoded.push_back(y_more);
      } else if (encoded[i] == y_less + (decoded[i - 1])) {
        decoded.push_back(y_less);
      }
    }
    return Decoder(decoded, this->N);
  }

  void printEncoded() {
    for (int i = 0; i < this->N; i++) {
      printf("%d\n", this->encoded[i]);
    }
  }
};

int main() {
  int n, t;

  scanf("%d %d", &n, &t);
  vector<int> encode;
  for (int i = 0; i < n; i++) {
    int e;
    scanf("%d", &e);
    encode.push_back(e);
  }

  if (t == 1) {
    Decoder(encode, n).decodeI().printEncoded();
  } else if (t == 2) {
    Decoder(encode, n).decodeII().decodeI().printEncoded();
  }
}