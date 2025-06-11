#include<bits/stdc++.h>
using namespace std;
int n, cnt[130];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		cnt[c]++;
	}
	int cntj=0;
	for(int i=0;i<=122;i++){
		if(cnt[i]%2) cntj++;
	}
	int k=cntj;
	if(k==0){
		int st=1;
		vector<char> s(n+1, 0);
		for(int i=0;i<=122;i++){
			while(cnt[i]){
				s[st]=s[n-st+1]=i;
				st++;
				cnt[i]-=2;
			}
		}
		cout<<1<<endl;
		for(int i=1;i<=n;i++) cout<<s[i];
		return 0;
	}
	while(k<n&& (n%k|| (n/k%2==0))){
		k+=2;
	}
	if(n%k|| n==k){//注意n==k
		cout<<n<<endl;
		for(int i=0;i<=122;i++){
			while(cnt[i]--){
				cout<<(char)i<<" ";
			}
		}
	}else{
		int c=n/k;
		vector<vector<char>> s(k+1, vector<char>(c+1, 0));
		int idx=1, idx_mid=1, st=1;
		for(int i=0;i<=122;i++){
			if(cnt[i]%2){
				s[idx_mid++][(c+1)/2]=i;
				cnt[i]--;
			}
			while(cnt[i]){
				if(idx<=k){
					s[idx][st]=s[idx][c-st+1]=i;
					st++;
					if(st>c/2){
						st=1;
						idx++;
					}
					cnt[i]-=2;
				}else{
					s[idx_mid++][(c+1)/2]=i;
					cnt[i]--;
				}		
			}
		}
		cout<<k<<endl;
		for(int i=1;i<=k;i++){
			for(int j=1;j<=c;j++){
				cout<<s[i][j];
			}
			cout<<" ";
		}
	}
	return 0;
}
