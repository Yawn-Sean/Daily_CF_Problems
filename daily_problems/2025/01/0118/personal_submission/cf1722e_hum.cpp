#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  int t;
  cin >> t;
  int M = 1001;

  while (t--) {
    vector sum(M, vector<i64>(M));
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
      int h, w;
      cin >> h >> w;
      sum[h][w] += 1ll * h * w;
    }

    for (int i = 1; i < M; i++) {
      for (int j = 1; j < M; j++) {
        sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
      }
    }

    for (int i = 0; i < q; i++) {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      x1++, y1++, x2--, y2--;
      cout << sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1] << endl;
    }
  }
}
