/*
 * 线段树（区间加 + 区间求和）
 * Time: O(log n) per query/update  Space: O(4n)
 *
 * 功能：
 *   1. 区间加：[l, r] 每个元素 +val
 *   2. 区间求和：查询 [l, r] 的元素之和
 *
 * 关键步骤：
 *   - pushup：子节点信息合并到父节点
 *   - pushdown：懒标记下传给子节点（区间修改的核心）
 *
 * 编译：g++ -std=c++17 -O2 -o segment_tree segment_tree.cpp
 */

#include <iostream>
using namespace std;

const int MAXN = 1e5 + 10;
int n, m;
long long a[MAXN];

long long tree[4 * MAXN];
long long lazy[4 * MAXN];

void pushup(int p) {
    tree[p] = tree[2 * p] + tree[2 * p + 1];
}

void pushdown(int p, int len) {
    if (lazy[p]) {
        int left = len - len / 2, right = len / 2;
        tree[2 * p] += lazy[p] * left;
        lazy[2 * p] += lazy[p];
        tree[2 * p + 1] += lazy[p] * right;
        lazy[2 * p + 1] += lazy[p];
        lazy[p] = 0;
    }
}

void build(int p, int l, int r) {
    if (l == r) { tree[p] = a[l]; return; }
    int mid = (l + r) / 2;
    build(2 * p, l, mid);
    build(2 * p + 1, mid + 1, r);
    pushup(p);
}

void update(int p, int l, int r, int ul, int ur, long long val) {
    if (ul <= l && r <= ur) {
        tree[p] += val * (r - l + 1);
        lazy[p] += val;
        return;
    }
    pushdown(p, r - l + 1);
    int mid = (l + r) / 2;
    if (ul <= mid) update(2 * p, l, mid, ul, ur, val);
    if (ur > mid)  update(2 * p + 1, mid + 1, r, ul, ur, val);
    pushup(p);
}

long long query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return tree[p];
    pushdown(p, r - l + 1);
    int mid = (l + r) / 2;
    long long res = 0;
    if (ql <= mid) res += query(2 * p, l, mid, ql, qr);
    if (qr > mid)  res += query(2 * p + 1, mid + 1, r, ql, qr);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);

    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int l, r; long long k;
            cin >> l >> r >> k;
            update(1, 1, n, l, r, k);
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << "\n";
        }
    }
    return 0;
}
