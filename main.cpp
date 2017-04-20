#include "graph.h"

int main(){
	string city[] = {
		"Seattle",
		"Chicago",
		"Denver",
		"San Francisco",
		"Los Angeles",
		"Kansas City",
		"New York",
		"Boston",
		"Dallas",
		"Atlanta",
		"Houston",
		"Miami"
	};
	graph gr(12);
	for(int i = 0; i < 12; ++i)
		gr.addVertex(city[i], i);
	gr.addEdge(0, 1, 2097);
	gr.addEdge(0, 2, 1331);
	gr.addEdge(0, 3, 807);
	gr.addEdge(1, 2, 1003);
	gr.addEdge(1, 5, 533);
	gr.addEdge(1, 6, 787);
	gr.addEdge(1, 7, 983);
	gr.addEdge(2, 3, 1267);
	gr.addEdge(2, 5, 599);
	gr.addEdge(2, 4, 1015);
	gr.addEdge(3, 4, 381);
	gr.addEdge(4, 5, 1663);
	gr.addEdge(4, 8, 1435);
	gr.addEdge(5, 6, 1260);
	gr.addEdge(5, 8, 496);
	gr.addEdge(5, 9, 864);
	gr.addEdge(6, 7, 214);
	gr.addEdge(6, 9, 888);
	gr.addEdge(8, 9, 781);
	gr.addEdge(8, 10, 239);
	gr.addEdge(9, 10, 810);
	gr.addEdge(9, 11, 661);
	gr.addEdge(10, 11, 1187);
	cout << "Weight Adjacency Matrix\n" << gr << endl;
	//gr.bfs(1);
	//gr.dfs(1);
}