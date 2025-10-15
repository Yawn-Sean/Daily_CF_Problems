#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/1027/D

//   基环树
//

//日期： 2024-3-30
//格式化： ctrl+shift+ a

const int MAX=2e5+10;
typedef long long ll;
typedef vector<int> vv;

int n;
int cost[MAX];
int p[MAX];
bool vis[MAX];

void f() {
	int ans=0;
	for(int i=1; i<=n; i++) {
		
		if(vis[i]) continue;
		unordered_set<int> mp;

		int x=i;
		bool is_ok=1;
		while(1) {
			if(mp.count(x)) break;

			if(vis[x]) {         //已经结算过该环了
				is_ok=0;
				break;
			}

			mp.insert(x);
			x=p[x];
		}

		for(int x:mp) {
			vis[x]=1;
		}
		if(!is_ok) continue; 

		int tmp=cost[x];
		int tou=x;
		while(p[x]!=tou) {
			x=p[x];
			tmp=min(tmp,cost[x]);
		}


		ans+=tmp;
	}
	cout<<ans<<endl;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>cost[i];
	}
	for(int i=1; i<=n; i++) {
		cin>>p[i];
	}

	f();


	return 0;
}
/*
10
1 1 2 3 4 5 6 7 8 8


*/

