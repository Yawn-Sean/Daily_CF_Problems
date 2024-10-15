#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-15;

void solve(){
    auto call = [&](double ang)->long double{
        return (ang * 180) / pi;
    };
    int n;
    cin >> n;
    long double res = 0;
    vector <long double> A;

    for (int i = 1; i <= n; ++ i){
        int x, y;
        cin >> x >> y;
        A.push_back(atan2l(y, x));
    }
    sort(A.begin(), A.end());
    for (int i = 1; i < n; ++ i){
        res = max(res, call(A[i]-A[i-1]));
    }

    cout << fixed << setprecision(10) << min(360-res, call(A[n-1]-A[0])) << "\n";
}
