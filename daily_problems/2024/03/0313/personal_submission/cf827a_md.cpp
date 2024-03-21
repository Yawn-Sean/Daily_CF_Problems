#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct DSU {
private:
    std::vector<int> f;
    std::vector<int> siz;
public:    
    explicit DSU(int n) noexcept : f(n), siz(n, 1) {
         std::iota(std::begin(f), std::end(f), 0); 
    }
    int leader (int x) noexcept {
        while (x != f[x]) {
            f[x] = f[f[x]];
            x = f[x];
        }
        return x;
    }
    bool merge(int x, int y) noexcept {
        x = leader(x);
        y = leader(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    bool same(int x, int y) noexcept { return leader(x) == leader(y); }
    int size(int x) noexcept { return siz[leader(x)]; }
};

constexpr int N = 2e6 + 6;

void solve() {
    int n;
    cin >> n;

    auto ret = string(N, 'a');
    DSU dsu(N);
    int ret_len = 0;
    while (n--) {
        string input;
        cin >> input;
        int len = size(input);

        int m;
        cin >> m;
        for (int i = 0; i < m; ++i) {
            int pos;
            cin >> pos;
            pos--;

            int end_pos = pos + len;
            ret_len = max(ret_len, end_pos);
            for (int next_pos = dsu.leader(pos); next_pos < end_pos; next_pos = dsu.leader(next_pos)) {
                ret[next_pos] = input[next_pos - pos];
                dsu.merge(next_pos + 1, next_pos);
            }
        }
    }

    ret.resize(ret_len);
    cout << ret << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}