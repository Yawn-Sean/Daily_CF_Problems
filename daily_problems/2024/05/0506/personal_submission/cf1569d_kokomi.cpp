#include<bits/stdc++.h>
using namespace std;
//感觉在构成长方形的对边的顶点构成一对
const int N = 1e6+10;
#define int long long
struct Node{
	int x,y,r;
};

int dx,dy,ans;
int x[N],y[N];
map<int,bool> bx,by;
Node cx[N],cy[N];
void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	bx.clear(),by.clear();
	dx=dy=ans=0;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		bx[x[i]]=1;
	}
	for(int i=1;i<=m;i++){
		cin>>y[i];
		by[y[i]]=1;
	}
	for(int i=1;i<=k;i++){
		int x,y;
		cin>>x>>y;
		if(bx.count(x)&&by.count(y)) continue;//交界点忽略不计
		if(bx.count(x)) cx[++dx]={x,y};
		if(by.count(y)) cy[++dy]={x,y};
	}
	sort(x+1,x+1+n);
	sort(y+1,y+1+m);
	for(int i=1;i<=dx;i++) cx[i].r=lower_bound(y+1,y+1+m,cx[i].y)-y;
	for(int i=1;i<=dy;i++) cy[i].r=lower_bound(x+1,x+1+n,cy[i].x)-x;
	sort(cx+1,cx+1+dx,[](Node u,Node v){
		int p=u.r,q=v.r;	
		if(p==q) return u.x<v.x;
		else return p<q;
	});
	sort(cy+1,cy+1+dy,[](Node u,Node v){
		int p=u.r,q=v.r;	
		if(p==q) return u.y<v.y;
		else return p<q;	
	});
	int cur=1;
	for(int i=2;i<=m;i++){
		int s=y[i-1],e=y[i];
		int last=cur;
		while(cur<=dx&&cx[cur].y<e) cur++;
		int p=last;
		int sum=0;
		for(int j=last+1;j<cur;j++){
			if(cx[j].x!=cx[j-1].x) sum+=(j-p)*(j-p),p=j;
		}
		sum+=(cur-p)*(cur-p);
		ans+=((last-cur)*(last-cur)-sum)/2;	
	}
	cur=1;
	for(int i=2;i<=n;i++){
		int s=x[i-1],e=x[i];
		int last=cur;
		while(cur<=dy&&cy[cur].x<e) cur++;
		int p=last;
		int sum=0;
		for(int j=last+1;j<cur;j++){
			if(cy[j].y!=cy[j-1].y) sum+=(j-p)*(j-p),p=j;
		}
		sum+=(cur-p)*(cur-p);
		ans+=((last-cur)*(last-cur)-sum)/2;
	}
	cout<<ans<<endl;
}
signed main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
