#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q, m;
    cin >> n >> q >> m;
    vector<int> a(n);
    copy_n(istream_iterator<int>(cin), n, begin(a));

    vector<tuple<int, int, int>> queries;
    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        queries.emplace_back(t, l, r);
    }

    vector<int> b(m);
    copy_n(istream_iterator<int>(cin), m, begin(b));

    for (int i = size(queries) - 1; i >= 0; --i) {
        auto[t, l, r] = queries[i];
        for (auto& pos : b) {
            if (t == 1) {
                if (pos >= l && pos <= r) {
                    if (pos == l) {
                        pos = r;
                    } else {
                        pos--;
                    }
                }
            } else {
                if (pos >= l && pos <= r) {
                    pos = l + r - pos;
                }
            }
        }
    }
    
    for (auto x : b) {
        cout << a[x - 1] << " ";
    }
    cout << endl;

    return 0;
}