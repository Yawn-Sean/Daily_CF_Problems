int main(void)
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s[3];
	cin>>s[0]>>s[1]>>s[2];

	int cnt[3][26]={};
	for(int i=0;i<3;i++){
		for(int j=0;j<s[i].size();j++){
			cnt[i][s[i][j]-'a']++;
		}
	}
	int n=s[0].size();
	int ans=0;
	pii res={};
	for(int a=0;a<=n;a++){
		int b=INF;
		for(int i=0;i<26;i++){
			if(cnt[0][i]-cnt[1][i]*a<0){
				b=INF;
				break;
			}
			if(cnt[2][i])b=min(b,(cnt[0][i]-cnt[1][i]*a)/cnt[2][i]);
		}
		if(b==INF)break;

		if(ans<a+b){
			res={a,b};
			ans=a+b;
		}
	}
	for(int i=0;i<26;i++){
		cnt[0][i]-=(res.fi*cnt[1][i]+res.se*cnt[2][i]);
	}
	for(int i=0;i<res.fi;i++){
		cout<<s[1];
	}
	for(int i=0;i<res.se;i++){
		cout<<s[2];
	}

	for(int i=0;i<26;i++){
		for(int j=0;j<cnt[0][i];j++){
			cout<<char(i+'a');
		}
	}
	cout<<"\n";
}
