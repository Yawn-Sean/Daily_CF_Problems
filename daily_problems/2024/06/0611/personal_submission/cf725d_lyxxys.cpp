using ll = long long;
struct cmp {
    bool operator ()(array<ll,2> a, array<ll,2> b){
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    }
};

void solve(){
    int n;
    cin >> n;
    ll t, w;
    cin >> t >> w;
    -- n;

    priority_queue<ll, vector<ll>, greater<ll>> pq1;
    priority_queue<array<ll,2>, vector<array<ll,2>>, cmp> pq2;
    while (n--){
        ll x, y;
        cin >> x >> y;
        if (x > t) pq1.push(y-x+1);
        if (x <= t) pq2.push({x, y-x+1});
    }

    int res = pq1.size();
    while (pq1.size() && t >= pq1.top()){
        t -= pq1.top();
        pq1.pop();
        while (pq2.size() && pq2.top()[0] > t){
            pq1.push(pq2.top()[1]);
            pq2.pop();
        }
        res = min(res, (int)pq1.size());
    }

    cout << res+1 << "\n";
}
 
