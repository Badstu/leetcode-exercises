#include <iostream>
using namespace std;

double calc(Mat &img, int x0, int y0, int k){
    double t = 0;
    int start_x = x0 - k/2, start_y = y0 - k/2;
    int end_x = x0 + k/2, end_y = y0 + k/2;
    for(int i = start_x; i < end_x; i++){
        for(int j = start_y; j < end_y; j++){
            t += img[i][j];
        }
    }
    return t / (k*k);
}

void padding(Mat &img, int k){
    int pad = k/2;
    int n = img.size(), m = img.size();
    int new_H = n + k - 1, new_W = m + k - 1;
}

void mean_filter(Mat &img, int k){
    int n = img.size(0), m = img.size(1); //402*302
    padding(img);
    int start_x = k / 2, start_y = k / 2, end_x = n + k / 2, end_y = m + k / 2;
    for(int i = start_x; i < end_x; i++){
        for(int j = start_y; j < end_y; j++){
            img[i][j] = calc(i, j, k);
        }
    }
}


int main() {
    //int a;
    //cin >> a;
    cout << "Hello World!" << endl;
}