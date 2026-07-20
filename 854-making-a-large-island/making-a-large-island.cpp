class Solution {
public:
    vector<int> parent;
    vector<int> size;

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {

        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent)
            return;

        else if (size[x_parent] > size[y_parent]) {
            parent[y_parent] = x_parent;
            size[x_parent] += size[y_parent];
        }

        else if (size[x_parent] < size[y_parent]) {
            parent[x_parent] = y_parent;
            size[y_parent] += size[x_parent];
        }

        else {
            parent[y_parent] = x_parent;
            size[x_parent] += size[y_parent];
        }
    }

    int largestIsland(vector<vector<int>>& grid) {

        bool allZero = true;
        bool allOne = true;

        int r[4] = {-1, 1, 0, 0};
        int c[4] = {0, 0, 1, -1};

        int m = grid.size();
        int n = grid[0].size();

        parent.resize(m * n);
        size.resize(m * n, 1);

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                int idx = i * n + j;
                parent[idx] = idx;
            }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    allZero = false;
                    for (int k = 0; k < 4; k++) {
                        int ni = i + r[k];
                        int nj = j + c[k];
                        if (ni >= 0 && nj >= 0 && ni < m && nj < n &&
                            grid[ni][nj] == 1)
                            Union(i * n + j, ni * n + nj);
                    }
                } else
                    allOne = false;
            }

        if (allOne)
            return m * n;
        if (allZero)
            return 1;

        int maxArea = 0;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 0) {
                    set<int> s;
                    for (int k = 0; k <= 3; k++) {
                        if (i + r[k] >= 0 && i + r[k] < m && j + c[k] >= 0 &&
                            j + c[k] < n && grid[i + r[k]][j + c[k]] == 1) {
                            int uniqueParent =
                                find((i + r[k]) * n + (j + c[k]));
                            s.insert(uniqueParent);
                        }
                    }
                    int area = 1;
                    for (int a : s) {
                        area += size[a];
                    }
                    maxArea = max(maxArea, area);
                }

        return maxArea;
    }
};