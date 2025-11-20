#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[])
{
    //Get the time
    time_t A = time(NULL);

    //Space for the name of the topic
    char *topic = malloc(sizeof(char)*10);
    if(topic == NULL)
        return -1;

    //Topic name is everything after the 0th index 
    //i.e. you can write a topic name with spaces
    for(int i = 1 ; i < argc ; i++)
    {
	//check if you have enough space for the next argument
        int size_of_topic = strlen(topic);
        int size_of_next_argument = strlen(argv[i]);
        if(100-size_of_topic < size_of_next_argument)
	    //skip if no
            break;

	//concatenate argument to topic
        strcat(topic, argv[i]);

        if(i != argc-1)
            strcat(topic, " ");
    }

    char *file_name = malloc((sizeof(char))*180);
    if(file_name == NULL)
        return -1;

    sprintf(file_name, "%02d-%02d-%d_%02d:%02d_[%s]", localtime(&A)->tm_mday, localtime(&A)->tm_mon+1, localtime(&A)->tm_year+1900, localtime(&A)->tm_hour, localtime(&A)->tm_min, topic);

    char *cmd = malloc(sizeof(char)*200);
    if(cmd == NULL)
        return -1;

    sprintf(cmd, "nano journal/\"%s.txt\"", file_name);
    system(cmd);
    system("git add .");
    system("git commit -m \"Added a though\"");
    system("git push");
    return 0;
}
