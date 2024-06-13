//https://codeforces.com/problemset/submission/1292/265559688
import java.util.Scanner;

public class B1292 {
    public  static long dis(long x,long y,long x1,long y1){
        return Math.abs(x-x1)+Math.abs(y-y1);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long x0=sc.nextLong();
        long y0=sc.nextLong();
        long ax=sc.nextLong();
        long ay=sc.nextLong();
        long bx=sc.nextLong();
        Long by=sc.nextLong();
        Long xs=sc.nextLong();
        Long ys=sc.nextLong();
        Long t=sc.nextLong();
        long xi[]=new long[100];
        long yi[]=new long[100];
        xi[0]=x0;
        yi[0]=y0;
        //1e16
        long Max=10000000000000000L;;
        int ant=1;
        for(int i=1;i<70;i++){
            xi[i]=ax*xi[i-1]+bx;
            yi[i]=ay*yi[i-1]+by;
            ant++;
            if(xi[i]>Max||yi[i]>Max){
                break;
            }
        }
        int nnt=0;
        long time=t;
 
        for(int i=0;i<ant;i++){
            t=time;
            int sum=0;
            if(dis(xi[i],yi[i],xs,ys)>t){
                continue;
            }
            t=t-dis(xi[i],yi[i],xs,ys);
            sum++;
            int cur=i;
            while(t>0&&cur-1>=0){
                long dd=dis(xi[cur],yi[cur],xi[cur-1],yi[cur-1]);
                if(dd>t){
                    break;
                }
                sum++;
                cur--;
                t=t-dd;
            }
            t-=dis(xi[i],yi[i],xi[0],yi[0]);
            cur=i;
            while(t>0){
                long dd=dis(xi[cur],yi[cur],xi[cur+1],yi[cur+1]);
                if(dd>t){
                    break;
                }
                sum++;
                cur++;
                t=t-dd;
            }
            nnt=Math.max(nnt,sum);
        }
        System.out.println(nnt);
    }
}
