import java.io.*;
import java.util.*;

// 并查集
public class cf827a_WindLY {
    static BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);
    public static void main(String[] args) throws IOException {
        int n = ni();
        int MAX = (int) 1e7;
        char[] ans = new char[MAX];
        int[] f = new int[MAX];
        for (int i = 0; i < MAX; i++) {
            f[i] = i;
        }
        int max = 0; // the max length of str
        for (int i = 0; i < n; i++) {
            String[] in = sc.readLine().split(" ");
            String s = in[0];
            char[] a = s.toCharArray();
            int len = s.length();
            int k = Integer.parseInt(in[1]); // times
            int idx = 2; // to process string_in
            for (int j = 0; j < k; j++) {
                int p = Integer.parseInt(in[idx++]); // first position, start from 1
                for (int l = p; l < p + len; l++) {
                    l = find(f, l);
                    if (l >= p + len) break;
                    ans[l] = a[l - p];
                    union(f, l, l + 1);
                }
                max = Math.max(max, p + len - 1);
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i < max + 1; i++) {
            if (ans[i] == 0) sb.append("a");
            else sb.append(ans[i]);
        }
        out.println(sb);
        out.flush();
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
    static void union(int[] f, int i, int j) {
        f[find(f, i)] = find(f, j); // i -> j
    }
    // 两次循环取代递归
    static int find(int[] f, int i) {
        int v = i, fv = f[v];
        while (f[i] != i) {
            i = f[i];
        }
        while (v != i) {
            f[v] = i;
            v = fv;
            fv = f[fv];
        }
        return i;
    }
}
