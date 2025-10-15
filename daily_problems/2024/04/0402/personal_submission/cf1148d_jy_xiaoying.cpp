#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/1148/D

//  排序 + 贪心
//

//日期： 2024-4-2
//格式化： ctrl+shift+ a

const int MAX=3e5+10;
typedef long long ll;
typedef pair<int,int> pp;

bool is_up[MAX];
int n;
vector<pp> v;

void f() {
	vector<int> p1;
	for(int i=0; i<n; i++) {
		if(is_up[i]) {
			p1.push_back(i);
		}
	}

	vector<int> p2;
	for(int i=0; i<n; i++) {
		if(!is_up[i]) {
			p2.push_back(i);
		}
	}

	if(p1.size()>=p2.size()) {
		sort(p1.begin(),p1.end(),[&](int i,int j) {
			return v[i].first>v[j].first;
		});
		cout<<p1.size()<<endl;
		for(int tmp:p1) {
			cout<<tmp+1<<" ";                       //数组下标输出 从 1 开始 
		}
		cout<<endl;
	} else {
		sort(p2.begin(),p2.end(),[&](int i,int j) {
			return v[i].first<v[j].first;
		});
		cout<<p2.size()<<endl;
		for(int tmp:p2) {
			cout<<tmp+1<<" ";                    //数组下标输出 从 1 开始 
		}
		cout<<endl;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n;
	v=vector<pp>(n);
	int x,y;
	for(int i=0; i<n; i++) {
		cin>>x>>y;
		v[i]=pp(x,y);
		if(x<y)
			is_up[i]=1;
		else
			is_up[i]=0;
	}

	f();

	return 0;
}
/*



*/

