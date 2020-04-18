class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.empty()) return 0;
        int n = height.size();
        
        int i = 0, j = n - 1;
        int max_area = 0;
        while(i < j){
            int h = min(height[i], height[j]);
            max_area = max(max_area, (j - i) * h);
            if(height[i] <= height[j]){
                i++;
            } else{
                j--;
            }
        }
        return max_area;
    }
};