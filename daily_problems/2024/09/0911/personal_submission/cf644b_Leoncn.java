import java.util.ArrayDeque;
import java.util.Deque;

public class cf644b_Leoncn {
        public static void solve() {
        int n = sc.ni();
        int b = sc.ni();
        int[][] g = sc.nmi(n,2);
        Deque<Long> dq = new ArrayDeque<>();

        for (int i = 0; i < n; i++) {
            long c = g[i][0];
            long d = g[i][1];
            while (dq.size()>0 && dq.peekFirst()<= c){
                dq.pollFirst();
            }
            if(dq.size()<=b){
                if(dq.size()!= 0){
                    c = dq.peekLast();
                }
                out.print(c + d  + " ");
                dq.addLast( c + d);
            }else {
                out.print(-1  + " ");
            }
        }
    }

}
