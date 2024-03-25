import java.util.*;
import java.io.*;
public class cf986b_WindLY {
    static BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);
    public static void main(String[] args) throws IOException {
        int n = ni();
        int[] a = na();
        int[] tree = new int[n + 1];
        // 树状数组算逆序对
        long sum = 0;
        for (int v: a) {
            sum += search(tree, n) - search(tree, v);
            add(tree, v);
        }
        if ((n & 1) == 1) {
            out.println((sum & 1) == 1 ? "Petr" : "Um_nik");
        } else {
            out.println((sum & 1) == 0 ? "Petr" : "Um_nik");
        }
        out.flush();
    }
    static void add(int[] tree, int v) {
        while (v < tree.length) {
            tree[v] += 1;
            v += v & -v;
        }
    }
    static int search(int[] tree, int v) {
        int sum = 0;
        while (v > 0) {
            sum += tree[v];
            v &= v - 1;
        }
        return sum;
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