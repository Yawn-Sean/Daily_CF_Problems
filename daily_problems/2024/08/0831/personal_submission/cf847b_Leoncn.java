
public class cf847b_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int[] g = sc.na(n);
        List<List<Integer>> ans = new ArrayList<>();
        for(int a: g){
            add(ans, a);
        }
        for(List<Integer> w: ans){
            for(int a: w){
                out.print(a + " ");
            }
            out.println("");
        }
    }
    private static void add(List<List<Integer>> ans, int a){
        int l = 0, r = ans.size();
        while (l<r){
            int mid = l + r >> 1;
            if( ans.get(mid).get(ans.get(mid).size()-1)<a){
                r = mid;
            }else {
                l = mid + 1;
            }
        }
        if(l == ans.size()){
            ans.add(new ArrayList<>());
        }
        ans.get(l).add(a);
    }
}
