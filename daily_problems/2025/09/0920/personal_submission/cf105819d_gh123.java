import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class D105819 {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();   
        int[]a=new int[n];
        for (int i = 0; i < a.length; i++) {
            a[i]=sc.nextInt();
        }
        
        List<int[]>list=new ArrayList<>();
        for (int i = 0; i < m; i++) {
            int u=sc.nextInt()-1;
            int v=sc.nextInt()-1;
            list.add(new int[]{u,v});
        }
        sc.close();
        int[][]ans=new int[n][n];
        for (int i = 0; i < 30; i++) {
            int[]parent=new int[n];
            for (int j = 0; j < parent.length; j++) {
                parent[j]=j;
            }
            for (int[] edge : list) {
                if(((a[edge[0]] >> i) & 1) == 1 && ((a[edge[1]] >> i) & 1) == 1){
                    union(edge[0], edge[1], parent);
                }
            }
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if(find(j, parent)==find(k, parent)){
                        ans[j][k]=1;
                    }
                }
            }
        }
        for (int i = 0; i < ans.length; i++) {
            for (int j = 0; j < ans.length; j++) {
                System.out.print(ans[i][j]);
            }
            System.out.println();
        }
    }
    static int find(int x,int[]parent){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent[x], parent);
    }
    static void union(int x,int y,int[]parent){
        int px=find(x, parent);
        int py=find(y, parent);
        if(px==py) return;
        if(px>py){
            parent[px]=py;
        }
        if(px<py){
            parent[py]=px;
        }
    }
}
