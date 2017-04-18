#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

struct edge{
	node *n1, *n2;
	int weight;
};

struct node{
	string name;
	vector<edge> edges;
	node(string s = ""): name(s){}
};

class graph{
	vector<list<node>> adj;
public:
	void addVertex(string s, int idx, int distance);
};