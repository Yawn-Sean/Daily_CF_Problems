#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;
const int N = 200010;

vector<int> son[N];
int n,ans = 0,color[N];

void dfs(int i,int fa) {
	ans = max(ans,1 + (int)son[i].size() - 1);
	
	for (int nxt : son[i]) {
		if (nxt == fa) continue;
		
		ans = max(ans,2 + (int)son[nxt].size() - 1);
		dfs(nxt,i);
	}
}

void make_color(int i,int fa) {	
	int c1 = color[i],c2 = color[fa];
	for (int c = 1,j = 0; c <= ans && j < son[i].size(); c++) {
		if (c == c1 || c == c2) continue;
		
		int nxt = son[i][j];
		if (nxt == fa) {
			++j;
			if (j >= son[i].size()) break;
		}
		
		nxt = son[i][j];
		color[nxt] = c;
		++j;
	}
	
	for (int nxt : son[i]) {
		if (nxt == fa) continue;
		
		make_color(nxt,i);
	}
	
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	int a,b;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		
		son[a].push_back(b);
		son[b].push_back(a);
	}
	
	son[1].push_back(0);
	
	dfs(1,0);
	color[1] = 1; color[0] = 0;
	make_color(1,0);
	cout << ans << "\n";
	for (int i = 1;i <= n; i++) {
		cout << color[i] << " ";
	}
	
	return 0;
} 
