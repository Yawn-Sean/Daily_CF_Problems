#include <iostream>
using namespace std;
#define int long long

int arr[1 << 18] {}, nxt[1 << 18] {};
void yrlpSolve() {
    int n, k; cin >> n >> k;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    nxt[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] != 1) nxt[i] = i;
        else nxt[i] = nxt[i + 1];
    }
    int ml = sum * k, ans = 0;
    for (int i = 0; i < n; i++) {
        int s = 0, m = 1;
        for (int j = i; j < n; j++) {
            if (ml / m < arr[j]) break;
            if (arr[j] == 1 and j != n - 1) {
                int p = nxt[j];
                if (s * k < m && (s + p - j) * k >= m && m % k == 0) ans++;
                s += p - j;
                j = p - 1;
            } else {
                m *= arr[j];
                s += arr[j];
                if (s * k == m) ans++;
            }
        }
    }
    cout << ans;
    return; 
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T = 1; //cin >> T;
    while (T--) yrlpSolve();
}
