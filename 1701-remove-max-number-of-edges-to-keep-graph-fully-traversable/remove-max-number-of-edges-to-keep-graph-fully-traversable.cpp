#include <vector>
using namespace std;

class UnionFind {
public:
    UnionFind(int size) : parent(size), rank(size, 0) {
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) {
            return false;
        }
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }

private:
    vector<int> parent;
    vector<int> rank;
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind aliceUF(n + 1);
        UnionFind bobUF(n + 1);
        int removableEdges = 0;
        int aliceEdges = 0;
        int bobEdges = 0;

        // Process type 3 edges first
        for (const auto& edge : edges) {
            if (edge[0] == 3) {
                if (aliceUF.unionSets(edge[1], edge[2])) {
                    bobUF.unionSets(edge[1], edge[2]);
                    aliceEdges++;
                    bobEdges++;
                } else {
                    removableEdges++;
                }
            }
        }

        // Process type 1 and type 2 edges
        for (const auto& edge : edges) {
            if (edge[0] == 1) {
                if (aliceUF.unionSets(edge[1], edge[2])) {
                    aliceEdges++;
                } else {
                    removableEdges++;
                }
            } else if (edge[0] == 2) {
                if (bobUF.unionSets(edge[1], edge[2])) {
                    bobEdges++;
                } else {
                    removableEdges++;
                }
            }
        }

        // Check if both Alice and Bob can traverse the entire graph
        if (aliceEdges != n - 1 || bobEdges != n - 1) {
            return -1;
        }

        return removableEdges;
    }
};
