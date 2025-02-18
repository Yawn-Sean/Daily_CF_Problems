//https://codeforces.com/problemset/submission/768/278734853
import java.util.Scanner;

public class B768 {

    static long cnt(long n){
        long x=1;
        while (n>1) {
            n/=2;
            x*=2;
        }
        return x;
    }
    static int find_one(long pos,long target,long num){
        if(num<2){
            return (int)num;
        }
        if(pos+1==2*target){
            return (int)num%2;
        }
        num/=2;
        pos/=2;
        if(target>pos+1){
            target-=(pos+1);
        }
        return find_one(pos, target, num);
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        long n=sc.nextLong();
        long l=sc.nextLong();
        long r=sc.nextLong();
        long x=cnt(n);
        x=x*2-1;
        long ans=0;
        sc.close();
        for (long i = l; i <=r; i++) {
            ans+=find_one(x, i, n);
        }
        System.out.println(ans);
    }
}
