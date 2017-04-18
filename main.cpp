#include "graph.h"

int main(){
	graph gr(5);
	gr.addVertex("what", 1, 4, 2134);
	cout << gr << endl;
}