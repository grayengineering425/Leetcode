#pragma once
#include <vector>
#include <memory>

namespace DataStructures
{

struct Edge
{
	Edge(int src, int dst, int weight);

	int src;
	int dst;
	int weight;
};

struct Graph
{
	Graph(int v, int e);

	int v;
	int e;

	std::vector<std::shared_ptr<Edge>> edges;
};

class UnionFind
{
public:
	UnionFind(int n);
	
	bool createsCycle	(const std::shared_ptr<Edge>& edge);
	void createUnion	(int x, int y);

private:
	int	find(int val);

private:
	std::vector<int> parent;
};

}