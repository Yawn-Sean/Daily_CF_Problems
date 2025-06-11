#include <bits/stdc++.h>

#pragma GCC optimize("O3")
using namespace std;


using i64 = long long;
using pii = pair<int, int>;
//using u32 = unsigned;
constexpr int inf = INT32_MAX >> 1;
//constexpr i64 inf = INT64_MAX >> 1;
using vi = vector<int>;
using vl = vector<i64>;
using vb = vector<bool>;
#define all(x) (x).begin(),(x).end()


int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int v = 0;
    for (int i = 1; i < n; ++i)
        v += s[i] == '.' && s[i - 1] == '.';
    while (m--) {
        int x;
        char c;
        cin >> x >> c;
        if ((s[x - 1] != '.' && c != '.') || (s[x - 1] == '.' && c == '.')) {
            cout << v << endl;
            continue;
        }
        v -= (x > 1 ? s[x - 1] == '.' && s[x - 2] == '.' : 0) + (x < n ? s[x] == '.' && s[x - 1] == '.' : 0);
        s[x - 1] = c;
        v += (x > 1 ? s[x - 1] == '.' && s[x - 2] == '.' : 0) + (x < n ? s[x] == '.' && s[x - 1] == '.' : 0);
        cout << v << endl;

    }
}






