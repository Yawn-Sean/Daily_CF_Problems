using namespace std;
const int N = 2000050;
int cnt[N], b[N], n;
 
void solve(){
    cin >> n;
    for (int i = 1; i <= n; ++ i) cnt[i] = 0;
    for (int i = 1; i <= n; ++ i){
        int x;
        cin >> x;
        ++ cnt[x];
    }
    
    int val = 2e9;
    int tot = 0;
    for (int i = 1; i <= n; ++ i)
        if (cnt[i]) b[++ tot] = cnt[i], val = min(val, cnt[i]);
 
    int res;
    for (int i = val+1; i >= 1; -- i){
        res = 0;
        bool brake = 0;
        for (int j = 1; j <= tot; ++ j){
            int t = (b[j]-1)/i + 1;
            res += t;
            if ((i-1)*t > b[j]){
                brake = 1;
                break;
            }
        }
        if (!brake) break;
    }
    cout << res << "\n";
}   

