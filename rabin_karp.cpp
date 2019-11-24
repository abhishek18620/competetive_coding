#include <iostream>
#include <string>

// consts
constexpr int d = 256;
constexpr int prime = 103;

// Rabin Karp function
void RabinKarp(std::string &text, std::string &pattern) {
  int text_len = text.length();
  int patt_len = pattern.length();
  int text_hash = 0;
  int patt_hash = 0;
  int h_common = 1;
  // Calculate d^(patt_len-1) % prime
  for (int i = 0; i < patt_len; i++) {
    h_common = (h_common * d) % prime;
  }

  // Calculate hashes for first window
  for (int i = 0; i < patt_len; i++) {
    patt_hash = (d * patt_hash + pattern[i]) % prime;
    text_hash = (d * text_hash + text[i]) % prime;
  }

  for (int i = 0; i <= text_len - patt_len; i++) {
    if (patt_hash == text_hash) {
      bool verify_equality = true;
      for (int j = 0; j < patt_len; j++) {
        if (text[i + j] != pattern[j]) {
          verify_equality = false;
          break;
        }
      }
      if (verify_equality) {
        std::cout << "Pattern found at " << i << std::endl;
      }
    }
    if (i < text_len - patt_len) {
      // text hash for text(i+1, i + patt_len + 1)
      text_hash =
          (d * (text_hash - text[i] * h_common) + text[i + patt_len]) % prime;
      if (text_hash < 0) {
        // text_hash could come out to be negative
        text_hash += prime;
      }
    }
  }
  return;
}

int main() {
  std::string text;
  std::string pattern;
  std::cin >> text >> pattern;
  RabinKarp(text, pattern);
  return 0;
}
