#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N = 2e5+10;
LL a[N];
LL pre[N];
int main() {
    LL n,s;
    cin>>n>>s;
    for(LL i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(LL i=1;i<=n;i++)
        pre[i]=pre[i-1]+a[i];
    
    auto check=[&](LL x){
        LL sum=x*(x+1)/2;
        LL id=upper_bound(a+1,a+n+1,x)-a;
        sum+=pre[n]-pre[id-1];
        return sum<s;
    };
    LL l=0,r=2000000010LL;
    while(l<r){
        LL mid=l+r+1>>1;
        if(check(mid)){
            l=mid;
        }else{
            r=mid-1;
        }
    }
    if(pre[n] >= s) {
        cout << n << endl;
        return 0;
    }
    LL id=upper_bound(a+1,a+n+1,l)-a;
    cout<<l+n-id+2;
    return 0;
}

