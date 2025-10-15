import java.util.Scanner;

public class I100488 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        int c=sc.nextInt();
        int[][]edge=new int[n][n];
        int[]pa=new int[n];
        while (m-->0) {
            int u=sc.nextInt()-1;
            int v=sc.nextInt()-1;
            edge[u][v]=1;
            edge[v][u]=1;
        }
        for (int i = 0; i < n; i++) {
            pa[i]=i;
        }
        sc.close();   
     for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(edge[i][j]==0){
                union(i, j, pa);
            }
        }
     }
     int[]col=new int[n];
     int val=1;
     for (int i = 0; i < n; i++) {
        if(find(i, pa)==i){
            col[i]=val;
            val++;
        }
     }
     for (int i = 0; i < n; i++) {
        if(i!=pa[i]){
            col[i]=col[pa[i]];
        }
     }
     if(val>c+1){
        System.out.println(-1);
     }else{
        boolean flag=true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(i!=j&&edge[i][j]==1){
                    if(col[i]==col[j]){
                        flag=false;
                        break;
                    }
                }
            }
        }
        if(flag){
            for (int i = 0; i < n; i++) {
                System.out.print(col[i]+" ");
            }
            System.out.println();
        }else{
            System.out.println(-1);
        }
     }
    }
   static int find(int x,int[]pa){
    if(pa[x]==x){
        return x;
    }
    return pa[x]=find(pa[x], pa);
   }
   static void union(int x,int y,int[]pa){
    int px=find(x, pa);
    int py=find(y, pa);
    if(px==py){
        return;
    }
    if(px>py){
        pa[px]=py;
    }
    if(px<py){
        pa[py]=px;
    }
   }
}
