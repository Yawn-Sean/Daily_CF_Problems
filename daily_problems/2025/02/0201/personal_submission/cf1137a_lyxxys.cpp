#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using f64 = long double;
using u64 = unsigned long long;
const f64 eps = 1e-12;
const i64 inf_i64 = 4e18;
const int inf_int = 2e9;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}
template <class T> void print(vector <T> &A){
    int n = A.size();
    for (int i = 0; i < n; ++ i){
        if (i) cout << " ";
        cout << A[i];
    }
    cout << "\n";
}
int jgs(f64 x){
    return x < -eps ? -1 : x > eps;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> A(n,vector<int>(m)), ans(n,vector<int>(m));
    vector<vector<int>> R, C;

    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            cin >> A[i][j];
        }
        R.push_back(A[i]);
    }
    for (int i = 0; i < m; ++ i){
        vector <int> nows;
        for (int j = 0; j < n; ++ j){
            nows.push_back(A[j][i]);
        }
        C.push_back(nows);
    }
    for (auto &vec : R){
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
    }
    for (auto &vec : C){
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
    }

    auto find_L = [&](vector<int>&vec, int x)->int{
        return lower_bound(vec.begin(), vec.end(), x) - vec.begin();
    };

    auto find_R = [&](vector<int>&vec, int x)->int{
        return vec.size() - (lower_bound(vec.begin(), vec.end(), x) - vec.begin()) - 1;
    };

    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            int cur = 1;
            cur += max(find_L(R[i], A[i][j]), find_L(C[j], A[i][j]));
            cur += max(find_R(R[i], A[i][j]), find_R(C[j], A[i][j]));
            ans[i][j] = cur;
        }
    }

    for (auto &vec : ans){
        print(vec);
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
