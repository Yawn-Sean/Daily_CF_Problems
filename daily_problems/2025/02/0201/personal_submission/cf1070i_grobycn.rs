//! core logic only
//! submission: https://codeforces.com/problemset/submission/1070/307410908
const MULTIPLE_TEST: bool = true;

fn solver(n: usize, m: usize, k: usize, scanner: &mut Scanner) -> impl Printable {
    let edges: Vec<(usize, usize)> = scanner.iter(m).collect();
    let mut adj = vec![vec![]; n];
    let mut graph = Graph::new(n + m + 2);
    let (src, dst) = (n + m, n + m + 1);
    for (i, &(u, v)) in edges.iter().enumerate() {
        adj[u - 1].push(i);
        adj[v - 1].push(i);
        graph.add_edge(u - 1, n + i, 1);
        graph.add_edge(v - 1, n + i, 1);
        graph.add_edge(n + i, dst, 1);
    }
    let mut tot_flow = 0;
    for (i, edges) in adj.iter().enumerate() {
        let f = edges.len().saturating_sub(k) * 2;
        if f > 0 {
            tot_flow += f;
            graph.add_edge(src, i, f);
        }
    }

    if graph.max_flow(src, dst) != tot_flow {
        return Sep::<_, ' '>(vec![0; m]);
    }

    let mut ans: Vec<_> = (1..=m).collect();
    let mut pairs = vec![None; n];
    for e in graph.edges.iter() {
        if e.from < n && e.to < src && e.flow == 0 {
            let vidx = e.from;
            let eidx = e.to - n;
            if let Some(c) = pairs[vidx].take() {
                ans[eidx] = c;
            } else {
                pairs[vidx] = Some(ans[eidx]);
            }
        }
    }
    Sep::<_, ' '>(ans)
}

struct Edge {
    from: usize,
    to: usize,
    flow: usize,
}

impl Edge {
    fn new(from: usize, to: usize, flow: usize) -> Self {
        Self { from, to, flow }
    }
}

struct Graph {
    edges: Vec<Edge>,
    nodes: Vec<Vec<usize>>,
}

impl Graph {
    fn new(n: usize) -> Self {
        Self {
            edges: vec![],
            nodes: vec![vec![]; n],
        }
    }
    fn add_edge(&mut self, from: usize, to: usize, flow: usize) {
        let eidx = self.edges.len();
        let e = Edge::new(from, to, flow);
        self.edges.push(e);
        self.nodes[from].push(eidx);

        let re = Edge::new(to, from, 0);
        self.edges.push(re);
        self.nodes[to].push(eidx ^ 1);
    }
    fn max_flow(&mut self, src: usize, dst: usize) -> usize {
        let mut flow = 0;
        loop {
            if !self.bfs(src, dst) {
                return flow;
            }
            flow += 1;
        }
    }
    fn bfs(&mut self, src: usize, dst: usize) -> bool {
        let n = self.nodes.len();
        let mut from = vec![usize::MAX; n];
        from[src] = n;
        let mut queue = std::collections::VecDeque::from([src]);
        while let Some(cur) = queue.pop_front() {
            for &eidx in &self.nodes[cur] {
                let e = &self.edges[eidx];
                if e.flow == 0 || from[e.to] != usize::MAX {
                    continue;
                }
                from[e.to] = eidx;
                queue.push_back(e.to);
            }
        }
        if from[dst] == usize::MAX {
            return false;
        }
        let mut cur = dst;
        while cur != src {
            let eidx = from[cur];
            let e = &mut self.edges[eidx];
            e.flow -= 1;
            let re = &mut self.edges[eidx ^ 1];
            re.flow += 1;
            cur = re.to;
        }
        true
    }
}
