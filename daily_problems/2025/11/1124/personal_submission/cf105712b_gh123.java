import java.util.Scanner;

public class B105712 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
            int n=sc.nextInt();
            int[]a=new int[n];
            int max=Integer.MIN_VALUE;
            for (int i = 0; i < a.length; i++) {
                a[i]=sc.nextInt();
                max=Math.max(max, a[i]);
            }
            if(max<2){
                System.out.println(0);
            }else if(n==2){
                int x=a[0],y=a[1];
                int ans=0;
                while (x>1||y>1) {
                    int nx=x/2,ny=y/2;
                    x&=1;
                    y&=1;
                    ans+=nx;
                    ans+=ny;
                    x+=ny;
                    y+=nx;
                }
                System.out.println(ans);
            }else{
                long total=0;
                for (int x : a) {
                    total+=x;
                }
                if(total==3&&max==3){
                    System.out.println(1);
                }else{
                    System.out.println(total-1);
                }
            }
            
        }   
        sc.close();
    }
}
