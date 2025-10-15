import java.io.*;
import java.util.*;


public class a{
    private static void michael() throws FileNotFoundException, IOException {
        FastReader sc = new FastReader();
        PrintWriter out = new PrintWriter(System.out);

        int n = sc.nextInt();
        int[] arr = new int[n + 1];
        String S = sc.next();
        char[] s = S.toCharArray();
        for (int i = 1;i <= n;i++) arr[i] = s[i-1] - '0';
        int[] dp = new int[n + 1];
        for(int i = 2;i <= n;i++){
            if(arr[i] == arr[i-1]){
                if(dp[i-1] + 1 < i - dp[i - 1] - 1){
                    dp[i] = dp[i - 1] + 1;
                    arr[i] = arr[i] == 0 ? 1 : 0;
                }else{
                    dp[i] = i - dp[i - 1] - 1;
                }
            }else{
                dp[i] = dp[i-1];
            }
            
        }
        out.println(dp[n]);
        out.close();
    }

    public static void main(String[] args) throws IOException {
        michael();
    }

     static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try { st = new StringTokenizer(br.readLine()); }
                catch (IOException e) { e.printStackTrace(); }
            }
            return st.nextToken();
        }

        int nextInt() { return Integer.parseInt(next()); }
        long nextLong() { return Long.parseLong(next()); }
        double nextDouble() { return Double.parseDouble(next()); }
        String nextLine() {
            String str = "";
            try { str = br.readLine(); }
            catch (IOException e) { e.printStackTrace(); }
            return str;
        }
    }
}