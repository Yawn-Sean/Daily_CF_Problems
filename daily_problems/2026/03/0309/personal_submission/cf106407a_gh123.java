import java.util.Scanner;

public class cf106407a {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
            long n=sc.nextLong();
            long m=sc.nextLong();
            long k=sc.nextLong();
            if(k==1){
                System.out.println((n*m)%2==1?"Munir":"Matthew");
            }else if((n%2!=0)||(m%2!=0)||k>=4){
                System.out.println("Munir");
            }else{
                System.out.println("Matthew");
            }
        }   
        sc.close();
    }
}
