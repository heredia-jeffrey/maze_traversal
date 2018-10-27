/*
Assignment: PA2
Description: Creates a maze from an input file and then traverses the maze
using both a breath first search as well as a depth first search
Author: Jeffrey Heredia
*/
#pragma once
#ifndef MAZE_SPACE_H
#define MAZE_SPACE_H
#include <string>
#include <sstream>
using namespace std;

class MazeSpace
{
private:
	int _id = 0;
	MazeSpace *_north_space = nullptr;
	MazeSpace *_south_space = nullptr;
	MazeSpace *_east_space = nullptr;
	MazeSpace *_west_space = nullptr;

public:
	MazeSpace(int id = 0,
		MazeSpace *north = nullptr,
		MazeSpace *south = nullptr,
		MazeSpace *east = nullptr,
		MazeSpace *west = nullptr
	)
	{
		_id = id;
		_north_space = north;
		_south_space = south;
		_east_space = east;
		_west_space = west;
	}

	int getId()
	{
		return _id;
	}

	void setId(int id)
	{
		_id = id;
	}

	MazeSpace *getNorth()
	{
		return _north_space;
	}

	void setNorth(MazeSpace *north)
	{
		_north_space = north;
	}

	MazeSpace *getEast()
	{
		return _east_space;
	}

	void setEast(MazeSpace *east)
	{
		_east_space = east;
	}

	MazeSpace *getSouth()
	{
		return _south_space;
	}

	void setSouth(MazeSpace *south)
	{
		_south_space = south;
	}

	MazeSpace *getWest()
	{
		return _west_space;
	}

	void setWest(MazeSpace *west)
	{
		_west_space = west;
	}
};

#endif // MAZE_SPACE_H
