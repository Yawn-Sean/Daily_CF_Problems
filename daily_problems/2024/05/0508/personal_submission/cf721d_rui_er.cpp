const ll N = 2e5 + 5;

ll n, k, x, a[N];
struct Index {
    ll x;
    Index(ll x) : x(x) {}
    friend bool operator<(Index p, Index q) {return abs(a[p.x]) > abs(a[q.x]);}
};
priority_queue<Index> heap;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k >> x;
    rep(i, 1, n) cin >> a[i];
    ll cnt = 0;
    rep(i, 1, n) cnt += a[i] < 0;
    rep(i, 1, n) heap.push(i);
    while(k--) {
        ll u = heap.top().x; heap.pop();
        if(a[u] < 0) {
            if(!(cnt & 1)) {
                a[u] += x;
                if(a[u] >= 0) --cnt;
            }
            else a[u] -= x;
        }
        else {
            if(!(cnt & 1)) {
                a[u] -= x;
                if(a[u] < 0) ++cnt;
            }
            else a[u] += x;
        }
        heap.push(u);
    }
    rep(i, 1, n) cout << a[i] << " \n"[i == n];
    return 0;
}
