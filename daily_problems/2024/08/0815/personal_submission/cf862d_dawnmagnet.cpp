#include <iostream>
#include <vector>

void print(const std::vector<unsigned char> &z) {
  std::cout << "? ";
  for (const auto &item : z) {
    std::cout << static_cast<int>(item);
  }
  std::cout << std::endl;
}

void flush() {
  std::cout.flush();
}

unsigned int input() {
  unsigned int n;
  std::cin >> n;
  return n;
}

unsigned int query(const std::vector<unsigned char> &z) {
  print(z);
  flush();
  return input();
}

unsigned int binary_query(unsigned int n, unsigned char t) {
  std::vector<unsigned char> z(n, t);
  unsigned int r1 = query(z);
  unsigned int l = 0;
  unsigned int r = n;
  while (r > l) {
    unsigned int m = (l + r) / 2;
    std::vector<unsigned char> z(n, t);
    for (unsigned int i = l; i <= m; ++i) {
      z[i] = 1 - t;
    }
    unsigned int r2 = query(z);
    if (r1 - r2 == m - l + 1) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  return l;
}

int main() {
  unsigned int n = input();
  std::vector<unsigned char> str(n);
  unsigned int r1 = query(str);
  str[0] = 1;
  unsigned int r2 = query(str);
  if (r2 > r1) {
    int r = binary_query(n, 1);
    std::cout << "! " << 1 << " " << r + 1 << std::endl;
  } else {
    int r = binary_query(n, 0);
    std::cout << "! " << r + 1 << " " << 1 << std::endl;
  }
  return 0;
}