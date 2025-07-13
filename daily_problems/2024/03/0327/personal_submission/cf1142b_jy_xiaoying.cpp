#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/1142/B

//   ST表 + 转化
//

//日期： 2024-3-27
//格式化： ctrl+shift+ a

const int MAX=2e5+10;
const int limits=19;
int st[MAX][limits];

int n,m,q;
int p[MAX];
int id[MAX];   //下标从0开始

int nums[MAX];
int questions[MAX][2];

int suf[MAX];

int Log_2(int x) {
	int ans=0;
	while( (1<<ans) <= (x>>1) ) {
		ans++;
	}
	return ans;
}

void f() {
	vector<int> tmp(n+10,m);
	for(int i=m-1; i>=0; i--) { //初始化st[i][0]
		int cur=nums[i];
		int suf=p[(id[cur]+1)%n];
		st[i][0]=tmp[suf];
		tmp[cur]=i;
		
	}
	
	//for(int i=0;i<m;i++) cout<<st[i][0]+1<<" ";
	//cout<<endl;

	int ops=Log_2(m+1);
	for(int j=1; j<=ops; j++) {
		for(int i=0; i<m; i++) {
			int suf=st[i][j-1];

			if(suf==m)
				st[i][j]=m;
			else
				st[i][j]=st[suf][j-1];
		}
	}
	for(int i=0; i<m; i++) {
		int tmp=n-1;
		int j=i;
		int kk=0;
		while(tmp && j<m) {
			if(tmp & 1) j=st[j][kk];
			tmp>>=1;
			kk++;
		}
		suf[i]=j;
	}

	for(int i=m-2; i>=0; i--) {
		suf[i]=min(suf[i],suf[i+1]);
	}
    
    string ans="";
	for(int i=0; i<q; i++) {
		int l=questions[i][0];
		int r=questions[i][1];
		
		//cout<<suf[l]+1<<endl;
		
		if(suf[l]<=r)
			ans+='1';
		else
			ans+='0';
	}
	cout<<ans<<endl;

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>m>>q;
	int tmp;
	for(int i=0; i<n; i++) {
		cin>>tmp;
		p[i]=tmp;
		id[tmp]=i;
	}
	for(int i=0; i<m; i++) {
		cin>>nums[i];
	}
	int l,r;
	for(int i=0; i<q; i++) {
		cin>>l>>r;
		questions[i][0]=l-1;
		questions[i][1]=r-1;
	}
	f();

	return 0;
}
/*


*/

