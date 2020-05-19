// class Solution {
// public:
//     bool validPalindrome(string s) {
// 		if(s.empty()) return true;
		
// 		int i = 0, j = s.size() - 1;
//         int ti, tj;
// 		bool del = false;
// 		while(i < j){
// 			if(s[i] != s[j] && del == false){
//                 // if(lor < 2) ti = i, tj = j, lor = 1;
// 				if(s[i] == s[j - 1]){
//                     ti = i, tj = j - 1;
//                     while(ti < tj && s[ti] == s[tj]){
//                         ti++;
//                         tj--;
//                     }
// 				} else if(s[ti] != s[tj] && s[i + 1] == s[j]){
//                     ti = i + 1, tj = j;
//                     while(ti < tj && s[ti] == s[tj]){
//                         ti++;
//                         tj--;
//                     }
// 				}
//                 if(s[ti] != s[tj]) return false;
// 				del = true;
// 			}

//             if(s[i] == s[j]){
//                 i++;
// 			    j--;
//             }
//             cout << s[i] << " " << s[j] << endl;
// 		}
//         return true;
//     }
// };

class Solution {
public:
	bool checkPalinDrome(string &s, int low, int high){
		int i = low, j = high;
		while(i < j) {
			if(s[i] != s[j]){
				return false;
			} else {
				i++;
				j--;
			}
		}
		return true;
	}

    bool validPalindrome(string s) {
		if(s.empty()) return true;
		for(int i = 0, j = s.size() - 1; i < j; i++, j--){
			if(s[i] != s[j]){
				return checkPalinDrome(s, i + 1, j) || checkPalinDrome(s, i, j-1);
			}
		}
		return true;
    }
};



