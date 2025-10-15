import java.io.*;
import java.util.*;

public class Main {
    static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try { 
                    st=new StringTokenizer(br.readLine());				               
                } catch (IOException e) {}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}

    static FastScanner SC = new FastScanner();

    static final long INF = (long) 1e18;

    static class Edge {
        int to, w;

        public Edge(int to, int w){
            this.to = to;
            this.w = w;
        }
    }

    static class Node {
        int id, hashorse;
        long d;

        public Node(int id, int hashorse, long d){
            this.id = id;
            this.hashorse = hashorse;
            this.d = d;
        }
    }

    public static void main(String[] args){

        int T = SC.nextInt();
        while(T-- > 0){
            int n = SC.nextInt();
            int m = SC.nextInt();
            int h = SC.nextInt();
            boolean [] horse = new boolean[n + 1];
            for(int i = 1; i <= h; ++i){
                int x = SC.nextInt();
                horse[x] = true;
            }

            ArrayList <ArrayList <Edge> > adj = new ArrayList <ArrayList <Edge> > (n + 1);
            for(int i = 0; i <= n; ++i) adj.add(new ArrayList <Edge> ());
            for(int i = 1; i <= m; ++i){
                int u = SC.nextInt();
                int v = SC.nextInt();
                int w = SC.nextInt();
                adj.get(u).add(new Edge(v, w));
                adj.get(v).add(new Edge(u, w));
            }

            long[][] d1 = new long[n + 1][2]; // shortest paths sourced at 1
            long[][] d2 = new long[n + 1][2]; // shortest paths sourced at n
            for(int i = 1; i <= n; ++i){
                d1[i][0] = d1[i][1] = d2[i][0] = d2[i][1] = INF;
            }
            {
                PriorityQueue <Node> q = new PriorityQueue <Node> (m * 2 + 1, new Comparator <Node> () {
                    public int compare(Node a, Node b){
                        return Long.compare(a.d, b.d);
                    }
                });
                q.add(new Node(1, 0, 0));
                d1[1][0] = 0;
                boolean[][] vis = new boolean[n + 1][2];
                while(!q.isEmpty()){
                    Node node = q.poll();
                    int cur = node.id, hashorse = node.hashorse;
                    if(vis[cur][hashorse]) continue;
                    vis[cur][hashorse] = true;
                    // i mount a horse
                    if(horse[cur] && hashorse == 0 && d1[cur][0] < d1[cur][1]){
                        d1[cur][1] = d1[cur][0];
                        q.add(new Node(cur, 1, d1[cur][1]));
                    }
                    // i traverse an edge
                    for(Edge e : adj.get(cur)){
                        int to = e.to, w = e.w;
                        if(hashorse == 1) w /= 2;
                        long nd = d1[cur][hashorse] + w;
                        if(nd < d1[to][hashorse]){
                            d1[to][hashorse] = nd;
                            q.add(new Node(to, hashorse, d1[to][hashorse]));
                        }
                    }
                }
            }
            {
                PriorityQueue <Node> q = new PriorityQueue <Node> (m * 2 + 1, new Comparator <Node> () {
                    public int compare(Node a, Node b){
                        return Long.compare(a.d, b.d);
                    }
                });
                q.add(new Node(n, 0, 0));
                d2[n][0] = 0;
                boolean[][] vis = new boolean[n + 1][2];
                while(!q.isEmpty()){
                    Node node = q.poll();
                    int cur = node.id, hashorse = node.hashorse;
                    if(vis[cur][hashorse]) continue;
                    // i mount a horse
                    if(horse[cur] && hashorse == 0 && d2[cur][0] < d2[cur][1]){
                        d2[cur][1] = d2[cur][0];
                        q.add(new Node(cur, 1, d2[cur][1]));
                    }
                    // i traverse an edge
                    for(Edge e : adj.get(cur)){
                        int to = e.to, w = e.w;
                        if(hashorse == 1) w /= 2;
                        long nd = d2[cur][hashorse] + w;
                        if(nd < d2[to][hashorse]){
                            d2[to][hashorse] = nd;
                            q.add(new Node(to, hashorse, d2[to][hashorse]));
                        }
                    }
                }
            }

            long ans = INF;
            for(int i = 1; i <= n; ++i){
                long time = Math.max(Math.min(d1[i][0], d1[i][1]), Math.min(d2[i][0], d2[i][1]));
                if(time < ans){
                    ans = Math.min(ans, time);
                }
            }
            if(ans == INF) ans = -1;
            System.out.println(ans);
            

        }

    }
}