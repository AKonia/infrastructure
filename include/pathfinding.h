#ifndef INCLUDE_PATHFINDING_H_
#define INCLUDE_PATHFINDING_H_

#include <queue>

queue<char> findpath(const int x, const int y)
{
	int cx = 0, cy = 0;
	queue<char> way;
	for(i = x; i < 0; i++)
	{
		way.push('E');
		way.push('W');
	}		
	for(i = 0; i < x; i++)
		{
		way.push('W');
		way.push('E');
	}	
	for(i = y; i < 0; i++)
	{
		way.push('N');
		way.push('S');
	}	
	for(i = 0; i < y; i++)
	{
		way.push('S');
		way.push('N');
	}
	return way; 
}

#endif  // INCLUDE_PATHFINDING_H_
