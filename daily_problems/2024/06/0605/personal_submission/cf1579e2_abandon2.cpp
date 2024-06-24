#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
typedef long long LL;
LL c[N];
int n;

int lowbit(int x){
	return x&(-x);
}

void add(int k,int x){
	for(int i=k;i<=n;i+=lowbit(i)){
		c[i]+=x;
	}
}

int ask(int k){
	int res=0;
	for(int i=k;i>=1;i-=lowbit(i)){
		res+=c[i];
	}
	return res;
}

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)c[i]=0;
	vector<int>a(n+1),b,d(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b.push_back(a[i]);
	}
	sort(b.begin(),b.end());
	b.erase(unique(b.begin(),b.end()),b.end());

	for(int i=1;i<=n;i++){
		d[i]=lower_bound(b.begin(),b.end(),a[i])-b.begin()+1;
	}
	deque<int>dq;
	LL sum=0;
	for(int i=1;i<=n;i++){
		int t=ask(d[i]-1);//前面有多少个小于的
		int p=ask(d[i]);
		int q=i-1-p;//前面有多少个比他大的
		//cout<<t<<" "<<q<<"\n";
		if(t<=q){
			dq.push_back(a[d[i]]);
		}
		else{
			dq.push_back(a[d[i]]);
		}
		sum+=min(t,q);
		add(d[i],1);
	}
	//cout<<sum<<"\n";
	while(dq.size()){
		cout<<dq.front()<<" ";
		dq.pop_front();
	}
	cout<<"\n";
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--)
		solve();
	return 0;
}
