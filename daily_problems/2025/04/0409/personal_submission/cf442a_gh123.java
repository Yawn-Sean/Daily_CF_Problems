//https://codeforces.com/problemset/submission/442/314694529
//不太会位运算....

import java.util.Arrays;
import java.util.Scanner;
 
public class A442 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[]aa=new int[n];
        for (int i = 0; i < n; i++) {
            String s=sc.next();
            char c=s.charAt(0);
            char d=s.charAt(1);
            int a=0;
            if(c=='R'){
                a|=1<<0;
            }else if(c=='G'){
                a|=1<<1;
            }else if(c=='B'){
                a|=1<<2;
            }else if(c=='Y'){
                a|=1<<3;
            }else if(c=='W'){
                a|=1<<4;
            }
            a|=1<<5+d-'1';
            aa[i]=a;
        }
        int size=1<<10;
        sc.close();
        boolean[]vis=new boolean[size];
        for (int i = 0; i < n; i++) {
            vis[aa[i]]=true;
        }
        int k=0;
        for (int i = 0; i < size; i++) {
            if(vis[i]) k++;
        }
        int ans=10;
        for (int i = 0; i < size; i++) {
            int c=count(i);
            if(ans>c){
                Arrays.fill(vis, false);
                for (int j = 0; j < n; j++) {
                    int a=aa[j]&i;
                    vis[a]=true;
                }
                int l=0;
                for (int j = 0; j < size; j++) {
                    if(vis[j]) l++;
                }
                if(k==l) ans=c;
            }
        }
        System.out.println(ans);
    }
    static int count(int k){
        return k==0?0:count(k&k-1)+1;
    }
}
