#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long double Pi = acos(-1.0);
template <class T> void fmax(T &a, T b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    const int limi = (1<<10);
    int n, m;
    cin >> n;
    vector <vector<int>> f(n+100, vector<int>(limi));
    vector <string> pre(n+100), sf(n+100);
    
    for (int i = 0; i < n; ++ i){  // O(n * 10*10)
        string s;
        cin >> s;
        int len = s.size();  // 表达前后缀长度为10的
        pre[i] = s.substr(0, min(len, 10));
        sf[i] = s.substr(max(0, len-10));
        for (int l = 0; l < len; ++ l){
            int msk = 0;
            for (int r = l; r < min(len,l+10); ++ r){
                msk = msk*2 + (s[r]-'0');
                f[i][msk] |= 1 << r-l;
            }
        }
    }

    auto merge = [&](int cur, int x, int y)->void{
        string s = sf[x] + pre[y];
        for (int i = 0; i < limi; ++ i){  
            f[cur][i] = f[x][i] | f[y][i];
        }
        int len = s.size();
        for (int l = 0; l < len; ++ l){
            int msk = 0;
            for (int r = l; r < min(len,l+10); ++ r){
                msk = msk*2 + (s[r]-'0');
                f[cur][msk] |= 1 << r-l;
            }
        }

        s = pre[x] + pre[y];
        pre[cur] = s.substr(0, min(len, 10));
        s = sf[x] + sf[y];
        sf[cur] = s.substr(max(0, len-10));
    };
    auto find = [&](int x)->int{
        int res = 0;
        for (int len = 1; len <= 10; ++ len){
            bool jg = 1;
            for (int i = 0; i < 1<<len; ++ i){
                if (!((f[x][i]>>len-1)&1)){
                    jg = 0;
                    break;
                }
            }
            if (jg) res = len;
        }
        return res;
    };

    cin >> m;
    for (int i = n; i < n+m; ++ i){
        int x, y;
        cin >> x >> y;
        x -= 1, y -= 1;
        merge(i, x, y);

        cout << find(i) << "\n";
    }
}
