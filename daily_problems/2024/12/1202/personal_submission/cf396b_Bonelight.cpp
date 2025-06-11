/*
    Bonelight =^x^=
    20241117: 单枪匹马，无畏粉身碎骨
    我尝试过无数次了，但我知道，机会只会出现在其中的一两次
 */
#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'
#define pii pair<int,int>
#define tiii tuple<int,int,int>  
#define INF 2e18
#define VC vector<int>
#define VCii vector<pii>
#define MAT vector<VC>
#define MATii vector<VCii>
#define For(_tag,x,y) for(int _tag = x; _tag <= y; _tag ++)
#define Rof(_tag,y,x) for(int _tag = y; _tag >= x; _tag --)
#define all(_tag) begin(_tag),end(_tag)
#define x first
#define y second

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

    string str(){return (to_string(p) + '/' + to_string(q));}
};

/*希望残酷的世界还能为我这样的蝼蚁留下一丝美好*/
void solve(){
    auto isPrime = [&](int x){
        int sqrtX = sqrt(x);
        if(x == 2) return true;
        for(int i = 2; i <= sqrtX; i ++){
            if(x % i == 0) return false;
        }
        return true;
    };

    int n; cin >> n;
    int l = n,r = n+1;
    while(!isPrime(l)) l --;
    while(!isPrime(r)) r ++;

    Rat ans(1,2);
    Rat sub(1,r);
    Rat add(r-n-1,l*r);
    // cout << sub.str() << ' ' << add.str() << ' ';
    ans = ans - sub - add;
    cout << ans.str() << endl;
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int T = 1; cin >> T;
    
    while(T --){
        solve();
    } 
}
