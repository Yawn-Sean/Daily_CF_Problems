import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

public class cf1267e_Leoncn {
        private static void solve() {
        int n = sc.ni();
        int m = sc.ni();
        int[][] g = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                g[i][j] = sc.ni();
            }
        }
        int ans = m;
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            res.add(i+1);
        }
        for (int i = 0; i < n-1; i++) {
            int[][] arr = new int[m][2];
            int sum = 0, cnt = 0;
            for (int j = 0; j < m; j++) {
                arr[j][0] = g[j][i] - g[j][n-1];
                sum += arr[j][0];
                arr[j][1] = j;
            }
            Arrays.sort(arr, Comparator.comparingInt(a -> a[0]));
            int loc = 0;
            List<Integer> list = new ArrayList<>();
            while (sum<0){
                sum -= arr[loc][0];
                list.add(arr[loc][1]+1);
                loc++;
                cnt++;
            }
            if(cnt<ans){
                ans = cnt;
                res = list;
            }
        }
        out.println(ans);
        for(int l: res){
            out.print(l + " ");
        }
    }
}
