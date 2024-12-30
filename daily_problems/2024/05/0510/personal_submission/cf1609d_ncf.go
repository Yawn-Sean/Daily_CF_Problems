func main() { CF1609D(os.Stdin, os.Stdout) }

func CF1609D(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, d, x, y int
	fmt.Fscan(in, &n, &d)
	set := makeSet1609d(n)
	mx := 0
	count := 1
	for i := 0; i < d; i++ {
		fmt.Fscan(in, &x, &y)
		x, y = x-1, y-1
		fa1, fa2 := find1609d(x, set), find1609d(y, set)
		if fa1 != fa2 {
			union1609d(x, y, set)
		} else {
			count += 1
		}
		m := map[int]bool{}
		var arr []int
		for j := 0; j < n; j++ {
			fa := find1609d(j, set)
			if !m[fa] {
				arr = append(arr, set.size[fa])
				m[fa] = true
			}
		}
		sort.Slice(arr, func(i, j int) bool {
			return arr[i] > arr[j]
		})
		cur := 0
		for j := 0; j < count; j++ {
			cur += arr[j]
		}
		mx = max(mx, cur)
		fmt.Fprintf(out, "%d\n", mx-1)
	}
}

type DisjointSet1609d struct {
	parent []int // 父节点数组
	rank   []int // 节点秩数组
	size   []int // 大小
}

func makeSet1609d(n int) *DisjointSet1609d {
	ds := &DisjointSet1609d{
		parent: make([]int, n),
		rank:   make([]int, n),
		size:   make([]int, n),
	}
	for i := 0; i < n; i++ {
		ds.parent[i] = i
		ds.rank[i] = 1 // 初始化每个集合的秩为1
		ds.size[i] = 1
	}
	return ds
}

// 将递归的find()函数改为迭代形式
func find1609d(x int, ds *DisjointSet1609d) int {
	var root int = x
	for root != ds.parent[root] {
		root = ds.parent[root]
	}

	// 路径压缩：将x到root路径上的所有节点直接指向root
	for x != root {
		next := ds.parent[x]
		ds.parent[x] = root
		x = next
	}

	return root
}

func union1609d(a, b int, ds *DisjointSet1609d) {
	fa, fb := find1609d(a, ds), find1609d(b, ds)
	if fa != fb {
		if ds.rank[fa] > ds.rank[fb] {
			ds.parent[fb] = fa
			ds.size[fa] += ds.size[fb]
		} else if ds.rank[fa] < ds.rank[fb] {
			ds.parent[fa] = fb
			ds.size[fb] += ds.size[fa]
		} else { // 当两者秩相等时，将秩较小的集合赋给较大的集合，并将秩+1
			ds.parent[fb] = fa
			ds.size[fa] += ds.size[fb]
			ds.rank[fa]++
		}
	}
}
