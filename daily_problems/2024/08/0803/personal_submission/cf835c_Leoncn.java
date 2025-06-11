//Star Sky
import java.io.*;
import java.util.*;
//Um episode 12
public class C835{
   
   public static void main(String[] args)throws IOException{
      BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
      PrintWriter out = new PrintWriter(System.out);
      
      StringTokenizer st = new StringTokenizer(f.readLine());
      
      int n = Integer.parseInt(st.nextToken());
      int q = Integer.parseInt(st.nextToken());
      int c = Integer.parseInt(st.nextToken());
      
      int N = 100;
      
      int[][][] board = new int[c+1][N+1][N+1];
      
      for(int k = 0; k < n; k++){
         st = new StringTokenizer(f.readLine());
      
         int x = Integer.parseInt(st.nextToken());
         int y = Integer.parseInt(st.nextToken());
         int s = Integer.parseInt(st.nextToken());
         
         board[s][x][y]++;
      }
      
      //2d prefix sums for every s
      int[][][] psums = new int[c+1][N+1][N+1];
      for(int s = 0; s <= c; s++){
         for(int k = 1; k <= N; k++){
            for(int j = 1; j <= N; j++){
               psums[s][k][j] = board[s][k][j] + psums[s][k-1][j] + psums[s][k][j-1] - psums[s][k-1][j-1];
            }
         }
      }
      
      int[] answer = new int[q];
      
      for(int qq = 0; qq < q; qq++){
         st = new StringTokenizer(f.readLine());
      
         int t = Integer.parseInt(st.nextToken());
         int x1 = Integer.parseInt(st.nextToken());
         int y1 = Integer.parseInt(st.nextToken());
         int x2 = Integer.parseInt(st.nextToken());
         int y2 = Integer.parseInt(st.nextToken());
         
         for(int s = 0; s <= c; s++){
            int count = psums[s][x2][y2] - psums[s][x1-1][y2] - psums[s][x2][y1-1] + psums[s][x1-1][y1-1];
            answer[qq] += ((s+t)%(c+1)) * count;
         }
      }
      
      StringJoiner sj = new StringJoiner("\n");
      for(int k = 0; k < q; k++){
         sj.add("" + answer[k]);
      }
      out.println(sj.toString());
      
      
      
      
      
      out.close();
   }
   
      
}
