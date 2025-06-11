import java.io.*;

public class c1615 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));

    static int t,n;

    public static void main(String[] args)throws Exception{
        t = Integer.parseInt(br.readLine());
        while (t-- > 0){
            int s = 0,s1=0,s2=0;
            n = Integer.parseInt(br.readLine());
            char[] a = br.readLine().toCharArray();
            char[] b = br.readLine().toCharArray();
            for(int i=0;i<n;i++){
                s += a[i]!=b[i]? 1:0;
                if(a[i] == '1') s1++;
                if(b[i] == '1') s2++;
            }
            int ans = Integer.MAX_VALUE;
            if(s1==s2) ans = s;
            if((n-s1 + 1) == s2) ans = Math.min(ans,n-s);
            pw.println(ans == Integer.MAX_VALUE? -1:ans);
            pw.flush();
        }
    }
}
