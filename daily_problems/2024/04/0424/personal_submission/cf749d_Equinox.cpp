#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
#define QIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define FIN freopen("in.txt", "r", stdin);
#define FOUT freopen("out.txt", "w", stdout);
#define sc scanf
const int N = 2e5 + 10;
typedef pair<int, int> PII;
vector<int> bids[N];
PII ma[N];
int n, q;
bool vis[N];
struct cmp{
	bool operator()(int x, int y){
		return ma[x].first > ma[y].first;
	}
};
set<int, cmp> st;
int main(){
	cin >> n;
	for(int i = 1, a, b; i <= n; i ++){
		cin >> a >> b;
		bids[a].emplace_back(b);
		ma[a].first = max(ma[a].first, b);
		ma[i].second = i;
	}
	for(int i = 1; i <= n; i++)
		if(bids[i].size()) st.insert(i);
	cin >> q;
	for(int i = 0, m, a; i < q; i ++){
		vector<int> del;
		cin >> m;
		while(m --)
			cin >> a, vis[a] = 1, del.emplace_back(a);
		int first = -1, second = -1, p = n;
		for(int x : st)
			if(!vis[x]) {
				if(first == -1) first = x;
				else if(second == -1) second = x;
				else break;
			}
		int d = ~second ? ma[second].first : 0;	
		if(~first) {
			int t = ma[first].second;
			cout << t << ' ';
			int l = 0, r = bids[t].size() - 1;
			while(l < r){
				int mid = l + r >> 1;
				if(bids[t][mid] > d) r = mid;
				else l = mid + 1;
			}
			cout << bids[t][l] << '\n';
		}
		else
			cout << "0 0\n";
		for(int x : del) vis[x] = 0;
	}
	return 0;
}
