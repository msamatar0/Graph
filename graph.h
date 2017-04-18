#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

int longestStrLen(const string *list, const int strNum);

class outOfBounds{
	string msg;
public:
	outOfBounds(string s = "Error"): msg(s){}
	string what(){ return msg; }
};

class graph{
	map<int, string> vertices;
	int *adjMatrix;
	bool directed;
	size_t size;
public:
	graph(size_t n, bool d = false): size(n), adjMatrix(new int[size * size]), directed(d){
		for(int i = 0; i < size * size; ++i)
			adjMatrix[i] = 0;
	}
	~graph(){ delete[] adjMatrix; }
	void addVertex(string vname, int src, int dest, int weight);
	friend ostream &operator<<(ostream &gout, const graph &g);
};

typedef pair<int, string> vertex;