class Solution {
public:
    int lastRemaining(int n, int m){
        if(n == 1) return 0; //新编号中只有一个人，0号留下来
        return (lastRemaining(n - 1, m) + m) % n; //通过递推式算出旧编号中谁留下来
    }
};