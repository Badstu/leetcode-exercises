#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;

#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
int main(){
    double A,B,C;

    int n;
    cin >> n;
    while(n--){
        cin >> A >> B >> C;
        double x2,x3,y2,y3;
        x2 = (2*(A-B*C)+sqrt(4*A*A-8*A*B*C))/2*B*B;
        x3 = (2*(A-B*C)-sqrt(4*A*A-8*A*B*C))/2*B*B;
        y2 = B*x2 + C;
        y3 = B*x3 + C;
//        double s = -(y2)/pow(x2, 2)*pow(x3-x2, 3)/6;
        double s = -(x2)/pow(y2, 2)*pow(y3-y2, 3)/6;
        printf("%.10lf\n",s);
    }

}