#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
//#include <algorithm>
using namespace std;

int longestStrLen(const string *list, const int strNum);
int longestStrLen(vector<string> list, const int strNum);
void printSearch(vector<string> &v);

class outOfBounds{
	string msg;
public:
	outOfBounds(string s = "Error"): msg(s){}
	string what(){ return msg; }
};

class graph{
	vector<string> vertex;
	int *adjMatrix;
	bool directed;
	size_t size;
	void dfsHelper(int i, bool *visited, vector<string> &searchVec);
public:
	graph(size_t n, bool d = false);
	graph(const graph &g);
	~graph();
	graph operator=(const graph &g);
	void addVertex(string vname, int src);
	void addEdge(int src, int dest, int weight);
	void removeVertex(int src, int dest);
	int getSize() const;
	vector<string> dfs(int v);
	vector<string> bfs(int v);
	friend ostream &operator<<(ostream &gout, const graph &g);
};

void createGraph(graph &g);