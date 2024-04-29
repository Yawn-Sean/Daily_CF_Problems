using Pii = pair<int, int>;
const int N = 3e5+11;
Pii dot[N], lc[N], rc[N];
int n;
 
void solve(){
    cin >> n;
    for (int i = 1; i <= n; ++ i)
        cin >> dot[i].first >> dot[i].second;

    lc[0].second = rc[n+1].second = 2e9;
    for (int i = 1; i <= n; ++ i){
        lc[i].first = max(lc[i-1].first, dot[i].first);
        lc[i].second = min(lc[i-1].second, dot[i].second);
    }
    for (int i = n; i >= 1; -- i){
        rc[i].first = max(rc[i+1].first, dot[i].first);
        rc[i].second = min(rc[i+1].second, dot[i].second);
    }
    int res = 0;
    for (int i = 1; i <= n; ++ i)
        res = max(res, min(rc[i+1].second, lc[i-1].second) - max(rc[i+1].first, lc[i-1].first));
    cout << res << "\n";
    return;
}
