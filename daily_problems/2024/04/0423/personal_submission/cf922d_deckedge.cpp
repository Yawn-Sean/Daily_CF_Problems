#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pi pair<int, int>
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 7;

struct Node {
    int64_t cs, ch, tot;
}st[N];

inline int red() {
    int x;
    cin >> x;
    return x;
}

void init(int n) {
    int i;
    string s;
    for (i = 0; i < n; i++) {
        cin >> s;
        int a = 0, b = 0, cur = 0;
        for (char c : s) {
            if (c == 's') {
                a++;
            } else {
                cur += a;
                b++;
            }
        }
        st[i].cs = a;
        st[i].ch = b;
        st[i].tot = cur;
    }
    sort(st, st + n, [&](const Node& a, const Node& b) {
        return a.cs * b.ch > a.ch * b.cs;
    });
}

int64_t get_val(int n) {
    int64_t a = 0, res = 0;
    int i;
    for (i = 0; i < n; ++i) {
        res += st[i].tot;
        res += a * st[i].ch;
        a += st[i].cs;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = red(); 
    init(n);
    cout << get_val(n) << '\n';

    return 0;
}

