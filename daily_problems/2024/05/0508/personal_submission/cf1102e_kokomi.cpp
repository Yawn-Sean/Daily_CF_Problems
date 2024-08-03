#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
const int mod = 998244353;
typedef long long ll;
//哪些地方可以+1 +1意味着ans*2
//两个相同的ai aj之间肯定是一样的
//区间是可能有重叠的，要找到所有不重叠区间
//类似于之前做过的区间合并的技巧，按左端点排序，然后扫右端点进行合并
int n;
ll a[N];
map<int,int> mini,maxi;
struct Node{
	int l,r;
}node[N];
ll qmi(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1){
			ans=a*ans%mod;
		}
		b>>=1;
		a=a*a%mod;
	}
	return ans;
}
bool cmp(Node a,Node b){
	return a.l<b.l;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//记录最晚出现位置
	for(int i=n;i>=1;i--){
		if(maxi[a[i]]==0){
			maxi[a[i]]=i;
		}
	}
//	记录最早出现位置
	for(int i=1;i<=n;i++){
		if(mini[a[i]]==0){
			mini[a[i]]=i;
		}
	}
	int len = 1;
	for(int i=1;i<=n;i++){
		node[len].l=mini[a[i]];
		node[len].r=maxi[a[i]];
		len++;
	}
	sort(node+1,node+1+n,cmp);
	int cnt=1;//统计独立区间数目
	int maxi=node[1].r;
	for(int i=2;i<=n;i++){
		if(node[i].l>=maxi){
			cnt++;
		}
		maxi=max(maxi,node[i].r);
	}
//	cout<<cnt<<endl;
	cout<<qmi(2,cnt-1);
}