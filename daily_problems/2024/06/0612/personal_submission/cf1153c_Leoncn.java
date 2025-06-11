public class cf1153c_Leoncn {

    public static void solve() {
        int n = sc.ni();
        char[] cs = sc.ns().toCharArray();
        if((n&1)==1){
            out.println(":(");
            return;
        }
        int c = 0;
        for (int i = 0; i < n; i++) {
            if(cs[i] == '('){
                c++;
            }
        }
        if(c>n/2){
            out.println(":(");
            return;
        }
        int l= 0, r = 0;
        for (int i = 0; i < n; i++) {
            if(cs[i] == '('){
                l++;
            }else if(cs[i] == ')'){
                r++;
            }else {
                if(c!=n/2){
                    cs[i] = '(';
                    l++;
                    c++;
                }else {
                    cs[i] =')';
                    r++;
                }
            }
            if(i!=n-1 && l <= r){
                out.println(":(");
                return;
            }
        }
        out.println(new String(cs));

    }    
}
