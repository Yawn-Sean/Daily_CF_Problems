#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using PLI = pair<ll, int>;
using PLL = pair<ll, ll>;
using PSI = pair<string, int>;
using PSS = pair<string, string>;
using PDD = pair<double, double>;
template <typename T> using max_heap = priority_queue<T>;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<>>;
#define endl '\n'

class FenWickTree {
public :
    int n;
    vector<int> c;

    FenWickTree (int t) : n(t), c(t + 1) {}

    int lowbit(int x) {
        return x & -x;
    }

    void add(int i, int x) {
        while (i <= n) c[i] += x, i += lowbit(i);
        return;
    }

    int query(int i) {
        int sum = 0;
        while (i) sum += c[i], i -= lowbit(i);
        return sum;
    }
};

const int N = 3e5 + 10;
char s[N];

void solve() { 
    int n, m; scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    s[0] = 'A', s[n + 1] = 'A';
    FenWickTree tr(n + 2);
    for (int i = 1; i <= n; i++) {
        if (s[i] == '.' && s[i - 1] == '.') tr.add(i, 1);
    }
    while (m--) {
        int i;
        string t;
        cin >> i >> t;
        char t1 = s[i], t2 = t[0];
        if (t1 == '.' && t2 == '.' || t1 != '.' && t2 != '.') printf("%d\n", tr.query(n));
        else if (t1 == '.' && t2 != '.') {
            if (s[i - 1] == '.') tr.add(i, -1);
            if (s[i + 1] == '.') tr.add(i + 1, -1);
            s[i] = t2;
            printf("%d\n", tr.query(n));
        } else if (t1 != '.' && t2 == '.') {
            if (s[i - 1] == '.') tr.add(i, 1);
            if (s[i + 1] == '.') tr.add(i + 1, 1); 
            s[i] = t2;
            printf("%d\n", tr.query(n));
        }
    }
    return ;
}

int main() {
    int t; t = 1;
    while (t--) solve();
    return 0;
}
