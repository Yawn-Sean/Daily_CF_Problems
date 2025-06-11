import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class cf490e_Leoncn {
        static RealFastReader sc = new RealFastReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        int t = 1;
        while (t-- > 0) {
            solve();
        }
        out.close();
    }

    public static void solve() {
        int n = sc.ni();
        List<char[]> list = new ArrayList<>();
        char[] csPre = new char[]{};
        for (int i = 0; i < n; i++) {
            char[] cs = sc.ns().toCharArray();
            int l = cs.length;
            if( l> csPre.length){
                for (int j = 0; j < l; j++) {
                    if(cs[j] == '?'){
                        if(j == 0){
                            cs[j] = '1';
                        }else {
                            cs[j] = '0';
                        }
                    }
                }
            }else{
                boolean isBig = false;
                int lPre = csPre.length;
                if(l == lPre){
                    for (int j = 0; j <l ; j++) {
                        if(cs[j]!='?'){
                            if(cs[j]>csPre[j]){
                                for (int k = 0; k <j ; k++) {
                                    if(cs[k] == '?'){
                                        cs[k] = csPre[k];
                                    }
                                }
                                for (int k = j+1; k < l; k++) {
                                    if(cs[k] == '?'){
                                        cs[k] = '0';
                                    }
                                }
                                isBig = true;
                                break;
                            }else if(cs[j]<csPre[j]){
                                boolean f1 = false;
                                for (int k = j+1; k < l; k++) {
                                    if(cs[k] == '?'){
                                        cs[k] = '0';
                                    }
                                }
                                for (int k = j-1; k >=0 ; k--) {
                                    if(cs[k] == '?'){
                                        if(f1){
                                            cs[k] = csPre[k];
                                        }else {
                                            if(csPre[k] == '9'){
                                                cs[k] = '0';
                                            }else {
                                                cs[k] = (char) (csPre[k]-'0' + 1 + 48);
                                                f1 = true;
                                            }
                                        }
                                    }
                                }
                                if(!f1){

                                    out.println("NO");
                                    return;
                                }
                                isBig = true;
                                break;
                            }

                        }
                    }
                    if(!isBig){
                        boolean f1 = false;
                        for (int k = l-1;k >=0 ; k--) {
                            if(cs[k] == '?'){
                                if(f1){
                                    cs[k] = csPre[k];
                                }else {
                                    if(csPre[k] == '9'){
                                        cs[k] = '0';
                                    }else {
                                        cs[k] = (char) (csPre[k]-'0' + 1 + 48);
                                        f1 = true;
                                    }
                                }
                            }
                        }
                        if(!f1){
                            out.println("NO");
                            return;
                        }
                    }


                }else {
                    out.println("NO");
                    return;
                }
            }
            csPre = cs;

            list.add(cs);
        }
        out.println("YES");
        for(char[] cs:list){
            out.println(new String(cs));
        }
    }

}
