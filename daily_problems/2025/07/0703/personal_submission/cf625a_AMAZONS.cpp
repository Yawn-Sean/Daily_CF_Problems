#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod= 998244353;
#define int long long
signed main(){
    int n;cin>>n;
    int a,b,c;cin>>a>>b>>c;
    int fake=b-c;
    int ans=0;
    if(a<=fake){
        ans=n/a;
        cout<<ans<<endl;
        return 0;
    }
    else{
        int cnt=0;
        int x=b; 

        if(x<=n){
            cnt=(n-x)/fake+1;
            int left=n-cnt*fake;
            ans=cnt+(left)/a;
            cout<<ans<<endl;
            return 0;
            // cout<<left<<endl;
        }
        else{
            ans=n/a;
            cout<<ans<<endl;
            return 0;
        }   

    }
    
    return 0;
}
