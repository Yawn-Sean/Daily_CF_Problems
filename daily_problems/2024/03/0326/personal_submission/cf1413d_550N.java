import java.io.*;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

// If AtCoder, change className to Main
public class cf1413d_550N {
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
        int[] res = new int[n];
        int idx = 0;
        // [index, lowerbound]
        Deque<int[]> dq = new ArrayDeque<>();
        boolean flag = true;
        for (int i = 0; i < 2 * n; i++) {
            String token = sc.nextLine();
            if (token.equals("+")) {
                dq.offerLast(new int[] {idx++, 0});
            } else {
                int num = Integer.parseInt(token.split(" ")[1]);
                if (dq.isEmpty()) {
                    flag = false;
                } else {
                    int[] pair = dq.pollLast();
                    res[pair[0]] = num;
                    if (pair[1] > num) {
                        flag = false;
                    } else {
                        if (!dq.isEmpty()) {
                            int[] last = dq.pollLast();
                            dq.offerLast(new int[] {last[0], Math.max(num, last[1])});
                        }
                    }
                }
            }
        }
        if (!flag) {
            out.println("NO");
        } else {
            out.println("YES");
            for (int nn : res) {
                out.print(nn + " ");
            }
            out.println();
        }
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
