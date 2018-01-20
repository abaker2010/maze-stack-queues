// Aaron Baker
#ifndef MAZE_H
#define MAZE_H

#define NORTH   0
#define SOUTH   1
#define EAST    2
#define WEST    3
#define ROW_SIZE   20
#define COL_SIZE   20

class Maze
{
public:
	Maze() {}
	~Maze();
	void genMaze();
	void printMaze();
	void saveMaze();
	void solveMaze();
	
private:
	char maze[COL_SIZE][ROW_SIZE];
	
};

#endif // !MAZE_H

