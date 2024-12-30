#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using pi = pair<int, int>;

inline int red() {
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n = red(), dif = -1;
    vector<int> a(n);
    generate(all(a), red);
    rep(i, 1, n) {
        int cur = abs(a[i] - a[i - 1]);
        if (cur == 1) {
            continue;
        }
        if (!cur) {
            cout << "NO\n";
            return ;
        }
        if (dif == -1) {
            dif = cur;
        }
        if (dif != cur) {
            cout << "NO\n";
            return ;
        }
    }
    if (dif == -1) {
        dif = 1;
    }
    
    rep(i, 0, n - 1) {
        int tx1 = (a[i] - 1) / dif, ty1 = (a[i] - 1) % dif;
        int tx2 = (a[i + 1] - 1) / dif, ty2 = (a[i + 1] - 1) % dif;
        if (abs(tx1 - tx2) + abs(ty1 - ty2) == 1) {
            continue;
        }
        cout << "NO\n";
        return ;
    }

    cout << "YES\n" << 1000000000 << ' ' << dif << '\n';

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0; 
}


/*
https://codeforces.com/problemset/problem/954/C
*/