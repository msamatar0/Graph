#include "graph.h"

graph::graph(size_t n, bool d):
	size(n), adjMatrix(new int[n * n]), vertex(vector<string>(n)), directed(d){
	for(int i = 0; i < size * size; ++i)
		adjMatrix[i] = 0;
}

graph::graph(const graph &g): vertex(g.vertex){
	delete[] adjMatrix;
	adjMatrix = new int[g.size * g.size];
	for(int i = 0; i < g.size * g.size; ++i)
		adjMatrix[i] = g.adjMatrix[i];
}

graph::~graph(){
	delete[] adjMatrix;
}

graph graph::operator=(const graph & g){
	for(int i = 0; i < g.vertex.size(); ++i)
		vertex.push_back(g.vertex[i]);
	delete[] adjMatrix;
	adjMatrix = new int[g.size * g.size];
	for(int i = 0; i < g.size * g.size; ++i)
		adjMatrix[i] = g.adjMatrix[i];
	return *this;
}

void graph::addVertex(string vname, int src){
	if(src >= size)
		throw outOfBounds("Error: Out of Bounds on Matrix");
	vertex[src] = vname;
	cout << "Inserted vertex " << vname
		<< " w/ index " << src << endl;
}

void graph::addEdge(int src, int dest, int weight){
	if(src >= size || dest >= size)
		throw outOfBounds("Error: Out of Bounds on Matrix");
	adjMatrix[src + size * dest] = weight;
	if(!directed)
		adjMatrix[dest + size * src] = weight;
	cout << "Added Edge: "
		<< vertex[src] << (directed? " -> ":" <-> ")
		<< vertex[dest] << endl;
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

vector<string> graph::dfs(int v){
	vector<string> searchVec;
	int distance = 0;
	bool *visited = new bool[size];
	for(int i = 0; i < size; ++i)
		visited[i] = false;
	dfsHelper(v, visited, distance, searchVec);
	delete[] visited;
	cout << "Total Distance: " << distance << endl;
	return searchVec;
}


 void graph::dfsHelper(int v, bool *visited, int &dist, vector<string> &searchVec){
	visited[v] = true;
	searchVec.push_back(vertex[v]);
	for(int j = 0; j < size; ++j)
		if(adjMatrix[v + size * j] != 0 && !visited[j]){
			dist += adjMatrix[v + size * j];
			dfsHelper(j, visited, dist, searchVec);
		}
	cout << "";
}

vector<string> graph::bfs(int v){
	vector<string> searchVec;
	int distance = 0;
	bool *visited = new bool[size];
	for(int i = 0; i < size; ++i)
		visited[i] = false;
	visited[v] = true;
	queue<int> q;
	q.push(v);
	while(!q.empty()){
		int n = q.front();
		q.pop();
		searchVec.push_back(vertex[n]);
		for(int j = 0; j < size; ++j){
			if(adjMatrix[n + size * j] != 0 && !visited[j]){
				distance += adjMatrix[n + size * j];
				q.push(j);
				visited[j] = true;
			}
		}
	}
	delete[] visited;
	cout << "Total Distance: " << distance << endl;
	return searchVec;
}

ostream &operator<<(ostream &gout, const graph &g){
	stringstream ss;
	string *weightStr = new string[g.size * g.size], format;
	for(int i = 0; i < g.size; ++i){
		for(int j = 0; j < g.size; ++j){
			ss << g.adjMatrix[i + g.size * j];
			ss >> weightStr[i + g.size * j];
			ss.clear();
		}
	}
	int len = longestStrLen(weightStr, g.size * g.size);
	ss << "%-" << len << "d";
	ss >> format;
	ss.clear();
	for(int i = 0; i < g.size; ++i){
		for(int j = 0; j < g.size; ++j){
			char buffer[100];
			sprintf(buffer, format.c_str(), g.adjMatrix[i + g.size * j]);
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

int longestStrLen(vector<string> list, const int strNum){
	int len = list[0].length();
	for(int i = 1; i < strNum; ++i)
		if(len < list[i].length())
			len = list[i].length();
	return len;
}

void printSearch(vector<string> &v){
	for(string s : v)
		cout << s << "->";
	cout << "END\n";
}

void createGraph(graph &g){
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
	for(int i = 0; i < 12; ++i)
		g.addVertex(city[i], i);
	g.addEdge(0, 1, 2097);
	g.addEdge(0, 2, 1331);
	g.addEdge(0, 3, 807);
	g.addEdge(1, 2, 1003);
	g.addEdge(1, 5, 533);
	g.addEdge(1, 6, 787);
	g.addEdge(1, 7, 983);
	g.addEdge(2, 3, 1267);
	g.addEdge(2, 5, 599);
	g.addEdge(2, 4, 1015);
	g.addEdge(3, 4, 381);
	g.addEdge(4, 5, 1663);
	g.addEdge(4, 8, 1435);
	g.addEdge(5, 6, 1260);
	g.addEdge(5, 8, 496);
	g.addEdge(5, 9, 864);
	g.addEdge(6, 7, 214);
	g.addEdge(6, 9, 888);
	g.addEdge(8, 9, 781);
	g.addEdge(8, 10, 239);
	g.addEdge(9, 10, 810);
	g.addEdge(9, 11, 661);
	g.addEdge(10, 11, 1187);
}