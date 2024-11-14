#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Entry {
    int r, c, v;
};

int main() {
    int p, q, n;
    cin >> p >> q >> n;
    
    unordered_map<int, unordered_map<int, int>> matrix;
    vector<Entry> entries(n);
    
    for (int i = 0; i < n; i++) {
        cin >> entries[i].r >> entries[i].c >> entries[i].v;
        matrix[entries[i].r][entries[i].c] = entries[i].v;
    }
    
    int start_i, start_j;
    cin >> start_i >> start_j;
    
    vector<int> dr = {1, 0, -1, 0}; // Down, Right, Up, Left row movement
    vector<int> dc = {0, 1, 0, -1}; // Down, Right, Up, Left column movement
    vector<int> dir = {1, 2, 3, 4}; // Direction identifiers
    
    int current_dir = 0, traversed = 0, r = start_i, c = start_j;
    vector<vector<int>> result;

    while (traversed < n) {
        if (matrix.count(r) && matrix[r].count(c)) {
            result.push_back({r, c, matrix[r][c], dir[current_dir]});
            matrix[r].erase(c);
            if (matrix[r].empty()) matrix.erase(r);
            traversed++;
        }
        
        int next_r = r + dr[current_dir];
        int next_c = c + dc[current_dir];
        
        if (!(matrix.count(next_r) && matrix[next_r].count(next_c))) {
            current_dir = (current_dir + 1) % 4;
            next_r = r + dr[current_dir];
            next_c = c + dc[current_dir];
        }
        
        r = next_r;
        c = next_c;
    }
    
    for (auto &entry : result)
        cout << entry[0] << " " << entry[1] << " " << entry[2] << " " << entry[3] << endl;

    return 0;
}
