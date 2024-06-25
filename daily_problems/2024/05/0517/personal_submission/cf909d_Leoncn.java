public class cf909d_Leoncn {
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
            char[] cs = sc.ns().toCharArray();
            int n = cs.length;
            List<Integer> list = new ArrayList<>();
            List<Character> listC = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                int c = 0;
                int loc = i;
                while (loc<n && cs[i] == cs[loc]){
                    loc++;
                    c++;
                }
                i = loc-1;
                list.add(c);
                listC.add(cs[i]);
            }
            int ans = 0;
            while (list.size()>1){
                List<Integer> tem = new ArrayList<>();
                List<Character> temC = new ArrayList<>();
                int l = list.size();
                for (int i = 0; i < l; i++) {
                    int c = list.get(i);
                    if(c==1 ) continue;
                    if(c==2 && i<l-1 && i>0 ) continue;
                    c = (i==l-1 || i == 0)? c-1:c-2;
                    if(temC.size()>0 && listC.get(i).equals(temC.get(temC.size()-1))){
                        tem.set(tem.size()-1,tem.get(tem.size()-1) + c);
                    }else {
                        tem.add(c);
                        temC.add(listC.get(i));
                    }
                }
                list = tem;
                listC = temC;
                ans ++;
            }
            out.println(ans);
        }
    
}
