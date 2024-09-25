#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<dirent.h>
#include<stdlib.h>
#include<fcntl.h>


// -------------------------------------------------------------------------------------------------------------
int main(){
    // creating new file
    open("sample.txt", O_WRONLY | O_CREAT | O_APPEND, 0755);
    // using chmod
    chmod("sample.txt", 0644);
    // using chown
    chown("sample.txt", 1001, 1002);
    // hard link
    link("sample.txt", "hardlink.txt");
    // symbolic link
    symlink("sample.txt", "sym_link.txt");
}

// -------------------------------------------------------------------------------------------------------------

int main(){
    char ch;
    int fd1 = open("input.txt", O_RDONLY);
    int fd2 = open("Encrypted.txt", O_WRONLY | O_CREAT | O_TRUNC);

    while(read(fd1, &ch, 1) > 0){
        ch = ch + 3;
        write(fd2, &ch, 1);
    }
}

// ----------------------------------------------------------------------------------------------------------

int main(){
    char ch;
    int fd = open("input.txt", O_WRONLY | O_CREAT| O_APPEND | O_TRUNC);
    printf("Enter Input: \n");
    while(1){
        scanf("%c",&ch);
        if(ch == '$') break;
        write(fd, &ch, 1);
    }
}

// --------------------------------------------------------------------------------------------------------------

int main(){
    char filename[250], output[250];
    scanf("%s",filename);
    int fd1 = open(filename, O_RDONLY);
    int choice;
    char ch;
    scanf("%d",&choice);
    int size = lseek(fd1, 0, SEEK_END);
    int half = size / 2;
    if(choice == 1){
        lseek(fd1, 0, SEEK_SET);
    } else if(choice == 2){
        lseek(fd1, half, SEEK_SET);
    } else{
        printf("Envalid Choice....");
        return 0;
    }
    scanf("%s", output);
    int fd2 = open(output, O_WRONLY | O_TRUNC | O_APPEND | O_CREAT);
    while(half > 0 && read(fd1, &ch, 1)){
        write(fd2, &ch, 1);
        half--;
    }
}



// ----------------------------------------------------------------------------------------------------------------

int main(){
    char dir_Name[250], path[250];
    scanf("%s %s",dir_Name, path);
    mkdir(dir_Name);
    printf("Directory created succesfuly");
    rmdir(dir_Name);
    printf("Directory Deleted succesfuly");

    getcwd(path, sizeof(path));
    printf("%s",path);

}

// -------------------------------------------------------------------------------------------------------------

int main(){
    DIR *d;
    struct dirent *de;
    d = opendir(".");
    while(de = readdir(d)){
        printf("%s\n", de->d_name);
    }
}