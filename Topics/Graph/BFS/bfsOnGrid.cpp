#include<bits/stdc++.h>

#define checkCell(row, col) (row >= 0 and row < 10 and col >= 0 and col < 10)

using namespace std;

const int fx[] = {1,-1, 0, 0};
const int fy[] = {0, 0, 1, -1};


int d[10][10]; // distance array
int row, col;

void bfs(int sx, int sy){

	memset(d, -1, sizeof(d));
	queue<pair<int, int>> queue;
	queue.push({sx,sy});
	d[sx][sy] = 0;

	while(!queue.empty()){
		pair<int, int> pos = queue.front();
		queue.pop();

		for(int i = 0; i<4; i++){
			row = pos.first + fx[i];
			col = pos.second + fy[i];

			if(checkCell(row, col) and d[row][col] == -1){
				d[row][col] = d[pos.first][pos.second] + 1;
				queue.push({row, col});
			}
		}
	}

	for(int row = 0; row<10; row++){
		for(int col = 0; col<10; col++){
			cout<<d[row][col]<<" ";
		}
		cout<<endl;
	}

}


int main(){

	bfs(5,5);

	return 0;
}