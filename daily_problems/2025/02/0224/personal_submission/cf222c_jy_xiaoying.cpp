#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/222/C
//格式化： ctrl+shift+ a

const int MAX=1e7+10;
int n,m;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>m;

	vector<int> num1(n),num2(m);
	vector<int> pri;
	vector<int> cnt1(MAX,0),cnt2(MAX,0);

	vector<int> g(MAX);
	iota(g.begin(),g.end(),0);


	for(int i=0; i<n; i++) {
		cin>>num1[i];
	}
	for(int j=0; j<m; j++) {
		cin>>num2[j];
	}

	auto prime_num=[&]()->void {       //埃氏筛
		for(int i=2; i<MAX; i++) {
			if(g[i]!=i) continue;
			pri.emplace_back(i);
			for(int j=i; j<MAX; j+=i) {
				g[j]=i;
			}
		}
	};

	auto Cnt=[&](vector<int> &num,vector<int> &cnt)->void {
		for(int x:num) {
			while(x>1) {
				cnt[g[x]]+=1;
				x/=g[x];
			}
		}
	};


	auto print_num=[&](vector<int> &num,vector<int> &cnt)->void {
		for(int x:pri) {
			int y=min(cnt1[x],cnt2[x]);
			cnt[x]=y;
		}
		
		for(int &x:num) {
			int y=x;
			while(y>1) {
				if(cnt[g[y]]>0){
					x/=g[y];
					cnt[g[y]]--;
				}
				y/=g[y];
			}
		}

	};

	prime_num();
	Cnt(num1,cnt1);
	Cnt(num2,cnt2);

    vector<int> tmp1=cnt1;
    vector<int> tmp2=cnt2;
	print_num(num1,tmp1);
	print_num(num2,tmp2);

	cout<<num1.size()<<" "<<num2.size()<<endl;
	for(int x:num1) {
		cout<<x<<" ";
	}
	cout<<endl;

	for(int x:num2) {
		cout<<x<<" ";
	}
	cout<<endl;

  //cout<<g[100]<<endl;
	return 0;
}

/*

4 3
2 5 10 20
100 1 3

*/
