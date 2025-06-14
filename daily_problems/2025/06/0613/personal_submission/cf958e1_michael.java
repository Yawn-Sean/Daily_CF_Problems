import java.io.*;
import java.util.*;

public class a{
    private static void michael(){
        FastReader sc = new FastReader();
        PrintWriter out = new PrintWriter(System.out);
        int r,b;
        r = sc.nextInt();
        b = sc.nextInt();
        if(r!=b){
            out.println("No");
        }else{
            out.println("Yes");
        }
        out.close();
        return;
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