package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF33B(os.Stdin, os.Stdout) }

func CF33B(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, w int
	var a, b string
	var s, t string
	fmt.Fscan(in, &s, &t, &n)
	mp := make([][]int, 26)
	inf := 256
	for i := 0; i < 26; i++ {
		mp[i] = make([]int, 26)
		for j := 0; j < 26; j++ {
			mp[i][j] = inf
		}
	}

	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a, &b, &w)
		x, y := a[0]-'a', b[0]-'a'
		mp[x][y] = min(mp[x][y], w)
	}

	for i := 0; i < 26; i++ {
		mp[i][i] = 0
	}

	// 三层循环，遍历所有顶点对(i, j)和所有可能的中间顶点k
	for k := 0; k < 26; k++ { // 中间顶点
		for i := 0; i < 26; i++ { // 起始顶点
			for j := 0; j < 26; j++ { // 结束顶点
				// 如果经过顶点k从i到j的路径比当前已知的最短路径更短，则更新最短路径
				if mp[i][k]+mp[k][j] < mp[i][j] {
					mp[i][j] = mp[i][k] + mp[k][j]
				}
			}
		}
	}

	if len(s) != len(t) {
		fmt.Fprintf(out, "-1")
		return
	}
	ansCount := 0
	ans := make([]uint8, len(s))
	for i := 0; i < len(s); i++ {
		v := inf
		var cr int
		if s[i] != t[i] {
			x, y := s[i]-'a', t[i]-'a'
			for j := 0; j < 26; j++ {
				if v > mp[x][j]+mp[y][j] {
					v = mp[x][j] + mp[y][j]
					cr = j
				}
			}
			if v == inf {
				fmt.Fprintf(out, "-1")
				return
			}
			ansCount += v
			ans[i] = uint8(97 + cr)
		} else {
			ans[i] = s[i]
		}
	}
	fmt.Fprintf(out, "%d\n%s", ansCount, ans)
}
