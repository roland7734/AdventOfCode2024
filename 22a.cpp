#include <iostream>
#include <fstream>

using namespace std;

long long mix(long long secret, long long value) { return secret ^ value; }

long long prune(long long secret) { return secret % 16777216; }

long long nextSecret(long long secret) {
  secret = mix(secret, secret * 64);
  secret = prune(secret);
  secret = mix(secret, secret / 32);
  secret = prune(secret);
  secret = mix(secret, secret * 2048);
  secret = prune(secret);
  return secret;
}

int main() {
  ifstream input("input.txt");
  ofstream output("output.txt");

  long long sum = 0;
  long long secret;
  while (input >> secret) {
    for (int i = 0; i < 2000; ++i) {
      secret = nextSecret(secret);
    }
    sum += secret;
  }

  output << sum << endl;

  input.close();
  output.close();

  return 0;
}
