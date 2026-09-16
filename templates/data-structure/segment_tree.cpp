/*
 * 线段树模板（区间加 + 区间求和）
 * 时间复杂度：建树 O(n)，查询/修改 O(log n)
 * 空间复杂度：O(4n)
 *
 * 支持操作：
 *   1. 区间加：给 [l, r] 每个元素加上 val
 *   2. 区间求和：查询 [l, r] 的元素之和
 *
 * 编译：g++ -std=c++17 -O2 -o segment_tree segment_tree.cpp
 */

#include <iostream>
using namespace std;

const int MAXN = 1e5 + 10;

int n, m;
long long a[MAXN];

// 线段树数组
long long tree[4 * MAXN];  // 区间和
long long lazy[4 * MAXN];  // 懒标记（区间加的值）

// 向上合并
void pushup(int p) {
    tree[p] = tree[2 * p] + tree[2 * p + 1];
}

// 下传懒标记
void pushdown(int p, int len) {
    if (lazy[p]) {
        // 左子节点
        tree[2 * p] += lazy[p] * (len - len / 2);
        lazy[2 * p] += lazy[p];
        // 右子节点
        tree[2 * p + 1] += lazy[p] * (len / 2);
        lazy[2 * p + 1] += lazy[p];
        // 清除当前节点标记
        lazy[p] = 0;
    }
}

// 建树：p=节点编号，[l, r]=管辖区间
void build(int p, int l, int r) {
    lazy[p] = 0;
    if (l == r) {
        tree[p] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * p, l, mid);
    build(2 * p + 1, mid + 1, r);
    pushup(p);
}

// 区间加：将 [ul, ur] 每个元素加 val
void update(int p, int l, int r, int ul, int ur, long long val) {
    if (ul <= l && r <= ur) {
        // 完全覆盖，直接修改
        tree[p] += val * (r - l + 1);
        lazy[p] += val;
        return;
    }
    pushdown(p, r - l + 1);  // 下传标记
    int mid = (l + r) / 2;
    if (ul <= mid) update(2 * p, l, mid, ul, ur, val);
    if (ur > mid)  update(2 * p + 1, mid + 1, r, ul, ur, val);
    pushup(p);
}

// 区间求和：查询 [ql, qr] 的和
long long query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        return tree[p];
    }
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

    build(1, 1, n);  // 从节点1开始建树，管辖 [1, n]

    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            // 区间加
            int l, r;
            long long k;
            cin >> l >> r >> k;
            update(1, 1, n, l, r, k);
        } else {
            // 区间求和
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << "\n";
        }
    }

    return 0;
}
