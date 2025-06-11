//https://codeforces.com/problemset/submission/1041/273650921
import java.util.Scanner;

public class D1041 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int h=sc.nextInt();
        int[] ls=new int[n];
        int[] rs=new int[n];
        for (int i = 0; i < n; i++) {
            ls[i]=sc.nextInt();
            rs[i]=sc.nextInt();
        }
        int l=0,r=0,cur=h,res=0,ans=0;
      //还不熟，这里是双指针处理，看了下别人的提交，也有很多是二分处理的，
        while (l<n) {
            while (r<n-1&&ls[r+1]-rs[r]<cur) {
                res+=rs[r]-ls[r];
                cur-=ls[r+1]-rs[r];
                r++;
            }
            ans=Math.max(ans, res+rs[r]-ls[r]+h);
            res-=rs[l]-ls[l];
            l++;
            if(l<n){
                cur+=ls[l]-rs[l-1];
            }
        }
        System.out.println(ans);
        sc.close();
    }
}
