#include <bits/stdc++.h>
using namespace std;
const int MAXLEN = 100005;
int a[MAXLEN];
int b[MAXLEN];

int main() {
    int n, ans;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[x]++;
        b[a[x]]++;
        if (a[x] * b[a[x]] == i-1) {
            ans = i;
        }
        if (a[x] * b[a[x]] == i && i != n) {
            ans = i + 1;
        }
    }
    cout << ans << endl;
    return 0;
}