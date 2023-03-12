#include <iostream>
#include <vector>
#define max(x, y) (x > y ? x : y)
#define min(x, y) (x < y ? x : y)
using namespace std;

void dec(int num) {
  int input[3];
  int tmp_max[2][3]={};
  int tmp_min[2][3]={};

  bool fl = 0;
  
  for (int i = 0; i < num; i++) {
    cin >> input[0] >> input[1] >> input[2];

    tmp_max[fl][0] = max(tmp_max[1-fl][0],tmp_max[1-fl][1]) + input[0];
		tmp_max[fl][1] = max(max(tmp_max[1-fl][0],tmp_max[1-fl][1]),tmp_max[1-fl][2]) + input[1];
		tmp_max[fl][2] = max(tmp_max[1-fl][1],tmp_max[1-fl][2]) + input[2];
		
		tmp_min[fl][0] = min(tmp_min[1-fl][0],tmp_min[1-fl][1]) + input[0];
		tmp_min[fl][1] = min(min(tmp_min[1-fl][0],tmp_min[1-fl][1]),tmp_min[1-fl][2]) + input[1];
		tmp_min[fl][2] = min(tmp_min[1-fl][1],tmp_min[1-fl][2]) + input[2];

    fl=!fl;
  }
  // output
  cout << max(max(tmp_max[1-fl][0],tmp_max[1-fl][1]),tmp_max[1-fl][2]);
  cout << " " << min(min(tmp_min[1-fl][0],tmp_min[1-fl][1]),tmp_min[1-fl][2]);  
}

int main() {
  int n;  // arr
  cin >> n;

  dec(n);  // output
}