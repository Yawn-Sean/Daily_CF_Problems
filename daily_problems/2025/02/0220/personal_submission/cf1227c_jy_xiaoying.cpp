#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/1227/C
//格式化： ctrl+shift+ a

typedef pair<int,int> pp;
const int MAX=2010;
string s;
char t[MAX];

int tt;
int n,k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>tt;

	auto f=[&]()->void {
        
		int id=0;
		for(int i=0; i<k-1; i++) {
			t[id++]='(';
			t[id++]=')';
		}
		int j=n-(k-1)*2;
		for(int i=0; i<j/2; i++) {
			t[id++]='(';
		}
		for(int i=0; i<j/2; i++) {
			t[id++]=')';
		}

		vector<int> left,right;
		for(int i=0; i<n; i++) {
			if(s[i]==t[i])
				continue;
			if(s[i]=='(')
				left.emplace_back(i);
			else
				right.emplace_back(i);
		}

		
		int len=left.size();
		if(len==0) {
			cout<<0<<endl;
			return ;
		}

		vector<pp> ans;
		for(int i=0; i<len; i++) {
			int l=min(left[i],right[i]);
			int r=max(left[i],right[i]);
			ans.emplace_back(pp(l,r));
			if(l+1<r-1)
				ans.emplace_back(pp(l+1,r-1));
		}

		cout<<(int)(ans.size())<<endl;
		for(auto its:ans) {
			cout<<its.first+1<<" "<<its.second+1<<endl;     //字符串下标从1开始 
		}
	
	};


	while(tt--) {
		cin>>n>>k;
		cin>>s;
		f();
	}

	return 0;
}
