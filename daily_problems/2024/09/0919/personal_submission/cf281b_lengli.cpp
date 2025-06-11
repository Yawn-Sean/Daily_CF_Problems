/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back


#define int long long

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

int inf=1e9;

void solve(){
    int x,y,n;
    std::cin>>x>>y>>n;
    Frac t=Frac(x,y);
    Frac res=Frac(inf,1ll);
    Frac out=Frac(inf,1ll);
    for(int i=1;i<=n;i++){
        int l=0,r=1e5;

        auto check=[&](int x){
            return t>=Frac(x,i);
        };

        while(l<r){
            int mid=(l+r+1)/2;
            if(check(mid)) l=mid;
            else r=mid-1;
        }
        for(int j=l;j<=l+1;j++){
            Frac p=Frac(j,i);
            Frac ans=Frac(1ll);
            if(p>t) ans=p-t;
            else ans=t-p;
            if(ans<res) res=ans,out=p;
            else if(ans==res){
                out=std::min(out,p);
            }
        }
    }
    std::cout<<out.num<<"/"<<out.den<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
