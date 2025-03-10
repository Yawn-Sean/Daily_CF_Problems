struct Trie
{
  struct node
  {
    int cnt, used, val;
    vector<node *> son;
    node() : cnt(0), used{0}, val{0} { son = vector<node *>(2); }
  };

  node *root;

  Trie() : root{new node()} {}

  void insert(int n)
  {
    node *cur = root;
    Rof1(i, 0, 29)
    {
      int id = ((n >> i) & 1);
      if (!cur->son[id])
      {
        cur->son[id] = new node();
      }
      cur = cur->son[id];
      cur->used++;
    }
    cur->cnt++;
    cur->val = n;
  }

  int search(int n)
  {
    node *cur = root;
    Rof1(i, 0, 29)
    {
      int id = ((n >> i) & 1);
      if (cur->son[id] != nullptr && cur->son[id]->used > 0)
      {
        cur = cur->son[id];
      }
      else if (cur->son[id ^ 1] && cur->son[id ^ 1]->used)
      {
        cur = cur->son[id ^ 1];
      }
      cur->used--;
    }
    cur->cnt--;
    return cur->val;
  }
};

void solve()
{
  int n;
  cin >> n;

  VI a(n + 1), p(n + 1);
  cin >> a >> p;

  VI ans(1);
  Trie tree;

  For1(i, 1, n) { tree.insert(p[i]); }
  For1(i, 1, n) { ans.pb(tree.search(a[i]) ^ a[i]); }
  cout << ans;
}
