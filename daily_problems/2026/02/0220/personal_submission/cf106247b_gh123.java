import java.util.Scanner;

public class cf106247b {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        if(n==1){
            System.out.println("1");
            System.out.println("1");
        }else if(n==2){
            System.out.println("-1");
        }else{
            System.out.println(3<<(n-2));
            StringBuilder sb=new StringBuilder();
            sb.append("1 2");
            for (int i = 0; i < n-2; i++) {
                sb.append(" ").append(3<<i);
            }
            System.out.println(sb.toString());
        }
        sc.close();
    }
}
