import java.io.*;

public class c900 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StreamTokenizer cin = new StreamTokenizer(br);
    static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
    static int nextInt()throws  Exception{
        cin.nextToken();
        return (int) cin.nval;
    }
    static int[] f = new int[100005];
    static int fmx = Integer.MIN_VALUE;
    static int smx = Integer.MIN_VALUE;
    public static void  main(String[] args)throws Exception{
        int n = nextInt();
        for(int i=1;i<=n;i++){
            int a = nextInt();
            if(a>fmx){
                --f[a];smx=fmx;fmx=a;
            }else if(a>smx){
                ++f[fmx];smx=a;
            }
        }
        int ans = 1;
        for(int i=2;i<=n;i++){
            if(f[ans]<f[i]){
                ans = i;
            }
        }
        pw.print(ans);
        pw.flush();
    }
}
