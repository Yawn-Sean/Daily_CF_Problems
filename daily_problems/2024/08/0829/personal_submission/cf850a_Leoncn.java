
public class cf850a_Leoncn {
    public static void solve() {
        int n = sc.ni();
        if(n>=34){
            out.println(0);
            return;
        }
        int[][] g = sc.nmi(n,5);
        List<Integer> ans = new ArrayList<>();

        for (int i = 0; i < n; i ++) {
            boolean flg = true;
            for (int j = 0; j < n; j ++) {
                for (int k = 0; k < j; k ++) {
                    int res = 0;
                    for (int d = 0; d < 5; d ++) {
                        res += (g[k][d] - g[i][d]) * (g[j][d] - g[i][d]);
                    }
                    if (res > 0) flg = false;
                }
            }
            if(flg){
                ans.add(i+1);
            }
        }
        out.println(ans.size());
        for(int a: ans ){
            out.print(a + " " );
        }

    }
}
