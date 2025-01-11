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
    return (x < -eps ? -1 : x >= eps);
}
void print(vector <int> &A){
    int n = A.size();
    for (int i = 0; i < n; ++ i){
        if (i) cout << " ";
        cout << A[i];
    }
}

void solve(){
    int x, y, z, x1, y1, z1;
    vector <int> A(6);
    cin >> x >> y >> z;
    cin >> x1 >> y1 >> z1;
    for (auto &x : A){
        cin >> x;
    }

    int res = 0;
    if (y < 0) res += A[0];
    if (y > y1) res += A[1];
    if (z < 0) res += A[2];
    if (z > z1) res += A[3];
    if (x < 0) res += A[4];
    if (x > x1) res += A[5];

    cout << res << "\n";
}
