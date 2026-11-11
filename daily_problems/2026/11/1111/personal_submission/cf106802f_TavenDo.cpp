#include <bits/stdc++.h>
using namespace std;
//#define int long long
//#define endl "\n"
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

//
const int MXN=1e9;
void solve() {
	int n;
	cin>>n;
	if(n>=15){
		int x=rng()%MXN+1;
		while(1){
			cout<<"? "<<x<<endl;
			string a;
			int b;
			cin>>a>>b;
			vector<int>q={(x-b+MXN-1)%MXN+1,(x+b-1)%MXN+1};
			int p=rng()%2;
			cout<<"? "<<q[p]<<endl;
			cin>>a>>b;
			if(a=="NO"){
				cout<<"! "<<q[1-p]<<endl;
				return;
			}else{
				x=q[p];
			}
		}
	}else{
		map<int,int>res;
		for(int i=1;i<=30;++i){
			int x=rng()%MXN+1;
			cout<<"? "<<x<<endl;
			string a;
			int b;
			cin>>a>>b;
			vector<int>q={(x-b+MXN-1)%MXN+1,(x+b-1)%MXN+1};
			if(a=="YES"){
				res[x]=-10000;
			}
			++res[q[0]];
			++res[q[1]];
		}
		for(auto &[u,v]:res){
			if(v>=2){
				cout<<"! "<<u<<endl;
				return;
			}
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int loop = 1;
	//cin >> loop;
	while (loop--){
		solve();
	}
	return 0;
}