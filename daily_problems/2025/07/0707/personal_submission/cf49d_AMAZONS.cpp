#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
#define int long long
void solve(){
	int n;cin>>n;
    string s;
    cin>>s;string s2=s;
    int ans1=1,f1=1,f2=0,ans2=1;
    if(s[0]=='1')ans2=0,ans1=1,s[0]='0';
    else ans1=0,ans2=1,s2[0]='1';
    //010101
    for(int i=1;i<n;i++){
        if(s[i]==s[i-1]){
            // if(s[i]!=f1+'0'){
                ans1++;
                s[i]=f1+'0';
                
            // }
        }
        f1^=1;
    }
    // cout<<s<<endl;
    //101010
    for(int i=1;i<n;i++){
        if(s2[i]==s2[i-1]){
            if(s2[i]!=f2+'0'){
                ans2++;
                s2[i]=f2+'0';
                
            }
        }
        f2^=1;
    }
    cout<<min(ans1,ans2)<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}
