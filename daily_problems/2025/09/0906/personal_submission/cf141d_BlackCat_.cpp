#include<bits/stdc++.h>
#define endl '\n'
void solve(){
	int n,m;
	std::cin>>n>>m;
	std::vector<int> dian;
	dian.push_back(0);
	dian.push_back(m);
	std::vector<std::array<int,4>> a(n);
	for(int i=0;i<n;i++){
		std::cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3];
		dian.push_back(a[i][0]-a[i][3]);
		dian.push_back(a[i][0]+a[i][1]);
	}
	std::sort(dian.begin(),dian.end());
	dian.erase(std::unique(dian.begin(),dian.end()),dian.end());
	int q=dian.size();
	auto get=[&](int w)->int{
		return std::lower_bound(dian.begin(),dian.end(),w)-dian.begin();
	};
	std::vector e(q,std::vector<std::array<int,3>>());
	for(int i=0;i<n;i++){
		int u=get(a[i][0]-a[i][3]);
		int v=get(a[i][0]+a[i][1]);
		e[u].push_back({v,a[i][2]+a[i][3],i});
	}
	int cnt=n;
	for(int i=0;i<q-1;i++){
		e[i].push_back({i+1,dian[i+1]-dian[i],cnt++});
		e[i+1].push_back({i,dian[i+1]-dian[i],cnt++});
	}
	std::vector<int> vis(q,1e9+100);
	std::vector<std::pair<int,int>> fu(q);
	std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>>pq;
	pq.push({0,get(0)});
	vis[get(0)]=0;
	int w=get(0);
	while(!pq.empty()){
		auto [val,u]=pq.top();
//		std::cerr<<dian[u]<<" "<<endl;
		pq.pop();
		if(vis[u]<val){
			continue;
		}
		if(u==q-1){
			std::cout<<val<<endl;
			std::vector<int> ans;
			int cur=u;
			while(cur!=w){
				if(fu[cur].first<n){
					ans.push_back(fu[cur].first);
				}
				cur=fu[cur].second;
			}
			std::cout<<ans.size()<<endl;
			for(int i=ans.size()-1;i>=0;i--){
				std::cout<<ans[i]+1<<endl;
			}
			return ;
		}
		for(auto [next,v,lu]:e[u]){
			if(dian[next]<0){
				continue;
			}
			if(val+v<vis[next]){
				vis[next]=val+v;
				fu[next]={lu,u};
				pq.push({val+v,next});
			}
		}
	}
}
int main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	solve();
}
