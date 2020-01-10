#include "Graph.h"

using namespace DataStructures;

Edge::Edge(int src, int dst, int weight)
	:	src		(src)
	,	dst		(dst)
	,	weight	(weight)
{
}

Graph::Graph(int v, int e)
	:	v	(v)
	,	e	(e)
{
}

UnionFind::UnionFind(int n)
	:	parent(n, -1)
{
}

bool UnionFind::createsCycle(const std::shared_ptr<Edge>& edge)
{
	if (!edge) return true;

	int start	= edge->src;
	int end		= edge->dst;

	int parentStart = find(start);
	int parentEnd	= find(end);

	return parentStart == parentEnd;
}

void UnionFind::createUnion(int x, int y)
{
	int parentX = find(x);
	int parentY = find(y);

	if (parentX != parentY) parent[parentX] = parentY;
}

int UnionFind::find(int val)
{
	if (parent[val] == -1) return val;

	return find(parent[val]);
}
