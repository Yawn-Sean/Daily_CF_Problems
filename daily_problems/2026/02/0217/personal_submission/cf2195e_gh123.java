import java.util.ArrayList;
import java.util.Scanner;
import java.util.List;

public class cf2195e {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        long mod=(long)1e9+7;
        int t=sc.nextInt();
        while (t-->0) {
            int n=sc.nextInt();
            int[][]path=new int[n+1][2];
            List<Integer>que=new ArrayList<>();
            que.add(0);
            int root=1;
            for (int i = 1; i <=n; i++) {
                path[i][0]=sc.nextInt();
                path[i][1]=sc.nextInt();
            }
            int head=0;
            que.add(root);
            while (head<que.size()) {
                int u=que.get(head);
                head++;
                if(u>0){
                    int l=path[u][0];
                    int r=path[u][1];
                    if(l!=0&&r!=0){
                        que.add(l);
                        que.add(r);
                    }
                }
            }
            long[] size=new long[n+1];
            for (int i = que.size()-1; i >=0; i--) {
                int idx=que.get(i);
                if(idx>0){
                    int l=path[idx][0];
                    int r=path[idx][1];
                    if(l*r!=0){
                        size[idx]=(size[l]+size[r]+4)%mod;
                    }
                }
            }
            for (int i = 0; i < que.size(); i++) {
                int idx=que.get(i);
                if (idx==0) {
                    size[1]=(size[1]+size[0]+1)%mod;
                }else{
                    int l=path[idx][0];
                    int r=path[idx][1];
                    if(l*r!=0){
                        size[l]=(size[l]+size[idx]+1)%mod;
                        size[r]=(size[r]+size[idx]+1)%mod;
                    }
                }
            }
            StringBuilder sb=new StringBuilder();
            for (int i = 1; i <=n; i++) {
                sb.append(size[i]).append(" ");
            }
            System.out.println(sb.toString().trim());
        }   
        sc.close();
    }    
}
