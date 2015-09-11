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

   void addData(int, T);
   /*----------------------------------------------------------------
   Purpose:
   Precondition:
   Postcondition:
   Time Complexity:
   ----------------------------------------------------------------*/

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
   int n = 2 * (size * size);
   myAdjacencyLists.reserve(n);
}

template <class T>
void Maze<T>::addData(int location, T data) {
	Maze<T>::VertexInfo temp;

	temp.data = data;

	myAdjacencyLists[location] = temp;
	
	//VertexInfo * temp = new VertexInfo;
	//
	//temp->data = data;

	//myAdjacencyLists[location] = temp;
}

#endif /* MAZE_H_ */
