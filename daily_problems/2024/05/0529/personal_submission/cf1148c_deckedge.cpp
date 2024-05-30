#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
#define all(x) (x).begin() + 1, (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using pi = pair<int, int>;

#define maxn 300005
int n;
ve<int> a, b;
int otp[maxn * 10][2], cnt = 0;

inline int red() {
    int x;
    cin >> x;
    return x;
}

void sw(int i, int j) {
    otp[cnt][0] = i, otp[cnt++][1] = j;
    swap(a[i], a[j]);
    swap(b[a[i]], b[a[j]]);
}

void cal(int i, int j) {
    if (i == j) {
        return;
    }
    if (i > j) {
        swap(i, j);
    }
    if (abs(i - j) >= n / 2) {
        sw(i, j);
        return;
    }
    if (i <= n / 2) {
        if (j <= n / 2) {
            sw(i, n), sw(j, n), sw(i, n);
        } else {
            sw(j, 1), sw(i, n), sw(1, n), sw(j, 1), sw(i, n);
        } 
    } else {
        sw(j, 1), sw(1, i), sw(j, 1);
    }
} 

void solve() {
    n = red();
    a.resize(n + 1), b.resize(n + 1);
    rep(i, 1, n + 1) {
        a[i] = red();
        b[a[i]] = i;
    }
    rep(i, 1, n + 1) {
        cal(i, b[i]);
    }
    cout << cnt << '\n';
    rep(i, 0, cnt) {
        cout << otp[i][0] << ' ' << otp[i][1] << '\n'; 
    }

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
https://codeforces.com/contest/1148/problem/C
*/



  

  

  
