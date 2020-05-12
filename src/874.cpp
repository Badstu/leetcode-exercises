class Solution {
public:
    typedef pair<int, int> PII;
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<PII> obs_set;
        for(int i = 0; i < obstacles.size(); i++){
            obs_set.insert({obstacles[i][0], obstacles[i][1]});
        }

        int res = 0;
        int x = 0, y = 0;
        int direction = 0;
        for(int i = 0; i < commands.size(); i++){
            int t = commands[i];
            while(t > 0){
                int tx = x + dx[direction];
                int ty = y + dy[direction];
                // cout << tx << " " << ty << endl;
                if(obs_set.find({tx, ty}) != obs_set.end()){
                    break;
                }

                x = tx;
                y = ty;
                res = max(res, x*x+y*y);
                t--;
            }

            if(t == -1){
                direction = (direction + 1) % 4;
            }
            if(t == -2){
                direction = (direction + 4 - 1) % 4;
            }
        }

        return res;
    }
};