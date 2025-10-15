#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> sq, nsq;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        int rt = sqrt(x);
        if(rt * rt == x) sq.push_back(1 + !x);
        else nsq.push_back(min(x - rt * rt, (rt + 1) * (rt + 1) - x));
    }
    vector<int>& t = sq.size() <= nsq.size() ? nsq : sq;
    sort(t.begin(), t.end());
    ll ans = 0;
    int need = abs((int) nsq.size() - (int) sq.size()) / 2;
    for(int i = 0; i < need; ++i) {
        ans += t[i];
    }
    cout << ans << "\n";
}
