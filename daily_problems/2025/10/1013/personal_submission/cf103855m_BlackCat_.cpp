#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
using i128 = __int128;
std::mt19937_64 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
void solve() {
    int n;
    std::cin>>n;
    std::vector<std::pair<i64,i64>>  a(n);
    std::vector<std::pair<ld64,ld64>>  b(n);
    for(int i=0;i<n;i++){
        std::cin>>a[i].first;
    }
    for(int i=0;i<n;i++){
        std::cin>>a[i].second;
        b[i].first=(a[i].first+a[i].second);
        b[i].second=a[i].first-a[i].second;
        b[i].first/=2;
        b[i].second/=2;
    }
    ld64 res1=0;
    std::sort(b.begin(),b.end());
    ld64 sum=0;
    for(int i=0;i<n;i++){
        res1+=b[i].first*i-sum;
        sum+=b[i].first;
    }
    sum=0;
    std::sort(b.begin(),b.end(),[&](auto &a1,auto &a2){
        return a1.second<a2.second;
    });
    for(int i=0;i<n;i++){
        res1+=b[i].second*i-sum;
        sum+=b[i].second;
    }
    res1*=2;
    i64 ans=-res1;
    std::sort(a.begin(),a.end());
    sum=0;
    i64 res=0;
    for(int i=0;i<n;i++){
        res+=a[i].first*i-sum;
        sum+=a[i].first;
    }
    sum=0;
    std::sort(a.begin(),a.end(),[&](auto &a1,auto &a2){
        return a1.second<a2.second;
    });
    for(int i=0;i<n;i++){
        res+=a[i].second*i-sum;
        sum+=a[i].second;
    }
    res*=2;
    std::cout<<res+ans<<endl;
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int t = 1;
	while (t--) {
		solve();
	}
	return 0;
}
