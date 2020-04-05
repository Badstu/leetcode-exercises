class Solution {
public:
    bool verifySequenceOfBST(vector<int> sequence) {
        int n = sequence.size();
        return isTree(sequence, 0, n - 1);
    }

    bool isTree(vector<int> &s, int l, int r){
        if(l >= r) return true;
        int root = s[r];
        int k = l;
        while(k < r && s[k] < root){
            k++;
        }

        for(int i = k; i <= r - 1; i++){
            if(s[i] < root) return false;
        }

        return isTree(s, l, k - 1) && isTree(s, k, r - 1);;
    }

};