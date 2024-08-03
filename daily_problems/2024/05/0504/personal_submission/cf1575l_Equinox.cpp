#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> PII;
const int N = 2e5 + 10;
int n, tot, res;
vector<int> p[N];



int main(){
	freopen("in.txt", "r", stdin);
	cin >> n;
	for(int i = 1, a; i <= n; i ++) {
		cin >> a; 
		if(i >= a)
			p[a].emplace_back(i - a);
	}
	vector<int> f;
	for (int i = 1; i <= n; i ++){
		sort(p[i].begin(), p[i].end());
		reverse(p[i].begin(), p[i].end());
		for(int x : p[i]){
			auto it = upper_bound(f.begin(), f.end(), x);
			if (it == f.end()) f.emplace_back(x);
			else *it = x;
		}
	}
	
	cout << f.size();
	return 0;
}
