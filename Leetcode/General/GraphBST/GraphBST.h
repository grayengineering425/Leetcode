#pragma once
#include <vector>

namespace General
{

//https://leetcode.com/problems/word-ladder-ii/

class GraphBST
{
public:
	GraphBST();

	bool isGraphBST(std::vector<std::vector<int>>& edges, int n);

private:
	bool createsCycle(int u, int v);
	void createUnion (int u, int v);
	int  find		 (int u);

private:
	std::vector<int> parents;
};

}
