#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n, a, b;
    cin >> n >> a >> b;

    map <long long, long long> mps;
    map <array<long long,2>, long long> cnt;
    long long res = 0;
    for (int i = 0; i < n; ++ i){
        long long x, vx, vy;
        cin >> x >> vx >> vy;
        long long y = a*vx - vy;
        res += mps[y], res -= cnt[{vx, vy}];
        mps[y] += 1, cnt[{vx, vy}] += 1;;
    }

    cout << res*2 << "\n";
}
 
 
