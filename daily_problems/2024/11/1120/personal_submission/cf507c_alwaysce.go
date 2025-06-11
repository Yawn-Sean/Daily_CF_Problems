package main

import (
	"bufio"
	. "fmt"
	"io"
)

func cf507C(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	/*
		LRLRLRLR...的序列
		DFS(u, dir)
		这个点在子树内 / 不在子树内
	*/
	var n, h int64
	Fscan(in, &h, &n)

	var dfs func(int64, int64, int64, int64) int64

	dfs = func(l, r, cur, dep int64) int64 {
		if dep == 0 {
			return 0
		}
		ans := int64(0)
		mid := (l + r) / 2
		if (cur == 1 && (n <= mid)) || (cur == 0 && (n > mid)) {
			ans = int64(1) << dep // 额外走这么多
		} else {
			ans = int64(1) // 只需要1步到下一个节点
		}

		if n <= mid {
			ans += dfs(l, mid, 1, dep-1)
		} else {
			ans += dfs(mid+1, r, 0, dep-1)
		}
		return ans
	}

	ans := dfs(int64(1), int64(1)<<h, 0, h)
	Fprintln(out, ans)
}

//func main() {
//	cf507C(bufio.NewReader(os.Stdin), os.Stdout)
//}
