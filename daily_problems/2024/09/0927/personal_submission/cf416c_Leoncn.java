import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;

public class cf416c_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int[][] g = new int[n][3];

        for (int i = 0; i < n; i++) {
            g[i][0] = sc.ni();
            g[i][1] = sc.ni();
            g[i][2] = i+1;
        }
        int k = sc.ni();
        int[][] arr = new int[k][2];
        for (int i = 0; i < k; i++) {
            arr[i][0] = sc.ni();
            arr[i][1] = i+1;
        }
        Arrays.sort(arr,(a,b)->a[0]-b[0]);
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b)->b[1]-a[1]);
        Arrays.sort(g,(a,b)->a[0]-b[0]);
        int loc = 0;
        long ans = 0;
        List<String> list = new ArrayList<>();
        for (int i = 0; i < k; i++) {
            while (loc<n && g[loc][0]<= arr[i][0]){
                pq.add(g[loc++]);
            }
            if(pq.size()>0){
                ans += pq.peek()[1];
                list.add(pq.poll()[2] + " " + arr[i][1]);
            }
        }
        out.println(list.size() + " " + ans);
        for(String s: list){
            out.println(s);
        }

    }
}
