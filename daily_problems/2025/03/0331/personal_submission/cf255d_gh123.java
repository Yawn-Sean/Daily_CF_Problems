//https://codeforces.com/problemset/submission/255/313201953
import java.util.Scanner;

public class D225 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        long n=sc.nextLong();
        long x=sc.nextLong();
        long y=sc.nextLong();
        long c=sc.nextLong();
        sc.close();
        long l=0,r=n*2,ans=-1;
        while (l<=r) {
            long mid=(r-l)/2+l;
            long res=mid*mid*2+mid*2+1;
            if(mid>x-1){
                res-=(mid-(x-1))*(mid-(x-1));
            }
            if(mid>n-x){
                res-=(mid-(n-x))*(mid-(n-x));
            }
            if(mid>y-1){
                res-=(mid-(y-1))*(mid-(y-1));
            }
            if(mid>n-y){
                res-=(mid-(n-y))*(mid-(n-y));
            }
            if(mid>x-1+y-1){
                res += (mid-((x-1)+(y-1))-1)*(mid-((x-1)+(y-1))) / 2;
            }
            if(mid>(x-1)+(n-y)){
                res += (mid - ((x - 1) + (n - y)) - 1) * (mid - ((x - 1) + (n - y))) / 2;
            }
            if(mid>(n-x)+(y-1)){
                res += (mid- ((n - x) + (y - 1)) - 1) * (mid - ((n - x) + (y - 1))) / 2;
            }
            if(mid>(n-x)+(n-y)){
                res += (mid-((n-x)+(n-y))-1) * (mid - ((n - x) + (n - y))) / 2;
            }
            if(res>=c){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        System.out.println(ans);
      //这道题挺难的，对我这种菜鸟来说...
    }
}
