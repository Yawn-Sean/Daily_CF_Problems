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
        int n = sc.nextInt();
        long[] a = new long[n + 1];
        for (int i = 0; i < n; i++) a[i + 1] = sc.nextLong();

        long[] sum_a = new long[n + 1];
        long[] sum_ak = new long[n + 1];
        long[] sum2 = new long[n + 1];
        long[] sum1 = new long[n + 1];
        for(int i=1;i<=n;i++) {
            sum_a[i] = sum_a[i-1] + a[i];
            sum_ak[i] = sum_ak[i-1] + a[i] * i;
            sum2[i] = sum2[i-1] + a[i] * (n - i +1);
            sum1[i] = sum1[i-1] + a[i] * i * (n -i +1);
        }

        long[] pre = new long[n +2];
        pre[1] =0;
        for(int c=2;c<=n+1;c++) {
            long term1 = (long)(c-1) * (n +1);
            long term2 = ((long)(c-1) * c) /2;
            pre[c] = term1 - term2;
        }
        int q = sc.nextInt();
        while (q-- > 0) {
            long l = sc.nextLong(), r = sc.nextLong();
            long sum_r = help(r, n, sum1, sum2, sum_a, sum_ak, pre);
            long sum_lm1 = (l >1) ? help(l-1, n, sum1, sum2, sum_a, sum_ak, pre) : 0;
            long answer = sum_r - sum_lm1;
            out.println(answer);
        }
    }

    static long help(long j, int n, long[] sum1, long[] sum2, long[] sum_a, long[] sum_ak, long[] S) {
        // Binary search to find c such that S[c] <j <= S[c+1]
        int l = 1;
        int r = n + 1;
        while(l < r){
            int mid = l + (r - l)/2;
            if(S[mid] >=j){
                r = mid;
            }
            else{
                l = mid +1;
            }
        }
        int c = (int)l -1;
        int d = (int)(j - S[c] + c -1);
        long x1 = (c >=3) ? sum1[c-2] : 0;
        long x2 = (c-1) * (sum2[n] - ((c-2)>=0 ? sum2[c-2] : 0));
        long x3 = (d+1) * (sum_a[d] - sum_a[c-1]);
        long x4 = (sum_ak[d] - sum_ak[c-1]);
        return x1 + x2 + x3 - x4;
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
