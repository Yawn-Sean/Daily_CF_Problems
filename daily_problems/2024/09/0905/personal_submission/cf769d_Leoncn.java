public static void solve() {
    int n = sc.ni();
    int k = sc.ni();
    int[] g = sc.na(n);
    int max = 1<<14;
    int[] cnt = new int[max];
    for(int w: g){
        cnt[w]++;
    }
    long ans = 0;
    if(k == 0){
        for(int w: cnt){
            ans += (long)(w-1)*w/2;
        }
    }else {
        List<Integer> list = new ArrayList<>();
        for (int i = 1; i < max; i++) {
            if(Integer.bitCount(i)==k){
                list.add(i);
            }
        }
        for (int i = 0; i < max; i++) {
            for(int l: list){
                ans +=  (long)cnt[i] * cnt[i^l];
            }

        }

        ans/=2;
    }
    out.println(ans);

}