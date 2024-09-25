#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<dirent.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

// Experiment 4

int main(){   //    Q -> 1 , 3 , 4
    char name[250], path_name[250];
    scanf("%s %s", name, path_name);
    mkdir(name);
    rmdir(name);
    getcwd(path_name, sizeof(path_name));
}

int main(){  // Q - 2;
    DIR *d;
    struct dirent *de;
    d = opendir(".");
    while(de = readdir(d)){
        printf("%s\n",de->d_name);
    }
}

// Experiment 3;

int main(){  // Q -> 1
    char filename[250], output[250];
    scanf("%s",filename);
    int fd1 = open(filename, O_RDONLY);
    int choice;
    int size = lseek(fd1, 0, SEEK_END);
    int half = size/2;
    scanf("%d",&choice);
    if(choice == 1){
        lseek(fd1, 0, SEEK_SET);
    } else if(choice == 2){
        lseek(fd1, half, SEEK_SET);
    } else{
        printf("Invalid choice!");
        return 0;
    }
    scanf("%s",output);
    int fd2 = open(output, O_WRONLY | O_TRUNC | O_CREAT | O_APPEND, 0777);
    char ch;
    while(half > 0 && read(fd1, &ch, 1)){
        write(fd2, &ch, 1);
        half--;
    }
}

int main(){  // Q -> 3
    int fd1 = ("input.txt", O_RDONLY);
    int fd2 = ("Encrypted.txt", O_WRONLY | O_TRUNC | O_APPEND | O_CREAT);
    char ch;
    while(read(fd1, &ch, 1)){
        ch = ch + 3;
        write(fd2, &ch, 1);
    }
}

int main(){  // Q-2
    int fd1 = open("input.txt",O_WRONLY | O_APPEND | O_CREAT | O_TRUNC);
    char ch;
    printf("Enter input: \n");
    while(1){
        ch = getchar();
        if(ch == '$')break;
        write(fd1, &ch, 1);
    }
}