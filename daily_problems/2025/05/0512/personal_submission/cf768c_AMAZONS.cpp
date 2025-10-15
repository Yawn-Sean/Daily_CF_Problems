#include<bits/stdc++.h>
using namespace std;
const int N =2100;
const int mod=1e9+7;
typedef long long ll;
void solve(){
	int n,k,x;cin>>n>>k>>x;int v[N]={0},p;
    for(int i=1;i<=n;i++)cin>>p,v[p]++;
    int tmp[N]={0};
    while(k--)
    {
        int judge=1;memset(tmp, 0, sizeof(tmp)); 
        for(int i=0;i<N;i++)
        {
            if(v[i])
            {
                int a=v[i]/2,b=v[i]-a;
                if(judge)//当前第一个要不要异或操作
                {
                    tmp[i^x]+=b;
                    tmp[i]+=a;
                }
                else {
                    tmp[i^x]+=a;
                    tmp[i]+=b;
                }
            }
            
            judge^=v[i]&1;//很神奇的操作，使我大脑颤抖
        }
        memcpy(v,tmp,sizeof v);
    }
    
    int maxi=0,mini=1e9+7;
    for(int i=0;i<N;i++)
    {
        if(v[i])mini=min(mini,i),maxi=max(maxi,i);
    }
    cout<<maxi<<" "<<mini<<endl;

}
int main(){
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}
