//https://codeforces.com/problemset/submission/815/322923196
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class A815 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        int[][]a=new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j]=sc.nextInt();
            }
        }   
        sc.close(); 
        Map<Integer,Integer>row;
        Map<Integer,Integer>col;
        if(m<n){
            col=col(n,m,a);//先处理列
            row=row(n,m,a);
        }else{
            row=row(n,m,a);//先处理行
            col=col(n,m,a);
        }
        int cnt=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(a[i][j]>0){
                    cnt++;
                }
            }
        }
        if(cnt>0){
            System.out.println(-1);
        }else{
            int x=0;
            for (int key : row.keySet()) {
                x+=row.get(key);
            }
            for (int key : col.keySet()) {
                x+=col.get(key);
            }
            System.out.println(x);
            for (int key : row.keySet()) {
                int val=row.get(key);
                while (val>0) {
                    System.out.println("row "+(key+1));
                    val--;
                }
            }
            for (int key : col.keySet()) {
                int val=col.get(key);
                while (val-->0) {
                    System.out.println("col "+(key+1));
                }
            }
        }
    }
    public static Map<Integer,Integer>row(int n,int m,int[][]a){
        int i=0;
        Map<Integer,Integer>row=new HashMap<>();
        while (i<n) {
            int min=Integer.MAX_VALUE;
            int cnt=0;
            for (int j = 0; j < m; j++) {
                if(a[i][j]>0){
                    min=Math.min(a[i][j], min);
                    cnt++;
                }else{
                    i++;
                    break;
                }
            }
            if(cnt==m){
                for (int j = 0; j < m; j++) {
                    a[i][j]-=min;
                }
                row.put(i, min);
            }
        }
        return row;
    }
    public static Map<Integer,Integer>col(int n,int m,int[][]a){
        int j=0;
        Map<Integer,Integer>col=new HashMap<>();
        while (j<m) {
            int min=Integer.MAX_VALUE;
            int cnt=0;
            for (int i = 0; i < n; i++) {
                if(a[i][j]>0){
                    min=Math.min(min, a[i][j]);
                    cnt++;
                }else{
                    j++;
                    break;
                }
            }
            if(cnt==n){
                for (int i = 0; i < n; i++) {
                    a[i][j]-=min;
                }
                col.put(j, min);
            }
        }
        return col;
    }
}
