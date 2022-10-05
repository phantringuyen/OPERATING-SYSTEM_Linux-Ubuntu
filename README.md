### OPERATING SYSTEM
# Virtual Machine Linux with Ubuntu 18.04
## I. Set up a system call to work with files:
1. Install a system call **int Create(char*name)**. The Create system call will use the Nachos FileSystem Object to create an empty file. Pay attention that filename is in user space, which means that the buffer which the pointer in user space points to must be moved from user space to system space. System call Create returns 0 on success and -1 on error
2. Set up a system call **OpenFileID Open(char*name)** và **int Close(OpenFileID id)** (for opening and closing file)
3. Set up a system call **int Read(char*buffer, int size, OpenFileID id)** và **int Write(char*buffer, int size, OpenFileID id)**. The system calls read and write into file with the given ID. We must move the memory area between user space and system space, especially, we must distinguish between Console IO (OpenFileID 0, 1) and File.
4. Set up a system call **int Seek(int position, OpenFileID id)**. Seek has to move the cursor to suitable location. **position** save the location to move to, if pos = -1 then move to TOF. Return the real location in file if succeed and -1 if error. Call **Seek** in console must report an error.
5. Set up a system call **int Remove(char*name)**. **Remove system call** will use NachosFileSystem Object to delete file. Note: we must check if the file is open or not before deleting it.

## II. Create a program for users:
1. Write **createfile** program to check system call Create. We will use fixed file name, or let users to enter from the console from ReadString.
- *Example*: Create a file hello.txt

    `./nachos -x ../test/createfile hello.txt`


2. Write **cat** program, require users to enter filename, then display the contents of that file. 
- *Example*: Display the contents of hello.txt

    `./nachos -x ../test/cat hello.txt`


3. Write **copy** program, require users to enter source and destination file name and copy all of them.
- *Example*: Copy file a.txt and paste it to file b.txt

    `./nachos -x ../test/copy a.txt b.txt`


4. Write **delete** program to check system call **Remove**
- *Example*: delete file hello.c

    `./nachos -x ../test/delete hello.c`


5. Write **concatenate** program to concatenate the contents of 2 files, require users to enter source file 1 and source file 2
- *Example*: concatenate the contents of *a.txt* and *b.txt*

    `./nachos -x ../test/concatenate a.txt b.txt`
