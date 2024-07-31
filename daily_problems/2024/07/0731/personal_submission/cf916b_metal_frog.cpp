#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <numeric>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;

void solve() {
    ll n;
    int k;
    cin >> n >> k;
    vector<ll> bits;
    for (int i = 0; i < 63; i++) {
        if (n & (1LL << i)) {
            bits.push_back(i);
        }
    }
    if (sz(bits) > k) {
        cout << "No\n";
        return;
    }
    ll lim = 1LL << 60;
    ll l = -lim, r = lim;
    vector<ll> ans(k);
    while (l < r) {
        ll mid = l + (r - l) / 2LL;
        bool flag = true;
        priority_queue<ll> pq(all(bits));
        while (pq.top() > mid) {
            int x = pq.top(); pq.pop();
            pq.push(x - 1);
            pq.push(x - 1);
            if (pq.size() > k) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            l = mid + 1LL;
            continue;
        } else {
            r = mid;
        }
        int cnt = 0;
        while (!pq.empty()) {
            ans[cnt] = pq.top();
            pq.pop();
            cnt++;
        }
        while (cnt < k) {
            int val = ans[cnt - 1];
            ans[cnt - 1] = val - 1;
            ans[cnt] = val - 1;
            cnt++;
        }
    } 
    
    cout << "Yes\n";
    for (int i = 0; i < k; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}
