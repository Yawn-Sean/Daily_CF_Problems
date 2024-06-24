#include <bits/stdc++.h>
using PII = std::pair<int, int>;
using i64 = long long;
 
const int inf = 1e9;
 
 
void solve() {
    int N, K, res = 0;
    std::cin >> N >> K;
    std::vector<int> a(N);
    std::map<int, std::vector<int>> pos;
    std::unordered_set<int> buf;
    std::priority_queue<PII> pq;
 
    for (int i = 0; i < N; i ++ ) std::cin >> a[i];
    for (int i = N - 1; ~i; i -- ) pos[a[i]].push_back(i);
    
    for (int i = 0; i < N; i ++ ) {
        pos[a[i]].pop_back();
        if (buf.count(a[i])) {
            if (pos[a[i]].size()) pq.emplace(pos[a[i]].back(), a[i]);
            else buf.erase(a[i]);
            continue;
        }
        while (pq.size() && !pos[pq.top().second].size()) pq.pop();
        if (buf.size() == K) buf.erase(pq.top().second), pq.pop();
        if (pos[a[i]].size()) buf.insert(a[i]), pq.emplace(pos[a[i]].back(), a[i]);
        res ++;
    }
    std::cout << res;
}
 
 
int main () {
    std::ios::sync_with_stdio(false);   std::cin.tie(0);  std::cout.tie(0);
    int _ = 1;
    // std::cin >> _;
    while (_ --)
        solve();
    return 0;
}