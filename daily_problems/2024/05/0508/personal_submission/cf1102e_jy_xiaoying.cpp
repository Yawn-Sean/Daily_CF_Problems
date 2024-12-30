//链接：https://codeforces.com/problemset/problem/1102/E

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pp;

const int MAX=2e5+10;
const int mod=998244353;
int g[MAX];
vector<pp> arr(MAX);
int cnt;

int n;

void f(){
	map<int,int> mp;
	cnt=0;
	for(int i=0;i<n;i++){
		if(mp.count(g[i])){
			arr[mp[g[i]]].second=i;
		}
		else{
			mp[g[i]]=cnt;
			arr[cnt]=pp(i,i);
			cnt++;
		}
	}
	sort(arr.begin(),arr.begin()+cnt,[&](const pp &a,const pp &b){
		return a.first<b.first;
	});
	vector<pp> tmp;
	for(int i=0;i<cnt;i++){
		int j=i;
		int r=arr[i].second;
		while(j<cnt && arr[j].first<=r){
			r=max(r,arr[j].second);
			j++;
		}
		tmp.push_back(pp(arr[i].first,r));
		i=j-1;
	}
	
//	for(int i=0;i<(int)(tmp.size());i++){
//		cout<<tmp[i].first<<" "<<tmp[i].second<<endl;
//	}
	
	ll ans=1;
	for(int i=1;i<(int)(tmp.size());i++){
		for(int j=tmp[i-1].second+1;j<tmp[i].first;j++){
			ans=(ans*2)%mod;
		}
		ans=(ans*2)%mod;
	}
	printf("%lld",ans);
	
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&g[i]);
	}
	
	f();
	return 0;
} 
