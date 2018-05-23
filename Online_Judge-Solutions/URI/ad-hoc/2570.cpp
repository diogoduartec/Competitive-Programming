#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>

vvi grid;
vi aux;

int n, m, k;
int score_player[5];

void init_grid(){
	aux.assign(m, -1);
	grid.assign(n, aux);
	for(int i=0; i<=4; i++) score_player[i] = 0;
}

void write_column(int column, int player){
	for(int i=0; i<n; i++){
		grid[i][column] = player;
	}
}

void make_score(){
	for(int i=0; i<n; i++){
		for(int j=0; j<4; j++){
			score_player[j] += count(grid[i].begin(), grid[i].end(), j);
		//	printf("j: %d | s - %d\n", j, score_player[j]);
		//	printf("c - %d\n", count(grid[i].begin(), grid[i].end(), j));
		}
	}
}

void print(){
	for(int i = 0; i<n; i++){
		for(int j=0; j<m; j++){
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){
	char command;
	int row_column;
	cin >> m >> n >> k;

	init_grid();

	for(int i=0; i<k; i++){
		cin >> command >> row_column;
		if(command == 'L') grid[row_column-1].assign(m, i%4);
		else write_column(row_column-1, i%4);
	}
	//print();
	//printf("%d\n", count(grid[2].begin(), grid[2].end(), 3));
	make_score();
	//printf("\n---------------------\ncount - %d\n", count(grid[1].begin(), grid[1].end(), 0));
	printf("R%d H%d C%d P%d\n", score_player[0], score_player[1], score_player[2], score_player[3]);

	return 0;
}