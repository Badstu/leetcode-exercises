class Solution {
public:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int> max_heap;

    void insert(int num){
        max_heap.push(num);

        if(!min_heap.empty() && max_heap.top() > min_heap.top()){
            int min_v = min_heap.top(), max_v = max_heap.top();
            min_heap.pop(), max_heap.pop();
            min_heap.push(max_v), max_heap.push(min_v);
        }

        if(max_heap.size() > min_heap.size() + 1){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
    }

    double getMedian(){
        if((min_heap.size() + max_heap.size()) & 1){
            return max_heap.top();
        } else{
            return (max_heap.top() + min_heap.top()) / 2.0;
        }
    }
};

