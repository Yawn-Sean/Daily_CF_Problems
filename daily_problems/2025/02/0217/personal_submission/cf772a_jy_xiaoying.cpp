#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/772/A
//格式化： ctrl+shift+ a 

typedef long double ld;
int n,k;
const int MAX=1e5+10;
int p[MAX];         //power
int s[MAX];         //store

int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

	cin>>n>>k;
	for(int i=0; i<n; i++) {
		cin>>p[i]>>s[i];
	}

	ld l=0,r=1e16;
	ld ans=-100,mid=0;

	auto f=[&](ld x)->bool {
		ld sum=x*k;
		for(int i=0; i<n; i++) {
			sum-=max((ld)(0),x*p[i]-s[i]);
		}
		return sum>=0;
	};

	int cnts=100;
	for(int a=0; a<cnts; a++) {
		mid=(l+r)/2;
		if(f(mid)) {
			ans=mid;
			l=mid;
		} else
			r=mid;
	}

	if(ans==-100 || ans>=1e15)
		printf("-1");
	else
		printf("%.10Lf\n",ans);
	return 0;
}
