//https://codeforces.com/problemset/submission/216/321719744
import java.util.Arrays;
import java.util.Scanner;
//以前都是用的闭区间写的二分，这次用开区间了，居然也过了。。
public class D216 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[][]arr=new int[n][];
        for (int i = 0; i < n; i++) {
            int k=sc.nextInt();
            arr[i]=new int[k+2];
            arr[i][0]=-1;
            for (int j = 1; j <=k; j++) {
                arr[i][j]=sc.nextInt();
            }
            arr[i][k+1]=100001;
            Arrays.sort(arr[i]);
        }
        sc.close();
        int cnt=0;
        for (int i = 0; i < n; i++) {
            int[]l=arr[(i+n-1)%n];
            int[]r=arr[(i+1)%n];
            for (int j = 2; j < arr[i].length-1; j++) {
                int a=lower(l,arr[i][j])-higher(l,arr[i][j-1])+1;
                int b=lower(r,arr[i][j])-higher(r,arr[i][j-1])+1;
                if(a!=b){
                    cnt++;
                }
            }
        }
        System.out.println(cnt);
    }
    public static int lower(int[]a,int val){
        int l=-1,h=a.length;
        while (l+1<h) {
            int mid=(l+h)/2;
            if(a[mid]<val){
                l=mid;
            }else{
                h=mid;
            }
        }
        return l;
    }
    public static int higher(int[]a,int val){
        int l=-1,h=a.length;
        while (l+1<h) {
            int mid=(l+h)/2;
            if(a[mid]>val){
                h=mid;
            }else{
                l=mid;
            }
        }
        return h;
    }
}
