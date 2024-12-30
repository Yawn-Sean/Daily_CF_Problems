import java.util.ArrayList;
import java.util.List;

public class cf744b_Leoncn {
        static int n;
    public static void solve() {
        n = sc.ni();
        int k = 32 - Integer.numberOfLeadingZeros(n);
        int[][] save0 = new int[n][k];
        int[][] save1 = new int[n][k];
        for (int i = 0; i < k; i++) {
            List<Integer> tmp0 = new ArrayList<>();
            List<Integer> tmp1 = new ArrayList<>();
            for (int j = 1; j <=n ; j++) {
                if(((j>>i) &1)==0){
                    tmp0.add(j);
                }else {
                    tmp1.add(j);
                }
            }
            int[] res = query(tmp0);
            for (int j = 0; j < n; j++) {
                save0[j][i] = res[j];
            }
            res = query(tmp1);
            for (int j = 0; j < n; j++) {
                save1[j][i] = res[j];
            }
        }
        out.println(-1);
        for (int i = 0; i < n; i++) {
            int cur = Integer.MAX_VALUE;
            for (int j = 0; j < k; j++) {
                if(((i+1)>>j&1) == 1){
                    cur = Math.min(cur, save0[i][j]);
                }else {
                    cur = Math.min(cur, save1[i][j]);
                }
            }
            out.print(cur  + " ");
        }
    }
    private static int[] query(List<Integer> list){
        out.println(list.size());
        for(int l: list){
            out.print( l +" ");
        }
        out.println("");
        out.flush();
        return sc.na(n);
    }
}
