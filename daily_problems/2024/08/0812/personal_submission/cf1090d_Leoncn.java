
public class cf1090d_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int m = sc.ni();
        if(m== (long) n * (n - 1) /2){
            out.println("NO");
            return;
        }
        ArrayList<Integer>[] g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            int a = sc.ni() - 1;
            int b = sc.ni() - 1;
            g[a].add(b);
            g[b].add(a);
        }
        int f1 = -1, f2 = -1, now = 1;
        boolean[] vis = new boolean[n];
        for (int i = 0; i < n; i++) {
            if(g[i].size() == n-1 )continue;
            for(int w: g[i]){
                vis[w] = true;
            }
            for (int j = 0; j < n; j++) {
                if(i!=j && !vis[j]){
                    f1 = i;
                    f2 = j;
                    break;
                }
            }
            break;
        }
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            if(i!= f1 && i!=f2 ){
                ans[i] = now++;
            }
        }
        ans[f1] = n;
        ans[f2] = n-1;
        out.println("YES");
        for (int i = 0; i < n; i++) {
            out.print( ans[i] + " ");
        }
        out.println(" ");
        for (int i = 0; i < n; i++) {
            out.print(Math.min(n-1, ans[i]) + " ");
        }
    }

}
