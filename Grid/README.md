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
## 1. 
<img width="130" height="33" alt="image" src="https://github.com/user-attachments/assets/5cddd50e-3448-4b4a-be57-bd70286d3436" />

At first, I was confused why this line changes the value b in the code below:

Essentially 

```cpp
*p = 100
```

Means: go to the memory address stored in p and write a value there (100)
In other words:

```cpp
b = 100
```
## 2. 
After we add: 

```cpp
p++;
*p = 200;
```

we get: 

<img width="547" height="100" alt="image" src="https://github.com/user-attachments/assets/7985ae11-bb9b-4821-ace3-4b6d78fe3483" />


After moving the pointer to the next integer-sized memory location, p no longer points to &b and its stored value.
- p points to something random
- after doing *p = 200
- 	may be writing to memory which does not belong to us
- *We may only use p++ if p points into an array* because we know which values we are accessing.
- such as:

```cpp
int arr[3] = {10, 20, 30};
int *p = arr;

p++;   // now points to arr[1]
*p = 100;  // safe
```

# Pointers - The crash

After adding a breakpoint, to the instruction:
<img width="292" height="33" alt="image" src="https://github.com/user-attachments/assets/7f66f7de-cadf-4177-adf7-d433b77ece62" />
looking at the registers used and the memory on the stack:
<img width="489" height="176" alt="image" src="https://github.com/user-attachments/assets/bb1a9251-f64f-4e89-be4a-0aff48532b39" />
<img width="392" height="66" alt="image" src="https://github.com/user-attachments/assets/a5b36106-5803-47c0-9fe0-31b406c50c71" />
<img width="409" height="121" alt="image" src="https://github.com/user-attachments/assets/b868f8b6-51e0-4226-abc5-7f3f777d05d9" />




we can see that the memory location we are trying to write to, is not a valid memory location

<img width="279" height="50" alt="image" src="https://github.com/user-attachments/assets/97e343df-3a1b-4a7a-a725-47edc518ea01" />

This is because we do not control the stack and how its contents are managed. 


# Pointers - Pointers to Pointers

```cpp
void functionD() {
	double x = 3.14;
	double *q = &x;


	cout << "x= " << x << endl;

	double *p = q; // p points to q
	*p = 3.21; // modify x through p

	cout << "x= " << x << endl;
}
```

In this bit of code we have two pointers, one pointing to a value, and another to a pointer.
- Pointer *p* stores the same memory address as *q*
- Hence updating the value at which pointer *p* is pointing to, changes the value of x.

<img width="74" height="42" alt="image" src="https://github.com/user-attachments/assets/153b5963-b977-479e-b4b9-26413d67307e" />

 We can see that it is the same for pointer q:
<img width="483" height="77" alt="image" src="https://github.com/user-attachments/assets/17ff7ced-56b9-40c8-83b3-943790fe4bf8" />

# Pointer Chains

```cpp
	int* a;
	int* b;
	int* c;
	int* d;

	a = (int*)&b;
	b = (int*)&c;
	c = (int*)&d;
	d = (int*)&a;
```

In circulat pointer chains, pointers store the addresses of the pointer variables, not the values inside them. 

```cpp
a = (int*)&b;
```
&b gives the address of the pointer variable b, and the cast forces that address into an int*. This means a now points to the variable b, not to whatever b points to

&b = address of b
(int*) = treat the address of b as if it were an int*
(int*)&b = take the address of b, and think of it as the address of an int. 

We are using casting to force the compiler to treat the address of a pointer variable as if it were the address of an integer.
This is because a pointer to a pointer to an int (int**) cannot point to a pointer to an int (int*) as these types are not the same.

  

  












