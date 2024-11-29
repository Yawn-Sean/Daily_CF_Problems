package main

import (
	"bufio"
	"fmt"
	"io"
)

func cf700B(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	/*
		考虑每条边能被走过几次
		(u,v)边分割 cx,cy个点
		则这条边最多贡献min(cx,cy)次
		能否保证每条边都取最大? 可以
	*/

	var n, k int
	fmt.Fscan(in, &n, &k)

	flg := make([]int, n)
	for i := 0; i < 2*k; i++ {
		var tmp int
		fmt.Fscan(in, &tmp)
		tmp--
		flg[tmp] = 1
	}

	path := make([][]int, n)
	for i := 1; i < n; i++ {
		var u, v int
		fmt.Fscan(in, &u, &v)
		u--
		v--
		path[u] = append(path[u], v)
		path[v] = append(path[v], u)
	}
	ans := int64(0)

	var dfs func(int, int) int
	dfs = func(u, fa int) (res int) {
		res = flg[u]
		for _, v := range path[u] {
			if v != fa {
				res += dfs(v, u)
			}
		}
		ans += int64(min(res, 2*k-res))
		return res
	}
	dfs(0, -1)
	fmt.Fprintln(out, ans)
}

//func main() {
//	cf700B(bufio.NewReader(os.Stdin), os.Stdout)
//}
