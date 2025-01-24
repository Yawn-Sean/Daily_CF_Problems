#include <bits/stdc++.h>
using namespace std;


int main() {
  vector<int> tmp;
  for (int i = 0; i <= 9; i++) {
    cout << i << i << i << i << endl;
    int a, b;
    cin >> a >> b;
    for (int j = 0; j < a; j++) {
      tmp.push_back(i);
    }
  }

  do {
    for (int i: tmp) {
      cout << i;
    }
    cout << endl;
    int a, b;
    cin >> a >> b;
    if (a == 4 && b == 0) {
      return 0;
    }
  } while (ranges::next_permutation(tmp).found);
}
