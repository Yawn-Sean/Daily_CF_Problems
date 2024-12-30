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

inline string sred() {
    string x;
    cin >> x;
    return x;
}

void solve() {
    int n = red();
    vector<string> a(n);
    generate(all(a), sred);
    rep(j, 0, a[0].size()) {
        if (a[0][j] == '?') {
            a[0][j] = !j ? '1' : '0';
        }
    }
    rep(i, 1, n) {
        int x = a[i - 1].size(), y = a[i].size();
        if (x > y) {
            cout << "NO\n";
            return ;
        } else if (y > x) {
            rep(j, 0, y) {
                if (a[i][j] == '?') {
                    a[i][j] = !j ? '1' : '0';
                }
            }
        } else {
            int dif = 0, id = x;
            rep(j, 0, id) {
                if (a[i][j] != '?' && a[i - 1][j] != a[i][j]) {
                    if (a[i - 1][j] < a[i][j]) {
                        dif = 1;
                    } else {
                        dif = -1;
                    }
                    id = j;
                    break;
                } 
            }
            if (dif > 0) {
                rep(j, 0, x) {
                    if (a[i][j] == '?') {
                        if (j < id) {
                            a[i][j] = a[i - 1][j];
                        } else {
                            a[i][j] = '0';
                        }
                    }
                }
            } else if (dif < 0) {
                per(j, x - 1, 0) {
                    if (a[i][j] == '?') {
                        if (j > id) {
                            a[i][j] = '0';
                        } else if (dif > 0) {
                            a[i][j] = a[i - 1][j];
                        } else if (a[i - 1][j] == '9') {
                            a[i][j] = '0';
                        } else {
                            a[i][j] = a[i - 1][j] + 1;
                            dif = 1;
                        }
                    }
                }
            } else {
                per(j, x - 1, 0) {
                    if (a[i][j] == '?') {
                        if (dif > 0) {
                            a[i][j] = a[i - 1][j];
                        } else if (a[i - 1][j] == '9') {
                            a[i][j] = '0';
                        } else {
                            a[i][j] = a[i - 1][j] + 1;
                            dif = 1;
                        }
                    }
                }
            }
            if (dif != 1) {
                cout << "NO\n";
                return ;
            }
        }
    }
    cout << "YES\n";
    for (auto word : a) {
        cout << word << '\n';
    }

    cout << '\n';
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
https://codeforces.com/contest/490/problem/E
*/