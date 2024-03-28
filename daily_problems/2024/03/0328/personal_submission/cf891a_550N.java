import java.io.*;
import java.util.StringTokenizer;

// If AtCoder, change className to Main
public class A {
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
        int[] arr = new int[n];
        int one = 0;
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
            if (arr[i] == 1) one++;
        }
        if (one > 0) {
            out.println(n - one);
        } else {
            int res = Integer.MAX_VALUE;
            for (int l = 0; l < n; l++) {
                int g = arr[l];
                for (int r = l + 1; r < n; r++) {
                    g = gcd(g, arr[r]);
                    if (g == 1) {
                        res = Math.min(res, n - 1 + (r - l));
                        break;
                    }
                }
            }
            out.println(res == Integer.MAX_VALUE ? -1 : res);
        }
    }

    static int gcd(int a, int b)
    {
        // if b=0, a is the GCD
        if (b == 0)
            return a;

            // call the gcd() method recursively by
            // replacing a with b and b with
            // modulus(a,b) as long as b != 0
        else
            return gcd(b, a % b);
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
