#include<stdio.h> 
 
void worstfit(int b, int p, int blocks[],int process[]) 
{ 
	int max_sort(int blocks[], int b) 
	{ 
		int temp,i,j; 
		for(i=0; i<b;i++) 
		{ 
			for(j=i+1;j<b;j++) 
			{ 
				if(blocks[i]<blocks[j]) 
				{ 
					temp=blocks[i]; 
					blocks[i]=blocks[j]; 
					blocks[j]=temp; 
				} 
			} 
		} 
	} 
 
	int flag,i,j,temp_blocks[30]; 
	for(i=0;i<b;i++) 
	{ 
		temp_blocks[i]=blocks[i]; 
	} 
	printf("\nWorst Fit:\n"); 
	for(i=0;i<p;i++) 
	{ 
		max_sort(temp_blocks,b); 
		flag=-1; 
		for(j=0;j<b;j++) 
		{ 
			if(temp_blocks[j]>=process[i]) 
			{ 
				if(flag==-1)
				{ 
					flag=j; 
				} 
			} 
		} 
		if (flag!= -1) 
		{ 
			printf("\nThe process of size %dKB has been assigned to block %dKB\n",process[i], temp_blocks[flag] ); 
			temp_blocks[flag] -= process[i]; 
			printf("Size Of hole after assigning the process: %dKB\n",temp_blocks[flag]); 
 
		} 
		else
		{ 
			printf("\nThe process of size %dKB is in wait state\n",process[i]); 
		} 
	} 
} 


void firstfit(int b, int p, int blocks[],int process[]) 
{ 
	int flag,i,j,temp_blocks[30]; 
	for(i=0;i<b;i++) 
	{ 
		temp_blocks[i]=blocks[i]; 
	} 
	printf("\nFirst Fit:\n"); 
	for(i=0;i<p;i++) 
	{ 
		flag=-1; 
		for(j=0;j<b;j++) 
		{ 
			if(temp_blocks[j]>=process[i]) 
			{ 
				if(flag==-1)
				{ 
					flag=j; 
				} 
			} 
		} 
		if (flag!= -1) 
		{ 
			printf("\nThe process of size %dKB has been assigned to block %dKB\n",process[i], temp_blocks[flag] ); 
			temp_blocks[flag] -= process[i]; 
			printf("Size Of hole after assigning the process: %dKB\n",temp_blocks[flag]); 
 
		} 
		else
		{ 
			printf("\nThe process of size %dKB is in wait state\n",process[i]); 
		} 
	} 
} 


void bestfit(int b, int p, int blocks[],int process[]) 
{ 
	int asc_sort(int blocks[], int b) 
	{ 
		int temp,i,j; 
		for(i=0; i<b;i++) 
		{ 
			for(j=i+1;j<b;j++) 
			{ 
				if(blocks[i]>blocks[j]) 
				{ 
					temp=blocks[i]; 
					blocks[i]=blocks[j]; 
					blocks[j]=temp; 
				} 
			} 
		} 
	} 
 
	int flag,i,j,temp_blocks[30]; 
	for(i=0;i<b;i++) 
	{ 
		temp_blocks[i]=blocks[i]; 
	} 
	printf("\nBest Fit:\n"); 
	for(i=0;i<p;i++) 
	{ 
		asc_sort(temp_blocks,b); 
		flag=-1; 
		for(j=0;j<b;j++) 
		{ 
			if(temp_blocks[j]>=process[i]) 
			{ 
				if(flag==-1)
				{ 
					flag=j; 
				} 
			} 
		} 
		if (flag!= -1) 
		{ 
			printf("\nThe process of size %dKB has been assigned to block %dKB\n",process[i], temp_blocks[flag] ); 
			temp_blocks[flag] -= process[i]; 
			printf("Size Of hole after assigning the process: %dKB\n",temp_blocks[flag]); 
 
		} 
		else
		{ 
			printf("\nThe process of size %dKB is in wait state\n",process[i]); 
		} 
	} 
} 

int main() 
{ 
	int choice,b,p,blocks[30],processes[30],i,j; 
	printf("\nEnter the number of blocks:"); 
	scanf("%d",&b); 
	for(i=0;i<b;i++) 
	{ 
		printf("\n\tEnter the value of block %d in KB:",i+1); 
		scanf("%d",&blocks[i]); 
	} 
	printf("\nEnter the number of processes:"); 
	scanf("%d",&p); 
	for(i=0;i<p;i++) 
	{ 
		printf("\n\tEnter value of process %d in KB:",i+1); 
		scanf("%d",&processes[i]); 
	} 
 
	printf("\nChoose an algorithm:"); 
	printf("\n1.Best fit\n2.First Fit\n3.Worst Fit\n4.Exit"); 
	do{ 
		printf("\nEnter your choice:"); 
		scanf("%d",&choice); 
		printf("\n"); 
		if(choice == 1) 
		{ 
			bestfit(b,p,blocks,processes); 
		} 
		if(choice==2) 
		{ 
			firstfit(b,p,blocks,processes); 
		} 
		if(choice==3) 
		{ 
			worstfit(b,p,blocks,processes); 
		} 
	}while(choice<=3); 
	return 0; 
}

