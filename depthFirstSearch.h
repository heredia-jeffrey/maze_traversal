/*
Assignment: PA2
Description: Creates a maze from an input file and then traverses the maze
using both a breath first search as well as a depth first search
Author: Jeffrey Heredia
*/
#pragma once
#include <string>
#include <stack>
#include "MazeSpace.h"

using namespace std;

string depthFirstSearch(MazeSpace *node, int num_spaces, int end)
{
	//dynamically create and array to flag which nodes have been visited
	bool * visited = nullptr;
	visited = new bool[num_spaces];

	//initialize the array to hold all false
	for (int i = 0; i < num_spaces; i++)
	{
		visited[i] = false;
	}

	stack<MazeSpace*> path;
	path.push(node);

	//create a second MazeSpace pointer to be used as the following node
	MazeSpace *next_node;

	//craete string for output and initialize it as the first node's id
	string output;
	output = to_string(node->getId());

	while (node->getId() != end)
	{
		next_node = node->getNorth();
		//go to the North if it exists and you have never been there before
		if ((node->getNorth() != nullptr) && (visited[next_node->getId()] == false))
		{
			node = node->getNorth();
			path.push(node);
			output += "->";
			output += to_string(node->getId());
			visited[next_node->getId()] = true;
			continue;
		}
		//go to the East if it exists and you have never been there before
		next_node = node->getEast();
		if ((node->getEast() != nullptr) && (visited[next_node->getId()] == false))
		{
			node = node->getEast();
			path.push(node);
			output += "->";
			output += to_string(node->getId());
			visited[next_node->getId()] = true;
			continue;
		}
		//go to the South if it exists and you have never been there before
		next_node = node->getSouth();
		if ((node->getSouth() != nullptr) && (visited[next_node->getId()] == false))
		{
			node = node->getSouth();
			path.push(node);
			output += "->";
			output += to_string(node->getId());
			visited[next_node->getId()] = true;
			continue;
		}
		//go to the West if it exists and you have never been there before
		next_node = node->getSouth();
		if ((node->getWest() != nullptr) && (visited[next_node->getId()] == false))
		{
			node = node->getWest();
			path.push(node);
			output += "->";
			output += to_string(node->getId());
			visited[next_node->getId()] = true;
			continue;
		}
		//if all those fail then pop the stack and do it again to travel a different path
		if ((node->getNorth() == nullptr || (visited[next_node->getId()] == true))
			&& ((node->getEast() == nullptr) || (visited[next_node->getId()] == true))
			&& ((node->getSouth() == nullptr) || (visited[next_node->getId()] == true))
			&& ((node->getWest() == nullptr) || (visited[next_node->getId()] == true)))
		{
			path.pop();
		}
	}



	return output;
}