	void solve()
	{
		int n = ni(), A = ni(), B = ni();
		if((n == 2 || n == 3) && A == 1 && B == 1){
			out.println("NO");
		}else if(A == 1 && B == 1){
			char[][] res = new char[n][n];
			for(int i = 0;i < n;i++){
				for(int j = 0;j < n;j++){
					if(Math.abs(j-i) == 1){
						res[i][j] = '1';
					}else{
						res[i][j] = '0';
					}
				}
			}
			out.println("YES");
			for(char[] row : res){
				out.println(new String(row));
			}
		}else if(B == 1){
			char[][] res = make(n, A);
			out.println("YES");
			for(char[] row : res){
				out.println(new String(row));
			}
		}else if(A == 1){
			char[][] res = make(n, B);
			for(int i = 0;i < n;i++){
				for(int j = 0;j < n;j++){
					if(i != j){
						res[i][j] ^= 1;
					}
				}
			}
			out.println("YES");
			for(char[] row : res){
				out.println(new String(row));
			}
		}else{
			out.println("NO");
		}
	}
	
	char[][] make(int n, int A)
	{
		char[][] ret = new char[n][n];
		for(int i = 0;i < n;i++){
			Arrays.fill(ret[i], '0');
		}
		int m = n;
		while(m > A){
			ret[0][n-m+1] = '1';
			ret[n-m+1][0] = '1';
			m--;
		}
		return ret;
	}
