    public static void solve(){
        String s = sc.next();
        String t = sc.next();

        int n = s.length(), m = t.length();

        final int mod = (int)1e9+7;
        int[][] f = new int[n][m];
        
        int res = 0;
        for (int i = 0; i < n; ++ i){
            for (int j = 0; j < m; ++ j){
                if (s.charAt(i) == t.charAt(j)){
                    int spend = (1 + (j > 0 ? f[i][j-1] : 0)) % mod;
                    if (i > 0 && j > 0) spend = (spend + f[i-1][j-1]) % mod;
                    f[i][j] = spend;
                } else {
                    if (j > 0) f[i][j] = f[i][j-1];
                }
            }
            res = (res + f[i][m-1]) % mod;
        }

        out.println(res);
    }
