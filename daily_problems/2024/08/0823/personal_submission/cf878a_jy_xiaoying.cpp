//链接：https://codeforces.com/problemset/problem/878/A
//2024-8-23    ctrl+shift+A

#include<bits/stdc++.h>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin>>n;

	int s0=0,s1023=1023;
	char s;
	int x;
	for(int i=0; i<n; i++) {
		cin>>s>>x;
		if(s=='|') {
			s0|=x;
			s1023|=x;
		} else if(s=='^') {
			s0^=x;
			s1023^=x;
		} else {
			s0&=x;
			s1023&=x;
		}
	}

	cout<<2<<endl;
	cout << "& " << (s0 ^ s1023) << endl;
	cout << "^ " << s0 <<endl;
	return 0;
}
