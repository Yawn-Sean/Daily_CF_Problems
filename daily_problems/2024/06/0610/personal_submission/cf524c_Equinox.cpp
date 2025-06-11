#include <bits/stdc++.h>

void solve() {
    int N, K, Q;
    std::cin >> N >> K;
    std::vector<std::set<int>> o(K + 1);
    for (int i = 0, a; i < N; i ++ ) {
        std::cin >> a;
        for (int j = 1; j <= K; j ++ )
            o[j].insert(a * j);

    }
    // for (int j = 1; j <= K; j ++ ){
    //     for (int x : o[j]) std::cout << x << " "; std::cout << '\n';
    // }
    std::cin >> Q;
    while (Q --) {
        int s, ans = K + 1;
        std::cin >> s;
        for (int i = 1; i <= K; i ++ ) {
            auto it = o[i].find(s);
            if (it != o[i].end() && *it == s) {
                ans = std::min(ans, i);
                break;
            }
            for (int x : o[i]) { 
                if (x > s) break;
                for (int j = 1; j <= K - i; j ++) {
                    it = o[j].find(s - x);
                    if (it != o[j].end() && *it + x == s) {
                        ans = std::min(ans, i + j);
                        break;
                    }
                }
            }
        }
        std::cout << (ans == K + 1 ? -1 : ans) << '\n';
    }
}

int main(int argc, char** argv) {
    int _ = 1;
    while (_ --)
        solve();
    return 0;
}