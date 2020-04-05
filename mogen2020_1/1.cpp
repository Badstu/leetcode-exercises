#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'numberOfConnections' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY gridOfNodes as parameter.
 */

int numberOfConnections(vector<vector<int>> gridOfNodes) {
    int n = gridOfNodes.size();
    int m = gridOfNodes[0].size();
    int this_row = 0, last_row = 0;
    int res = 0;
    for(int i = 0; i < n; i++){
        this_row = 0;
        for(int j = 0; j < m; j++){
            if(gridOfNodes[i][j]){
                this_row ++;
            }
        }
        res += (this_row * last_row);

        if(this_row != 0){
            last_row = this_row;
        }
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string gridOfNodes_rows_temp;
    getline(cin, gridOfNodes_rows_temp);

    int gridOfNodes_rows = stoi(ltrim(rtrim(gridOfNodes_rows_temp)));

    string gridOfNodes_columns_temp;
    getline(cin, gridOfNodes_columns_temp);

    int gridOfNodes_columns = stoi(ltrim(rtrim(gridOfNodes_columns_temp)));

    vector<vector<int>> gridOfNodes(gridOfNodes_rows);

    for (int i = 0; i < gridOfNodes_rows; i++) {
        gridOfNodes[i].resize(gridOfNodes_columns);

        string gridOfNodes_row_temp_temp;
        getline(cin, gridOfNodes_row_temp_temp);

        vector<string> gridOfNodes_row_temp = split(rtrim(gridOfNodes_row_temp_temp));

        for (int j = 0; j < gridOfNodes_columns; j++) {
            int gridOfNodes_row_item = stoi(gridOfNodes_row_temp[j]);

            gridOfNodes[i][j] = gridOfNodes_row_item;
        }
    }

    int result = numberOfConnections(gridOfNodes);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}