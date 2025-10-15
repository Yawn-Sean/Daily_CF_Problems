#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using f64 = long double;
const f64 eps = 1e-9;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}

void solve(){
    string s;
    cin >> s;
    vector <int> loc(26, -1), vis(27);
    int i1 = 0, i2 = 0;
    for (int i = 0; i < 27; ++ i){
        int j = s[i]-'A';
        if (loc[j] != -1){
            i1 = loc[j], i2 = i;
        }
        loc[j] = i;
    }

    vector<vector<char>> ans(2, vector<char>(26, '?'));
    int d = i2-i1;
    if (d%2){
        if (d == 1) return void(cout << "Impossible\n");
        int dis = d/2, j = i1;
        for (int i = 12-dis; i < 13; ++ i){
            ans[0][i] = s[j++];
        }
        for (int i = 12; i > 12-dis; -- i){
            ans[1][i] = s[j++];
        }
        assert(j == i2);
        j = i1-1;
        int x = 0, y = 12-dis-1;
        while (j >= 0){
            if (y == -1){
                x = 1, y = 0;
            }
            if (x == 0){
                ans[x][y] = s[j--];
                y -= 1;
            } else {
                ans[x][y] = s[j--];
                y += 1;
            }
        }
        j = 26;
        while (j > i2){
            if (y == -1){
                x = 1, y = 0;
            }
            if (x == 0){
                ans[x][y] = s[j--];
                y -= 1;
            } else {
                ans[x][y] = s[j--];
                y += 1;
            } 
        }
    } else {
        int dis = d/2-1, j = i1;
        for (int i = 12-dis; i < 13; ++ i){
            ans[0][i] = s[j++];
        }
        for (int i = 12; i >= 12-dis; -- i){
            ans[1][i] = s[j++];
        }
        assert(j == i2);
        j = i1-1;
        int x = 0, y = 12-dis-1;
        while (j >= 0){
            if (y == -1){
                x = 1, y = 0;
            }
            if (x == 0){
                ans[x][y] = s[j--];
                y -= 1;
            } else {
                ans[x][y] = s[j--];
                y += 1;
            }
        }
        j = 26;
        while (j > i2){
            if (y == -1){
                x = 1, y = 0;
            }
            if (x == 0){
                ans[x][y] = s[j--];
                y -= 1;
            } else {
                ans[x][y] = s[j--];
                y += 1;
            } 
        }
    }
    for (int i = 0; i < 2; ++ i){
        for (int j = 0; j < 13; ++ j){
            cout << ans[i][j];
        }
        cout << "\n";
    }
}

int main(){
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
#else
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    int _ = 1;
    while (_--) solve();
    return 0;
}
