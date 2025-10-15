//https://codeforces.com/problemset/submission/67/334347918
import java.util.Arrays;
import java.util.Scanner;

public class A67 {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        String s=sc.next();
        int[]a=new int[n];
        Arrays.fill(a, 1);
        for (int i = 1; i < n; i++) {
            char c=s.charAt(i-1);
            if(c=='='){
                a[i]=a[i-1];
            }else if(c=='R'){
                a[i]=a[i-1]+1;
            }
        } 
        for (int i = n-2; i >=0; i--) {
            char c=s.charAt(i);
            if(c=='L'){
                a[i]=Math.max(a[i], a[i+1]+1);
            }else if(c=='='){
                a[i]=a[i+1];
            }
        }  

        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i]+" ");
        }
        sc.close();
    }
}
