#include <bits/stdc++.h>
using namespace std;
void fmax(int &x, int y){
    if (y > x) x = y;
}
void fmin(int &x, int y){
    if (y < x) x = y;
}
struct Rat {
    __int128 p, q;
    void normal(){
        __int128 d = __gcd(p, q);
        p /= d, q /= d;
    }
    Rat(__int128 p = 0, __int128 q = 1): p(p), q(q) {
        normal();
    }
    Rat operator + (Rat oth){
        __int128 d = __gcd(q, oth.q);
        __int128 a = q/d, b = oth.q/d;
        return Rat(p*b + oth.p*a, q/d * oth.q);
    }
    bool operator == (Rat oth){
        return p == oth.p && q == oth.q;
    }
    void reverse(){
        swap(p, q);
    }
};

void solve(){
    long long p, q;
    cin >> p >> q;

    int n;
    cin >> n;
    vector <long long> nums(n);
    for (auto &x : nums) cin >> x;

    auto recur = [&](auto &&self, int cur)->Rat{
        if (cur == n) return Rat{0,1};
        Rat res = Rat(nums[cur],1) + self(self, cur+1);
        res.reverse();
        return res;
    };
    Rat res1 = Rat(p, q);
    Rat res2 = Rat(nums[0], 1) + recur(recur, 1);

    if (res1 == res2){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
