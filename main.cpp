#include "graph.h"

int main(){
	graph g(12);
	createGraph(g);
	cout << endl << g << endl;
	cout << "DFS ";
	printSearch(g.dfs(0));
	cout << "\nBFS ";
	printSearch(g.bfs(0));
	cout << endl;
}