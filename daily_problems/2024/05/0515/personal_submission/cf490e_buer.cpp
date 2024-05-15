#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=2*N,mod=1e9+7;
#define int long long
#define uLL unsigned long long
const long long inf=1e18;
typedef pair<int,int> PII;
typedef long long LL;
using node=tuple<int,int,int>;
int n,m,k;
int a[N];
string s[N],tmp[N];
int get(string&s,string&t){
    if(s.size()>t.size()) return true;
    if(s.size()<t.size()){
        for(int i=0;i<s.size();i++){
            if(s[i]=='?') s[i]='9';
        }
        return false;
    }
    int flag=0,pos=0;
    string p=s;
    for(int i=0;i<s.size();i++){
        if(flag&&s[i]=='?') s[i]='9';
        if(!flag&&s[i]=='?') s[i]=t[i];
        if(t[i]>s[i]) flag=1;
        if(!flag&&s[i]>t[i]){
            int check=0;
            for(int j=i;j>=0;j--){
                if(p[j]=='?'){
                    if(s[j]=='0') s[j]='9';
                    else{
                        s[j]--;
                        check=1;break;
                    }
                }
            }
            if(check) flag=1;
            else return true;
        }
    }
    int check=0;
    if(s==t){
        for(int j=s.size()-1;j>=0;j--){
            if(p[j]=='?'){
                if(s[j]=='0') s[j]='9';
                else{
                    s[j]--;check=1;
                    break;
                }
            }
        }
        if(s[0]=='0'||s>=t) return true;
        if(check) return 0;
        return true;
    }
    if(s[0]=='0') return true;
    return false;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i],tmp[i]=s[i];
    s[n + 1] = "1145141919810";
    for(int i=n;i>=1;i--)
    {
        if(get(s[i],s[i+1])){
            cout<<"NO\n";return ;
        }
    }
    cout<<"YES\n";
    for(int i=1;i<=n;i++)
    cout<<s[i]<<"\n";
    
}

signed main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int t=1;
    //init();
   // cin>>t;
    while(t--) solve();
    return 0;
}
