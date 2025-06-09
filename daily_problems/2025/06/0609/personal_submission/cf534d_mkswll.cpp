#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector <int> a(n + 1, 0);
	vector rec(n + 1, vector <int> ());
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		rec[a[i]].push_back(i);
	}
	int cur = -1;
	vector <int> ans;
	for(int i = 1; i <= n; ++i){
		++cur;
		while(cur >= 3 && rec[cur].empty()) cur -= 3;
		if(rec[cur].size()){
			ans.push_back(rec[cur].back());
			rec[cur].pop_back();
		}
		else{
			cout << "Impossible\n";
			return 0;
		}
	}
	cout << "Possible\n";
	for(int i : ans) cout << i << " ";
	cout << "\n";
}