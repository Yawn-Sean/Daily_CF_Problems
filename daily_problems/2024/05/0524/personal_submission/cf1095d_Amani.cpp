#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int p[MAXN], a[MAXN][2], vis[MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    int i = 1;
    cout << 1;
    vis[1] = 1;
    int cnt = n-1;
    while (cnt--) {
        int x = a[i][0], y = a[i][1];
        if (a[x][0] == y || a[x][1] == y && !vis[x]) {
            p[i] = x;
            i = x;
            vis[x] = 1;
            cout << " " << x;
        }
        else {
            p[i] = y;
            i = y;
            vis[y] = 1;
            cout << " " << y;
        }
    }
    cout << endl;
    return 0;
}