//https://codeforces.com/problemset/submission/1015/331668366
import java.util.Scanner;

public class E1015 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        char[][]cs=new char[n][m];
        for (int i = 0; i < cs.length; i++) {
            cs[i]=sc.next().toCharArray();
        }   
        sc.close();
        int[][]grid=new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(cs[i][j]=='*'){
                    grid[i][j]=1;
                }
            }
        }
        StringBuilder sb=new StringBuilder();
        int[][]tmp=new int[n][m];
        int cnt=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(grid[i][j]==1){
                    int ux=i,uy=j;
                    int dx=i,dy=j;
                    int lx=i,ly=j;
                    int rx=i,ry=j;
                    int step=0;
                    while (true) {
                        ux--;
                        dx++;
                        ly--;
                        ry++;
                        if(ux>=0&&dx<n&&ly>=0&&ry<m&&grid[ux][uy]==1&&grid[dx][dy]==1&&grid[lx][ly]==1&&grid[rx][ry]==1){
                            tmp[ux][uy]=1;
                            tmp[dx][dy]=1;
                            tmp[lx][ly]=1;
                            tmp[rx][ry]=1;
                            tmp[i][j]=1;
                            step++;
                        }else{
                            break;
                        }
                       //if(step>0) 写这里的话，星星数就超过1w了，然后就错了。。。
                    }
                     if(step>0){
                        cnt++;
                        sb.append(i+1).append(" ");
                        sb.append(j+1).append(" ");
                        sb.append(step).append("\n");
                    }
                    
                }
            }
        }
        boolean flag=true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(grid[i][j]!=tmp[i][j]){
                    flag=false;
                    break;
                }
                // System.out.print(tmp[i][j]+" ");
            }
            // System.out.println();
        }

        if(flag){
            System.out.println(cnt);
            System.out.println(sb.toString());
        }else{
            System.out.println(-1);
        }
    }
}
