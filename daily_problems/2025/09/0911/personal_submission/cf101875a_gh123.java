//https://codeforces.com/gym/101875/my#

import java.util.Scanner;
//代码很短，题目很难。。
public class A101875 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int k=sc.nextInt();
        int gcd=gcd(n, k);
        long ans=1l*k*(n-gcd)+1l*(k-1)*(gcd-1);
        System.out.println(ans);
        sc.close();
    }
    static int gcd(int a,int b){
        if(b==0){
            return a;
        }
        return gcd(b, a%b);
    }
}
