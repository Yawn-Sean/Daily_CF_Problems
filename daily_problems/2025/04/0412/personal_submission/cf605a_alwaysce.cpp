#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    /*
    ans = n - 连续子序列的最大长度L
    */
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> pos(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    int L = 0;
    
    int i = 1;
    while (i <= n) {
        int cur = pos[i];
        int j = i;
        while (j <= n && pos[j] >= cur) {
            cur = pos[j];
            j++;
        }
        L = max(L, j - i);
        i = j;
    }
    cout << n - L << '\n';
    
    return 0;
}
