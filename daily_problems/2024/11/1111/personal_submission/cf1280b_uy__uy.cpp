#include<bits/stdc++.h>


using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve() {

    int r, c;
    cin >> r >> c;
    int cnt = 0;
    vector<string> a(r);
    vector<int> col(r), row(c);
    for (int i = 0; i < r; i++) {
        cin >> a[i];
        for (int j = 0; j < c; j++) {
            if (a[i][j] == 'A') {
                cnt++;
                row[j] += 1;
                col[i] += 1;
            }
        }
    }
    if (cnt == 0) {
        cout << "MORTAL" << "\n";
        return;
    } else if (cnt == c * r) {
        cout << 0 << "\n";
        return;
    }
    //最多操作4次
    if (col[0] == c || col[r - 1] == c || row[0] == r || row[c - 1] == r) {
        cout << 1 << "\n";
    } else if (a[0][0] == 'A' || a[0][c - 1] == 'A' || a[r - 1][0] == 'A' || a[r - 1][c - 1] == 'A' ||
               *max_element(col.begin(), col.end()) == c || *max_element(row.begin(), row.end()) == r) {
        cout << 2 << "\n";
    } else if (col[0] || col[r - 1] || row[0] || row[c - 1]) {
        cout << 3 << "\n";
    } else {
        cout << 4 << "\n";
    }
}

int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

//    freopen("input.in", "r", stdin);
//    freopen("output.out", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


