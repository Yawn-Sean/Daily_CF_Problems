package cf;

import java.io.*;

public class b573 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StreamTokenizer cin = new StreamTokenizer(br);
    static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
    static int nextInt()throws  Exception{
        cin.nextToken();
        return (int) cin.nval;
    }

    static int n,s;
    static int[] h = new int[100002];
    static int[] v = new int[100002];
    public static void main(String[] args)throws Exception{
        n = nextInt();
        for(int i=1;i<=n;i++){
            h[i] = nextInt();
        }
        v[1] = 1;
        for(int i=2;i<=n;i++){
            v[i]=Math.min(v[i-1]+1,h[i]);
        }
        v[n]=1;
        for(int i=n-1;i>=0;i--){
            v[i]=Math.min(v[i],v[i+1]+1);
        }
        for (int i=1;i<=n;i++){
            s = Math.max(s,v[i]);
        }

        pw.println(s);
        pw.flush();
    }
}
