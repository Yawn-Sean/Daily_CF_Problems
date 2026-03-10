import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class cf106409d{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt(),m=sc.nextInt();
        List<Integer>[]path=new ArrayList[n+1];
        for (int i = 1; i <=n; i++) {
            path[i]=new ArrayList<>();
        }   
        for (int i = 0; i < m; i++) {
            int u=sc.nextInt(),v=sc.nextInt();
            path[u].add(v);
            path[v].add(u);
        }
        sc.close();
        for (int u = 1; u <=n; u++) {
            for (int v : path[u]) {
                int sizeU=Math.min(3, path[u].size());
                int sizeV=Math.min(3, path[v].size());
                for (int i = 0; i < sizeU; i++) {
                    for (int j = 0; j < sizeV; j++) {
                        int a=path[u].get(i);
                        int b=path[v].get(j);
                        if(a!=v&&b!=u&&a!=b){
                            System.out.println(a);
                            System.out.println(u);
                            System.out.println(v);
                            System.out.println(b);
                            return;
                        }
                    }
                }
            }
        }
        System.out.println(-1);
        
    }
}
