#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    map<int, int> mp;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    vector<int> b(n);   
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        mp[b[i]]++;
    }

    int to_divide = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            ++to_divide;
        }
    }

    i64 ans = 1;
    i64 mod;
    cin >> mod;
    for (auto& [_, v]: mp) {
        for (int i = 1; i <= v; i++) {
            int y = i;
            while (y % 2 == 0 && to_divide > 0) {
                y /= 2;
                to_divide--;
            }
            ans = 1ll * ans * y % mod;
        }
    }    

    cout << ans << '\n';
    return 0;
}
