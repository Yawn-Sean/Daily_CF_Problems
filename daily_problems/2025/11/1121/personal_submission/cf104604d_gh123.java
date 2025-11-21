import java.util.Scanner;

public class D104604 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
            long a=sc.nextLong();
            long b=sc.nextLong();
            if(a>b){
                long tem=a;
                a=b;
                b=tem;
            }
            if(a*2<b){
                System.out.println("NO");
            }else if(a==b){
                if(a%2==1){
                    System.out.println("NO");
                }else{
                    System.out.println("SI");
                }
            }else{
                if(a%(b-a)>0){
                    System.out.println("NO");
                }else{
                    boolean flag=false;
                    for (int i = 2; i <=4; i++) {
                        if(b%i==0){
                            long x=a-b/i;
                            if(x>0&&b%x==0){
                                flag=true;
                            }
                        }
                    }
                    System.out.println(flag?"SI":"NO");
                }
            }
        }
        sc.close();
    }
}
