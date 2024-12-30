#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1000005, inf = 0x3f3f3f3f, mod = 1e9+7;
//文本串长度为n，给你模式串的一个子序列 和 模式串在文本串出现的m个位置，求有多少个可能的文本串

int pows(int a, int b){
    int res = 1;
    while (b){
        if (b&1) res = 1ll*res*a%mod;
        a = 1ll*a*a%mod;
        b >>= 1;
    }
    return res;
}
bool vis[N];
void init(vector<int> &ne, string a){
    ne[0] = -1;
    int n = a.size()-1;
    for (int i = 1, j; i <= n; ++ i){
        j = ne[i-1];
        while (j != -1 && a[j+1] != a[i])
            j = ne[j];
        ne[i] = j+1;
    }
    for (int i = n; i != -1; i = ne[i])
        vis[i] = true;
}
void solve(){
    int n, m;
    cin >> n >> m;
    string p;
    cin >> p;
    int len = p.size();
    p = " " + p;

    vector <int> Pos(m+1);
    for (int i = 1; i <= m; ++ i)
        cin >> Pos[i];
    if (!m) return cout << pows(26, n) << "\n", void();

    vector <int> ne(n+1);
    init(ne, p);
    // 用kmp的next数组处理重叠的部分是否合法

    for (int i = 2; i <= m; ++ i){
        if (Pos[i-1]+len > Pos[i])
            if (!vis[Pos[i-1]+len-Pos[i]])
                return cout << 0 << "\n", void();
    }

    int cnt = Pos[1]-1;

    for (int i = 1; i < m; ++ i)
        if (Pos[i]+len < Pos[i+1])
            cnt += Pos[i+1]-Pos[i]-len;
    cnt += n-Pos[m]-len+1;
    cout << pows(26, cnt) << "\n";
}
