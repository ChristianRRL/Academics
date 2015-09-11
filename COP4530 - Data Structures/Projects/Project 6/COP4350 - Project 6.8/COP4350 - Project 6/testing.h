int location;
int element;
int gridSize;
int gridSizeSquared;
template <class T>
void Maze<T>::addAdjacency(int location) {
	int gridSquared = gridSize * gridSize;
	int n = location;
	int i = myAdjacencyLists[location].data;

	if (i < 0) {
		i = abs(i);

		if (location < gridSquared) {
			addHorizontalVertical(n, i);
		}
		addDiagonal(n, i);
	}
	else
		addHorizontalVertical(n, i);
}

int up = location - element * gridSize;
int right = location + element;
int down = location + element * gridSize;
int left = location - element;

int up_left = location - element * (gridSize + 1) + gridSizeSquared;
int up_right = location - element * (gridSize - 1) + gridSizeSquared;
int down_right = location + element * (gridSize + 1) + gridSizeSquared;
int down_left = location + element * (gridSize - 1) + gridSizeSquared;


template <class T>
void Maze<T>::addAdjacency2(int location) {
	int element = myAdjacencyLists[location.data];
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
		if (right / gridSize <= n / gridSize) {
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
		if (left / gridSize == n / gridSize && left >= 0) {
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
		if ((up_left >= gridSizeSquared) && (up_left % gridSize <= n % gridSize)) {
			if (element < 0) {
				myAdjacencyLists[location].adjacencyLists.push_back(up_left - gridSizeSquared);
			}
			else
				myAdjacencyLists[location].adjacencyLists.push_back(up_left);
		}
		//check if northeast
		if ((up_right >= gridSizeSquared) && (up_right % gridSize >= n % gridSize)) {
			if (element < 0) {
				myAdjacencyLists[location].adjacencyLists.push_back(up_right - gridSizeSquared);
			}
			else
				myAdjacencyLists[location].adjacencyLists.push_back(up_right);
		}
		//check if southeast
		if ((down_right < (gridSizeSquared + gridSizeSquared) && (down_right % gridSize >= n % gridSize))) {
			if (element < 0) {
				myAdjacencyLists[location].adjacencyLists.push_back(down_right - gridSizeSquared);
			}
			else
				myAdjacencyLists[location].adjacencyLists.push_back(down_right);
		}
		// check if southwest
		if ((down_left < (gridSizeSquared + gridSizeSquared) && (down_left % gridSize <= n % gridSize))) {
			if (element < 0) {
				myAdjacencyLists[location].adjacencyLists.push_back(down_left - gridSizeSquared);
			}
			else
				myAdjacencyLists[location].adjacencyLists.push_back(down_left);
		}

	}
}
