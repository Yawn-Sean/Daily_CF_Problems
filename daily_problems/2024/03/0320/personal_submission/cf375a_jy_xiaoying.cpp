#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/375/A

//  数论   众所周知，一个数如果能被 7 整除，那么这个数 % 7 的余数一定是 0
//   1869%7=0,8961%7=1,1689%7=2,6198%7=3, 1698%7=4,9861%7=5,1896%7=6

//日期： 2024-3-20
//格式化： ctrl+shift+ a

string s;
int cnt[15];

string t[]= {"1869","8961","1689","6198","1698","9861","1896"};

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>s;
	for(char ss:s) {
		cnt[ss-'0']++;
	}

	cnt[1]--,cnt[6]--,cnt[8]--,cnt[9]--;
	int tmp=0;
	string ans="";
	for(int i=1; i<=9; i++) {

		for(int j=0; j<cnt[i]; j++) {
			ans+=('0'+i);
			tmp=(tmp*10+i)%7;
		}

	}
	 
	for(int i=0;i<4;i++){    //(tmp*10000+ ? )%7==0
		tmp=(tmp*10)%7;
	}
     tmp=(7-tmp)%7;
    
    
	ans+=t[tmp];
	while(cnt[0]--) {
		ans+='0';
	}

	cout<<ans<<endl;

	return 0;
}
/*


*/

