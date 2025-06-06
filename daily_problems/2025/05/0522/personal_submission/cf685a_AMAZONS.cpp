#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
typedef long long ll;
int cal(int x) {
    if (x == 0) return 1;
    int digits = 0;
    while (x > 0) {
        x /= 7;
        digits++;
    }
    return digits;
}
void dfs(int pos,int val,int vis,int len,int maxn,vector<int>& v){
    // if(val>maxn)return ;
    if(pos==len&&val<maxn){
        v[vis]++;
        return ;
    }
    for(int i=0;i<7;i++){
        if((vis&(1<<i))==0){
            dfs(pos+1,val*7+i,vis|(1<<i),len,maxn,v);
        }
    }
}
vector<int> make(int len,int edge){
    vector<int> v(1<<7,0);
    dfs(0,0,0,len,edge,v);//代表当前处理的那一位，当前数值大小，used，最终长度，最大数值，最终存放每个排列的数量的数组
    return v;

}
void solve(){
	int n,m;cin>>n>>m;
    int hour=cal(n-1),mint=cal(m-1),ans=0;
    vector<int> h1=make(hour,n);
    vector<int> m1=make(mint,m);
    for(int i=0;i<(1<<7);i++){
        for(int j=0;j<(1<<7);j++){
            if((i&j)==0){
                ans+=h1[i]*m1[j];
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}
