#include<stdio.h>
#include<stdlib.h>

int nRequests, nCylinders, currentHead, prevHead;

void getInput(){
	printf("No: of Requests              : ");
	scanf("%d", &nRequests);
	printf("No: of Cylinders             : ");
	scanf("%d", &nCylinders);
	printf("Current Head Position        : ");
	scanf("%d", &currentHead);
	printf("Previous Head Position       : ");
	scanf("%d", &prevHead);
}

void printRequests(int requests[]){
	for(int i=0; i<nRequests; i++){
		printf("%d\t", &requests[i]);
	}
	printf("\n");
}

void getRequestArray(int requests[]){
	printf("Enter the requests : ");
	for(int i=0; i<nRequests; i++){
		scanf("%d", &requests[i]);
		printf("%d", requests[i]);
	}
	printf("\n");
}

void FCFS(int requests[]){
    int seekTime = 0, head = currentHead; 
    int currentTrack;
    for (int i = 0; i < nRequests; i++) { 
        currentTrack = requests[i];
		seekTime += abs(currentTrack - head); 
		head = currentTrack; 
    }

    printf("\nSeek Time : %d\n", seekTime);
    printf("Head Movement : ");
    printRequests(requests);
} 

void main(){
	getInput();
	int requests[nRequests];
	getRequestArray(requests);
	printRequests(requests);
	// FCFS(requests);/
}