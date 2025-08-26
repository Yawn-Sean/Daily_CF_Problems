#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+10;
vector<int> g[N];
int col[N];
bool dfs(int u, int cl){
	col[u] = cl;
	for(auto v : g[u]){
		if(!col[v] && !dfs(v, 3-cl))return false;
		else if(col[v] == cl)return false; 
	}
	return true;
}

void solve(){
	int n, m;
	cin >> n >> m;
	memset(g, 0, sizeof g);
	memset(col, 0, sizeof col);
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u  >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if(!dfs(1,1)){
		cout << "Alice" <<endl;
		for(int i = 0;  i < n;i++){
			int a, b;
			cout << "1 2" << endl;
			cin >> a >> b;
		}
	}
	
	else {
		vector<int> p[3];
		for(int i = 1; i <= n; i++){
			if(col[i] == 1)p[1].push_back(i);
			else p[2].push_back(i);
		}
		cout << "Bob" <<endl;
		for(int i = 1; i <=n; i++){
			int a, b;
			cin >> a >> b;
			if(a > b)swap(a, b);
			if(p[a].size() == 0){
				cout << p[3-a].back()<< " " << b <<endl;
				p[3-a].pop_back();
			}
			else {
				cout << p[a].back() << " " << a <<endl;
				p[a].pop_back();
			}
			
		}
	}

}
int main(){
		int t;
		cin >> t;
		while(t--){
			
			solve();
		}	
	return 0;
} 
