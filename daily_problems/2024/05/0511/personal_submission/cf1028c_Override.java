//最大和次大  最小和次小
import java.io.*;
import java.net.NetworkInterface;

public class c1028 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StreamTokenizer cin = new StreamTokenizer(br);
    static PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
    static int nextInt()throws  Exception{
        cin.nextToken();
        return (int) cin.nval;
    }
    static int[] a = new int[6];
    static int[] b = new int[6];
    static int[] c = new int[6];
    static int[] d = new int[6];
    public static void main(String[] args)throws Exception{
        int n,e,f,g,h;
        n = nextInt();
        for(int i=1;i<=2;i++){
            a[i]=b[i]=Integer.MIN_VALUE;
            c[i]=d[i]=Integer.MAX_VALUE;
        }
        for(int i=1;i<=n;i++){
            e = nextInt();
            f = nextInt();
            g = nextInt();
            h = nextInt();
            if(e>=a[2]){
                if(e>=a[1]){
                    a[2]=a[1];a[1]=e;a[4]=i;
                }else{
                    a[2]=e;
                }
            }
            if(f>=b[2]){
                if(f>=b[1]){
                    b[2]=b[1];b[1]=f;b[4]=i;
                }else{
                    b[2]=f;
                }
            }
            if(g<=c[2]){
                if(g<=c[1]){
                    c[2]=c[1];c[1]=g;c[4]=i;
                }else{
                    c[2]=g;
                }
            }
            if(h<=d[2]){
                if(h<=d[1]){
                    d[2]=d[1];d[1]=h;d[4]=i;
                }else{
                    d[2]=h;
                }
            }
        }//处理最大和次大 最小和次小

        for(int i=1;i<=n;i++){
            int A,B,C,D;
            A= (i==a[4])? a[2]:a[1];
            B= (i==b[4])? b[2]:b[1];
            C= (i==c[4])? c[2]:c[1];
            D= (i==d[4])? d[2]:d[1];

            if(C>=A && D>=B){
                pw.println(A+" "+B);
                break;
            }
        }
        pw.flush();
    }


}
