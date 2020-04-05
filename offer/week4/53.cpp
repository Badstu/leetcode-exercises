class Solution {
public:
    vector<int> getLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(input.empty()) return res;
        priority_queue<int> heap;
        for(int x: input){
            heap.push(x);
            if(heap.size() > k){
                heap.pop();
            }
        }

        while(heap.size()){
            res.push_back(heap.top());
            heap.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};