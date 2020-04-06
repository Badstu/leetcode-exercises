#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'rollTheString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER_ARRAY roll
 */

string rollTheString(string s, vector<int> roll) {

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string roll_count_temp;
    getline(cin, roll_count_temp);

    int roll_count = stoi(ltrim(rtrim(roll_count_temp)));

    vector<int> roll(roll_count);

    for (int i = 0; i < roll_count; i++) {
        string roll_item_temp;
        getline(cin, roll_item_temp);

        int roll_item = stoi(ltrim(rtrim(roll_item_temp)));

        roll[i] = roll_item;
    }

    string result = rollTheString(s, roll);

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