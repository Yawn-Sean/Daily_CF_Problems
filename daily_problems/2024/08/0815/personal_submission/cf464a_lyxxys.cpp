#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 3e5+11, mod = 1e9+7, inf = 1e9;

void solve(){
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    s = " " + s;

    for (int i = n; i >= 1; -- i){
        bool jg = true;
        string t = s;
        for (int j = i, flg; j <= n; ++ j){
            flg = false;
            for (int k = (j==i?t[j]-'a'+1:0); k < p; ++ k){
                int x = j-1, y = j-2;
                if (x>0 && t[x]-'a'==k) continue;
                if (y>0 && t[y]-'a'==k) continue;
                t[j] = char('a'+k), flg = true;
                break;
            }
            if (flg == false){
                jg = false;
                break;
            }
        }
        if (jg){
            for (int i = 1; i <= n; ++ i) cout << t[i];
            cout << "\n";
            return;
        }
    }
    cout << "NO\n";
}

