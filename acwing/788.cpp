//
// Created by sayhi on 2020/2/15.
//

#include <iostream>

using namespace std;

const int N = 100010;
int n, q[N], tmp[N];

long long count_list(int q[], int l, int r) {
    if (l >= r) return 0;
    int mid = l + r >> 1;
    int i = l, j = mid + 1, k = 0;

    long long count = count_list(q, l, mid) + count_list(q, mid+1, r);

    while (i <= mid && j <= r) {
        if(q[i] <= q[j]) tmp[k++] = q[i++];
        else{
            count += mid - i + 1;
            tmp[k++] = q[j++];
        }
    }
    while(i <= mid) tmp[k++] = q[i++];
    while(j <= r) tmp[k++] = q[j++];

    for(int i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j];

    return count;
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }
    long long m = count_list(q, 0, n - 1);
    cout << m;
    return 0;
}