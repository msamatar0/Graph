#include "graph.h"

int main(){
	graph gr(12);
	gr.addVertex("what", 1, 3, 2134);
	cout << "Weight Adjacency Matrix\n" << gr << endl;
	gr.bfs(1);
	gr.dfs(1);
}