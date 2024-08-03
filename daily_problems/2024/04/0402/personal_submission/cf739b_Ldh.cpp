#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vpii vector<pii>
#define fori(n) for (int i = 0; i < (n); ++i)
#define forj(n) for (int j = 0; j < (n); ++j)
#define fork(n) for (int k = 0; k < (n); ++k)

const int MAXN = 2e5+5;
int fa[MAXN][18], dep2[MAXN];
ll dep[MAXN], res[MAXN];
vector<pair<int, int>> adj[MAXN];

namespace FastIO {
    const size_t bufferSize = 4096;
    char buffer[bufferSize];
    char *p = buffer + bufferSize;

    inline char readChar() {
        if (p == buffer + bufferSize) {
            fread(buffer, 1, bufferSize, stdin);
            p = buffer;
        }
        return *p++;
    }

    inline int readInt() {
        char c = readChar();
        while (c <= 32) c = readChar();
        int x = 0;
        while (c > 32) {
            x = x * 10 + c - '0';
            c = readChar();
        }
        return x;
    }
}

void solve() {
    int n = FastIO::readInt();
    
    ll A[n];
    fori(n) A[i] = FastIO::readInt();
    
    fori(n-1) {
        int p = FastIO::readInt(), c = FastIO::readInt();
        adj[p].push_back({i+2, c});
        fa[i+2][0] = p;
    }

    for (int j = 1; j < 18; ++j) {
        for (int i = 1; i <= n; ++i) {
            fa[i][j] = fa[fa[i][j-1]][j-1];
        }
    }

    auto find = [&](int node, int step) {
        int cur = node;
        for (int i = 0; i < 18; ++i) {
            if (step & (1 << i)) {
                cur = fa[cur][i];
            }
        }
        return cur;
    };

    dep[0] = (ll)-4e14;
    dep2[1] = 1;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (auto &[o, c] : adj[cur]) {
            dep[o] = dep[cur] + c;
            dep2[o] = dep2[cur] + 1;
            q.push(o);
        }
    }


    memset(res, 0, sizeof(res));
    for (int i = 1; i <= n; ++i) {
        int l = 0, r = dep2[i];
        while (l < r) {
            int mid = (l + r) >> 1;
            int o = find(i, mid);
            if (dep[o] >= dep[i] - A[i - 1]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        res[fa[i][0]]++;
        res[find(i, l)]--;
    }

    vector<int> idxs(n);
    iota(idxs.begin(), idxs.end(), 1);
    sort(idxs.begin(), idxs.end(), [&](int x, int y) { return dep[x] > dep[y]; });

    for (int idx : idxs) {
        res[fa[idx][0]] += res[idx];
    }

    for (int i = 1; i <= n; ++i) {
        if (i > 1) cout << " ";
        cout << res[i];
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Assuming there's only one test case as in the provided Python script
    solve();

    return 0;
}
