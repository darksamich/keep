
#include <vector>
#include <random>
#include <iostream>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 20
#define WIDTH 20

// Location = [row, column] as a std::pair
typedef std::pair<int, int> Location;

class Node {

	private:

	std::vector<Node> neighbors;

	bool visited;

	bool top;
	bool bot;
	bool right;
	bool left;

	int row;
	int col;

	public:

	Node(int, int);
	bool isVisited();
	void visit();
	std::vector< Location > getNeighbors();

};


Node::Node(int row, int col){
	top = true;
	right = true;
	left = true;
	bot = true;
	
	visited = false;
}

bool Node::isVisited(){
	return visited;
}

void Node::visit(){
	visited = true;
}

void Node::getNeighbors(){

	if (row-1 >= 0){
		neighbors.push_back(std::make_pair(row-1, col));
	}

	if (col-1 >= 0){
		neighbors.push_back(std::make_pair(row, col-1));
	}

	if (row+1 < HEIGHT){
		neighbors.push_back(std::make_pair(row+1, col));
	}

	if (col+1 < WIDTH){
		neighbors.push_back(std::make_pair(row, col+1));
	}
}

class Maze{
	private:

	std::vector< std::vector<Node> > cells;
	std::vector< Node > frontier;

	public:

	Maze();
	void generate();
	bool step();
	

}

Maze::Maze(){

	// build the array of nodes for the maze
	std::vector< std::vector<Node> > cells;

	for (int i=0; i<HEIGHT; i++){

		cells.push_back(std::vector<Node>());

		for (int j=0; j<WIDTH; j++){
			cells.back().push_back(Node(i, j));
		}

	}

}

void Maze::generate(){

	// get starting point
	
	int height = rand() % HEIGHT;
	int width  = rand() % WIDTH;

	// get frontier going
	Node start = cells[height][width];
	frontier.push_back(start);
	start.visit();

	
}

main(){
	// seed random gen
	srand(time(NULL));


	Maze m;
	m.generate();

	

}

























