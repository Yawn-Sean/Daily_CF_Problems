import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class cf1569d_Leoncn {
    static RealFastReader sc = new RealFastReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        int t = sc.ni();
        while (t-- > 0) {
            solve();
        }
        out.close();
    }

    public static void solve() {
        int n = sc.ni();
        int m = sc.ni();
        int k = sc.ni();
        Set<Integer> setX = new HashSet<>();
        Set<Integer> setY = new HashSet<>();
        int[] gX = new int[n];
        int[] gY = new int[m];
        for (int i = 0; i < n; i++) {
            gX[i] = sc.ni();
            setX.add(gX[i]);
        }
        for (int i = 0; i < m; i++) {
            gY[i] = sc.ni();
            setY.add(gY[i]);
        }
        List<int[]> listX = new ArrayList<>();
        List<int[]> listY = new ArrayList<>();

        for (int i = 0; i < k; i++) {
            int a = sc.ni();
            int b = sc.ni();
            if(!setX.contains(a)){
                listX.add(new int[]{a,b});
            }else if(!setY.contains(b)){
                listY.add(new int[]{a,b});
            }
        }
        long ans = 0;
        listX.sort((a,b)->Integer.compare(a[0],b[0]));
        listY.sort((a,b)->Integer.compare(a[1],b[1]));
        Map<Integer, Integer> mapX = new HashMap<>();
        int loc = 0;
        int left = 0;
        for (int i = 0; i < listX.size(); i++) {
            int[] p = listX.get(i);
            mapX.merge(p[1],1, Integer::sum);
            while (loc+1< n && gX[loc+1]<p[0]){
                loc++;
            }
            while (left< listX.size() && listX.get(left)[0]<gX[loc]){
                mapX.merge(listX.get(left)[1],-1, Integer::sum);
                left++;
            }
            ans += i-left+1-mapX.get(p[1]);
        }

        loc = 0;
        left = 0;
        Map<Integer, Integer> mapY = new HashMap<>();
        for (int i = 0; i < listY.size(); i++) {
            int[] p = listY.get(i);
            mapY.merge(p[0],1, Integer::sum);
            while (loc+1< m && gY[loc+1]<p[1]){
                loc++;
            }
            while (left< listY.size() && listY.get(left)[1]<gY[loc]){
                mapY.merge(listY.get(left)[0],-1, Integer::sum);
                left++;
            }
            ans += i-left+1-mapY.get(p[0]);
        }


        out.println(ans);
    }

}
