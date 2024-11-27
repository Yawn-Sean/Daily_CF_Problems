#include <bits/stdc++.h>
using namespace std;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    const int N = 2e5+10;
    int n;
    cin >> n;
    map <int, vector<int>> mps;
    for (int i = 0,x,y; i < n; ++ i){
        cin >> x >> y;
        mps[x].push_back(y);
    }

    vector <int> ans, w(N);
    long double j1 = 0, j2 = 1;
    for (int L = 1, len=mps.size(); L <= min(20, len); ++ L){
        vector <int> idx;
        for (auto &it : mps){
            int x = it.first;
            w[x] = 0, idx.push_back(x);
            for (auto &y : it.second){
                w[x] += min(L, y);
            }
        }
        sort(idx.begin(), idx.end(), [&](int &u, int &v){
            return w[u] > w[v];
        });
        vector <int> curs(idx.begin(), idx.begin()+L);
        long double sons = 0;
        for (auto &y : curs){
            sons += w[y];
        }
        if (sons*j2 > L*j1){
            j1 = sons, j2 = L;
            ans = curs;
        }
    }

    cout << ans.size() << "\n";
    for (int i = 0, len=ans.size(); i < len; ++ i){
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
}
