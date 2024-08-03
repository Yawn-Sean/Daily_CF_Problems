import java.util.*;

/**
 * @Description:
 * @Author: Leon
 * @Date: 2024/5/3
 */
public class B {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] g = new int[n];
        Map<Integer,Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            g[i] = sc.nextInt();
            map.merge(g[i],1,Integer::sum);
        }
        Map<Integer,Integer> cnt = new HashMap<>();
        for(int k: map.keySet()){
            cnt.merge(map.get(k), 1, Integer::sum);
        }
        int ans = n;


        for (int i = n-1; i >=0 ; i--) {
            if(cnt.size() == 1){
                for(int k:cnt.keySet()){
                    if(k==1 || cnt.get(k)==1){
                        System.out.println(ans);
                        return;
                    }
                }

            }
            if(cnt.size()==2){
                List<int[]> h = new ArrayList<>();
                for(int k : cnt.keySet()){
                    h.add(new int[]{k, cnt.get(k)});
                }
                h.sort((a,b)->a[0]-b[0]);
                if(h.get(0)[0]+1 == h.get(1)[0] && h.get(1)[1] == 1){
                    System.out.println(ans);
                    return;
                }
                if(h.get(0)[1] == 1 && h.get(0)[0] == 1){
                    System.out.println(ans);
                    return;
                }
            }

            int c = map.get(g[i]);
            map.put(g[i],c-1);
            int w = cnt.get(c);
            if(w==1){
                cnt.remove(c);
            }else{
                cnt.put(c, w-1);
            }
            if(c>1){
                cnt.merge(c-1, 1, Integer::sum);
            }
            ans--;
        }
    }
}
