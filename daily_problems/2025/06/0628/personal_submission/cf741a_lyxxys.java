    public static void solve(){
        int n = sc.nextInt();
        int[] perm = new int[n];
        int[] vis = new int[n];
        for (int i = 0; i < n; ++ i){
            perm[i] = sc.nextInt()-1;
        }

        long res = 0;
        for (int i = 0; i < n; ++ i){
            if (vis[i] != -1){
                int u = i, cnt = 0;
                while (vis[u] == 0){
                    vis[u] = 1;
                    cnt += 1;
                    u = perm[u];
                }

                if (u != i){
                    res = -1;
                    break;
                }

                if (cnt%2 == 0) cnt /= 2;
                res = LCM(res, 1L*cnt);
            }
        }

        out.println(res);
    }
