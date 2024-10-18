public class cf1138b_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int[][] num = new int[n+1][3];
        char[] cs = sc.ns().toCharArray();
        char[] tar = sc.ns().toCharArray();
        int sum =0;
        int sum0 = 0,sum1 =0 ,sum2 = 0,cnt0 =0,cnt1 =0;
        for (int i = 0; i < n; i++) {
            int x = cs[i] -'0';
            int y = tar[i] - '0';
            sum += y;
            if(x+y==0) num[++sum0][0]=i;
            if(x+y==1) num[++sum1][1]=i;
            if(x+y==2) num[++sum2][2]=i;
        }
        n>>=1;
        StringBuilder sb = new StringBuilder();
        for(int cnt2=0;cnt2<=sum2;cnt2++){
            cnt1=sum-(cnt2<<1);
            cnt0=n-cnt1-cnt2;
            if(cnt1>sum1 || cnt0>sum0 || cnt1<0 || cnt0<0 || cnt2>sum2 || cnt2<0 || cnt0>n || cnt1>n || cnt2>n) continue;
            for( int i=1;i<=cnt0;i++) sb.append(num[i][0]+1).append(" ");
            for( int i=1;i<=cnt1;i++) sb.append(num[i][1]+1).append(" ");
            for( int i=1;i<=cnt2;i++) sb.append(num[i][2]+1).append(" ");
            out.println(sb);
            return;
        }
        out.println(-1);

    }
}
