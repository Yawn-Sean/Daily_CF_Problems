import java.util.HashSet;
import java.util.Set;

public class cf906a_Leoncn {
        public static void solve() {
        int n = sc.ni();
        int ans = 0;
        boolean v = false;
        Set<Character> set = new HashSet<>();
        Set<Character> not = new HashSet<>();
        for (int i = 0; i < n-1; i++) {
            String c = sc.ns();
            char[] s = sc.ns().toCharArray();

            if(c.equals("!")){
                if(v){
                    ans++;
                    continue;
                }
                if(set.isEmpty()){
                    for(char cs: s){
                        if(not.contains(cs)){
                            continue;
                        }
                        set.add(cs);
                    }
                }else {
                    Set<Character> set2 = new HashSet<>();
                    for(char cs: s){
                        if(not.contains(cs)){
                            continue;
                        }
                        if(set.contains(cs)){
                            set2.add(cs);
                        }
                    }
                    set = set2;
                }
            }else if(c.equals(".")){
                for(char cs: s){
                    not.add(cs);
                    set.remove(cs);
                }
            }else {
                if(v ){
                    ans++;
                    continue;
                }
                for(char cs: s){
                    not.add(cs);
                    set.remove(cs);
                }
            }
            if(set.size() == 1 || not.size() == 25){
                v = true;
            }
        }
        out.println(ans);
    }
}
