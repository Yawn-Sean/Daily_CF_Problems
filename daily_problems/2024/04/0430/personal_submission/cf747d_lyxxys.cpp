using Pii = pair<int,int>;
const int N = 200050;
int a[N], n, k;
int d[N];

void error(){
    cout << -1 << "\n";
}
void solve(){
    cin >> n >> k;
    for (int i = 1; i <= n; ++ i)
        cin >> a[i], d[i] = -1;
    int cnt = 0;
    int p = -1;
    for (int i = n, last = n+1, symbol = 0; i >= 1; -- i){
        if (a[i] < 0){
            if (!symbol) symbol = 1, p = i;
            d[i] = last-i-1, last = i;
            -- k, cnt += 2;
        }
        if (k < 0) return error(), void();
    }
    priority_queue <int, vector<int>, greater<int>> heap;
    for (int i = 1; i <= n; ++ i)
        if (~d[i] && i != p) heap.push(d[i]);

    while (k >= 0 && heap.size()){
        auto top = heap.top();
        heap.pop();
        int dis = top;
        if (k - dis >= 0) k -= dis, cnt -= 2;
        else break;
    }
    if (~p) cnt = cnt - (k-d[p] >= 0 ? 1 : 0);
    cout << cnt << "\n";
}
