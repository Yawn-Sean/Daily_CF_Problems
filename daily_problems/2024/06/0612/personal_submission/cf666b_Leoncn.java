
public class cf666b_Leoncn {
    static ArrayList<Integer>[] g;
    static int[][] dis;
    static ArrayList<int[]>[] dis2;
    static ArrayList<int[]>[] dis3;
    public static void solve() {
        int n = sc.ni();
        int m = sc.ni();
        g = new ArrayList[n];
        dis = new int[n][n];
        dis2 = new ArrayList[n];
        dis3 = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
            dis2[i] = new ArrayList<>();
            dis3[i] = new ArrayList<>();
            Arrays.fill(dis[i], Integer.MAX_VALUE/2);
            dis[i][i] = 0;
        }
        for (int i = 0; i < m; i++) {
            int a = sc.ni() - 1;
            int b = sc.ni() - 1;
            g[a].add(b);
        }
        for (int i = 0; i < n; i++) {
            Deque<Integer> dq = new ArrayDeque<>();
            dq.add(i);
            dis[i][i] = 0;
            int c = 1;
            while (dq.size()>0){
                int s = dq.size();
                while (s-->0){
                    int p = dq.poll();
                    for(int w : g[p]){
                        if(dis[i][w]>c){
                            dis[i][w] = c;
                            dq.add(w);
                        }
                    }
                }
                c++;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(i == j) continue;
                if(dis[i][j] == Integer.MAX_VALUE/2) continue;
                if(dis2[i].size()<=2){
                    dis2[i].add( new int[]{dis[i][j], j});
                }else {
                    for (int k = 0; k < 3; k++) {
                        if(dis2[i].get(k)[0]<=dis[i][j]){
                            dis2[i].add(k, new int[]{dis[i][j], j});
                            break;
                        }
                    }
                    if(dis2[i].size()>3){
                        dis2[i].remove(3);
                    }

                }
                if(dis3[j].size()<=2){
                    dis3[j].add(new int[]{dis[i][j], i});
                }else {
                    for (int k = 0; k < 3; k++) {
                        if(dis3[j].get(k)[0]<dis[i][j]){
                            dis3[j].add(k, new int[]{dis[i][j], i});
                            break;
                        }
                    }
                    if(dis3[j].size()>3){
                        dis3[j].remove(3);
                    }

                }
            }
        }


        int max = 0;
        String ans = "";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(i == j) continue;
                if(dis[i][j] == Integer.MAX_VALUE/2) continue;
                if(dis3[i].size() == 0 || dis2[j].size() == 0) continue;
                for (int k = 0; k < Math.min(dis3[i].size(),3); k++) {
                    for (int l = 0; l < Math.min(dis2[j].size(),3); l++) {
                        int[] f = dis3[i].get(k);
                        int[] to = dis2[j].get(l);
                        if(f[1] != to[1] && f[1]!=j && i!=to[1] && f[0] + to[0] + dis[i][j]>max){
                            max = f[0] + to[0] + dis[i][j];
                            ans = (f[1] +1) + " " + (i+1) + " " + (j+1) +" " + (to[1]+1);
                        }
                    }
                }
            }
        }
        out.println(ans);
    }    
}
