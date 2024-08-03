#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5+1;
#define endl '\n'
#define all(x)	(x).begin(),(x).end()
#define mst(x,val)  memset((x),(val),sizeof (x))
int n, m, k, q, T;
vector<int> prime;
void init(){
	int v[N];
	mst(v,0);
	for(int i = 2; i < N; ++i){
		if(!v[i]){
			prime.push_back(i);
		}
		for(auto j:prime){
			if(1ll*j*i >= N)	break;
			v[j*i] = 1;
			if(i%j == 0)	break;
		}
	}
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    T = 1;
    remake:;
    init();
    while(T--){
		cin >> n >> m;
		int sm = 2*(n-2);
		int idx = *upper_bound(all(prime),sm)-sm; 
		sm += idx;
		cout << 2 << " " << sm << endl;
		int cc = 0;
		for(int i = n; i > 1; --i){
			cout << 1 << " " << i  << " " << (i == 2 ? idx : 2) << endl;
		}
		m -= n-1;
		for(int i = 2; i <= n && m; ++i){
			for(int j = i+1; j <= n && m; ++j){
				cout << i << " " << j << " " << idx+1  << endl; 
				--m;
			}
		}
	}
    return 0;
}
