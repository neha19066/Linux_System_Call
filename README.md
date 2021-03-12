A Linux system call written in C, where the user enters a process id (pid) and a filename as parameters to obtain data about the given process which, is stored in the file entered by the user.
1. Preparation<br />-
The linux-5.9.1 source code is downloaded using ‘wget -P ~/ https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.9.1.tar.xz’ and extracted to a folder.<br />-
A few modules are required to compile a kernel, run ‘sudo apt install build-essential libncurses-dev libssl-dev libelf-dev bison flex -y’ and ‘sudo apt update && sudo apt upgrade -y’.<br />- 
We make a configuration file for the new kernel by going to the linux-5.9.1 folder and running ‘make menuconfig’. To be on the safe side, make no changes to the default settings and then save and exit.<br />
2. Writing the System Call<br />-
Stay in the linux-5.9.1 directory and change directory to arch/x86/syscalls/syscall_64.tbl.<br />- 
Add the syscall under the last row under the common (i.e. for 32 bit and 64 bit) system calls and save.<br />-Then, go to kernel/sys.c in the same linux-5.9.1 folder.<br />-
At the end of the file, define a syscall function (with the same name as used in the table) and save (check diff file for the code).<br />-
Exit the kernel directory and try running ‘make kernel’, this will show errors if there are any. Debug them before the compilation since that takes a lot of time.<br />
3. Compiling the Kernel<br />-
Go to linux-5.9.1 folder, to compile it, run ‘sudo make -j4’. If this shows any errors, resolve them and run it again before going further.<br />-
Then run ‘sudo make modules_install -j4’<br />-
Then run ‘sudo make install’ to install the kernel.<br />-Reboot the system.<br />-
Check the kernel version using ‘uname -r’, it should be linux-5.9.1 now.<br />
4. Testing<br />-
Call the system call in a C test file using the serial number assigned to it in the syscall table (in this case also input the pid of the process you need info about and the name of the file where that info is to be stored respectively as parameters).<br />-In this code, if it is executed successfully, a file with the name as given by the user will be created in the working directory. Or we can check the log via 'dmesg'.<br />- 
The process name, it's priority, flags, scheduling policy, task state will be stored in the file or displayed in the logs.<br /> 
5. Errors Handled<br />-
If a pid <=0 or greater than 32768 is entered, the function returns the EINVAL, the invalid argument error.<br />-
If the filename is not a string, ENOTSUPP is thrown.<br />-
If despite being a valid pid, the process is not running at the moment and hence can’t be found, ESRCH is thrown.<br />



