#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[])
{
    time_t A = time(NULL);
    char *topic = malloc(sizeof(char)*100);
    for(int i = 1 ; i < argc ; i++)
    {
        strcat(topic, argv[i]);
        if(i != argc-1)
            strcat(topic, " ");
    }
    char file_name[180];
    sprintf(file_name, "%02d-%02d-%d_%02d:%02d_[%s]", localtime(&A)->tm_mday, localtime(&A)->tm_mon+1, localtime(&A)->tm_year+1900, localtime(&A)->tm_hour, localtime(&A)->tm_min, topic);
    char *cmd = malloc(sizeof(char)*200);
    sprintf(cmd, "nano journal/\"%s.txt\"", file_name);
    system(cmd);
    system("git add .");
    system("git commit -m \"Added a though\"");
    system("git push");
    return 0;
}