 private static void solve() {
        int n=sc.nextInt();
        setSize(n);
        TreeMap<Integer,ArrayList<Integer>> map = new TreeMap<>();
        for (int i=0;i<n;i++){
            int h=sc.nextInt();
            if (map.containsKey(h)){
                map.get(h).add(i+1);
            }else{
                ArrayList<Integer> arrayList = new ArrayList<>();
                arrayList.add(i+1);
                map.put(h,arrayList);
            }
        }
        long ans = 0;
        int now = 0;
        while (!map.isEmpty()){
            ArrayList<Integer> list = map.pollFirstEntry().getValue();
            int start = getStartingPos(list,now);
            int listSize = list.size();
            for (int i=0;i<listSize;i++){
                int index = list.get((i+start)%listSize);
                if (index>now){
                    ans+=sum(now+1,index);
                }else{
                    ans+=sum(now+1,n)+sum(1,index);
                }
                modify(index-1);
                now = index;
            }
        }
        pw.print(ans);
    }
