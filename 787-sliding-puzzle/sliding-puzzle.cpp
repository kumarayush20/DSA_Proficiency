// BFS

vector<vector<char>> adj = {{1, 3}, {0, 2, 4}, {1, 5},
                            {0, 4}, {1, 3, 5}, {2, 4}};
using info=pair<string, char>;
class Solution {
public:
    static int slidingPuzzle(vector<vector<int>>& board) {
        string target = "123450";
        string start(6, '-');
        char pos0=-1;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 3; j++){
                int index=i*3+j;
                start[index]= board[i][j]+'0';
                if (board[i][j]==0) pos0=index;
            }
        if (start == target)
            return 0;

        unordered_set<string> viz;
        viz.reserve(720);
        queue<info> q;
        q.emplace(start, pos0);
       
        for (int move= 0; !q.empty();  move++) {
            int qz = q.size();
            for (int i = 0; i < qz; i++) {
                auto [t, p0] = q.front();
            //    cout<<t<<" p0="<<int(p0)<<endl;
                q.pop();
                if (t == target)
                        return move;
                for (char p : adj[p0]) {
                    string s = t;
                    swap(s[p0], s[p]);
                    
                    if (viz.count(s))
                        continue;
                    q.emplace(s, p);
                    viz.insert(s);
                }
            }
        }
        return -1;
    }
};



auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();