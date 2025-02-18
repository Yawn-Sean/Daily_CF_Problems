#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int cnt[N];
bool f[N];
int main(){
	int n, A, c, cntA=0;
	cin>>n>>A;
	for(int i=1;i<=n;i++){
		cin>>c;
		cnt[c]++;
		if(c==A) cntA++;
		else{
			if(cnt[c]-1<cntA) f[c]=1;
		}
	}
	for(int i=1;i<N;i++){
		if(i!=A&&f[i]==0&&cnt[i]>=cntA){
			cout<<i;
			return 0;
		}
	}
	cout<<-1;
}
