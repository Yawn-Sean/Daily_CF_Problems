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
    int n;
    cin >> n;
    vector <int> vis(2*n+1), A(n), B;
    for (auto &x : A){
        cin >> x;
        vis[x] = 1;
    }
    for (int i = 1; i <= 2*n; ++ i){
        if (!vis[i]){
            B.push_back(i);
        }
    }
    auto chk1 = [&](int mid)->bool{
        for (int i = 0, j = n-mid; i < mid; ++ i, ++ j){
            if (A[i] > B[j]){
                return false;
            }
        }
        return true;
    };
    auto chk2 = [&](int mid)->bool{
        for (int i = n-mid, j = 0; i < n; ++ i, ++ j){
            if (A[i] < B[j]){
                return false;
            }
        }
        return true;
    };
    
    int lo, hi, l, r;
    lo = 0, hi = n;
    while (lo < hi){
        int mid = (lo+hi+1) >> 1;
        if (chk1(mid)) lo = mid;
        else hi = mid-1;
    }
    r = lo;

    lo = 0, hi = n;
    while (lo < hi){
        int mid = (lo+hi) >> 1;
        if (chk2(n-mid)) hi = mid;
        else lo = mid+1;
    }
    l = lo;

    cout << r-l+1 << "\n";
}
