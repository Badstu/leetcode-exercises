#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/


long countDolphin(int n, int m, vector < int > birthYear, int x) {
	vector <int > olds(m + 10, 0);
	int N = 1e7+10;
	int f[N];
	olds[0] = n;
	f[0] = n;

	for(int i = 1; i <= x; i++){
		int temp = 0;
		olds.insert(olds.begin(), 0);

		int new_birth = 0;
		for(int p_i: birthYear){
			new_birth += olds[p_i];
		}
		olds[0] += new_birth;
		temp += new_birth;

		int new_death = olds[m + 1];
		temp -= new_death;

		// cout << i << endl;
		// for(int x: olds){
		// 	cout << x << " ";
		// }
		// cout << endl;

		f[i] = f[i - 1] + temp;
	}
	
	
	// long res = 0;
	// for(int i = 0; i <= m; i++){
	// 	res += olds[i];
	// }

	return f[x];
}

/******************************结束写代码******************************/


int main() {
    long res;

    int _n;
    cin >> _n;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');


    int _m;
    cin >> _m;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');


    int _birthYear_size = 0;
    cin >> _birthYear_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _birthYear;
    int _birthYear_item;
    for(int _birthYear_i=0; _birthYear_i<_birthYear_size; _birthYear_i++) {
        cin >> _birthYear_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _birthYear.push_back(_birthYear_item);
    }


    int _x;
    cin >> _x;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');


    
    res = countDolphin(_n, _m, _birthYear, _x);
    cout << res;
    
    return 0;

}
