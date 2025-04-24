
#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n,m,a,b;
    std::cin>>n>>m>>a>>b;
    a--;
    b--;
    std::vector<int> s(m);
    for(int i=0;i<m;i++){
        std::cin>>s[i];
    }
    sort(s.begin(),s.end());
    auto check=[&](int m1)->bool{
        int a1=a;
        int b1=b;
        int ans=0;
        int times;
        if(a1<b1){
            times=b1;
        }
        else{
            times=n-b1-1;
        }
        int zuigan=std::min(abs(b1-a1)-1,m1);
        if(zuigan<m1){
            
            return 0;
        }
        int l=1;
        
        for(int i=m1-1;i>=0;i--){
            if(l+s[i]<=times){
                ans++;
            }
            l++;
        }
        return ans==m1;
    };
    int l=0;
    int r=m;
   int ans=0;
   while(l<=r){
    int mid=(l+r)>>1;
    if(check(mid)){
        ans=mid;
        l=mid+1;
    }
    else{
        r=mid-1;
    }
   }
   std::cout<<ans<<endl;
}
signed main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int t;
    std::cin>>t;
    while(t--)
    solve();
    return 0;
}
