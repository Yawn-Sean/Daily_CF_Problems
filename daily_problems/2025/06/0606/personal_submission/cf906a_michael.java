import java.io.*;
import java.util.*;

public class a{
    private static void michael(){
        FastReader sc = new FastReader();
        Set<Character> ans = new HashSet<>();
        for(int i=0;i<26;i++){
            ans.add((char)('a'+i));
        }
        int n=sc.nextInt();
        char[] sym = new char[n];
        String[] words = new String[n];
        for(int i=0;i<n;i++){
            String s = sc.nextLine();
            String []tmp = s.split(" ");
            sym[i] = tmp[0].charAt(0);
            words[i] = tmp[1];
        }
        boolean guess = false;
        int res=0;
        for(int i=0;i<n-1;i++){
            char c = sym[i];
            String word = words[i];
            if(guess){
                if(sym[i]=='!'||sym[i]=='?')
                    res++;
                continue;
            }
            if(c=='!'){
                    Set<Character> t = new HashSet<>();
                    for(int j=0;j<word.length();j++){
                    char tmp=word.charAt(j);
                    if(ans.contains(tmp)){
                        t.add(tmp);
                    }
                }
                ans=t;
            }else if(c=='.'){
                for(int j=0;j<word.length();j++){
                    char tmp=word.charAt(j);
                    if(ans.contains(tmp)){
                        ans.remove(tmp);
                    }
                }
            }else{
                ans.remove(word.charAt(0));
            }
            if(ans.size()==1) guess =true;
        }
        PrintWriter out =new PrintWriter(System.out);
        out.println(res);
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
