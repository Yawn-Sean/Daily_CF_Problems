
import java.io.*;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;

import java.util.Arrays; 

public class a1310 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StreamTokenizer cin = new StreamTokenizer(br);
    static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
    static int nextInt()throws  Exception{
        cin.nextToken();
        return (int) cin.nval;
    }
    public static void main(String[] args) throws Exception {

        int n = nextInt();
        Pair[] a = new Pair[n];
        int[] t1 = new int[n];
        int[] t2 = new int[n];
        for (int i = 0; i < n; i++) {
            t1[i] = nextInt();
        }
        for (int i = 0; i < n; i++) {
            t2[i] = nextInt();
        }
        for (int i = 0; i < n; i++) {
            a[i] = new Pair(t1[i], t2[i]);
        }
        Arrays.sort(a, (a1,a2)->a1.v - a2.v);

        long ans = 0L;
        PriorityQueue<Integer> h = new PriorityQueue<>(Comparator.reverseOrder());
        int cur = 0;
        long costSum = 0L;
        for (int i = 0; i < n || !h.isEmpty(); cur++) {
            if (h.isEmpty()) {
                cur = a[i].v;
            }
            while (i < n && a[i].v == cur) {
                h.add(a[i].t);
                costSum += a[i].t;
                i++;
            }
            costSum -= h.poll();
            ans += costSum;
        }
        System.out.println(ans);
    }

    static class Pair {
        int v, t;

        public Pair(int v, int t) {
            this.v = v;
            this.t = t;
        }
    }
}
