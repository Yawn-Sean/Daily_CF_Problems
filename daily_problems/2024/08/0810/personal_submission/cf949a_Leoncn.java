
public class cf949a_Leoncn {
    public static void solve() {
        char[] cs = sc.ns().toCharArray();
        List<List<Integer>> ans = new ArrayList<>();
        int  p = 0;
        for (int i = 0; i < cs.length; i++) {
            char c = cs[i];
            if(c == '0'){
                if( p == ans.size()){
                    ans.add(new ArrayList<>());
                }
                ans.get(p).add(i+1);
                p++;
            }else {
                if(p == 0){
                    out.println(-1);
                    return;
                }
                p--;
                ans.get(p).add(i+1);
            }
        }
        if(p!= ans.size()){
            out.println(-1);
            return;
        }
        out.println(ans.size());
        for(List<Integer> l: ans){
            out.print(l.size()+ " ");
            for(int a: l){
                out.print(a +" ");
            }
            out.println("");
        }
    }
}
