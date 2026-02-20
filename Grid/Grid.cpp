#include "Grid.h"
#include <fstream>

Grid::Grid()
{
}

Grid::~Grid()
{
}

void Grid::LoadGrid(const char filename[])
{
	int x = 0;
	int y = 0;
	std::ifstream fin;
	fin.open(filename);
	for (x = 0; x <= 8; x++)
	{
		for (y = 0; y <= 8; y++)
		{
			fin >> m_grid[x][y];
		}
	}

	fin.close();

}

void Grid::SaveGrid(const char filename[])
{
	std::ofstream fout;
	fout.open(filename);
		for (int x = 0; x <= 8; x++)
		{
			for (int y = 0; y <= 8; y++)
			{
				fout << m_grid[x][y] << " ";
			}
			fout << std::endl;

		}
	fout.close();
}
