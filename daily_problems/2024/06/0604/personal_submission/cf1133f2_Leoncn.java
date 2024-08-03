
public class cf1133f2_Leoncn {
    static ArrayList<Integer>[] g;
    static boolean[] v;
    static List<String> ans;
    static int cnt;
    static boolean[] con;
    public static void solve() {
        int n = sc.ni();
        int m = sc.ni();
        int d = sc.ni();
        g = new ArrayList[n];
        v = new boolean[n];
        ans = new ArrayList<>();
        con = new boolean[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            int a = sc.ni() - 1;
            int b = sc.ni() - 1;
            g[a].add(b);
            g[b].add(a);
            if(a == 0){
                con[b] = true;
            }
            if(b == 0){
                con[a] = true;
            }
        }
        if(g[0].size()<d){
            out.println("NO");
            return;
        }
        cnt = g[0].size()-d;
        v[0] = true;
        int sum = 0;
        for(int w: g[0]){
            if(!v[w]){
                sum ++;
                ans.add("1" + " " + (w+1));
                v[w] = true;
                dfs(w);

            }
        }
        if(sum > d){
            out.println("NO");
            return;
        }
        out.println("YES");
        for(String s: ans){
            out.println(s);
        }
    }

    private static void dfs(int c){
        for(int w: g[c]){
            if(v[w]){
                continue;
            }
            if(con[w]){
                if(cnt == 0){
                    continue;
                }else {
                    cnt--;
                }
            }
            v[w] = true;
            ans.add((w+1) + " " + (c+1));
            dfs(w);
        }
    }

}
