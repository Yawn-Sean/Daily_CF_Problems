#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/1092/C

//     2025-4-23-(字符串处理+字符串哈希)-cf1092c
//

//
//思路：

//日期： 2025-4-23
//格式化： ctrl+shift+ a


typedef unsigned long long ull;
typedef unordered_set<ull> mp;
const int MAX=2e3+60;
const ull base=1e9+7;

int n;
bool ans[MAX];
bool flag[MAX];
string s[MAX];

string t[3];
string tar;

bool is_ok(string t1,string t2) {
	int len=t1.size();
	for(int i=1,j=0; i<len; i++,j++) {
		if(t1[i]!=t2[j]) return 0;
	}
	return 1;
}

ull get_hash(string t1) {
	ull ans=0;
	for(char ss:t1) {
		ans=(ans+ss-'a'+1)*base;
	}
	return ans;
}

bool f_f(string t0,string t1) {

	if(is_ok(t0,t1)) {
		tar=t0;
		tar+=t1.back();
	} else {
		return 0;
	}

	ull tmp=0;
	mp st;
	for(char ss:tar) {
		tmp=(tmp+ss-'a'+1)*base;
		st.insert(tmp);
	}

	int cnt=0;
	for(int i=0; i<2*n-2; i++) {
		tmp=get_hash(s[i]);
		int len=s[i].size();
		if(st.count(tmp) && flag[len]==0) {
			flag[len]=1;
			ans[i]=1;                        // 是前缀
			cnt++;
		}
	}

	if(cnt!=n-1) return 0;

	for(int i=0; i<2*n-2; i++) {
		if(ans[i]) cout<<"P";
		else cout<<"S";
	}
	cout<<endl;
	return 1;
}

void init(){
	for(int i=0;i<MAX;i++){
		flag[i]=ans[i]=0;
	}
}

void solve() {
	if(n==2) {
		cout<<"PS"<<endl;
		return ;
	}
	
	init();
	if(f_f(t[0],t[1])){
		return ;
	}
	
	init();
	f_f(t[1],t[0]);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n;
	int id=0;
	for(int i=0; i<2*n-2; i++) {
		cin>>s[i];
		if(s[i].size()==n-1 ) t[id++]=s[i];
	}
	solve();


	return 0;
}
/*

5
ba
a
baba
a
aba
abab
ab
aba


*/

