#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=3e4+10;
struct node{
	int x;LL y;
	bool operator<(const node&v)const{
		return y<v.y;
	}
}a[N];
int vis[N];
LL num[N],c[N];

int n,m;
void solve(){
	cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		num[a[i].x]++;//人数
	}
	sort(a+1,a+1+n);
	LL ans=1e18+10;
	for(int i=num[1];i<=n;i++){//枚举当前有多少票
		memset(vis,0,sizeof vis);
		memcpy(c,num,sizeof num);
		LL p=0;//表示当前需要购买几张票
		LL s=0;
		for(int j=1;j<=n;j++){
			if(a[j].x==1){
				vis[j]=1;
				p++;		
				continue;
			}
			if(c[a[j].x]>=i){
				p++;
				vis[j]=1;
				c[a[j].x]--;
				s+=a[j].y;
				//cout<<j<<"dd\n";
			}
		}
		int j=1;
		while(p<i){
			if(!vis[j]){
				s+=a[j].y;
				p++;
			}
			j++;
		}
		//cout<<i<<" "<<s<<" "<<p<<"\n";
		ans=min(ans,s);
	}
	cout<<ans<<"\n";

}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
