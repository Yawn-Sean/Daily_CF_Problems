#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128;
using PII = std::pair<int, int>;
const int inf = 1e8 + 7;


void solve() {
    int N;
    std::string A, B;
    std::cin >> A >> B >> N;
    if (A.size() != B.size()) {
        std::cout << -1;
        return;
    }
    std::vector<char> letters(26);
    std::vector<std::vector<int>> adj(26, std::vector<int>(26, inf));
    std::iota(letters.begin(), letters.end(), 'a');
    for (int i = 0, c; i < N; i ++ ) {
        char a, b;
        std::cin >> a >> b >> c;
        adj[a - 'a'][b - 'a'] = std::min(adj[a - 'a'][b - 'a'], c);
    }
    for (int i = 0; i < 26; i ++ ) adj[i][i] = 0;
    for (int k = 0; k < 26; k ++ )
        for (int i = 0; i < 26; i ++ )
            for (int j = 0; j < 26; j ++ )
                adj[i][j] = std::min(adj[i][j], adj[i][k] + adj[k][j]);
    i64 res = 0;
    for (int i = 0, n = A.size(); i < n; i ++ ) {
        int mi = inf;
        char conn;
        for (char x : letters) {
            if (adj[A[i] - 'a'][x - 'a'] + adj[B[i] - 'a'][x - 'a'] < mi)
                mi = adj[A[i] - 'a'][x - 'a'] + adj[B[i] - 'a'][x - 'a'], conn = x;
        }
        if (mi >= inf) {
            std::cout << -1;
            return;
        }
        A[i] = B[i] = conn;
        res += mi;
    }
    std::cout << res << '\n' << A;
}


int main(int argc, char** argv) {
    std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    int _ = 1;
    // std::cin >> _;
    while (_ --)
        solve();
    return 0;
}