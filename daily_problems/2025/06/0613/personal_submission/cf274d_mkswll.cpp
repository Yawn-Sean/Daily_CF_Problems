#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector adj(m + 1, vector <int> ());
	vector <int> ind(m + 1, 0);
	int tot = m;
	for(int i = 1; i <= n; ++i){
		vector <pair <int, int> > lst;
		for(int j = 1; j <= m; ++j){
			int x;
			cin >> x;
			if(x != -1) lst.emplace_back(x, j);
		}
		if(lst.size()){
			sort(lst.begin(), lst.end());
			vector <vector <int> > nlst;
			int len = lst.size();
			for(int j = 0; j < len; ++j){
				if(!j || lst[j].first != lst[j - 1].first) nlst.push_back({lst[j].second});
				else nlst.back().push_back(lst[j].second);
			}
			int nlen = nlst.size();
			for(int j = 1; j < nlen; ++j){
				++tot;
				adj.emplace_back();
				ind.emplace_back();
				for(int k : nlst[j - 1]){
					adj[k].push_back(tot);
					ind[tot]++;
				}
				for(int k : nlst[j]){
					adj[tot].push_back(k);
					ind[k]++;
				}
			}
		}
	}
	queue <int> q;
	for(int i = 1; i <= tot; ++i){
		if(!ind[i]) q.push(i);
	}
	vector <int> ans;
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		if(cur <= m) ans.push_back(cur);
		for(int to : adj[cur]){
			if(!--ind[to]){
				q.push(to);
			}
		}
	}
	if(ans.size() != m) cout << -1 << "\n";
	else for(int i : ans) cout << i << " ";
	return 0;
}