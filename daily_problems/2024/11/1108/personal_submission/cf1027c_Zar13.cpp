#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		int n, a;
		cin>>n;
		map<int, int> mp;
		for(int i=1;i<=n;i++){
			cin>>a;
			mp[a]++;
		}
		vector<int> tmp;
		bool fg=0;
		for(auto it=mp.begin();it!=mp.end();it++){
			int k=(*it).first, v=(*it).second;
//			pair<int, int> p=*it;
//			int k=p.first, v=p.second;
//			cout<<"k:"<<k<<" v:"<<v<<endl; 
			if(v>=4){
				cout<<k<<" "<<k<<" "<<k<<" "<<k<<'\n';
				fg=1;
				break;
			}
			if(v>=2) tmp.push_back(k);
		}
		if(fg) continue;
		sort(tmp.begin(), tmp.end());
		int tx=0, ty=1;
		for(int i=0;i<(int)tmp.size()-1;i++){
			int x=tmp[i], y=tmp[i+1];
			if(x*ty>y*tx) tx=x, ty=y;
		}
		cout<<tx<<" "<<tx<<" "<<ty<<" "<<ty<<'\n';
	}
	return 0;
}
