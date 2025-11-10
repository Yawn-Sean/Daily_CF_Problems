import java.util.Scanner;

public class C106179 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
            long c=sc.nextLong();
            long v=c<<30;
            System.out.println(v+" "+(v^c));
        }   
        sc.close();
    }
}
