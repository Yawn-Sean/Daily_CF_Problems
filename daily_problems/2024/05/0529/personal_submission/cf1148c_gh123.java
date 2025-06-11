//https://codeforces.com/problemset/submission/1148/263080821
import java.util.ArrayList;
import java.util.Scanner;

public class C1148 {
    static int n,n2;
    static int[]a,pos;
    static ArrayList<String>ans=new ArrayList<>();
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        n2=n/2;
        a=new int[n];
        pos=new int[n];
        for (int i = 0; i < n; i++) {
            a[i]=sc.nextInt()-1;
            pos[a[i]]=i;
        }
        sc.close();
        for (int i = 1; i < n2; i++) {
            if(pos[i]>=n2){
                swap(pos[i],0);
            }
            swap(pos[i],n-1);
            swap(pos[i],i);
        }
        for (int i = n2; i < n; i++) {
            if(pos[i]<n2){
                swap(pos[i],n-1);
            }
            swap(pos[i],0);
            swap(pos[i],i);
        }
        System.out.println(ans.size());
        for (String s : ans) {
            System.out.println(s);
        }
    }
    static void swap(int i, int j){
        int t=a[i];
        a[i]=a[j];
        a[j]=t;
        pos[a[i]]=i;
        pos[a[j]]=j;
        ans.add((i+1)+" "+(j+1));
    }
}
