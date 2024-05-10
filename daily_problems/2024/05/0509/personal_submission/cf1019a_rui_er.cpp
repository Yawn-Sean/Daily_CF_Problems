const ll N = 1e5 + 5;

ll n, m, a[N], b[N];
vector<ll> cost[N];

inline ll calc(ll mid) {
    ll ans = 0, now = 0;
    vector<ll> tmp;
    rep(i, 1, m) {
        int j = 0, k = cost[i].size();
        while(k >= mid) {
            ans += cost[i][j++];
            --k;
            ++now;
        }
        while(j < cost[i].size()) tmp.push_back(cost[i][j++]);
    }
    sort(tmp.begin(), tmp.end());
    for(int i : tmp) {
        if(now >= mid) break;
        ans += i;
        ++now;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    rep(i, 1, n) {
        cin >> a[i] >> b[i];
        if(a[i] == 1) b[i] = 0;
        cost[a[i]].push_back(b[i]);
    }
    rep(i, 1, m) sort(cost[i].begin(), cost[i].end());
    ll l = 1, r = n;
    while(l <= r) {
        ll mid = (l + r) >> 1;
        if(calc(mid) < calc(mid + 1)) r = mid - 1;
        else l = mid + 1;
    }
    cout << calc(l) << endl;
    return 0;
}
