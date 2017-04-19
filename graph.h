#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
//#include <algorithm>
using namespace std;

int longestStrLen(const string *list, const int strNum);

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
	void dfsHelper(int i, bool *visited);
public:
	graph(size_t n, bool d = false);
	~graph();
	void addVertex(string vname, int src, int dest, int weight);
	void removeVertex(int src, int dest);
	int getSize() const;
	void dfs(int v);
	void bfs(int v);
	friend ostream &operator<<(ostream &gout, const graph &g);
};
