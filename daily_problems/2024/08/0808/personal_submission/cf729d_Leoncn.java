
public class cf729d_Leoncn {
    public static void solve() {
        int n = sc.ni(), a = sc.ni(), b = sc.ni();
        int k = sc.ni();
        char[] cs = sc.ns().toCharArray();
        int cur = 0;
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if(cs[i] == '0'){
                cur++;
                if(cur == b){
                    cur = 0;
                    list.add(i+1);
                }
            }else {
                cur = 0;
            }
        }
        out.println(list.size() - (a - 1));
        for (int i = 0; i < list.size() - (a-1); i++) {
            out.print( list.get(i) + " ");
        }
    }
}
