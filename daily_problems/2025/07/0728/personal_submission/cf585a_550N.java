import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

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
        int n = sc.nextInt();
        long[] v = new long[n], d = new long[n], p = new long[n];
        for (int i = 0; i < n; i++) {
            v[i] = sc.nextInt();
            d[i] = sc.nextInt();
            p[i] = sc.nextInt();
        }
        boolean[] gone = new boolean[n];
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (gone[i]) continue;
            ans.add(i + 1);
            int cry = (int)v[i];
            // 哭声影响
            for (int j = i + 1; j < n && cry > 0; j++) {
                if (gone[j]) continue;
                p[j] -= cry;
                cry--;
            }
            // 连锁跑路
            Queue<Integer> q = new LinkedList<>();
            for (int j = i + 1; j < n; j++) {
                if (!gone[j] && p[j] < 0) {
                    q.add(j);
                    gone[j] = true;
                }
            }
            while (!q.isEmpty()) {
                int idx = q.poll();
                // 跑路声影响
                for (int j = idx + 1; j < n; j++) {
                    if (gone[j]) continue;
                    p[j] -= d[idx];
                    if (p[j] < 0 && !gone[j]) {
                        q.add(j);
                        gone[j] = true;
                    }
                }
            }
        }
        System.out.println(ans.size());
        for (int x : ans) System.out.print(x + " ");
        System.out.println();
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
