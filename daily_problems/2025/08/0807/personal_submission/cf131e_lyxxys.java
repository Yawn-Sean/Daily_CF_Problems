    public static void solve(){
        int n = sc.nextInt(), m = sc.nextInt();
        int xs[] = new int[m];
        int ys[] = new int[m];
        List<Integer> idxList = new ArrayList<>();
        for (int i = 0; i < m; ++ i){
            xs[i] = sc.nextInt()-1;
            ys[i] = sc.nextInt()-1;
            idxList.add(i);
        }
        List<Integer> collect = idxList.stream().sorted((i, j) -> {
            return Integer.compare(xs[i], xs[j]) != 0 ? Integer.compare(xs[i], xs[j])
                    : Integer.compare(ys[i], ys[j]);
        }).collect(Collectors.toList());
 
        int B1[] = new int[n];
        int B2[] = new int[n];
        int B3[] = new int[2*n];
        int B4[] = new int[2*n];
        for (int i = 0; i < 2*n; ++ i){
            if (i < n){
                B1[i] = B2[i] = -1;
            }
            B3[i] = B4[i] = -1;
        }
 
        int idxCount[] = new int[m];
        int res[] = new int[9];
 
        for (int i = 0; i < m; ++ i){
            int idx = collect.get(i);
            int x = xs[idx], y = ys[idx];
            if (B1[x] != -1){
                int j = B1[x];
                idxCount[j] += 1;
                idxCount[idx] += 1;
            }
            if (B2[y] != -1){
                int j = B2[y];
                idxCount[j] += 1;
                idxCount[idx] += 1;
            }
            if (B3[x-y+n-1] != -1){
                int j = B3[x-y+n-1];
                idxCount[j] += 1;
                idxCount[idx] += 1;
            }
            if (B4[x+y] != -1){
                int j = B4[x+y];
                idxCount[j] += 1;
                idxCount[idx] += 1;
            }
 
            B1[x] = idx;
            B2[y] = idx;
            B3[x-y+n-1] = idx;
            B4[x+y] = idx;
        }
 
        Arrays.stream(idxCount).forEach(count -> res[count] += 1);
        out.println(String.join(" ", Arrays.stream(res).mapToObj(String::valueOf).collect(Collectors.toList())));
    }
