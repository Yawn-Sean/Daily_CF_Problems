package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
	"strconv"
)

func solveD(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n, k int
	Fscan(in, &n, &k)
	a := make([]int, n)
	for i := range a {
		Fscan(in, &a[i])
	}
	ans := 0
	cnt := map[int]int{}
	for i, j := 1, 10; i <= 10; i, j = i+1, j*10%k {
		clear(cnt)
		for _, v := range a {
			cnt[v*j%k]++
		}
		for _, v := range a {
			if len(strconv.Itoa(v)) == i {
				cnt[v*j%k]-- // 避免自己和自己匹配
				ans += cnt[(k-v%k)%k]
				cnt[v*j%k]++
			}
		}
	}
	Fprintln(out, ans)
}

func main() {
	solveD(os.Stdin, os.Stdout)
}
