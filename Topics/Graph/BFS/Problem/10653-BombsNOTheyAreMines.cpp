#include<bits/stdc++.h>

using namespace std;

const int fx[] = {1,-1, 0, 0};
const int fy[] = {0, 0, 1, -1};
const int mx = 1e6 + 123;
static int grid[mx];

struct node{
	int r,c;
};

int bfs(int row, int col){

	int grid[row][col];
	memset(grid, -1, sizeof(grid));

	queue<node> queue;

	int rowMines, rowNo, colNo, mineCount;
	cin>>rowMines;

	for(int i = 1; i<=rowMines; i++){
		cin>>rowNo>>mineCount;
		for(int j = 1; j<= mineCount; j++){
			cin>>colNo;
			grid[rowNo][colNo] = -10;
		}
	}

	node start;
	node end;
	cin>>start.r; cin>>start.c; cin>>end.r; cin>>end.c;

	grid[start.r][start.c] = 0;

	queue.push(start);

	while(!queue.empty()){
		node u = queue.front();
		queue.pop();

		for(int i = 0; i<4; i++){
			int r = u.r + fx[i];
			int c = u.c + fy[i];

			if(r >= 0 and r < row and c >= 0 and c < col){

				if(grid[r][c] == -1){
					grid[r][c] = grid[u.r][u.c] + 1;
					node vPos;
					vPos.r = r;
					vPos.c = c;
					queue.push(vPos);

					if(r == end.r and c == end.c)
						return grid[r][c];
				}
			}
		}
	}

	return 0;
}

int main(){

	int row, col;
	cin>>row>>col;
	while(row and col){

		int ans = bfs(row, col);
		cout<<ans<<endl;
		
		cin>>row>>col;
	}

	return 0;
}