  public static void solve(){
        int n = sc.nextInt();
        int[] A = new int[n];
        for (int i = 0; i < n; ++ i){
            A[i] = sc.nextInt();
            A[i] -= 1;
        }

        int cnt1 = 0, cnt2 = 0;
        int[] vis = new int[n];

        int step = 1;

        for (int i = 0; i < n; ++ i){
            if (vis[i] > 0) continue;

            int u = i;
            final int ori = step;
            vis[u] = step ++;

            while (vis[A[u]] == 0){
                int nxt = A[u];
                vis[nxt] = step ++;
                u = nxt;
            }

            int nxt = A[u];
            if (vis[nxt] < ori) continue;

            if (vis[u]-vis[nxt] <= 1) cnt1 += 1;
            else cnt2 += 1;
        }

        out.printf("%d %d\n", (cnt1>0?1:0)+cnt2, cnt1+cnt2);
    }

