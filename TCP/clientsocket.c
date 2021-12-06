#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>  
#include <string.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

//custion function to remove spaces
void remove_spaces(char* s);

int main(int argc, char *argv[])
{
    int sock;

    struct sockaddr_in server;


    //char message[1000], server_reply[2000];
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) 
        printf("ERROR opening socket"); 
    puts("Socket created");	

    server.sin_addr.s_addr=inet_addr("127.0.0.1");   
    server.sin_family = AF_INET;
    server.sin_port = htons(8888);

    if (connect(sock,(struct sockaddr *)&server,sizeof(server)) < 0){ 
        printf("ERROR connecting");
	return 1;
}
    puts("Connected");

while(1){
    //create variables to store client input and server output
    char message[10]="", server_reply[3000]="";
    //message to tell user to enter the equation
    printf("Please enter the equation: ");
    //get the user input
    fgets(message, 10, stdin);
    
    //array to hold numbers entered by user
    char *array[10];
    //variable used to increment through the array that holds numbers
    int i=0;
    //variable to hold the equation after it is converted
    char newstring[10]="";
    //variable to hold first number
    char holder[1]="";
    //variable to hold second number
    char holder2[1]="";
    //remove extra spaces in the user input
    remove_spaces(message);
    
    //plus
    //for when user enters addition equation
    //check if there is a + sign
    char *quotPtr = strchr(message, '+');
    //if there is a + sign
    if(quotPtr != NULL){
    	//break the message var by the + sign, leaving only the numbers
        array[i] = strtok(message,"+");
        //cycle through and assign the numbers to the array first digit in index 0 and second in index 1
        while(array[i]!=NULL){
            array[++i] = strtok(NULL,"+");
        }
        //add "add" to the newstring variable
        strcat(newstring, "add");
        //holder now has first digit
        strcpy(holder, array[0]);
        //first digit added to newstring
        strcat(newstring, holder);
        //holder2 now has second digit
        strcpy(holder2, array[1]);
        //second digit added to newstring
        strcat(newstring, holder2);
    }
    
    //minus
    //for when user enters subtraction equation
    //check if there is a - sign
    quotPtr = strchr(message, '-');
    //if there is a - sign
    if(quotPtr != NULL){
    	//break the message var by the - sign, leaving only the numbers
        array[i] = strtok(message,"-");
        //cycle through and assign the numbers to the array first digit in index 0 and second in index 1
        while(array[i]!=NULL){
            array[++i] = strtok(NULL,"-");
        }
        //add "sub" to the newstring variable
        strcat(newstring, "sub");
        //holder now has first digit
        strcpy(holder, array[0]);
        //first digit added to newstring
        strcat(newstring, holder);
        //holder2 now has second digit
        strcpy(holder2, array[1]);
        //second digit added to newstring
        strcat(newstring, holder2);
    }
    
    //multiply
    //for when user enters multiplication equation
    //check if there is a * sign
    quotPtr = strchr(message, '*');
    //if there is a * sign
    if(quotPtr != NULL){
    	//break the message var by the * sign, leaving only the numbers
        array[i] = strtok(message,"*");
        //cycle through and assign the numbers to the array first digit in index 0 and second in index 1
        while(array[i]!=NULL){
            array[++i] = strtok(NULL,"*");
        }
        //add "mul" to the newstring variable
        strcat(newstring, "mul");
        //holder now has first digit
        strcpy(holder, array[0]);
        //first digit added to newstring
        strcat(newstring, holder);
        //holder2 now has second digit
        strcpy(holder2, array[1]);
        //second digit added to newstring
        strcat(newstring, holder2);
    }
    
    //divide
    //for when user enters multiplication equation
    //check if there is a / sign
    quotPtr = strchr(message, '/');
    //if there is a / sign
    if(quotPtr != NULL){
    	//break the message var by the / sign, leaving only the numbers
        array[i] = strtok(message,"/");
        //cycle through and assign the numbers to the array first digit in index 0 and second in index 1
        while(array[i]!=NULL){
            array[++i] = strtok(NULL,"/");
        }
        //add "div" to the newstring variable
        strcat(newstring, "div");
        //holder now has first digit
        strcpy(holder, array[0]);
        //first digit added to newstring
        strcat(newstring, holder);
        //holder2 now has second digit
        strcpy(holder2, array[1]);
        //second digit added to newstring
        strcat(newstring, holder2);
    }
    
    //display the convert string
    puts(newstring);
    if (send(sock,newstring,strlen(newstring),0)< 0){ 
         printf("ERROR writing to socket");
	return 1;
	}
     
   if (recv(sock,server_reply,3000,0)<0){
	puts("recv failed");
	break;
	}
puts("server reply");
puts(server_reply);


}
close(sock);
    return 0;
}


void remove_spaces(char* s) {
    char* d = s;
    do {
        while (*d == ' ') {
            ++d;
        }
    } while (*s++ = *d++);
}
