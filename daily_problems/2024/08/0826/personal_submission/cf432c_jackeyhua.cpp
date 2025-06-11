#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <unordered_map>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

vector<int> vis, prime;

void sieve(int n) {
    vis.resize(n + 1, 0);
    for (int i = 2; i <= n; ++i) {
        if (!vis[i]) {
            prime.push_back(i);
        }
        for (int j = 0; prime[j] <= n / i; ++j) {
            vis[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> vc(n);
    for (int i = 0; i < n; ++i) cin >> vc[i];
    vector<int> arr = vc;
    sort(arr.begin(), arr.end());
    unordered_map<int, int> mp;
    for (int i = 0; i < n; ++i) mp[vc[i]] = i;
    vector<pii> ans;
    // 从最后一位开始，每次把最大的归位
    for (int i = n - 1; i >= 0; --i) {
        if (vc[i] == arr[i]) continue;
        int start = mp[arr[i]], end = i;
        while (start < end) {
            auto p = lower_bound(prime.begin(), prime.end(), end - start + 2);
            p--;
            int gap = *p;
            ans.emplace_back(start, start + gap - 1);
            swap(mp[vc[start]], mp[vc[start + gap - 1]]);
            swap(vc[start], vc[start + gap - 1]);
            start += gap - 1;
        }
    }
    cout << ans.size() << endl;
    for (auto& p : ans) cout << p.first + 1 << " " << p.second + 1 << endl;
} 

int main() {
    sieve(100005);
    solve();
    return 0;
}
 
