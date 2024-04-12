package daily_problems.2024.04.0411.personal_submission;

public class cf1592c_Leoncn {
    static RealFastReader sc = new RealFastReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);
 
    public static void main(String[] args) {
        int t = sc.ni();
        while (t-- > 0) {
            solve();
        }
        out.close();
    }
    static ArrayList<Integer>[] arr;
    static int ans;
    public static void solve() {
        int n = sc.ni();
        int k = sc.ni();
        int[] g = sc.na(n);
        arr = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            arr[i] = new ArrayList<>();
        }
        for (int i = 0; i < n-1; i++) {
            int a = sc.ni()-1;
            int b = sc.ni()-1;
            arr[a].add(b);
            arr[b].add(a);
        }
        int s = 0;
        for (int i = 0; i < n; i++) {
            s ^=g[i];
        }
        if(s==0){
            out.println("YES");
            return;
        }
        if(k == 2){
            out.println("NO");
            return;
        }
 
        ans = 0;
        dfs(0,-1, g, s);
        if(ans>=3){
            out.println("YES");
        }else {
            out.println("NO");
        }
 
    }
    private static int dfs(int cur, int p, int[] g, int s){
        int res = g[cur];
        for(int w:arr[cur]){
            if(w==p){
                continue;
            }
            int r = dfs(w, cur, g, s);
            res^=r;
        }
        if(res == s){
            res = 0;
            ans++;
        }
        return res;
    }
 
}
