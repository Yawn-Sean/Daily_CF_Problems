import java.util.Scanner;

public class cf105198m {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while(t-->0){
            long sx=sc.nextLong();
            long sy=sc.nextLong();
            long tx=sc.nextLong();
            long ty=sc.nextLong();
            long k=sc.nextLong();
            long dx=Math.abs(sx-tx);
            long dy=Math.abs(sy-ty);
            if(dx<dy){
                long tem=dx;
                dx=dy;
                dy=tem;
            }
            if(dx<=(dy+1)*k){
                System.out.println(dx+dy);
            }else{
                long extra=(dx-(dy+1)*k+2*k-1)/(2*k)*2;
                System.out.println(dx+dy+extra);
            }
        }   
        sc.close();
    }
}
