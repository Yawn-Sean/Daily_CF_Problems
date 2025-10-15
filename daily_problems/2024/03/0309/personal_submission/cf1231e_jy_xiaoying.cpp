#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/1231/E
//日期： 2024-3-9
//格式化： ctrl+shift+ a

int q;
int n;
string s,t;

void f(){
	
	vector<int> aa(30,0);
	vector<int> bb(30,0);
	for(int i=0;i<n;i++) {
		aa[s[i]-'a']++;
		bb[t[i]-'a']++;
	}
	
	for(int i=0;i<26;i++){
		if(aa[i]!=bb[i]) {
			cout<<"-1"<<endl;
			return ;
		}
	}
	
	int res=0;
	for(int j=0;j<n;j++){
		int id=j;
		for(int i=0;i<n && id<n;i++){
			if(s[i]==t[id]) id++;
		}
		res=max(res,id-j);
	}
	cout<<n-res<<endl;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>q;
	while(q--){
		cin>>n;
		cin>>s>>t;
		f();
	}
	
	return 0;
	
}


