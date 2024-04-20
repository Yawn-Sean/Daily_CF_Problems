https://codeforces.com/problemset/submission/1031/257373765
import java.util.ArrayList;
import java.util.Scanner;

public class C1031 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        long a=sc.nextLong();
        long b=sc.nextLong();
        long max=0;
        while (max*(max+1)/2<=a+b) {
            max++;
        }
        max--;
        ArrayList<Long>alist=new ArrayList<>();
        ArrayList<Long>blist=new ArrayList<>();
        while (max>0) {
            if(a>=max){
                a-=max;
                alist.add(max);
                max--;
            }else{
                if(b>=max){
                    b-=max;
                    blist.add(max);
                    max--;
                }
            }
        }
        System.out.println(alist.size());
        for (int i = 0; i < alist.size(); i++) {
            System.out.print(alist.get(i)+" ");
        }
        System.out.println();
        System.out.println(blist.size());
        for (int i = 0; i < blist.size(); i++) {
            System.out.print(blist.get(i)+" ");
        }
        System.out.println();
        sc.close();
    }
}
