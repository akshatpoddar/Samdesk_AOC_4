#include <iostream>
using namespace std; 

int check_xmas(const vector<string>& grid, int i, int j, const string& target, int d1, int d2){
  for(int k=1; k<target.size(); k++){
    i += d1;
    j += d2;
    if (i<0 || j<0 || i>=grid.size()|| j>=grid[0].size()) return 0;
    if (grid[i][j] != target[k]) return 0;
  }
  return 1;
}


int main(){
  vector<string> lines;
  string line;
  while(getline(cin, line) && !line.empty()){
    lines.push_back(line);
  }
  int m = lines.size();
  int n = lines[0].length();

  int count = 0;
  string target = "XMAS";
  int dirs[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      if (lines[i][j] == 'X'){
        for(int k=0; k<8; k++){
          count += check_xmas(lines, i, j, target, dirs[k][0], dirs[k][1]);
        }
      } 
    }
  }
  cout << count;
  return count;
}
