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
      exit(1);
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

      cout << "First Maze Object" << endl;

	  object.push_back(Maze<int>(gridSize));
      //Maze<int> mazeObject(gridSize);

	  for (int j = 0; j < gridSize * gridSize; j++) {
		  int current;
		  inFile >> current;

		  cout << current;
		  cin.ignore();

		  //object.at(i).myAdjacencyLists.insert(j, current);

		  // Copy constructor temp;

		  object[i] = current;

		  //cout << object[i];

		  cin.ignore();

		  //object.at(i).addData((gridSize*gridSize) + j, current);
	  }

   //   Maze object = new Maze(i);
   //   list.add(object);
   }
   cin.ignore();
   return 0;
}

