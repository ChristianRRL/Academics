/* maze.h -----------------------------------------------------------
authors: Alfredo Antolinez, Anthony Rodriguez, Christian A. Rodriguez
Header file of the class library for the class maze
-------------------------------------------------------------------*/

#ifndef MAZE_H_
#define MAZE_H_

#include <list>
#include <vector>
#include <queue>
#include <iostream>
#include <fstream>

// Function/Class Declarations
template <class T>

class Maze {
private:
	/* "Head nodes" of adjacency lists */
	class VertexInfo {
	public:
		T data;
		std::list<int> adjacencyLists;
		//list <int> adjacencyLists;
	};

public:
   /* Function Members */
   Maze(const int);
   /*----------------------------------------------------------------
   Purpose:
   Precondition:
   Postcondition:
   Time Complexity:
   ----------------------------------------------------------------*/

   //Maze(const Maze);
   /*----------------------------------------------------------------
   Purpose:
   Precondition:
   Postcondition:
   Time Complexity:
   ----------------------------------------------------------------*/

   //~Maze();
   /*----------------------------------------------------------------
   Purpose:
   Precondition:
   Postcondition:
   Time Complexity:
   ----------------------------------------------------------------*/

   //T data(int) const;
   /*----------------------------------------------------------------
   Purpose:
   Precondition:
   Postcondition:
   Time Complexity:
   ----------------------------------------------------------------*/

   //void display(std::ostream &);
   /*----------------------------------------------------------------
   Purpose:
   Precondition:
   Postcondition:
   Time Complexity:
   ----------------------------------------------------------------*/

   //void depthFirstSearch(int);
   /*----------------------------------------------------------------
   Purpose:
   Precondition:
   Postcondition:
   Time Complexity:
   ----------------------------------------------------------------*/

   //void breadthFirstSearch(int);
   /*----------------------------------------------------------------
   Purpose:
   Precondition:
   Postcondition:
   Time Complexity:
   ----------------------------------------------------------------*/

   //void dijkstrasAlgorithm(int);
   /*----------------------------------------------------------------
   Purpose:
   Precondition:
   Postcondition:
   Time Complexity:
   ----------------------------------------------------------------*/

   //vector<int> shortestPath(int, int);
   /*----------------------------------------------------------------
   Purpose:
   Precondition:
   Postcondition:
   Time Complexity:
   ----------------------------------------------------------------*/

   //Maze& operator=(const Maze& rhs);
   /*----------------------------------------------------------------
   Purpose:
   Precondition:
   Postcondition:
   Time Complexity:
   ----------------------------------------------------------------*/

   bool checkIfNegative(T);
   void addAdjacency(int);
   void read(std::ifstream &);
   void copyData(int);
   void output(int);
private:
	/* Data Members */
	std::vector<VertexInfo> myAdjacencyLists;
	
	/* Private Function Member */
   //void depthFirstSearchAux(int, vector<bool> &);
   //void copyMaze(VertexInfo *, VertexInfo * &);
   //void deleteMaze(VertexInfo * &);
};

// Function/Class Implementations
template <class T>
Maze<T>::Maze(const int size) {
   //int n = 2 * (size * size);
   //myAdjacencyLists.reserve(n);
	//myAdjacencyLists
}

template <class T>
void Maze<T>::read(std::ifstream & inFile)
{
	VertexInfo head;
	inFile >> head.data;
	myAdjacencyLists.push_back(head);
}

template <class T>
void Maze<T>::copyData(int location)
{
	VertexInfo temp;
	temp.data = myAdjacencyLists[location].data;
	myAdjacencyLists.push_back(temp);
}
template <class T>
void Maze<T>::output(int location)
{
	cout << myAdjacencyLists[location].data << " ";
}

template <class T>
void Maze<T>::addAdjacency(int location) {
	int gridSize = myAdjacencyLists.size();
	int gridSizeSquared = myAdjacencyLists.size() * myAdjacencyLists.size();
	int n = location;
	int i = myAdjacencyLists[location].data;	// i = data in position

	if (location < gridSizeSquared) {
		// Perform horizontal/vertical adjacency
		int up = n - i * gridSize;
		int right = i + n;
		int down = n + i * gridSize;
		int left = i - n;

		// check up
		if (up < 0)	{
			n = up;
		}
		// check right (newposition/3 > oldposition/3)
		if (right / gridSize <= n / gridSize) {
			n = right;
		}
		// check down
		if (down >= gridSizeSquared) {
			n = down;
		}
		// check left aka: cereal
		if (left / gridSize <= n / gridSize) {
			n = left;
		}
	}
	else if (location >= myAdjacencyLists.size() * myAdjacencyLists.size()) {
		// Perform diagonal adjacency
		int up_left = n - i(gridSize + 1);
		int up_right = n - i(gridSize - 1);
		int down_right = n + i(gridSize + 1);
		int down_left = n + i(gridSize - 1);

		// check if northwest
		if ((up_left >= gridSizeSquared) && (up_left % gridSize < n % gridSize )) {
			n = up_left;
		}
		// check if northeast
		if ((up_right >= gridSizeSquared) && (up_right % gridSize > n % gridSize)) { //if ((n / gridSize - up_right / gridSize)) {

		}
		// check if southeast
		if ((down_right < (gridSizeSquared + gridSizeSquared) && (down_right / gridSize - n / gridSize) <= i) {
			n = down_right;
		}
		// check if southwest
		if ((down_left < (gridSizeSquared + gridSizeSquared)) {
			
		}
	}
}

template <class T>
bool Maze<T>::checkIfNegative(T data) {
	if (data < 0) {
		return true;
	}
	else {
		return false;
	}
}
#endif /* MAZE_H_ */