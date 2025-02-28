#include <bits/stdc++.h>
using namespace std;

void solveA() {
    int n, ans = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j < n && a[j] != a[j-1]) j++;
        ans = max(ans, (j - i) / 2);
        for (int k = 0; k < (j-i)/2; k++) a[i+k] = a[i-1], a[j-k-2] = a[j-1];
        i = j;
    }
    cout << ans << '\n';
    for (int i = 0; i < n; i++) cout << a[i] << ' ';
    cout << '\n';
}

int main() {
    solveA();
    return 0;
}
