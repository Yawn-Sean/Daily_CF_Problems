public class cf1010d_Leoncn {
    static RealFastReader sc = new RealFastReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        int t = 1;
        while (t-- > 0) {
            solve();
        }
        out.close();
    }



    static int[] record;
    static int[] cnt;
    static boolean[] vis;
    static ArrayList<Integer>[] g;
    static int[] p;
    static int[] height;
    public static void solve() {
        int n = sc.ni();
        cnt = new int[n];
        record = new int[n];
        g = new ArrayList[n];
        p = new int[n];
        height = new int[n];
        vis = new boolean[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        Arrays.fill(p, -1);
        Deque<Integer> d = new ArrayDeque<>();
        for (int i = 0; i < n; i++) {
            String s = sc.ns();
            if(s.equals("IN")){
                int x = sc.ni();
                cnt[i] = x;
                d.add(i);
            }else if(s.equals("AND")){
                cnt[i] = -1;
                int a = sc.ni() - 1;
                int b = sc.ni() - 1;
                g[i].add(a);
                g[i].add(b);
                p[a] = i;
                p[b] = i;
                height[i]+=2;
            }else if(s.equals("XOR")){
                cnt[i] = -2;
                int a = sc.ni() - 1;
                int b = sc.ni() - 1;
                g[i].add(a);
                g[i].add(b);
                p[a] = i;
                p[b] = i;
                height[i]+=2;
            }else if(s.equals("NOT")){
                cnt[i] = -3;
                int a = sc.ni() - 1;
                g[i].add(a);
                p[a] = i;
                height[i]++;
            }else if(s.equals("OR")){
                cnt[i] = -4;
                int a = sc.ni() - 1;
                int b = sc.ni() - 1;
                g[i].add(a);
                g[i].add(b);
                p[a] = i;
                p[b] = i;
                height[i]+=2;
            }
        }


        while (d.size()>0){
            int c = d.poll();
            if(cnt[c]>=0){
                record[c] = cnt[c];

            }else {
                List<Integer> list = g[c];
                if(cnt[c] == -1){
                    record[c] = record[list.get(0)] & record[list.get(1)];
                }else if(cnt[c] == -2){
                    record[c] = record[list.get(0)] ^ record[list.get(1)];
                }else if(cnt[c] == -3){
                    record[c] = record[list.get(0)]^1;
                }else if(cnt[c] == -4){
                    record[c] = record[list.get(0)] | record[list.get(1)];
                }
            }

            if(p[c]!=-1){
                height[p[c]]--;
                if(height[p[c]] == 0){
                    d.add(p[c]);
                }
            }
        }



        Deque<Integer> dq = new ArrayDeque<>();
        dq.add(0);
        while (dq.size()>0){
            int c = dq.poll();
            if(cnt[c] >= 0){
                vis[c] = true;
                continue;
            }
            List<Integer> list = g[c];
            if(cnt[c] == -1){
                if(record[c] == 1){
                    dq.add(list.get(0));
                    dq.add(list.get(1));
                }else{
                    if(record[list.get(0)] == 1){
                        dq.add(list.get(1));
                    }
                    if(record[list.get(1)] == 1){
                        dq.add(list.get(0));
                    }
                }
            }else if(cnt[c] == -2){
                dq.add(list.get(0));
                dq.add(list.get(1));
            }else if(cnt[c] == -3){
                dq.add(list.get(0));
            }else if(cnt[c] == -4){
                if(record[c] == 0) {
                    dq.add(list.get(0));
                    dq.add(list.get(1));
                }else {
                    if(record[list.get(0)] == 1 && record[list.get(1)] == 0 ){
                        dq.add(list.get(0));
                    }
                    if(record[list.get(0)] == 0 && record[list.get(1)] == 1 ){
                        dq.add(list.get(1));
                    }
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            if(cnt[i]>=0){
                if(vis[i]){
                    sb.append(record[0]^1);
                }else {
                    sb.append(record[0]);
                }
            }
        }
        out.println(sb);
    }

}