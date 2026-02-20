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
I say this because 10 in hexadecimal is 0A. 
<img width="416" height="119" alt="image" src="https://github.com/user-attachments/assets/5e282a62-f5bc-44db-a83d-689166d3413f" />
<img width="295" height="85" alt="image" src="https://github.com/user-attachments/assets/a3d2413a-e0f0-47ec-ae59-bb6ac56108bf" />
Here I have added the code to update the value of the address pointer p is pointing to:
<img width="180" height="37" alt="image" src="https://github.com/user-attachments/assets/c43a0817-ad83-4aeb-9a74-931220184474" />
Here we can see, that after executing that line, we update the value of a
<img width="424" height="92" alt="image" src="https://github.com/user-attachments/assets/f48a7839-1758-41be-ac8a-5651b9afc041" />

### Reflection
a pointer does not store a value, it stores a memory location.
when we dereference (*p), we are accessing the value At That Location, hence the value that we initially assigned to the variable a, is changed to 100. This is because p stores the address of a, while the value stored at that address is changed by *p = 100e 

Essentially: 
- passing by reference
- 	*p = &a - this means that p gets a copy of the address, not the value of a.

# Pointers - False Assumptions















