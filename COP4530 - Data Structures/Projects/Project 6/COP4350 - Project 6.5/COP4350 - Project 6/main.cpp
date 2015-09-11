/* maze.h -----------------------------------------------------------
authors: Alfredo Antolinez, Anthony Rodriguez, Christian A. Rodriguez
Main file of the class library for the class maze
-------------------------------------------------------------------*/

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "maze.h"

using namespace std;

int main() {
   ifstream inFile;
   ofstream outFile;

   inFile.open("input.txt");

   if (!inFile) {
      cerr << "The file could not be opened";
      cin.ignore();
      return -1;
   }

   int instances = 0;
   inFile >> instances;

   ////List<Maze> MazeObject = new Maze
   ////array mazeObject


   vector<Maze<int>> object;
   object.reserve(instances);

   for (int i = 0; i < instances; i++) {
      int gridSize = 0;
      inFile >> gridSize;

	  object.push_back(Maze<int>(gridSize));

	  for (int j = 0; j < gridSize * gridSize; j++) {
		  object[i].read(inFile);
	  }
	  cin.ignore();
	  cout << "\n" << "Object Number " << i << endl;

	  for (int j = 0; j < gridSize * gridSize; j++) {
		  object[i].copyData(j);
	  }

	  for (int j = 0; j < 2 * gridSize * gridSize; j++) {
		  object[i].addAdjacency(j);
	  }

	  for (int j = 0; j < 2 * gridSize * gridSize; j++) {
		  cout << "Vertex " << j << ": ";
		  object[i].outputAdjacency(j);
		  cout << endl;
	  }

   }
   cin.ignore();
   return 0;
}
