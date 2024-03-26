import java.util.*;
import java.io.*;
public class cf1413d_WindLY {
    static BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);
    static List<Integer> ls = new ArrayList<>();
    public static void main(String[] args) throws IOException {
        int n = ni();
        String[] a = new String[2 * n];
        for (int i = 2 * n - 1; i >= 0; i--) {
            a[i] = sc.readLine();
        }
        if (solve(a, n)) {
            out.println("YES");
            for (int v: ls) {
                out.print(v + " ");
            }
        } else out.println("NO");
        out.flush();
    }
    static boolean solve(String[] a, int n) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (String s: a) {
            if (s.equals("+")) {
                if (pq.isEmpty()) return false;
                ls.add(pq.poll());
            } else {
                String[] ar = s.split(" ");
                int v = Integer.parseInt(ar[1]);
                if (!pq.isEmpty() && v > pq.peek()) return false;
                pq.offer(v);
            }
        }
        Collections.reverse(ls);
        return true;
    }
    static int ni() throws IOException {
        return Integer.parseInt(sc.readLine());
    }
    static int[] na() throws IOException {
        String[] in = sc.readLine().split(" ");
        int n = in.length;
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            ans[i] = Integer.parseInt(in[i]);
        }
        return ans;
    }
}
