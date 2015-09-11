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

   void dijkstrasAlgorithm(int, int);
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

	if (i > 0) {
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
		if (location >= gridSizeSquared){
			int up_left = n - i * (gridSize + 1);
			int up_right = n - i * (gridSize - 1);
			int down_right = n + i * (gridSize + 1);
			int down_left = n + i * (gridSize - 1);

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
		}

	}
	else{
		i = abs(i);

		int up = n - i * gridSize;
		int right = n + i;
		int down = n + i * gridSize;
		int left = n - i;
		if (location < gridSizeSquared){
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
		// Perform diagonal adjacency
		int up_left = n - i * (gridSize + 1) + gridSizeSquared;
		int up_right = n - i * (gridSize - 1) + gridSizeSquared;
		int down_right = n + i * (gridSize + 1) + gridSizeSquared;
		int down_left = n + i * (gridSize - 1) + gridSizeSquared;
		if (location < gridSizeSquared){
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
		}
	}
}

/*
template <class T>
void Maze<T>::addAdjacency(int location) {
	int element = myAdjacencyLists[location].data;
	int gridSizeSquared = gridSize * gridSize;
	//int absElement = abs(element);

	if (location < gridSizeSquared) {
		int up = location - abs(element) * gridSize;
		int right = location + abs(element);
		int down = location + abs(element) * gridSize;
		int left = location - abs(element);

		// check up
		if (up >= 0)	{
			if (element < 0) {
				myAdjacencyLists[location].adjacencyLists.push_back(up + gridSizeSquared);
			}
			else
				myAdjacencyLists[location].adjacencyLists.push_back(up);
		}
		// check right (newposition/3 > oldposition/3)
		if (right / gridSize <= location / gridSize) {
			if (element < 0) {
				myAdjacencyLists[location].adjacencyLists.push_back(right + gridSizeSquared);
			}
			else
				myAdjacencyLists[location].adjacencyLists.push_back(right);
		}
		// check down
		if (down < gridSizeSquared) {
			if (element < 0) {
				myAdjacencyLists[location].adjacencyLists.push_back(down + gridSizeSquared);
			}
			else
				myAdjacencyLists[location].adjacencyLists.push_back(down);
		}
		//check left aka: cereal
		if (left / gridSize == location / gridSize && left >= 0) {
			if (element < 0) {
				myAdjacencyLists[location].adjacencyLists.push_back(left + gridSizeSquared);
			}
			else
				myAdjacencyLists[location].adjacencyLists.push_back(left);
		}

	}
	else {
		int up_left = location - abs(element) * (gridSize + 1) + gridSizeSquared;
		int up_right = location - abs(element) * (gridSize - 1) + gridSizeSquared;
		int down_right = location + abs(element) * (gridSize + 1) + gridSizeSquared;
		int down_left = location + abs(element) * (gridSize - 1) + gridSizeSquared;

		// check if northwest
		if ((up_left >= gridSizeSquared) && (up_left % gridSize <= location % gridSize)) {
			if (element < 0) {
				myAdjacencyLists[location].adjacencyLists.push_back(up_left - gridSizeSquared);
			}
			else
				myAdjacencyLists[location].adjacencyLists.push_back(up_left);
		}
		//check if northeast
		if ((up_right >= gridSizeSquared) && (up_right % gridSize >= location % gridSize)) {
			if (element < 0) {
				myAdjacencyLists[location].adjacencyLists.push_back(up_right - gridSizeSquared);
			}
			else
				myAdjacencyLists[location].adjacencyLists.push_back(up_right);
		}
		//check if southeast
		if ((down_right < (gridSizeSquared + gridSizeSquared) && (down_right % gridSize >= location % gridSize))) {
			if (element < 0) {
				myAdjacencyLists[location].adjacencyLists.push_back(down_right - gridSizeSquared);
			}
			else
				myAdjacencyLists[location].adjacencyLists.push_back(down_right);
		}
		// check if southwest
		if ((down_left < (gridSizeSquared + gridSizeSquared) && (down_left % gridSize <= location % gridSize))) {
			if (element < 0) {
				myAdjacencyLists[location].adjacencyLists.push_back(down_left - gridSizeSquared);
			}
			else
				myAdjacencyLists[location].adjacencyLists.push_back(down_left);
		}

	}
}
*/

template <class T>
bool Maze<T>::checkIfNegative(T data) {
	if (data < 0) {
		return true;
	}
	else {
		return false;
	}
}

template <class T>
void Maze<T>::dijkstrasAlgorithm(int start, int destination) {
	vector<string> status;
	int realSize = 2 * gridSize * gridSize;	// number of vertices
	vector<int> parent;
	vector<int> distance;

	//for (int i = 0; i < realSize; i++) {
	//	status.push_back("undiscovered");
	//	//parent.push_back(NULL);
	//	//distance.push_back(-1);
	//}
	////vector<string> status(realSize, "undiscovered"); // This sets all undiscoverd
	//status[start] = "discovered";



	//status[start] = "discovered";
	////parent[start] = NULL;
	//distance[start] = 0;

	for (int i = 0; i < realSize; i++) {
		status.push_back("undiscovered");
		parent.push_back(NULL);
		//distance.push_back(-1);
	}
	 int distance = 0;
	 
	 
	 
	 int vertex;



	int number = myAdjacencyLists.size();
	vector<int> distLabel(number, -1),
		predLabel(number);

	distLabel[start] = 0;
	int distance = 0,
		vertex;
	queue<int> vertexQueue;
	vertexQueue.push(start);

	while (distLabel[destination] < 0 && !vertexQueue.empty()) {
		vertex = vertexQueue.front();
	}


	int n = myAdjacencyLists.size();	// number of vertices (#ed from 1)
	vector<int> distLabel(n, -1),	// distance labels for vertices, all marked as unvisited (-1)
		predLabel(n);				// predecessor labels for vertices

	// Perform breadth first search from start to find destination, labeling vertices with distances from start as we go.
	distLabel[start] = 0;
	int distance = 0,		// distance from start vertex
		vertex;				// a vertex

	queue<int> vertexQueue;	// queue of vertices
	vertexQueue.push(start);

	while (distLabel[destination] == "undiscovered" && !vertexQueue.empty()) {
		vertex = vertexQueue.front();
		vertexQueue.pop();
		if (distLabel[vertex] > distance)
			distance++;
		for (vector<int>::iterator it = myAdjacencyLists[vertex].adjacencyLists.begin();
			it != myAdjacencyLists[vertex].adjacencyList.end(); 
			it++) {
			int tmp = *it;
			if (distLabel[tmp] == "undiscovered") {
				distLabel[tmp] = distance + 1;
				predLabel[tmp] = vertex;
				vertexQueue.push(tmp);
			}
		}
		distance++;

		// Now reconstruct the shortest path if there is one
		vector<int> path(distance + 1);
		if (distLabel[destination] == "undiscovered")
			cout << "Destination not reachable from start vertex\n";
		else {
			path[distance] = destination;
			for (int k = distance - 1; k >= 0; k--) {
				path[k] = predLabel[k + 1];
			}
		}
	}
}


#endif /* MAZE_H_ */
