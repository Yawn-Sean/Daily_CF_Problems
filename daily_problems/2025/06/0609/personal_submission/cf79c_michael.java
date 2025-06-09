import java.io.*;
import java.util.*;

public class a{
    private static void michael(){
        FastReader sc = new FastReader();
        String s = sc.nextLine();
        char[] s1=s.toCharArray();
        int n = sc.nextInt();
        String[] arr = new String[n];
        for(int i=0;i<n;i++){
            arr[i] = sc.nextLine();
        }
        StringBuilder sb = new StringBuilder();
        int index=0;
        int len=0;
        for(int r=0;r<s.length();r++){
            sb.append(s1[r]);
            boolean same = true;
            while(same){
                same=false;
                for(String tmp : arr){
                    int l=tmp.length();
                    if(sb.length()>=l&&sb.substring(sb.length()-l).equals(tmp)){
                        sb.delete(0, 1);
                        same=true;
                        break;
                    }
                }
            }
            if(sb.length()>len){
                len=sb.length();
                index=r-len+1;
            }
        }
        PrintWriter out = new PrintWriter(System.out);
        out.println(len + " " + index);
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