/*
Assignment: PA2
Description: Creates a maze from an input file and then traverses the maze
using both a breath first search as well as a depth first search
Author: Jeffrey Heredia
*/
#pragma once
#include <string>
#include <queue>
#include "MazeSpace.h"

string breathFirstSearch(MazeSpace *node, int num_spaces, int end)
{
	//dynamically create and array to flag which nodes have been visited
	bool * visited = nullptr;
	visited = new bool[num_spaces];

	//initialize the array to hold all false
	for (int i = 0; i < num_spaces; i++)
	{
		visited[i] = false;
	}

	//initialize the queue for the path as well as output string
	//along with another Mazespace pointer to help traverse the maze
	queue<MazeSpace*> path;
	path.push(node);
	string output;

	output = to_string(node->getId());
	output += "->";

	MazeSpace *next_node = nullptr;

	MazeSpace *next_maze = nullptr;
	while (node->getId() != end)
	{
		next_node = node->getNorth();
		if ((node->getNorth() != nullptr) && (visited[next_node->getId()] == false))
		{
			path.push(node->getNorth());
			visited[next_node->getId()] = true;
		}
		next_node = node->getEast();
		if ((node->getEast() != nullptr) && (visited[next_node->getId()] == false))
		{
			path.push(node->getEast());
			visited[next_node->getId()] = true;
		}
		next_node = node->getSouth();
		if ((node->getSouth() != nullptr) && (visited[next_node->getId()] == false))
		{
			path.push(node->getSouth());
			visited[next_node->getId()] = true;
		}
		next_node = node->getWest();
		if ((node->getWest() != nullptr) && (visited[next_node->getId()] == false))
		{
			path.push(node->getWest());
			visited[next_node->getId()] = true;
		}
		path.pop();
		node = path.front();
		output += to_string(node->getId());
		output += "->";
	}

	return output;
}