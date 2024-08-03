#include<bits/stdc++.h>
using namespace std;
//遍历前i个条件，如果已经连通，则连最大的两个连通块，否则连通两个点
const int N = 1e4+10;
int fa[N],sum[N];
int n,d,cnt=0;
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}

void merge(int a,int b){
	a = find(a), b = find(b);
	if(a==b){
		cnt++;//多一条空闲边
		return;
	}
	fa[a]=b;
	sum[b]+=sum[a];
}
int main(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		fa[i]=i;
		sum[i]=1;
	}
	for(int i=1;i<=d;i++){
		vector<int> v;
		int x,y;
		cin>>x>>y;
		merge(x,y);
		for(int j=1;j<=n;j++){
			if(j==find(j)){
				v.push_back(sum[j]);
			}
		}
		sort(v.begin(),v.end(),greater<int>());
		int ans=0;
		for(int j=0;j<v.size()&&j<=cnt;j++){
			ans+=v[j];
		}	
		cout<<ans-1<<endl;
	}
}