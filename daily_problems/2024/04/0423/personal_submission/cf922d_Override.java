
import java.util.*;
import java.io.*;

public class d922 {

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int n = Integer.parseInt(sc.nextLine());
        Segment[] noise = new Segment[n];
        for(int i = 0; i < n; i++){
            String term = sc.nextLine();
            long sCount = 0;
            long hCount = 0;
            for(int j = 0; j < term.length(); j++){
                if(term.charAt(j) == 's')
                    sCount++;
                else
                    hCount++;
            }
            noise[i] = new Segment(term, sCount, hCount);
        }

        Arrays.sort(noise,(q,w)-> Long.compare(w.s * q.h, q.s * w.h));

        long res = 0;
        long cns = 0;
        for(Segment s : noise){
            for(int i = 0; i < s.word.length(); i++){
                if(s.word.charAt(i) == 's')
                    cns++;
                else
                    res += cns;
            }
        }
        System.out.println(res);
    }
}


class Segment {
    public long s;
    public long h;
    public String word;

    public Segment(String w, long s, long h){
        word = w;
        this.s = s;
        this.h = h;
    }
}

