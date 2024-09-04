class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Direction vectors for North, East, South, West
        // vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int x = 0, y = 0; 
        int dir1 = 0; 
        set<pair<int, int>> st;
        for (const auto& obstacle : obstacles) {
            st.insert({obstacle[0], obstacle[1]});
        }

        int maxDist = 0;
        pair<int, int> dir = {0,1}; //North
        for (int cmd : commands) {
            if (cmd == -1) {
                dir = {dir.second, -dir.first}; // Right 90 degrees
            } 
            else if (cmd == -2) {
                dir = {-dir.second, dir.first}; // Left 90 degrees
            } 
            else {
                for (int step = 0; step < cmd; ++step) {
                    int newX = x + dir.first;
                    int newY = y + dir.second;
                    // agar mil gya to uske pehle wala
                    if (st.find({newX, newY}) != st.end()) {
                        break;
                    
                    }
                    // warna update
                    else {
                        x = newX;
                        y = newY;
                        maxDist = max(maxDist, x*x  + y*y);
                    }
                }
            }
        }
        return maxDist;
    }
};

/*
if (cmd == -1) {
    dir1 = (dir1 + 1) % 4;
} 
else if (cmd == -2) {
    dir1 = (dir1 + 3) % 4; 
}

int nx = x + directions[dir].first;
int ny = y + directions[dir].second;
*/