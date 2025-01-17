#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using f64 = long double;
const f64 eps = 1e-12;
const i64 inf_i64 = 4e18;
const int inf_int = 1e9;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}
int jgs(f64 x){
    return x < -eps ? -1 : x > eps;
}
void print(vector <int> &A){
    int n = A.size();
    for (int i = 0; i < n; ++ i){
        if (i) cout << " ";
        cout << A[i];
    }
}

void solve(){
    auto error = [&]()->void{
        cout << "NO\n";
    };

    int n, m;
    cin >> m >> n;
    vector <int> cnts(m);
    vector <vector<int>> gs(n);

    for (int i = 0, k; i < n; ++ i){
        cin >> k;
        for (int j = 0, x; j < k; ++ j){
            cin >> x;
            x -= 1;
            gs[i].push_back(x);
        }
    }

    int chose = -1;
    vector <int> ans;

    for (int i = 0; i < n; ++ i){
        ans.push_back(gs[i][0]);
        cnts[gs[i][0]] += 1;
        if (chose == -1 || cnts[gs[i][0]] > cnts[chose]) chose = gs[i][0];
    }

    assert(chose != -1);

    int limi = (n+1) / 2;
    if (cnts[chose] > limi){
        for (int i = 0; i < n; ++ i){
            if (ans[i] != chose) continue;

            for (auto &x : gs[i]){
                if (x != chose){
                    ans[i] = x;
                    cnts[chose] -= 1, cnts[x] += 1;
                    break;
                }
            }

            if (cnts[chose] <= limi) break;
        }
    }

    if (cnts[chose] > limi) return error();
    cout << "YES\n";
    for (int i = 0; i < n; ++ i){
        if (i) cout << " ";
        cout << ans[i]+1;
    }
    cout << "\n";
}
