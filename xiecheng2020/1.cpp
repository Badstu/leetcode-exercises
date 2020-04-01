#include <iostream>

using namespace std;

int cords[8];

int main(){
	for(int i = 0; i < 8; i++){
		cin >> cords[i];
	}

	int top1 = cords[0];
	int left1 = cords[1];
	int bottom1 = cords[2];
	int right1 = cords[3];
	int top2 = cords[4];
	int left2 = cords[5];
	int bottom2 = cords[6];
	int right2 = cords[7];

	int left_max = max(left1, left2);
	int right_min = min(right1, right2);
	int top_max = max(top1, top2);
	int bottom_min = min(bottom1, bottom2);
	
	double s1 = (right1 - left1) * (bottom1 - top1);
	double s2 = (right2 - left2) * (bottom2 - top2);
	double score;
	if(left_max >= right_min || top_max >= bottom_min){
		printf("%.4lf", 0.0000);
		return 0;
	} 
	else if((right2 >= right1 && left2 <= left1 && top2 <= top1 && bottom2 >= bottom1) || (right2 <= right1 && left2 >= left1 && top2 >= top1 && bottom2 <= bottom1)){
		score = min(s1, s2) / max(s1, s2);
	} else{
		double sj = (right_min - left_max) * (bottom_min - top_max);
		score = sj / (s1 + s2 - sj);
	}

	printf("%.4lf", score);


	return 0;
}