#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    /*
        What should the final length be?
        */
    i64 t,w,b;
    cin >> t >> w >> b;
    
    // i64 lcm = w / __gcd(w, b) * b;
    i64 lcm_cnt = t / b * __gcd(w, b) / w;
    i64 ansX = (lcm_cnt * min(w, b) - 1);
    // cout << lcm_cnt << '\n';
    
    // [xlcm,t]
    i64 last = lcm_cnt * w / __gcd(w, b) * b;
    i64 last_r = min(t, last + min(w, b) - 1);
    i64 add = last_r - last + 1;
    
    // cout << add << '\n';
    ansX += add;
    i64 ansY = t;

    i64 g = gcd(ansX, ansY);
    cout << ansX / g << "/" << ansY / g << endl;
    return 0;
}
