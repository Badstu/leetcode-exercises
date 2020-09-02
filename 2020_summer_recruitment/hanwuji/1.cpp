class Solution {
public:
    /**
     * return topK string
     * @param strings string字符串vector strings
     * @param k int整型 the k
     * @return string字符串vector<vector<>>
     */
    map<string, int> count;
    priority_queue<int> que;
    
    vector<vector<string> > topKstrings(vector<string>& strings, int k_num) {
        // write code here
        for(int i = 0; i < strings.size(); i++){
            if(count.find(strings[i]) == count.end()){
                count[strings[i]] = 0;
            }
            count[strings[i]] += 1;
        }
        
        for(auto i: count){
            string k = i.first;
            int c = i.second;
            que.push(c);
        }
        
        vector<vector<string>> res;
        while(k_num--){
            int c = que.top();
            res.push_back(find(c));
            que.pop();
        }
        
        return res;
    }
    
    vector<string> find(int c){
        vector<string> tmp;
        for(auto i: count){
            if(i.second == c){
                tmp = {i.first, to_string(i.second)};
                count.erase(i.first);
                break;
            }
        }
        return tmp;
    }
};