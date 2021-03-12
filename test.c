#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <errno.h>
#include <unistd.h>
int main()
{  
	printf("Testing 'sh_task_info' System Call\n");
	long int x = syscall(440, 1, "abc"); 
	if(x == 0) 
		printf("Test successful.\nUse dmesg to check logs.\n");

	else 
	{
		perror("Error ");
		printf("Test Unsuccessful. Error No.: %d\n", errno);
	}
	
	long int y = syscall(440, 2, "xyz"); 
	if(y == 0) 
		printf("Test successful.\nUse dmesg to check logs.\n");

	else 
	{
		perror("Error ");
		printf("Test Unsuccessful. Error No.: %d\n", errno);
	}
	return 0;
}