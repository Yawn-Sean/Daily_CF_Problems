//https://codeforces.com/problemset/submission/518/334143985
import java.util.Scanner;

public class C518{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        int k=sc.nextInt();
        int[]a=new int[n+1];
        int[]pos=new int[n+1];
        for (int i = 0; i < n; i++) {
            a[i]=sc.nextInt();
            pos[a[i]]=i;
        }
        long steps=0;
        while (m-->0) {
            int b=sc.nextInt();
            int idx=pos[b];
            steps+=(long)idx/k+1;
            if(idx>0){
                int tem=a[idx-1];
                a[idx-1]=a[idx];
                a[idx]=tem;
                pos[b]--;
                pos[tem]++;
            }
        }
        System.out.println(steps);
        sc.close();
    }
}
