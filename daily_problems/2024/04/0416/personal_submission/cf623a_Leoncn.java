package daily_problems.2024.04.0416.personal_submission;

public class cf623a_Leoncn {
    static RealFastReader sc = new RealFastReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        int t = 1;
        while (t-- > 0) {
            solve();
        }
        out.close();
    }

    public static void solve() {
        int n = sc.ni();
        int m = sc.ni();
        ArrayList<Integer>[] g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            int a = sc.ni() -1;
            int b = sc.ni() - 1;
            g[a].add(b);
            g[b].add(a);
        }
        char[] cs = new char[n];
        int cntB = 0;
        for (int i = 0; i < n; i++) {
            if(g[i].size() == n-1){
                cs[i] = 'b';
                cntB++;
            }

        }
        int c = 0;
        for (int i = 0; i < n; i++) {

            if(cs[i]!='b' && cs[i]!='a' && cs[i]!='c'){
                if(c == 0){
                    cs[i]='a';
                    int cntA = 1 + dfs(i, cs, 'a', g);
                    int cntEd = 0;
                    for (int j = 0; j < n; j++) {
                        if(cs[j] == 'a'){
                            cntEd += g[j].size();
                        }
                    }
                    if(cntEd!=cntA*(cntA-1) + cntB*cntA){
                        out.println("No");
                        return;
                    }
                    c++;
                }else if(c == 1){
                    cs[i] = 'c';
                    int cntC = 1 + dfs(i, cs, 'c', g);
                    int cntEd = 0;
                    for (int j = 0; j < n; j++) {
                        if(cs[j] == 'c'){
                            cntEd += g[j].size();
                        }
                    }
                    if(cntEd!=cntC*(cntC-1) + cntB*cntC){
                        out.println("No");
                        return;
                    }
                    c++;
                }else {
                    out.println("No");
                    return;
                }
            }
        }
        out.println("Yes");
        out.println(new String(cs));
    }
    private static int  dfs(int cur, char[] cs, char f,  ArrayList<Integer>[] g){
        int res = 0;
        for(int w: g[cur]){
            if(cs[w] == 'b' || cs[w] == f){
                continue;
            }
            cs[w] = f;
            res++;
            res += dfs(w, cs, f, g);
        }
        return res;
    }
}
