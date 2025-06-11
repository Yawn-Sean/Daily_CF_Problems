package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { solveB(os.Stdin, os.Stdout) }

func solveB(_r io.Reader, _w io.Writer) {
	in, out := bufio.NewReader(_r), bufio.NewWriter(_w)
	defer out.Flush()

	var s, t, a, b []byte
	var m, w int
	fmt.Fscan(in, &s, &t, &m)

	if len(s) != len(t) {
		fmt.Fprintln(out, -1)
		return
	}

	dis := [26][26]int{}
	for i := 0; i < 26; i++ {
		for j := 0; j < 26; j++ {
			if i != j {
				dis[i][j] = 1e9
			}
		}
	}

	for i := 0; i < m; i++ {
		fmt.Fscan(in, &a, &b, &w)
		x, y := int(a[0]-'a'), int(b[0]-'a')
		dis[x][y] = min(dis[x][y], w)
	}

	// floyd
	for k := 0; k < 26; k++ {
		for i := 0; i < 26; i++ {
			for j := 0; j < 26; j++ {
				dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j])
			}
		}
	}

	ans := 0
	for i, v := range s {
		if v != t[i] {
			ds, dt := dis[v-'a'], dis[t[i]-'a']
			mn, mni := int(1e9), 0
			// 注意s, t可能都变到其他的字母
			for j := 0; j < 26; j++ {
				if ds[j]+dt[j] < mn {
					mn, mni = ds[j]+dt[j], j
				}
			}
			ans += mn
			s[i] = 'a' + byte(mni)
		}
	}

	if ans >= 1e9 {
		fmt.Fprintln(out, -1)
	} else {
		fmt.Fprintf(out, "%d\n%s\n", ans, s)
	}
}
