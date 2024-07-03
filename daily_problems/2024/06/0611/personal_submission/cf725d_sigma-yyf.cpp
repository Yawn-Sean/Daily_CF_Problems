#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<pair<ll,ll> > a(n);

    for (auto &[t, w] : a) {
    	cin >> t >> w;
    }

    priority_queue<ll, vector<ll>, greater<ll >> q1;
    priority_queue<pair<ll,ll> > q2;

    ll x = a[0].first, y = a[0].second;

    for (int i = 1; i < n; ++i) {
    	if (a[i].first > x) {
    		q1.push(a[i].second - a[i].first + 1);
    	} else {
    		q2.push(a[i]);
    	}
    }

    int ans = q1.size() + 1;

    while (q1.size()) {
    	auto p = q1.top();
    	if (x < p) break;
    	x -= p;
    	q1.pop();
    	while (q2.size() && q2.top().first > x) {
    		auto [t, w] = q2.top();
    		q2.pop();
    		q1.push(w - t + 1);
    	}
    	ans = min(ans, (int)q1.size() + 1);
    }
    cout << ans << '\n';

    return 0;
}
