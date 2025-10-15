//https://codeforces.com/problemset/submission/1281/303727312

import java.util.Scanner;

public class B1281 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
            String s1=sc.next();
            String s2=sc.next();
            int n=s1.length();
            int a=0,b=0,pos=n-1;
            for (int i = n-2; i >=0; i--) {
                if(s1.charAt(i)<s1.charAt(pos)){
                    pos=i;
                }else if(s1.charAt(i)>s1.charAt(pos)){
                    a=i;
                    b=pos;
                }
            }
            char[]cs=s1.toCharArray();
            char tem=cs[a];
            cs[a]=cs[b];
            cs[b]=tem;
            s1=String.valueOf(cs);
            if(s1.compareTo(s2)<0){
                System.out.println(s1);
            }else{
                System.out.println("---");
            }
        }
    }
}
