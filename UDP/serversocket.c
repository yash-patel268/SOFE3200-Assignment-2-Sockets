// Server side C/C++ program to demonstrate Socket programming 
#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include<arpa/inet.h>
#include <string.h>

int main(int argv, char *afgv[]){ 

int socket_desc, c,read_size;
long unsigned int client_socket ;
char server_message[2000], client_message[2000];
struct sockaddr_in server, client;
int client_struct_length = sizeof(client);
//char client_message[1000];




// get a socket in udp
socket_desc = socket(AF_INET, SOCK_DGRAM,0); 
if (socket_desc==-1){ 
	 printf("Could not create socket.");
}
puts("Socket created");

//fill the fields 
server.sin_addr.s_addr = inet_addr("127.0.0.1");
server.sin_family =AF_INET; 
server.sin_port = htons( 8888 ); 


//bind the socket to the port
if(bind(socket_desc,(struct sockaddr *)&server, sizeof(server))<0){ 
	perror("bind faild. error");
	return 1;
}

//start listening for incoming connections
puts("bind done");
puts("Listening for incoming message");

puts("waiting for incomming connections...");
c = sizeof(struct sockaddr_in);
printf("Received message from IP: %s and port: %i\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
           
if (recvfrom(socket_desc, client_message, sizeof(client_message), 0, (struct sockaddr*)&client, &client_struct_length) < 0){
    	printf("Couldn't receive\n");
        return -1;
}

//while(read_size=recv(client_socket, client_message, 2000,0)>0) { 

	
	puts(client_message);
	
	//place holder for first digit
	char str[10]="";
	//place holder for second digit
	char dup[10]="";
	//variable to hold anwser to the equation
	char rstr[10]="";
	//variable to assign an index to delete
	int idxToDel=0;
	//check if the equation was successfull or not, deflaut is 1 meaning success
	int check=1;
	
	//variable for success message
	char success[]="Success: 1, Answer: ";
	//variable for fail message
	char fail[]="Success: 0, Error: Tried to divide by 0";
	
	//add
	//check if client message has a which is unique to add
	char *quotPtr = strchr(client_message, 'a');
	//if a exists
    	if(quotPtr != NULL){
    		//remove add portion from string
        	for(int i=0; i<=2; i++){
            		idxToDel = 0; 
            		memmove(&client_message[idxToDel], &client_message[idxToDel + 1], strlen(client_message) - idxToDel);
        	}   
    		
		//copy the remain numbers to str and dup
		strcpy(str, client_message);
		strcpy(dup, client_message);
		
		//remove second digit in str variable
		idxToDel = 1; 
		memmove(&str[idxToDel], &str[idxToDel + 1], strlen(str) - idxToDel);
		//Remove first digit in dup
		idxToDel = 0;
		memmove(&dup[idxToDel], &dup[idxToDel + 1], strlen(dup) - idxToDel);
	    	//parse int the strings and add them
		int x= atoi(str) + atoi(dup);
		//convert the int to string and assign to rstr
		sprintf(rstr, "%d", x);
    	}
    	
    	//sub
    	//check if client message has s which is unique to sub
	quotPtr = strchr(client_message, 's');
	//if s exists
    	if(quotPtr != NULL){
    		//remove sub portion from string
        	for(int i=0; i<=2; i++){
            		idxToDel = 0; 
            		memmove(&client_message[idxToDel], &client_message[idxToDel + 1], strlen(client_message) - idxToDel);
        	}   
    		
		//copy the remain numbers to str and dup
		strcpy(str, client_message);
		strcpy(dup, client_message);
		//remove second digit in str variable
		idxToDel = 1; 
		memmove(&str[idxToDel], &str[idxToDel + 1], strlen(str) - idxToDel);
		//Remove first digit in dup
		idxToDel = 0;
		memmove(&dup[idxToDel], &dup[idxToDel + 1], strlen(dup) - idxToDel);
	    	//parse int the strings and sub them
		int x= atoi(str) - atoi(dup);
		//convert the int to string and assign to rstr
		sprintf(rstr, "%d", x);
    	}
    	
    	//mul
    	//check if client message has m which is unique to mul
    	quotPtr = strchr(client_message, 'm');
    	//if m exists
    	if(quotPtr != NULL){
    		//remove mul portion from string
        	for(int i=0; i<=2; i++){
            		idxToDel = 0; 
            		memmove(&client_message[idxToDel], &client_message[idxToDel + 1], strlen(client_message) - idxToDel);
        	}   
    		
		//copy the remain numbers to str and dup
		strcpy(str, client_message);
		strcpy(dup, client_message);
		//remove second digit in str variable
		idxToDel = 1; 
		memmove(&str[idxToDel], &str[idxToDel + 1], strlen(str) - idxToDel);
		//Remove first digit in dup
		idxToDel = 0;
		memmove(&dup[idxToDel], &dup[idxToDel + 1], strlen(dup) - idxToDel);
	    	//parse int the strings and mul them
		int x= atoi(str) * atoi(dup);
		//convert the int to string and assign to rstr
		sprintf(rstr, "%d", x);
    	}
    	
    	//div
    	//check if client message has v which is unique to div
    	quotPtr = strchr(client_message, 'v');
    	//if v exists
    	if(quotPtr != NULL){
    		//remove mul portion from string
        	for(int i=0; i<=2; i++){
            		idxToDel = 0; 
            		memmove(&client_message[idxToDel], &client_message[idxToDel + 1], strlen(client_message) - idxToDel);
        	}   
    		
		//copy the remain numbers to str and dup
		strcpy(str, client_message);
		strcpy(dup, client_message);
		//remove second digit in str variable
		idxToDel = 1; 
		memmove(&str[idxToDel], &str[idxToDel + 1], strlen(str) - idxToDel);
		//Remove first digit in dup
		idxToDel = 0;
		memmove(&dup[idxToDel], &dup[idxToDel + 1], strlen(dup) - idxToDel);
		//if one of the digits is zero change check to zero, meaning unsuccessful
		if(atoi(str)==0 || atoi(dup)==0){
			check=0;
		}
	    	//parse double the strings and div them
		double x= atof(str) / atof(dup);
		//convert the double to string and assign to rstr
		sprintf(rstr, "%f", x);
    	}
	//if there was no zero, thus successful
	if(check==1){
		strcat(success, rstr);
		if (sendto(socket_desc, success, strlen(success), 0,
        	(struct sockaddr*)&client, client_struct_length) < 0){
        		printf("Can't send\n");
        		return -1;
    		}
	
	}
	//if there was a zero, thus unsuccessful
	if(check==0){
		if (sendto(socket_desc, fail, strlen(fail), 0,
        	(struct sockaddr*)&client, client_struct_length) < 0){
        		printf("Can't send\n");
        		return -1;
    		}
	}
		 

 


if(read_size==0){ 
  puts("client disconnected");
  fflush(stdout);
}
else if(read_size==-1){
 perror("recv failed");
}
 

return 0;
}
