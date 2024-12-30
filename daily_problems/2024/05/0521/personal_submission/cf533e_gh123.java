https://codeforces.com/problemset/submission/533/261948358
import java.util.Scanner;

public class E533 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        char[]a=sc.next().toCharArray();
        char[]b=sc.next().toCharArray();
        sc.close();
        int l=0,r=n-1;
        for (int i = 0; i < n; i++) {
            if(a[i]!=b[i]){
                l=i;
                break;
            }
        }
        for (int j = n-1; j >=0; j--) {
            if(a[j]!=b[j]){
                r=j;
                break;
            }
        }
        if(l==r){
            System.out.println(2);
            return;
        }
        int ans=2;
        for (int i = l+1; i <=r; i++) {
            if(a[i]!=b[i-1]){
                ans--;
                break;
            }
        }
        for (int i = l+1; i <=r; i++) {
            if(b[i]!=a[i-1]){
                ans--;
                break;
            }
        }
        System.out.println(ans);
    }
    
}
