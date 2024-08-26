import java.io.*;
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
        int[] xs = new int[n];
        int[] ys = new int[n];
        for (int i = 0; i < ys.length; i++) {
            xs[i] = i + 1;
            ys[i] = sc.nextInt();
        }
        // 如果有fail的，把斜率记下来。
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < i; j++) {
                //以 i，j确定一条斜率
                if (check(xs, ys, i, j)) {
//                    out.println(i + " " + j);
                    out.println("YES");
                    return;
                }
            }
        }
        out.println("NO");
    }

    private static boolean check(int[] xs, int[] ys, int i, int j) {
        int x1 = xs[i], y1 = ys[i], x2 = xs[j], y2 = ys[j];
        // y2 - y1 / x2 - x  = y3 - y1 / x3 - x
        // (y2 - y1) * (x3 - x) = (x2 - x) * (y3 - y1);
        int x11 = -1, y11 = -1, x22 = -1, y22 = -1;
        for (int k = 0; k < xs.length; k++) {
            if (k == i || k == j) continue;
            // 如果和slope1不能形成一对，那就换
            int x3 = xs[k], y3 = ys[k];
            if ((y2 - y1) * (x3 - x1) != (x2 - x1) * (y3 - y1)) {
                // new slope
                if (x11 == -1) {
                    x11 = x3;
                    y11 = y3;
                } else if (x22 == -1) {
                    x22 = x3;
                    y22 = y3;
                } else {
                    if ((y22 - y11) * (x3 - x11) != (x22 - x11) * (y3 - y11)) return false;
                }
            }
        }
        return x11 != -1 && (x22 == -1 ||  (y2 - y1) * (x22 - x11) == (y22 - y11) * (x2 - x1) );
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
