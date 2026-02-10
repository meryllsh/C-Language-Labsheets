#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
int pid = fork();
if (pid==-1) {
return 1;
}
if(pid==0) { //child process
sleep(5);
// Open the file for appending
    int file = open(FILENAME, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (file < 0) {
        perror("Error opening the file");
        exit(1);
    }

    char input[100]={"101"};

        // Write user input to the file
        write(file, input, sizeof(input) - 1);
    }
      
    // Close the file
    close(file);
    exit(0);
    }
}
else {

    // Open the file for appending
    int file = open(FILENAME, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (file < 0) {
        perror("Error opening the file");
        exit(1);
    }

    // Prompt the user for input
    char input[100];
    printf("Enter some text (you have 5 seconds): ");
    scanf("%s",input);
    
        // Write user input to the file
        write(file, input, sizeof(input) - 1);

        printf("Input added to the file.\n");
    }
      exit(0);
    // Close the file
    close(file);
    }
    


return 0;
}


