#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/190/B
//格式化： ctrl+shift+ a

typedef long double ld;

ld x1,y1,r1;
ld x2,y2,r2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>x1>>y1>>r1;
	cin>>x2>>y2>>r2;

	ld tmp=hypotl(x1-x2,y1-y2);
	if(abs(r1-r2)<=tmp && tmp<=r1+r2) {
		cout << fixed << setprecision(15)<<0<<endl;
	} else if(abs(r1-r2)>tmp) {
		cout << fixed << setprecision(15)<<(abs(r1-r2)-tmp)/2<<endl;
	} else {
		cout << fixed << setprecision(15)<<(tmp-r1-r2)/2<<endl;
	}
	return 0;
}

