#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> edges;
    vector<int> indegree;
    int visited = 0;
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        indegree.resize(numCourses);

        for(int i = 0; i < prerequisites.size(); i++){
            vector<int> info = prerequisites[i];
            edges[info[1]].push_back(info[0]);
            indegree[info[0]] ++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            visited += 1;
            int t = q.front();
            q.pop();
            for(int v: edges[t]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }

        return visited == numCourses;
    }

};
// @lc code=end

