public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        int size = Integer.valueOf(s.split(" ")[0]);
        int time = Integer.valueOf(s.split(" ")[1]);
        int[][] temp = new int[size][];
        for(int i = 0; i < size; i++){
            s = sc.nextLine();
            temp[i] = new int[]{Integer.valueOf(s.split(" ")[0]),Integer.valueOf(s.split(" ")[1]),i+1};
        }
        Arrays.sort(temp,(i1,i2)->{
            if(i1[1] == i2[1]) return i1[0] - i2[0];
            return i1[1] - i2[1];
        });
        int left = 0,right = size;
        List<String> res = null;
        out : while(left <= right){
            List<String> list = new ArrayList<>();
            int mid = (left + right) / 2;
            int sum = 0;
            for(int i = 0; i < size; i++){
                if(list.size() == mid) break;
                if(temp[i][0] < mid) continue;
                list.add(""+temp[i][2]);
                sum += temp[i][1];
                if(sum > time){
                    right = mid - 1;
                    continue out;
                }
            }
            if(list.size() == mid){
                left = mid + 1;
                res = list;
            }else{
                right = mid - 1;
            }
        }
        System.out.println(right);
        System.out.println(res.size());
        System.out.println(String.join(" ",res));
        //System.out.println(maxPossibleScore(new int[]{1000000000,0}, 1000000000));
    }
