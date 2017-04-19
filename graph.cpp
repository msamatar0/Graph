#include "graph.h"

graph::graph(size_t n, bool d):
	size(n), adjMatrix(new int[n * n]), vertex(vector<string>(n)), directed(d){
	for(int i = 0; i < size * size; ++i)
		adjMatrix[i] = 0;
}

graph::~graph(){
	delete[] adjMatrix;
}

void graph::addVertex(string vname, int src, int dest, int weight){
	if(src >= size || dest >= size)
		throw outOfBounds("Error: Out of Bounds on Matrix");
	vertex[src] = vname;
	adjMatrix[src + size * dest] = weight;
	if(!directed)
		adjMatrix[dest + size * src] = weight;
}

void graph::removeVertex(int src, int dest){
	vertex[src] = "";
	adjMatrix[src + size * dest] = 0;
	if(!directed)
		adjMatrix[dest * size + src] = 0;
}

int graph::getSize() const{
	return size;
}

void graph::dfs(int v){
	bool *visited = new bool[size];
	for(int i = 0; i < size; ++i)
		visited[i] = false;
	dfsHelper(v, visited);
	delete[] visited;
	cout << endl;
}


void graph::dfsHelper(int v, bool *visited){
	visited[v] = true;
	cout << vertex[v];
	for(int j = 0; j < size; ++j)
		if(adjMatrix[v + size * j] != 0 && !visited[j]){
			cout << "->";
			dfsHelper(j, visited);
		}
	for(int j = 0; j < size; ++j)
		visited[j] = false;
}

void graph::bfs(int v){
	bool *visited = new bool[size];
	for(int i = 0; i < size; ++i)
		visited[i] = false;
	visited[v] = true;
	queue<int> q;
	q.push(v);
	while(!q.empty()){
		int n = q.front();
		q.pop();
		cout << vertex[n] << "->";
		for(int j = 0; j < size; ++j){
			if(adjMatrix[v + size * j] != 0 && !visited[v]){
				q.push(v);
				visited[v] = true;
			}
		}
	}
	for(int i = 0; i < size; ++i)
		visited[i] = false;
	cout << endl;
}

ostream &operator<<(ostream &gout, const graph &g){
	stringstream ss;
	string *weightStr = new string[g.size * g.size], buffer, format;
	for(int i = 0; i < g.size; ++i){
		for(int j = 0; j < g.size; ++j){
			ss << g.adjMatrix[i + g.size * j];
			ss >> weightStr[i + g.size * j];
			ss.clear();
		}
	}
	ss << "%-" << longestStrLen(weightStr, g.size * g.size) << "d";
	ss >> format;
	ss.clear();
	for(int i = 0; i < g.size; ++i){
		for(int j = 0; j < g.size; ++j){
			char cbuf[100];
			sprintf(cbuf, format.c_str(), g.adjMatrix[i + g.size * j]);
			buffer = string(cbuf);
			gout << buffer << "  ";
		}
		gout << endl;
	}
	delete[] weightStr;
	return gout;
}

int longestStrLen(const string *list, const int strNum){
	int len = list[0].length();
	for(int i = 1; i < strNum; ++i)
		if(len < list[i].length())
			len = list[i].length();
	return len;
}
