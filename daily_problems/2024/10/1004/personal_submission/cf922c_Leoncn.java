import java.util.Scanner;

/**
 * @Description:
 * @Author: Leon
 * @Date: 2024/10/4
 */
public class C {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long k = sc.nextLong();
        for (int i = 1; i <=k ; i++) {
            if(n%i!=i-1){
                System.out.println("No");
                return;
            }
        }
        System.out.println("Yes");
    }
}
