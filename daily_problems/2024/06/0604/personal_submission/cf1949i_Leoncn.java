
public class cf1949i_Leoncn {
        public static void solve() {
        int n = sc.ni();
        long[][] arr = new long[n][3];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nal(3);
        }
        ArrayList<Integer>[] g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long a = arr[i][0] - arr[j][0];
                long b = arr[i][1] - arr[j][1];
                long c = arr[i][2] + arr[j][2];

                if(a * a + b*b  == c*c){
                    g[i].add(j);
                    g[j].add(i);

                }
            }
        }
        boolean f = false;
        int[] cnt = new int[n];
        for (int i = 0; i < n; i++) {
            int sum = 0;
            boolean tag = true;
            if(cnt[i]==0){
                Deque<Integer> dq = new ArrayDeque<>();
                dq.add(i);
                cnt[i] = 1;
                while (dq.size()>0){
                    int p = dq.poll();
                    sum += cnt[p];
                    for(int c : g[p]){
                        if(cnt[c] == 0){
                            dq.add(c);
                            cnt[c] = -cnt[p];
                        }
                        if(cnt[c]==cnt[p]){
                            tag = false;
                        }
                    }
                }

            }
            if(tag && sum!=0){
                f = true;
                break;
            }
        }
        if(f){
            out.println("YES");
        }else {
            out.println("NO");
        }

    }
}
