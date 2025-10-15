#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define me memset
#define rep(a,b,c) for(int a=b;a<=c;++a)
#define per(a,b,c) for(int a=b;a>=c;--a)
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
using namespace std;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}

int t;
int n,m,a,b;
int s[N];

bool check(int x,int lim){
	rep(i,1,x){
		if(i+s[x-i+1]>lim) return false;
	}
	return true;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t;

	while(t--){
		cin>>n>>m>>a>>b;

		rep(i,1,m){
			cin>>s[i];
		}

		sort(s+1,s+1+m);

		int fin=b-1;  //when is caught
		int cnt=b-a-1;  //nums of firecrackers

		if(a>b){
			fin=n-b;
			cnt=a-b-1;
		}
		
		cnt=min(cnt,m);

		int l=0,r=cnt;

		while(l<r){
			int mid=(l+r+1)>>1;
			if(check(mid,fin)) l=mid;
			else r=mid-1;
		}
	
		cout<<l<<'\n';
		
	}

    return 0;
}
