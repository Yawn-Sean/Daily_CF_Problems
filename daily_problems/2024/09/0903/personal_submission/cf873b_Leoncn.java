
public class cf873b_Leoncn {
    static int k;
    static int[] ans;
    public static void solve() {
        int n = sc.ni();
        k = sc.ni();
        if((k&1)==0){
            out.println(-1);
            return;
        }
        k/=2;
        ans = new int[n];
        for (int i = 0; i <n ; i++) {
            ans[i] = i+1;
        }
        dfs(0,n);
        if(k !=0){
            out.println(-1);
            return;
        }
        for(int a: ans){
            out.print(a + " ");
        }


    }
    private static void dfs(int l, int r){
        if(k == 0 || l+1 == r){
            return;
        }
        int m = l + r>>1;
        k-=1;
        int tem = ans[m];
        ans[m] = ans[m-1];
        ans[m-1] = tem;
        dfs(l,m);
        dfs(m,r);
    }
}
