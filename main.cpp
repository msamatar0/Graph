#include "graph.h"

int main(){
	graph g(12);
	createGraph(g);
	cout << "Weight Adjacency Matrix:\n" <<
		g << endl;
	printSearch(g.dfs(0));
	printSearch(g.bfs(0));
}