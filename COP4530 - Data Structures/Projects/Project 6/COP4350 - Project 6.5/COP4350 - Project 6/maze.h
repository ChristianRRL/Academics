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
#include <cmath>

// Function/Class Declarations
template <class T>

class Maze {
private:
	/* "Head nodes" of adjacency lists */
	class VertexInfo {
	public:
		T data;
		std::vector<int> adjacencyLists;
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
   void outputAdjacency(int);
   void addAdjacency(int);
   void read(std::ifstream &);
   void copyData(int);
   void output(int);
private:
	/* Data Members */
	std::vector<VertexInfo> myAdjacencyLists;
	int gridSize;

	
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
	gridSize = size;

}

template <class T>
void Maze<T>::read(std::ifstream & inFile) {
	VertexInfo head;
	inFile >> head.data;
	myAdjacencyLists.push_back(head);
}

template <class T>
void Maze<T>::copyData(int location) {
	VertexInfo temp;
	temp.data = myAdjacencyLists[location].data;
	myAdjacencyLists.push_back(temp);
}

template <class T>
void Maze<T>::output(int location) {
	cout << myAdjacencyLists[location].data << " ";
}

template <class T>
void Maze<T>::outputAdjacency(int location) {
	for (vector<int>::iterator it = myAdjacencyLists[location].adjacencyLists.begin(); 
		it != myAdjacencyLists[location].adjacencyLists.end(); it++) {
		int tmp = *it;
		
		if (it == (myAdjacencyLists[location].adjacencyLists.end() - 1)) {
			cout << tmp;
		}
		else {
			cout << tmp << " -> ";
		}
	}
	//cout << myAdjacencyLists[location].adjacencyLists[i] << " ";
}

template <class T>
void Maze<T>::addAdjacency(int location) {
	int gridSizeSquared = gridSize * gridSize;
	int n = location;
	int i = myAdjacencyLists[location].data;	// i = data in position

	if (i < 0) {
		i = abs(i); // i = 0 - i;

		if (location < gridSizeSquared) {
			// Perform horizontal/vertical adjacency
			int up = n - i * gridSize;
			int right = n + i;
			int down = n + i * gridSize;
			int left = n - i;

			// check up
			if (up >= 0)	{
				myAdjacencyLists[location + gridSizeSquared].adjacencyLists.push_back(up);
			}
			// check right (newposition/3 > oldposition/3)
			if (right / gridSize <= n / gridSize) {
				myAdjacencyLists[location + gridSizeSquared].adjacencyLists.push_back(right);
			}
			// check down
			if (down < gridSizeSquared) {
				myAdjacencyLists[location + gridSizeSquared].adjacencyLists.push_back(down);
			}
			//check left aka: cereal
			if (left / gridSize == n / gridSize && left >= 0) {
				myAdjacencyLists[location + gridSizeSquared].adjacencyLists.push_back(left);
			}
		}
		//if (location >= gridSizeSquared) {

			// Perform diagonal adjacency
			int up_left = n - i * (gridSize + 1) + gridSizeSquared;
			int up_right = n - i * (gridSize - 1) + gridSizeSquared;
			int down_right = n + i * (gridSize + 1) + gridSizeSquared;
			int down_left = n + i * (gridSize - 1) + gridSizeSquared;

			// check if northwest
			if ((up_left >= gridSizeSquared) && (up_left % gridSize <= n % gridSize)) {
				myAdjacencyLists[location].adjacencyLists.push_back(up_left);
			}
			//check if northeast
			if ((up_right >= gridSizeSquared) && (up_right % gridSize >= n % gridSize)) {
				myAdjacencyLists[location].adjacencyLists.push_back(up_right);
			}
			//check if southeast
			if ((down_right < (gridSizeSquared + gridSizeSquared) && (down_right % gridSize >= n % gridSize))) {
				myAdjacencyLists[location].adjacencyLists.push_back(down_right);
			}
			// check if southwest
			if ((down_left < (gridSizeSquared + gridSizeSquared) && (down_left % gridSize <= n % gridSize))) {
				myAdjacencyLists[location].adjacencyLists.push_back(down_left);
			}
		//}

	}
	else {
		i = abs(i); // i = 0 - i;

		if (location < gridSizeSquared) {
			// Perform horizontal/vertical adjacency
			int up = n - i * gridSize;
			int right = n + i;
			int down = n + i * gridSize;
			int left = n - i;

			// check up
			if (up >= 0)	{
				myAdjacencyLists[location].adjacencyLists.push_back(up);
			}
			// check right (newposition/3 > oldposition/3)
			if (right / gridSize <= n / gridSize) {
				myAdjacencyLists[location].adjacencyLists.push_back(right);
			}
			// check down
			if (down < gridSizeSquared) {
				myAdjacencyLists[location].adjacencyLists.push_back(down);
			}
			//check left aka: cereal
			if (left / gridSize == n / gridSize && left >= 0) {
				myAdjacencyLists[location].adjacencyLists.push_back(left);
			}
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

//template <class T>
//void Maze<T>::breadthFirstSearch(std::vector<VertexInfo> vertices, int startLoc) {
//	int s = 0;
//	for (vector<int>::iterator it = myAdjacencyList[location].begin(); it != myAdjacencyList[location].end(); i++) {}
//}
#endif /* MAZE_H_ */
