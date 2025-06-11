
public class cf1249d2_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int k = sc.ni();
        int[][] g = new int[n][3];
        for (int i = 0; i < n; i++) {
            g[i][0] = sc.ni();
            g[i][1] = sc.ni();
            g[i][2] = i;
        }
        Arrays.sort(g, (a,b)->{
            if(a[0] == b[0]){
                return a[1] - b[1];
            }
            return a[0] - b[0];
        });
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b)->b[1]-a[1]);
        int[] cnt = new int[200002];
        int loc = 0;
        int s = 0;
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < cnt.length; i++) {
            s += cnt[i];
            while (loc<n && g[loc][0]<=i){
                s++;
                cnt[g[loc][1]+1]--;
                pq.add(g[loc]);
                loc++;
            }
            while (s>k){

                int[] p = pq.poll();
                list.add(p[2] + 1);
                cnt[p[1]+1]++;
                s--;
            }
        }
        out.println(list.size());
        for(int l:list){
            out.print(l + " ");
        }
    }

}
