/*
Assignment: PA2
Description: Creates a maze from an input file and then traverses the maze 
	using both a breath first search as well as a depth first search
Author: Jeffrey Heredia
Completion Time: 12 hours
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <queue>
#include "MazeSpace.h"
#include "breathFirstSearch.h"
#include "depthFirstSearch.h"

using namespace std;

int main()
{
	//initialize variables
	string file_name, next_value;
	enum input_t { FIRST = 0, DIRECTION, NEXT };

	//grab the file
	cout << "Enter the file: ";
	getline(cin, file_name);

	//open file
	ifstream maze_file(file_name);

	//get the size of the maze
	string dimensions;
	getline(maze_file, dimensions);

	//get the size of maze
	//convert the string to an int
	int maze_size = stoi(dimensions);
	
	//dynamically creat an array of MazeSpace
	//initialize all IDs to index + 1
	//this is because the maze id starts at 1 but an array 
	//starts at 0
	MazeSpace * maze = nullptr;
	maze = new MazeSpace[maze_size-1];
	for (int i = 0; i < maze_size-1; i++)
	{
		maze[i].setId(i + 1);
	}

	//creat MazeSpace objects for current and next space
	MazeSpace maze_space;
	MazeSpace *next_space;

	//initialize variable for file processing
	int value_type=0;
	string direct;
	
	//process the file, continue loop until you reach end of file
	while (maze_file >> next_value)
	{
		//this is reading in the first value on a line
		//convert string to int and use it to set the id of current space
		if (value_type == FIRST)
		{
			int id = stoi(next_value);
			maze_space.setId(id);
			
		}
		//this is reading in the second value on a line
		//grab the direction of the next node
		else if (value_type == DIRECTION)
		{
			direct = next_value;

		}
		//this is reading in the third value on a line
		//assign the value to next space and connect
		//current space in array to next space
		else if (value_type == NEXT)
		{
			int next_node_id = stoi(next_value);
			if (direct == "N")
			{
				
				maze_space.setNorth(&maze[next_node_id]);
			}
			else if (direct == "S")
			{
				maze_space.setSouth(&maze[next_node_id]);
			}
			else if (direct == "E")
			{
				maze_space.setEast(&maze[next_node_id]);
			}
			else if (direct == "w")
			{
				maze_space.setWest(&maze[next_node_id]);
			}
			//copy over current space into maze array
			maze[maze_space.getId()] = maze_space;
		}
		//this keeps track of which value you're reading in
		value_type ++;
		value_type %= 3;
	}

	//get the start and end points for the traversal
	int start=0;
	int end_point=0;

	cout << "Enter the starting point of the maze:";
	cin >> start;
	cout << "Enter the ending point of the maze:";
	cin >> end_point;
	
	cout << "Depth First Search" << endl;
	cout << depthFirstSearch(&maze[start], maze_size, end_point);
	cout << "Breath First Search" << endl;
	cout << breathFirstSearch(&maze[start], maze_size, end_point);
	return 0;
}