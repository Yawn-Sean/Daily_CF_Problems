#include<bits/stdc++.h>
using namespace std;
const int N =1e5+10,md=998244353;
using LL=long long;
#define int long long
int c[N];
int p[N];

void solve(){
    int n;cin>>n;
    std::vector<int>a(n+1);
    p[0]=1;
    for(int i=1;i<=20;i++)p[i]=p[i-1]*10LL%md;
    
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int t=to_string(a[i]).size();
        c[t]++;
    }   
    
    LL ans=0; 
    for(int i=1;i<=n;i++){
        string s=to_string(a[i]);
        reverse(s.begin(),s.end());
        int t=s.size();
        for(int j=1;j<=16;j++){
            if(c[j]){
                if(j<=t){
                    
                    int mi=0;
                    LL res=0;
                    for(int k=0;k<j;k++){
                        //cout<<s[k]<<" ";
                        res+=(s[k]-'0')*1LL*p[k*2]%md;
                        mi=k*2;
                        res%=md;
                    }
                    mi++;
                    for(int k=j;k<t;k++){
                        //cout<<s[k]<<" o\n";
                        res+=(s[k]-'0')*1LL*p[++mi]%md;
                        res%=md;
                    }
                    res*=c[j];res%=md;
                    ans+=res;ans%=md;

                    res=0;
                    mi=1;
                    for(int k=0;k<j;k++){
                        //cout<<s[k]<<" ";
                        res+=(s[k]-'0')*1LL*p[mi]%md;
                        mi=mi+2;
                        res%=md;
                    }
                    //cout<<i<<" "<<res<<" ok\n";
                    mi--;
                    for(int k=j;k<t;k++){
                        //cout<<s[k]<<" o\n";
                        res+=(s[k]-'0')*1LL*p[mi++]%md;
                        res%=md;
                    }
                    res*=c[j];res%=md;
                    ans+=res;ans%=md;
                    // cout<<"\n";
                    // cout<<i<<" "<<res<<" "<<ans<<"\n";
                }
                else{
                    LL res=0;
                    for(int k=0;k<t;k++){
                        res+=(s[k]-'0')*1LL*p[k*2]%md;
                        res%=md;
                    }
                    res*=c[j];res%=md;
                    ans+=res;ans%=md;
                    //cout<<i<<" "<<j<<" "<<res<<"\n";

                    res=0;
                    int mi=1;
                    for(int k=0;k<t;k++){
                        res+=(s[k]-'0')*1LL*p[mi]%md;mi+=2;
                        res%=md;
                    }
                    res*=c[j];res%=md;
                    ans+=res;ans%=md;
                    //cout<<i<<" "<<j<<" "<<res<<"\n";
                }
            }
           
        }  
        //cout<<i<<" "<<ans<<"\n";
    }
    cout<<ans<<"\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
