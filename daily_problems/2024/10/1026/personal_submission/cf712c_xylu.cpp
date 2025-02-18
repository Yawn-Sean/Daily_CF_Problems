#include <bits/stdc++.h>
using namespace std;

void solveC() {
    int x, y, ans = 0;
    cin >> x >> y;
    int a = x, b = x, c = x;
    while (a != x) {
        a = min(x, b + c - 1);
        swap(a, b);
        swap(b, c);
        ans++;
    }
    cout << ans << '\n';
}

int main() {
    solveC();
    return 0;
}
