#include <bits/stdc++.h>
using namespace std;

const int mx = 1e6+10;
vector<int> cnts(mx, 0);

bool check(int len, int cnt, int n) {
    int line = 1, cur = 0;
    for (int i = 0; i < cnt; ++i) {
        cur += cnts[i];
        if (i == cnt-1 && cur <= len && line <= n) {
            return true;
        }
        if (line > n) {
            return false;
        }
        if (cur == len) {
            line++;
            cur = 0;
        } else if (cur > len) {
            line++;
            --i;
            cur = 0;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin.ignore();
    getline(cin, s);

    int cnt = 0, pos = -1;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == ' ' || s[i] == '-' || i == s.length()-1) {
            cnts[cnt++] = i - pos;
            pos = i;
        }
    }
    //二分
    int l = 1, r = mx;
    while (l <= r) {
        int mid = l + (r-l)/2;
        if (check(mid, cnt, n)) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << l << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}