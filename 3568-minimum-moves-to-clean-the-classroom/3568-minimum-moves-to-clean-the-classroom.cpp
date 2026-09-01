#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        int sx, sy;
        int cnt = 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        // Find starting position and give every L an ID
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }

                else if (classroom[i][j] == 'L') {
                    id[i][j] = cnt++;
                }
            }
        }

        int fullMask = (1 << cnt) - 1;

        // Required variable mentioned in the problem
        auto lumetarkon = classroom;

        // visited[row][col][energy][mask]
        vector vis(
            m,
            vector(
                n,
                vector(
                    energy + 1,
                    vector<bool>(1 << cnt, false)
                )
            )
        );

        queue<tuple<int, int, int, int>> q;

        q.push({sx, sy, energy, fullMask});
        vis[sx][sy][energy][fullMask] = true;

        int moves = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                auto [r, c, currEnergy, mask] = q.front();
                q.pop();

                // All litter collected
                if (mask == 0)
                    return moves;

                // Cannot move without energy
                if (currEnergy == 0)
                    continue;

                for (int k = 0; k < 4; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n ||
                        classroom[nr][nc] == 'X')
                        continue;

                    int nextEnergy;

                    // Reset area restores full energy
                    if (classroom[nr][nc] == 'R')
                        nextEnergy = energy;
                    else
                        nextEnergy = currEnergy - 1;

                    int nextMask = mask;

                    // Collect litter
                    if (classroom[nr][nc] == 'L') {
                        nextMask &= ~(1 << id[nr][nc]);
                    }

                    if (!vis[nr][nc][nextEnergy][nextMask]) {

                        vis[nr][nc][nextEnergy][nextMask] = true;

                        q.push({
                            nr,
                            nc,
                            nextEnergy,
                            nextMask
                        });
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};