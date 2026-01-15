import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class B105242 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
            int n=sc.nextInt();
            ArrayList<Integer>[]path=new ArrayList[n];
            for (int i = 0; i < path.length; i++) {
                path[i]=new ArrayList<>();
            }
            for (int i = 0; i < n-1; i++) {
                int u=sc.nextInt()-1;
                int v=sc.nextInt()-1;
                path[u].add(v);
                path[v].add(u);
            }
            boolean flag=true;
            int rt=-1;
            for (int i = 0; i < n; i++) {
                if(path[i].size()>3){
                    flag=false;
                }else if(path[i].size()==3){
                    rt=i;
                }
            }
            if(!flag){
                System.out.println("NO");
            }else if(rt!=-1){
                int[]parent=new int[n];
                Arrays.fill(parent, -1);
                int[]que=new int[n];
                int head=0,tail=0;
                que[tail]=rt;
                tail++;
                boolean[]vis=new boolean[n];
                vis[rt]=true;
                while (head<tail) {
                    int u=que[head];
                    head++;
                    for (int v : path[u]) {
                        if(!vis[v]){
                            vis[v]=true;
                            parent[v]=u;
                            que[tail]=v;
                            tail++;
                        }
                    }
                }
                int[]cnt=new int[n];
                for (int i = 0; i < n; i++) {
                    if(path[i].size()==3){
                        int cur=i;
                        while (cur>=0&&cnt[cur]==0) {
                            cnt[cur]=1;
                            cur=parent[cur];
                        }
                    }
                }
                for (int i = 0; i < n; i++) {
                    int vcnt=0;
                    for (int next : path[i]) {
                        vcnt+=cnt[next];
                    }
                    if(vcnt>=3){
                        flag=false;
                    }
                }
                System.out.println(flag?"YES":"NO");
            }else{
                System.out.println("YES");
            }
        }
        sc.close();
    }    
}
