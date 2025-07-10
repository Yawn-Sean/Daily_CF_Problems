/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

template<class T>
struct Frac {
    T num,den;
    Frac(T num_, T den_) : num(num_), den(den_) {
        if (den < 0) {
            den = -den;
            num = -num;
        }
    }
    Frac() : Frac(0, 1) {}
    Frac(T num_) : Frac(num_, 1) {}
    explicit operator double() const {return 1. * num / den;}
    Frac &operator+=(const Frac &rhs) {
        num = num * rhs.den + rhs.num * den;
        den *= rhs.den;
        return *this;
    }
    Frac &operator-=(const Frac &rhs) {
        num = num * rhs.den - rhs.num * den;
        den *= rhs.den;
        return *this;
    }
    Frac &operator*=(const Frac &rhs) {
        num *= rhs.num;
        den *= rhs.den;
        return *this;
    }
    Frac &operator/=(const Frac &rhs) {
        num *= rhs.den;
        den *= rhs.num;
        if (den < 0) {
            num = -num;
            den = -den;
        }
        return *this;
    }
    friend Frac operator+(Frac lhs, const Frac &rhs) {return lhs += rhs;}
    friend Frac operator-(Frac lhs, const Frac &rhs) {return lhs -= rhs;}
    friend Frac operator*(Frac lhs, const Frac &rhs) {return lhs *= rhs;}
    friend Frac operator/(Frac lhs, const Frac &rhs) {return lhs /= rhs;}
    friend Frac operator-(const Frac &a) {return Frac(-a.num, a.den);}
    friend bool operator==(const Frac &lhs, const Frac &rhs) {return lhs.num * rhs.den == rhs.num * lhs.den;}
    friend bool operator!=(const Frac &lhs, const Frac &rhs) {return lhs.num * rhs.den != rhs.num * lhs.den;}
    friend bool operator<(const Frac &lhs, const Frac &rhs) {return lhs.num * rhs.den < rhs.num * lhs.den;}
    friend bool operator>(const Frac &lhs, const Frac &rhs) {return lhs.num * rhs.den > rhs.num * lhs.den;}
    friend bool operator<=(const Frac &lhs, const Frac &rhs) {return lhs.num * rhs.den <= rhs.num * lhs.den;}
    friend bool operator>=(const Frac &lhs, const Frac &rhs) {return lhs.num * rhs.den >= rhs.num * lhs.den;}
    friend std::ostream &operator<<(std::ostream &os, Frac x) {
        T g = std::gcd(x.num, x.den);
        if (x.den == g) {
            return os << x.num / g;
        } else {
            return os << x.num / g << "/" << x.den / g;
        }
    }
};

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<std::array<int,2>> pt(m);
    for(auto &[x,y]:pt){
        std::cin>>x>>y;
    }
    std::vector<int> mx(n+2,1);
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(i==j) continue;
            i64 dx=pt[j][0]-pt[i][0],dy=pt[j][1]-pt[i][1];
            if(dy==0) continue;
            Frac<i64> t={dy,dx};
            if((pt[i][1]*dx)%dy) continue;
            i64 idx=pt[i][0]-(pt[i][1]*dx)/dy;
            if(idx<1 or idx>n) continue;
            int cnt=2;
            for(int k=0;k<m;k++){
                if(i==k or j==k) continue;
                i64 ddx=pt[k][0]-pt[i][0],ddy=pt[k][1]-pt[i][1];
                Frac<i64> tt={ddy,ddx};
                if(t==tt) cnt++;
            }
            mx[idx]=std::max(mx[idx],cnt);
        }
    }
    int res=0;
    for(int i=1;i<=n;i++){
        res+=mx[i];
    }
    std::cout<<res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
