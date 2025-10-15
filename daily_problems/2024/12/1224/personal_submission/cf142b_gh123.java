//https://codeforces.com/problemset/submission/142/298161256
import java.util.Scanner;
//代码量不大，但是挺费脑的，直接做是做不出来。。

public class B142 {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int a=sc.nextInt();
        int b=sc.nextInt();
        int mn=Math.min(a,b);
        int mx=a+b-mn;
        if(mn==1){
            System.out.println(a*b);
        }else if(mn==2){
            System.out.println(mx/4*4+Math.min(mx%4,2)*2);
        }else{
            System.out.println((a*b+1)/2);
        }
        sc.close();
    }
}
