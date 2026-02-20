# Linker error & What is needed in the .h and .cpp files

1. .h files tell the compiler what to expect, such as methods, constructors etc.
2. .cpp files tell the compiler how it is implemented / how it is used
3. .cpp file must have "#include file.h"

+-------------------------------------------+
|                .h File                    |
|-------------------------------------------|
|  • Declares class                         |
|  • Declares methods                       |
|  • Declares constructors/destructors      |
|  • No logic                               |
+-------------------------------------------+
                    |
                    |  included by
                    v
+-------------------------------------------+
|                .cpp File                  |
|-------------------------------------------|
|  • Implements methods                     |
|  • Contains logic                         |
|  • Uses #include "MyClass.h"              |
+-------------------------------------------+


# Reading into Grid Class

```cpp
void Grid::LoadGrid(const char filename[])
{
	std::ifstream fin; // Create an object of type ifstream called fin - which is used to open our file and read in from our file
	fin.open(filename);
	for (x = 0; x <= 8; x++) // For each row
	{
		for (y = 0; y <= 8; y++) // and for each column
		{
			fin >> m_grid[x][y]; // read in and add to our m_grid 2D array_
		}
	}

	fin.close(); // close the file

}
```
# Saving / Writing to a file with ifstream and ofstream

```cpp
void Grid::SaveGrid(const char filename[])
{
	std::ofstream fout; // create an object of type ofstream called fout (file out) 
	fout.open(filename); // open the file
	for (int x = 0; x <= 8; x++) // loop through the grid
	{
		for (int y = 0; y <= 8; y++)
		{
			fout << m_grid[x][y] << " "; // write the grid separated by spaces
		}
		fout << std::endl; // add a new line after each row

	}
	fout.close(); // close the file 
}
```

# Basics of Pointers
Here we confirm the address of *p pointed to by p is indeed "a"
<img width="416" height="119" alt="image" src="https://github.com/user-attachments/assets/5e282a62-f5bc-44db-a83d-689166d3413f" />
<img width="295" height="85" alt="image" src="https://github.com/user-attachments/assets/a3d2413a-e0f0-47ec-ae59-bb6ac56108bf" />
