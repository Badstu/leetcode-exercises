#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'getIdealNums' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. LONG_INTEGER low
 *  2. LONG_INTEGER high
 */
typedef long long LL;

long getIdealNums(long low, long high) {
    vector<LL> q;

    int i = 0, j = 0;
    q.push_back(1);
    while(q.back() < high){
        LL t = min(q[i] * 3, q[j] * 5);
        q.push_back(t);
        if(t == q[i] * 3) i++;
        if(t == q[j] * 5) j++;
    }
    
    // cout << q.size() << endl;

    long res = 0;
    for(int x: q){
        // cout << x << endl;
        if(x < low) continue;
        if(x > high) continue;
        res ++;
    }

    cout << res << endl;
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string low_temp;
    getline(cin, low_temp);

    long low = stol(ltrim(rtrim(low_temp)));

    string high_temp;
    getline(cin, high_temp);

    long high = stol(ltrim(rtrim(high_temp)));

    long result = getIdealNums(low, high);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
