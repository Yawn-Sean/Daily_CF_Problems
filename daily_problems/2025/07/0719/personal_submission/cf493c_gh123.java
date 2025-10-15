//https://codeforces.com/problemset/submission/493/329696349
//我用二分写的，又臭又长。。。初始化的时候，x=3*n y=3*m应该就可以减少一次判断了。
import java.util.Arrays;
import java.util.Scanner;

public class C493 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[]a=new int[n];
        for (int i = 0; i < a.length; i++) {
            a[i]=sc.nextInt();
        }
        int m=sc.nextInt();
        int[]b=new int[m];
        for (int i = 0; i < b.length; i++) {
            b[i]=sc.nextInt();
        }
        sc.close();
        Arrays.sort(a);
        Arrays.sort(b);
        int x=2*n,y=2*m;
        for (int i = 0; i < n; i++) {
            int val=a[i];
            int ans=-1;
            int l=0,r=m-1;
            while (l<=r) {
                int mid=(l+r)/2;
                if(b[mid]>=val){
                    r=mid-1;
                    ans=mid;
                }else{
                    l=mid+1;
                }
            }
            int tema=(n-i)*3+2*i;//(ai-1,ai]
            int temb=0;
            if(ans==-1){
                temb=2*m;
            }else{
                temb=ans*2+(m-ans)*3;
            }
            if(tema-temb>x-y){
                x=tema;
                y=temb;
            }else if(tema-temb==x-y&&tema>x){
                x=tema;
                y=temb;
            }
        }
        int val=a[n-1];
        int l=0,r=m-1,ans=-1;
        while (l<=r) {
            int mid=(l+r)/2;
            if(b[mid]>val){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        int tema=2*n;
        int temb=0;
        if(ans==-1){
            temb=2*m;
        }else{
            temb=ans*2+3*(m-ans);
        }
        if(tema-temb>x-y){
            x=tema;
            y=temb;
        }else if(tema-temb==x-y&&tema>x){
            x=tema;
            y=temb;
        }
        if(3*n-3*m>x-y){
            x=3*n;
            y=3*m;
        }else if(3*n-3*m==x-y&&3*n>x){
            x=3*n;
            y=3*m;
        }
        System.out.println(x+":"+y);
    }
}
