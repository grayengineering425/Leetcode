#pragma once
#include <vector>
#include <memory>

namespace Amazon
{

struct Edge
{
	Edge(int src, int dst, int weight)
		:	src		(src)
		,	dst		(dst)
		,	weight	(weight)
	{
	}

	int src;
	int dst;
	int weight;
};

struct Graph
{
	Graph(int v, int e)
		:	v	(v)
		,	e	(e)
	{
	}

	int v;
	int e;

	std::vector<std::shared_ptr<Edge>> edges;
};

class Cities
{
public:
	Cities(std::vector<std::vector<int>>& connections, int n);

	int minimumCost();

private:
	bool	createsCycle(const std::shared_ptr<Edge>& edge);
	int		find		(int val);
	void	createUnion	(int x, int y);

private:
	Graph				graph;
	std::vector<int>	parent;
};

}