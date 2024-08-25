
import java.io.*;
import java.util.Arrays;
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
        int[] status = new int[10];
        Arrays.fill(status, 2);
        while (n-- > 0) {
            String op = sc.next();
            int num = sc.nextInt();
            for (int i = 0; i < 10; i++) {
                int bit = num & (1 << i);
                if (op.equals("|")) {
                    if (bit != 0) {
                        status[i] = 1;
                    }
                } else if (op.equals("&")) {
                    if (bit == 0) {
                        status[i] = 0;
                    }
                } else {
                    if (bit != 0) {
                        status[i] ^= 1;
                    }
                }
            }

        }
        out.println(3);
        int and = (1 << 10) - 1, or = 0, xor = 0;
        for (int i = 0; i < 10; i++) {
            if (status[i] == 0) and ^= 1 << i;
            else if (status[i] == 1) or ^= 1<<i;
            else if (status[i] == 3) xor ^= 1<<i;
        }
        out.println("& " + and);
        out.println("| " + or);
        out.println("^ " +xor);
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
