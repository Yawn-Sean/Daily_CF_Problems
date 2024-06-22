
import java.io.*;
import java.util.Arrays;

public class d1151 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StreamTokenizer cin = new StreamTokenizer(br);
    static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
    static int nextInt()throws  Exception{
        cin.nextToken();
        return (int) cin.nval;
    }

    static int[] a,b;
    static Integer[] s;
    public static void main(String[] args) throws Exception{
        long sum = 0;
        int n = nextInt();
        a = new int[n+1];
        b = new int[n+1];
        s = new Integer[n+1];
        for(int i=1;i<=n;i++){
            a[i] = nextInt();
            b[i] = nextInt();
            s[i] = a[i]-b[i];
            sum += (long)1*b[i]*n-a[i];
        }
        Arrays.sort(s,1,n+1,(o,p)->p-o);  //第二个只适合对象 int用不了好像
        for(int i=1;i<=n;i++){
            sum+=(long)1*s[i]*i;
//            System.out.println(s[i]);
        }
        pw.println(sum);
        pw.flush();
    }
}
