/* #pragma GCC optimize(2) */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define Debug(x) cout << #x << ':' << x << endl
#define all(x) (x).begin(), (x).end()

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int d;
  cin >> d;
  int n, m;
  cin >> n >> m;

  vector<int> minX(d), maxX(d), minY(d), maxY(d);
  for (int i = 0; i < d; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    minX[i] = min(x1, x2);
    maxX[i] = max(x1, x2);
    minY[i] = min(y1, y2);
    maxY[i] = max(y1, y2);
  }

  int targetL, targetR, targetT, targetB;
  cin >> targetL >> targetR >> targetT >> targetB;

  vector<int> allMinX = minX, allMaxX = maxX;
  vector<int> allMinY = minY, allMaxY = maxY;
  sort(allMinX.begin(), allMinX.end());
  sort(allMaxX.begin(), allMaxX.end());
  sort(allMinY.begin(), allMinY.end());
  sort(allMaxY.begin(), allMaxY.end());

  for (int i = 0; i < d; i++) {
    int cntL = int(lower_bound(allMinX.begin(), allMinX.end(), maxX[i]) -
                   allMinX.begin());
    if (minX[i] < maxX[i])
      cntL--;
    int cntR = d - int(upper_bound(allMaxX.begin(), allMaxX.end(), minX[i]) -
                       allMaxX.begin());
    if (maxX[i] > minX[i])
      cntR--;

    int cntT = int(lower_bound(allMinY.begin(), allMinY.end(), maxY[i]) -
                   allMinY.begin());
    if (minY[i] < maxY[i])
      cntT--;

    int cntB = d - int(upper_bound(allMaxY.begin(), allMaxY.end(), minY[i]) -
                       allMaxY.begin());
    if (maxY[i] > minY[i])
      cntB--;

    if (cntL == targetL && cntR == targetR && cntT == targetT &&
        cntB == targetB) {
      cout << (i + 1) << endl;
      return 0;
    }
  }

  cout << -1 << endl;
  return 0;
}
