
public class cf1243b2_Leoncn {
    static List<String> list;
    public static void solve() {
        int n = sc.ni();
        char[] cs = sc.ns().toCharArray();
        char[] tar = sc.ns().toCharArray();

        list = new ArrayList<>();
        out:for (int i = 0; i < n; i++) {
            if(cs[i] == tar[i]){
                continue;
            }
            if(cs[i] != tar[i]){
                for (int j = i+1; j <n ; j++) {
                    if(cs[j] == cs[i]){
                        char c = cs[j];
                        cs[j] = tar[i];
                        tar[i] = c;
                        list.add((j+1) + " " + (i+1));
                        continue out;
                    }
                }
                for (int j = i+1; j < n; j++) {
                    if(tar[j] == cs[i]){
                        char c = cs[n-1];
                        cs[n-1] = tar[j];
                        tar[j] = c;
                        list.add((n) + " " + (j+1));


                        c = cs[n-1];
                        cs[n-1] = tar[i];
                        tar[i] = c;
                        list.add((n) + " " + (i+1));
                        continue  out;
                    }
                }
                out.println("NO");
                return;
            }
        }
        out.println("YES");
        out.println(list.size());
        for(String l: list){
            out.println(l);
        }
    }

}
