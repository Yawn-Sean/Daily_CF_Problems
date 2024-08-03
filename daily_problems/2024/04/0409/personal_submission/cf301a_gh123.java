https://codeforces.com/problemset/submission/301/255811628

import java.util.Scanner;
public class A301 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int N=2*n-1;
        int neg=0;
        int sum=0;
        int min=1001;
        for (int i = 0; i < N; i++) {
            int tem=sc.nextInt();
            if(tem<0) neg++;
            tem=Math.abs(tem);
            sum+=tem;
            min=Math.min(min, tem);
        }
        if(neg%2==0){
            System.out.println(sum);
        }else{
            if(n%2==0){
               System.out.println(sum-2*min);
            }else{
                System.out.println(sum);
            }
        }
        sc.close();
    }
}
