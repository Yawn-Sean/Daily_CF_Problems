#include <iostream>
using namespace std;

const int N = 2e5 + 10;

int n, a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    int ans = a[n];
    for (int i = n - 1; i >= 2; i--) {
        ans = max(ans, a[i] - ans);
    }
    cout << ans;
    return 0;
}
