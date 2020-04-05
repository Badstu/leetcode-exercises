class Solution{
public:

    unordered_map<char, int> count;
    queue<int> q;
    //Insert one char from stringstream
    void insert(char ch){
        q.push(ch);
        count[ch]++;

        while(q.size() && count[q.front()] > 1){
            q.pop();
        }
    }
    //return the first appearence once char in current stringstream
    char firstAppearingOnce(){
        if(q.empty()){
            return '#';
        } else{
            return q.front();
        }
    }
};