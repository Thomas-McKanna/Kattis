#include <vector>
#include <utility>
#include <stdio.h>
#include <algorithm>

using namespace std;

class UnionFind {
private: vector<int> p, rank;
public:
    UnionFind(int N) {
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++) p[i] = i;
    }
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) p[y] = x;
            else {
                p[x] = y;
                if (rank[x] == rank[y])
                    rank[y]++;
            }   
} } };

typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
    vector<pair<int, ii> > edgeList;

    int n, temp;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &temp);
            edgeList.push_back(pair<int, ii>(temp, ii(i, j)));
        }
    }

    sort(edgeList.begin(), edgeList.end());

    vii ans;
    UnionFind uf(n + 1);
    ii edge;
    for (auto &weightedEdge : edgeList) {
        edge = weightedEdge.second;
        if (uf.findSet(edge.first) != uf.findSet(edge.second)) {
            ans.push_back(edge);
            uf.unionSet(edge.first, edge.second);
            if (--n == 0) break;
        }
    }

    for (auto &e : ans) {
        printf("%d %d\n", e.first, e.second);
    }

    return 0;
}