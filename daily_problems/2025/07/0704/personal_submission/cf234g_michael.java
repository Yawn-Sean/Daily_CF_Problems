import java.io.*;
import java.util.*;

public class a{
    private static void michael() throws FileNotFoundException, IOException {
        FastReader sc = new FastReader();
        PrintWriter out = new PrintWriter("output.txt");
        int n = sc.nextInt();
        int ans = (int)Math.ceil(Math.log(n) / Math.log(2));

        out.println(ans);

        for(int i=0;i<ans;i++){
            List<Integer> list = new ArrayList<>();
            for(int j=1;j<=n;j++){
                if(((j >> i)&1) == 1){
                    list.add(j);
                }
            }
            out.print(list.size() + " ");
            for(int tmp: list){
                out.print(tmp + " ");
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
            try {
                br = new BufferedReader(new FileReader("input.txt"));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
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