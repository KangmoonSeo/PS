#include <iostream>
#include <vector>
#define max(x, y) (x > y ? x : y)
#define min(x, y) (x < y ? x : y)
using namespace std;

void dec(int num) {
  int input[3];
  int m_max[2][3]={};
  int m_min[2][3]={};

  bool fl = 0;
  
  for (int i = 0; i < num; i++) {
    cin >> input[0] >> input[1] >> input[2]; // input

    m_max[fl][0] = max(m_max[1-fl][0],m_max[1-fl][1]) + input[0];
		m_max[fl][1] = max(max(m_max[1-fl][0],m_max[1-fl][1]),m_max[1-fl][2]) + input[1];
		m_max[fl][2] = max(m_max[1-fl][1],m_max[1-fl][2]) + input[2];
		
		m_min[fl][0] = min(m_min[1-fl][0],m_min[1-fl][1]) + input[0];
		m_min[fl][1] = min(min(m_min[1-fl][0],m_min[1-fl][1]),m_min[1-fl][2]) + input[1];
		m_min[fl][2] = min(m_min[1-fl][1],m_min[1-fl][2]) + input[2];

    fl=!fl;
  }
  // output
  cout << max(max(m_max[1-fl][0],m_max[1-fl][1]),m_max[1-fl][2]);
  cout << " " << min(min(m_min[1-fl][0],m_min[1-fl][1]),m_min[1-fl][2]);  
}

int main() {
  int n;  
  cin >> n;
  dec(n);  
}