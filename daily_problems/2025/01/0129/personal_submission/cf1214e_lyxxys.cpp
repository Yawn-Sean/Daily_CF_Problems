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
    vector <array<int,2>> ans;
    auto push = [&](int x, int y)->void{
        ans.push_back({x, y});
    };

    int n;
    cin >> n;
    vector <int> D(n), dep(2*n+1), idx(n);
    for (auto &x : D){
        cin >> x;
    }
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](auto &u, auto &v){
        return D[u] > D[v];
    });
    for (int i = 0; i < n; ++ i){
        dep[i] = 2*idx[i] + 1;
        if (i) push(dep[i-1], dep[i]);
    }
   
    int end_point = dep[n-1]; 
    for (int i = 0; i < n; ++ i){
        int id = idx[i], nxt_id = 2*(idx[i]+1);
        int d = D[id];
        int blow = i+d-1;

        if (dep[blow] == end_point){
            dep[blow+1] = nxt_id;
            end_point = nxt_id;
            push(dep[blow], dep[blow+1]);
        } else {
            push(nxt_id, dep[blow]);
        }
    }


    for (auto &it : ans){
        cout << it[0] << " " << it[1] << "\n";
    }
}
