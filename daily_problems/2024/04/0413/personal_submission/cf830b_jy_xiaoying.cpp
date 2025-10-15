#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/830/B

//       排序 + 模拟 + 树状数组 
//思路：

//日期：  2024-4-13 
//格式化： ctrl+shift+ a


const int MAX=1e5+10;

typedef long long ll;
typedef pair<int,int> pp;
typedef vector<int> vv;

int tree[MAX];

int nums[MAX];
int p[MAX];
vector<vv> g;

int n;

int bs(vv &v,int x){
	int l=0,r=v.size()-1;
	int ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(v[mid]>=x){
			ans=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	return ans;
}

int lowbit(int x){
	return (x & -x);
}

void add(int i,int val){
	while(i<=n){
		tree[i]+=val;
		i+=lowbit(i);
	}
}

int query(int i){
	int ans=0;
	while(i>0){
		ans+=tree[i];
		i-=lowbit(i);
	}
	return ans;
}



void init(){
	for(int i=0;i<MAX;i++) tree[i]=0;
	
	for(int i=1;i<=n;i++){
		add(i,1);
	}
	g=vector<vv>(MAX,vv(0));
	for(int i=1;i<=n;i++){
		int x=nums[i];
		g[x].push_back(i);
	}
	
	int pre=0;
	int index=1;
	for(int i=1;i<MAX;i++){
		if(g[i].size()==0) continue;
		
		int id=bs(g[i],pre);
		int len=g[i].size();
		
		for(int j=id;j<len;j++){
			p[index++]=g[i][j];
		}
		for(int j=0;j<id;j++){
			p[index++]=g[i][j];
		}
		if(id==0) id=len-1;
		else id-=1;
		pre=g[i][id];
	}
}

void solve(){
	int pre=0;
	ll ans=0;
	for(int i=1;i<=n;i++){
		int j=p[i];
		
		ll tmp=0;
		
		if(j>=pre)
		tmp=query(j)-query(pre);
		else{
			tmp=query(n)-query(pre);
			tmp+=query(j);
		}
		ans+=tmp;
		
		add(j,-1);
		pre=j;
	}
	
	cout<<ans<<endl;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>nums[i];
	}
	init();

	solve();

	return 0;
}
/*


*/

