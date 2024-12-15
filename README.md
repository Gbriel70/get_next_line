---
<div align="center"><h1>Grade [125 / 100]</h1></div>

<div align="center">
   <a href="https://github.com/ArthurSobreira/42_get_next_line" target="_blank">
      <img height=170 src="https://github.com/byaliego/42-project-badges/blob/main/badges/get_next_linem.png" hspace = "10">
   </a>
</div>

---

# About the Project

This is the second project at 42, where the main goal is to implement the `get_next_line()` function, which reads a line from a file and returns it. The challenge is that when calling the function again, it should return the next line from the file, and so on, until the end.

The project focuses on memory management and handling various situations, such as dealing with buffers of variable sizes and avoiding excessive data reading. The bonus of the project involves the ability to perform these operations on multiple files simultaneously.

Key concepts covered:
- Dynamic memory management
- Efficient file reading
- Error handling and edge cases
- Support for multiple open files at the same time

## How to Use

To use the project, start by cloning the repository:

```bash
git clone git@github.com:Gbriel70/get_next_line.git
```

Inside the project directory, create a file with some text, then create a `main.c` where you will call the function.

Once the `main.c` file is created, compile the project by running the provided script (`comp.sh`):

```bash
./comp.sh
```

If you wish, you can define a custom `BUFFER_SIZE` by adding the following compile flag (e.g., `-D BUFFER_SIZE=10`):

```bash
./comp.sh -D BUFFER_SIZE=10
```

---
