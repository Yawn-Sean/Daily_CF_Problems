#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

void solve(){
    long long n;
    cin >> n;
    vector <long long> fib;
    fib.push_back(1), fib.push_back(2);
    while (fib.back() < n){
        auto it = &fib.back();
        fib.push_back(*it+*(it-1));
    }
    cout << fib.size()-1-(fib.back() > n) << "\n";
}
