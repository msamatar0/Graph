#include "graph.h"

void graph::addVertex(string vname, int src, int dest, int weight){
	if(src >= size || dest >= size)
		throw outOfBounds("Error: Out of Bounds on Matrix");
	vertices.insert(vertex(src, vname));
	adjMatrix[src + size * dest] = weight;
	if(!directed)
		adjMatrix[dest + size * src] = weight;
}

ostream &operator<<(ostream &gout, const graph &g){
	string *names = new string[g.size];
	for(int i = 0; i < g.vertices.size(); ++i)
		names[i] = g.vertices.at(i);
	int len = longestStrLen(names, g.size);
	for(int i = 0; i < len + 2; ++i)
		gout << " ";
	gout << endl;
	gout << setw(len + 2) << left;
	for_each(names + 0, names + g.size, [&gout](string s){ gout << s; });
	for(int i = 0; i < g.size; ++i){
		gout << names[i] << "  ";
		for(int j = 0; j < g.size; ++j)
			gout << g.adjMatrix[i * g.size * j];
		gout << endl;
	}
	return gout;
}

int longestStrLen(const string *list, const int strNum){
	int len = list[0].length();
	for(int i = 1; i < strNum; ++i)
		if(len < list[i].length())
			len = list[i].length();
	return len;
}