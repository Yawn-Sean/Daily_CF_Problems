//https://codeforces.com/problemset/submission/825/330884540
import java.util.Arrays;
import java.util.Scanner;

public class C825 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int k=sc.nextInt();
        int cnt=0;
        int[]a=new int[n];
        for (int i = 0; i < a.length; i++) {
            a[i]=sc.nextInt();
        }
        sc.close();
        Arrays.sort(a);
        for (int i = 0; i < a.length; i++) {
            while(2*k<a[i]){
                cnt++;
                k*=2;
            }
            if(a[i]>k){
                k=a[i];
            }
        }
        System.out.println(cnt);
    }
}
