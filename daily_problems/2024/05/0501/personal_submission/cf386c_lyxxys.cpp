using ll = long long;
const int N = 300050, INF = 2e9;
char str[N];
ll f[30];

void solve(){
    cin >> str+1;
    int n = strlen(str+1);
    map <char, int> buk, ori;
    int tot = 0;
    for (int i = 1; i <= n; ++ i){
        if (!ori[str[i]]) ++ tot;
        ++ ori[str[i]];
    }

    for (int k = 1, cnt; k <= tot; ++ k){
        buk.clear(), cnt = 0;
        for (int i = 1, j = 1; i <= n; ++ i){
            while (j <= n && (cnt < k || cnt == k && buk[str[j]])){
                if (++ buk[str[j]] == 1) ++ cnt;
                ++ j;
            }
            f[k] += j-i;
            if (-- buk[str[i]] == 0) -- cnt;
        }
    }
    for (int i = tot; i >= 1; -- i)
        f[i] -= f[i-1];
    cout << tot << "\n";
    for (int i = 1; i <= tot; ++ i)
        cout << f[i] << "\n";
}
