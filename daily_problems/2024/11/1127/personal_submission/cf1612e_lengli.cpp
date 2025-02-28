/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

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
    int n;
    std::cin>>n;
    std::vector<std::array<int,2>> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i][0]>>a[i][1];

    Frac<int> res=Frac(0,1);
    std::vector<int> ans;

    for(int t=1;t<=20;t++){
        std::vector<int> cnt(200010);
        for(int i=1;i<=n;i++){
            cnt[a[i][0]]+=std::min(t,a[i][1]);
        }
        std::vector<std::array<int,2>> q;
        for(int i=0;i<200010;i++){
            q.pb({cnt[i],i});
        }
        sort(all(q),std::greater<>());
        Frac<int> tmp=Frac(0,t);
        std::vector<int> p;
        for(int i=0;i<t;i++){
            tmp.num+=q[i][0];
            p.pb(q[i][1]);
        }
        if(tmp>res) res=tmp,ans=p;
    }
    std::cout<<ans.size()<<"\n";
    for(auto x:ans) std::cout<<x<<" ";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
