import java.io.*;
import java.util.*;

public class a{
    private static void michael(){
        FastReader sc=new FastReader();
        int n=sc.nextInt();
        int k=sc.nextInt();

        PriorityQueue<Integer> r1=new PriorityQueue<>();
        PriorityQueue<Integer> r2=new PriorityQueue<>(Collections.reverseOrder());
        for(int i=0;i<n;i++){
            r1.add(sc.nextInt());
        }
        for(int i=0;i<n;i++){
            r2.add(sc.nextInt());
        }
        int worst=0;
        while(r2.size()>0){
            int b=r2.poll();
            while(r1.size()>0 && r1.peek()+b<k) r1.poll();
            if(r1.isEmpty()) break;
            r1.poll();
            worst++;
        }
        PrintWriter out=new PrintWriter(System.out);
        out.print(1+" "+worst);
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
