import java.io.*;
import java.util.*;

public class Main {
    static MyScanner sc = new MyScanner();
    public static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    public static void main(String[] args) {
        int t = 1;
        while (t-- > 0) {
            solve();
        }
        out.close();
    }

    private static void solve() {
        int n = sc.nextInt(), m = sc.nextInt(), prevCnt = 0;
        boolean[] seen = new boolean[n + 1];
        boolean[] ans = new boolean[n + 1];
        char[] op = new char[m];
        int[] a = new int[m];
        for (int i = 0; i < m; i++) {
            op[i] = sc.next().charAt(0);
            a[i] = sc.nextInt();
            if (op[i] == '-' && !seen[a[i]]) {
                // 第一次遇到是出去，说明在这之前就进来了
                prevCnt++;
            }
            seen[a[i]] = true;
        }

        for (int i = 0; i < m; i++) {
            if (op[i] == '+') {
                if (i > 0 && a[i - 1] != a[i] || prevCnt > 0) {
                    // 如果前面有数字，或者说不是连续的加减则挂
                    ans[a[i]] = true;
                }
                prevCnt++;
            } else {
                prevCnt--;
                if (i < m - 1 && a[i] != a[i + 1] || prevCnt > 0) {
                    // 如果后面不是立刻加入且现在有数字在
                    ans[a[i]] = true;
                }
            }
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (!ans[i]) {
                cnt++;
            }
        }
        out.println(cnt);
        for (int i = 1; i <= n; i++) {
            if (!ans[i]) {
                out.print(i + " ");
            }
        }
        out.println();

    }

    //-----------PrintWriter for faster output---------------------------------


    //-----------MyScanner class for faster input----------
    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine(){
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

    }
}
