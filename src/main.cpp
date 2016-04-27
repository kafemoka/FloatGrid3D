#include "main.hpp"

void printGrid(FloatGrid3D &grid) {
	std::cout << "grid is now:" << std::endl;
	for (int i = 0; i < grid.m_numCells; i++) {
		std::cout << i << ": " << grid.m_cells[i] << std::endl;
	}
}

int main(int argc, char *argv[]) {
    std::cout << "Hello, world!\n";

	// initialize a grid at -1.0, -1.0, -1.0, 1.0, 1.0, 1.0
	// resolution 4 x 4 x 4
	// fill in the bottom corner with value of 10.0
	// then, trilinear interpolate everything around it until we're full.
	// then export to the python readable format.

	FloatGrid3D testGrid(4, 4, 4,
		-1.0f, -1.0f, -1.0f, 1.0f, 1.0f, 1.0f);

	std::cout << "4x4x4 grid has this many cells: " << testGrid.m_numCells << std::endl;

	printGrid(testGrid);

	std::cout << "clearing to 0.0" << std::endl;
	testGrid.clear(0.0f);

	printGrid(testGrid);

	std::cout << "setting by coordinate in the 0,0,0 cell" << std::endl;
	std::cout << "success? " << testGrid.setByCoordinate(-0.99f, -0.99f, -0.99f, 10.0f) << std::endl;

	printGrid(testGrid);


	std::cout << "running basic trilinear interpolation tests." << std::endl;
	float trilinear;

	std::cout << "trilinear interp at -1.0, -1.0, -1.0 should yield 10:" << std::endl;
	std::cout << "interpolation doable? " << testGrid.trilinear(-1.0f, -1.0f, -1.0f, trilinear) << std::endl;
	std::cout << "result: "<< trilinear << std::endl;

	std::cout << "trilinear interp at 0.0, 0.0, 0.0 should yield 0:" << std::endl;
	std::cout << "interpolation doable? " << testGrid.trilinear(0.0f, 0.0f, 0.0f, trilinear) << std::endl;
	std::cout << "result: " << trilinear << std::endl;

	std::cout << "trilinear interp at -0.75, -0.75, -0.75 should yield something interesting:" << std::endl;
	std::cout << "interpolation doable? " << testGrid.trilinear(-0.75, -0.75, -0.75, trilinear) << std::endl;
	std::cout << "result: " << trilinear << std::endl;

	std::cout << "exporting to file testGrid.txt" << std::endl;
	testGrid.exportToFile("testGrid.txt");

	return 0;
}
