import java.io.*;
import java.util.*;


public class a{
    private static void michael() throws FileNotFoundException, IOException {
        FastReader sc = new FastReader();
        PrintWriter out = new PrintWriter(System.out);

        int t = sc.nextInt();
        while(t-->0){
            int q = sc.nextInt();
            long l = 1;
            long r = Long.MAX_VALUE;
            while(q-->0){
                int syb = sc.nextInt();
                long a = sc.nextLong();
                long b = sc.nextLong();
                if(syb == 1){
                    long n = sc.nextLong();
                    long tmp = a - b;
                    long tmpR,tmpL;
                    if(n == 1){
                        tmpL = 1;
                        tmpR = a;
                    }else{
                        tmpR = tmp * (n - 1) + a;
                        tmpL = tmpR - tmp + 1;
                    }
                    if(r == Long.MAX_VALUE){
                        l = tmpL;
                        r = tmpR;
                        out.print("1 ");
                    }else{
                        long newL = Math.max(l,tmpL);
                        long newR = Math.min(r,tmpR);
                        if(newL <= newR){
                            l = newL;
                            r = newR;
                            out.print("1 ");
                        }else{
                            out.print("0 ");
                        }
                    }
                }else{
                    if(l > r){
                        out.print("-1 ");
                    }else if(a >= r){
                        out.print("1 ");
                    }else if(l <= a){
                        out.print("-1 ");
                    }else{
                        long tmp = a - b;
                        long nl = (l - a + tmp -1) / tmp + 1;
                        long nr = (r - a + tmp -1) / tmp + 1;
                        if(nl == nr){
                            out.print(nl + " ");
                        }else{
                            out.print("-1 ");
                        }
                    }
                }
            }
            out.println();
        }

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