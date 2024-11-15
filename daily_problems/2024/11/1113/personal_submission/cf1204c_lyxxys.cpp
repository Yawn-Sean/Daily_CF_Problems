#include <bits/stdc++.h>
using namespace std;
const long double Pi = acos(-1.0);
template <class T> void fmax(T &a, T b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    int n;
    cin >> n;
    const int inf = 1e9;
    vector <vector<int>> dist(n+1, vector<int>(n+1, inf));

    for (int i = 1; i <= n; ++ i){
        string s;
        cin >> s;
        s = " " + s;
        for (int j = 1; j <= n; ++ j){
            if (i == j) dist[i][j] = 0;
            if (s[j] == '1'){
                dist[i][j] = 1;
            }
        }
    }
    int m;
    cin >> m;
    vector <int> seq(m);
    for (auto &x : seq) cin >> x;

    for (int k = 1; k <= n; ++ k){
        for (int i = 1; i <= n; ++ i){
            for (int j = 1; j <= n; ++ j){
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    vector <int> ans;
    int i = 0;
    while (i < m-1){
        ans.push_back(seq[i]);

        int j = i, dis = 0;
        while (j+1 < m && dist[seq[i]][seq[j+1]] == dis+1){
            j += 1;
            dis += 1;
        }

        i = j;
    }
    assert(i == m-1);
    ans.push_back(seq[i]);

    cout << ans.size() << "\n";
    int len = ans.size();
    for (int i = 0; i < len; ++ i){
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
}
