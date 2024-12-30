using namespace std;
const int N = 100050;
int h[N], Pre[N], Suf[N];
int n;

void solve(){
    cin >> n;
    for (int i = 1; i <= n; ++ i) cin >> h[i];
    for (int i = 1; i <= n; ++ i)
        Pre[i] = min(Pre[i-1]+1, h[i]);
    for (int i = n; i >= 1; -- i)
        Suf[i] = min(Suf[i+1]+1, h[i]);
    int res = 0;
    for (int i = 1; i <= n; ++ i)
        res = max(res, min(Pre[i], Suf[i]));
    cout << res << "\n";
}
