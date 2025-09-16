public class Main {
    public static int V1(int v, int index){
        return (int) Math.floor(index+1 - Math.cbrt(v));
    }
    public static int V2(int v, int index){
        return (int) Math.ceil(index+1 + Math.cbrt(v));
    }
    static int n, q;
    static int[] A;
    static PriorityQueue<int[]> pq1, pq2;

    public static void clean_top(){
        while (!pq1.isEmpty()){
            int cur = pq1.peek()[0], index = pq1.peek()[1];
            if (cur != V1(A[index], index)){
                pq1.poll();
            } else break;
        }
        while (!pq2.isEmpty()){
            int cur = pq2.peek()[0], index = pq2.peek()[1];
            if (cur != V2(A[index], index)){
                pq2.poll();
            } else break;
        }
    }
    public static void solve(){
        pq1 = new PriorityQueue<>((u, v) -> {
            return Integer.compare(v[0], u[0]);
        });
        pq2 = new PriorityQueue<>((u, v) -> {
            return Integer.compare(u[0], v[0]);
        });

        n = sc.nextInt();
        A = new int[n];
        for (int i = 0; i < n; ++ i){
            A[i] = sc.nextInt();
            pq1.add(new int[]{V1(A[i], i), i});
            pq2.add(new int[]{V2(A[i], i), i});
        }

        q = sc.nextInt();
        while (q > 0){
            -- q;
            int opt = sc.nextInt();
            if (opt == 1){
                int i = sc.nextInt(), v = sc.nextInt();
                i -= 1;
                if (A[i] == v) continue;

                A[i] = v;
                pq1.add(new int[]{V1(A[i], i), i});
                pq2.add(new int[]{V2(A[i], i), i});
            } else {
                int anchor = sc.nextInt();
                clean_top();
                int ans = -2;
                if (anchor <= pq1.peek()[0]){
                    ans = pq1.peek()[1];
                }
                if (anchor >= pq2.peek()[0]){
                    ans = pq2.peek()[1];
                }
                out.println(ans + 1);
            }
        }
    }
}
