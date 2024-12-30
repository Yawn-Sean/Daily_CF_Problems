#include <bits/stdc++.h>
using namespace std;
struct Rat {
    long long p, q;
    void normal(){
        long long d = __gcd(p, q);
        p /= d, q /= d;
        if (q < 0) p = -p, q = -q;
    }
    Rat abs(){
        if (p < 0) p = -p;
        if (q < 0) q = -q;
        return *this;
    }
    Rat(long long p = 0, long long q = 1):p(p), q(q){
        normal();
    }
    Rat operator + (Rat A){
        long long d = __gcd(q, A.q);
        return Rat(A.q/d*p + q/d*A.p, q/d*A.q);
    }
    Rat operator - (Rat A){
        return *this + Rat(-A.p, A.q);
    }
    Rat operator * (Rat A){
        return Rat(p*A.p, q*A.q);
    }
    Rat operator / (Rat A){
        assert(A.p != 0);
        return *this * Rat(A.q, A.p);
    }
    bool operator < (Rat A){
        return p*A.q < A.p*q;
    }
    bool operator == (Rat A){
        this->normal(), A.normal();
        return p == A.p && q == A.q;
    }
};

void solve(){
    int x, y, n;
    cin >> x >> y >> n;
    Rat res(1000000000), num(x, y), cur;
    
    for (long long i = 1; i <= n; ++ i){
        int a = x*i/y;
        Rat ans;
        ans = (num-Rat(a,i)).abs();
        if (ans < res){
            res = ans;
            cur = Rat(a, i);
        }
        ans = (num-Rat(a+1,i)).abs();
        if (ans < res){
            res = ans;
            cur = Rat(a+1, i);
        }
    }

    cur.normal();
    cout << cur.p << "/" << cur.q << "\n";
}
 
