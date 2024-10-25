# Get Next Line by RaphRsl
![image](https://github.com/user-attachments/assets/b2c28f6b-9148-4198-8fd5-425827b7f42d)

## Description

The **Get Next Line** project is designed to create a function that reads a line from a file descriptor. This exercise introduces the concept of static variables in C, allowing the management of state across function calls. By implementing this function, we enhance our understanding of file I/O, memory management, and buffer handling.

## Overview of the Project

- **What the Project Is:**
  The **Get Next Line** project is a programming exercise focused on implementing a function that reads a line from a specified file descriptor, making file handling more convenient and efficient.

- **Main Technical Features or Functionalities:**
  - Implement the `get_next_line` function that reads a line from a file descriptor.
  - Utilize static variables to manage reading state across multiple calls.
  - Handle reading from both files and standard input.
  - Ensure proper memory management and error handling to prevent leaks or crashes.

- **Languages:**
  - C

- **Tools and Technical Notions Involved:**
  Static variables / Memory management / File I/O / Buffer handling / Error handling / Makefile configuration

## Key Features

- Efficient line reading from file descriptors.
- Management of the reading state using a static variable.
- Robust error handling to avoid crashes and memory leaks.
- Ability to read from multiple file descriptors simultaneously.
- Integration with testing frameworks for thorough validation.

## Key Parts from an Academic View

#### Subject Summary

##### Requirements
- Must be done in C.
- Must follow the Norm; any violations will lead to a grade of 0.
- All memory must be properly managed and freed to prevent leaks.
- Submission of a **Makefile** to compile the project using the appropriate flags.
- The function must be compiled with and without the `-D BUFFER_SIZE` flag.

##### Mandatory Part
- Implement the `get_next_line` function with the prototype:
  ```c
  char *get_next_line(int fd);
  ```
- The function should:
  - Return a line read from the specified file descriptor, including the newline character, unless at the end of the file.
  - Return `NULL` when there's nothing left to read or if an error occurs.
- Ensure the function works for both file and standard input.
- The header file `get_next_line.h` must contain the function prototype.
- Helper functions should be implemented in `get_next_line_utils.c`.
- Compile using:
  ```bash
  cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
  ```
  
##### Bonus Part
- Develop the get_next_line() function using only one static variable to manage the state of the reading process.
- The implementation must handle multiple file descriptors simultaneously, allowing calls to get_next_line() to read from different descriptors without losing the state of each.

<br><br>
<hr style="width: 50%; margin: auto;">
<br><br>

*Good luck!* Don’t hesitate to reach out if you have questions or suggestions for improving this README file! Feel free to star the repository if you find it useful and want to support me! ⭐ Sharing it with friends who might be struggling will also make you a hero!

## Author and Contributing

This project was created by RaphRsl as part of my curriculum at École 42 Paris (username rroussel). It is intended for academic purposes only. If you found this project useful, please consider starring the repository to show your support! ⭐

### How to Contribute

1. Fork the repository.
2. Create a new branch:
   ```bash
   git checkout -b feature-name
   ```
3. Commit your changes:
   ```bash
   git commit -m 'Add new feature'
   ```
4. Push to the branch:
   ```bash
   git push origin feature-name
   ```
5. Open a pull request.
