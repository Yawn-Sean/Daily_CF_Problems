#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	vector<tuple<int,int,int>> m(n);
	vector<int> x,y;
	for(int i=0;i<n;++i){
		cin>>get<0>(m[i])>>get<1>(m[i])>>get<2>(m[i]);
		x.push_back(get<0>(m[i]));
		y.push_back(get<1>(m[i]));
	}
	sort(x.begin(),x.end());
	x.erase(unique(x.begin(),x.end()),x.end());
	sort(y.begin(),y.end());
	y.erase(unique(y.begin(),y.end()),y.end());
	int vx=x.size(),vy=y.size();
	vector<long long> sx(vx),sy(vy);
	vector<vector<pair<int,int>>> mx(vx),my(vy);
	for(const auto &p:m){
		int cx=lower_bound(x.begin(),x.end(),get<0>(p))-x.begin();
		int cy=lower_bound(y.begin(),y.end(),get<1>(p))-y.begin();
		int v=get<2>(p);
		sx[cx]+=v;
		sy[cy]+=v;
		mx[cx].push_back({cy,v});
		my[cy].push_back({cx,v});
	}
	vector<pair<long long,int>> ssx(vx),ssy(vy);
	for(int i=0;i<vx;++i) ssx[i]={sx[i],i};
	for(int i=0;i<vy;++i) ssy[i]={sy[i],i};
	sort(ssx.rbegin(),ssx.rend());
	sort(ssy.rbegin(),ssy.rend());
	long long res=0,t=0;
	for(int i=0;i<vx&&i<3;++i){
		t+=ssx[i].first;
		res=max(res,t);
	}
	t=0;
	for(int i=0;i<vy&&i<3;++i){
		t+=ssy[i].first;
		res=max(res,t);
	}
	if(vx>0){
		for(int i=0;i<vy;++i){
			long long h=sy[i];
			set<int>pen;
			vector<long long>es;
			for(const auto &p:my[i]){
				pen.insert(p.first);
				es.push_back(sx[p.first]-p.second);
			}
			int f=0;
			for(const auto &p:ssx){
				if(pen.find(p.second)==pen.end()){
					es.push_back(p.first);
					f++;
					if(f==3) break;
				}
			}
			sort(es.rbegin(),es.rend());
			if(es.size()>=1){
				res=max(res,h+es[0]);
				if(es.size()>=2) res=max(res,h+es[0]+es[1]);
			}
		}
	}
	if(vy>0){
		for(int i=0;i<vx;++i){
			long long v=sx[i];
			set<int> pen;
			vector<long long>es;
			for(const auto &p:mx[i]){
				pen.insert(p.first);
				es.push_back(sy[p.first]-p.second);
			}
			int f=0;
			for(const auto &p:ssy){
				if(pen.find(p.second)==pen.end()){
					es.push_back(p.first);
					f++;
					if(f==3)break;
				}
			}
			sort(es.rbegin(),es.rend());
			if(es.size()>=1){
				res=max(res,v+es[0]);
				if(es.size()>=2) res=max(res,v+es[0]+es[1]);
			}
		}
	}
	cout<<res<<endl;
	return 0;
}
