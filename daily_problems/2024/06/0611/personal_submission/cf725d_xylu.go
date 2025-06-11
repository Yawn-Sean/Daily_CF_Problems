package main

import (
	"bufio"
	"container/heap"
	"fmt"
	"io"
	"os"
	"slices"
)

func main() { solveD(os.Stdin, os.Stdout) }

type pair struct{ x, y int }

func solveD(_r io.Reader, _w io.Writer) {
	in, out := bufio.NewReader(_r), bufio.NewWriter(_w)
	defer out.Flush()

	var n, mt, mw int
	fmt.Fscan(in, &n, &mt, &mw)
	b := make([]pair, n) // 最后 {0,0} 当作哨兵
	for i := 0; i < n-1; i++ {
		fmt.Fscan(in, &b[i].x, &b[i].y)
	}
	slices.SortFunc(b, func(i, j pair) int { return j.x - i.x })
	h := hp{}
	ans := n
	for _, v := range b {
		for mt >= v.x {
			ans = min(ans, len(h)+1)
			if len(h) == 0 {
				break
			}
			// 考虑将气球送给起飞所需最少的队伍
			mt -= heap.Pop(&h).(int)
		}
		heap.Push(&h, v.y-v.x+1)
	}
	fmt.Fprintln(out, ans)
}

type hp []int

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i] < h[j] }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(x any)        { *h = append(*h, x.(int)) }
func (h *hp) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
