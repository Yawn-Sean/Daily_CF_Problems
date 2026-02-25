import java.util.Scanner;

public class cf103870g {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
            int l=sc.nextInt(),r=sc.nextInt(),m=sc.nextInt();
            int bit=31-Integer.numberOfLeadingZeros(m);
            System.out.println(((r+1)>>bit)-(l>>bit));
        }   
        sc.close();
    }
}
