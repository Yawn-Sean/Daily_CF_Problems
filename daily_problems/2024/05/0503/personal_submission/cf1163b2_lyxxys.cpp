using namespace std;
const int N = 100050, p = 998244353, INF = 2e9;
vector <int> a(N), cnt(N);
int f[N], n; //f[i]表示出现次数为i的有多少组

void solve(){
    cin >> n;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    int res = 1, freq = 0;
    for (int i = 1; i <= n; ++ i){
        if (cnt[a[i]]) -- f[cnt[a[i]]];
        ++ cnt[a[i]], ++ f[cnt[a[i]]];
        freq = max(freq, cnt[a[i]]);

        if (freq == 1) res = i;  //最大频数为1，满足条件
        if (freq*f[freq] == i-1) res = i;
        if ((freq-1) * f[freq-1] == i - f[freq]*freq && f[freq] == 1) res = i;
    }
        
    cout << res << "\n";
} 
