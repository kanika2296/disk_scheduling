#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main()
{
   int i, n,total=0,curr,min,pos,j,k,up,low,flag;
   int a[12],b[12],c[12],d[12];
   time_t t;
   int set=1;
   int sum[3]={0};
   n = 12;
   
   /* Intializes random number generator */
   srand((unsigned) time(&t));
while(set < 13 )
{   /* random numbers from 0 to 1000 */
   for( i = 0 ; i < n ; i++ ) 
   {
       a[i]=rand() % 1000;
   }
   printf("\tSET %d FCFS\n",set);
   printf("CYLINDERS \t");
   for( i=0 ;i<n;i++)
   {	if(a[i]<10)											//printing the cylinder values in fcfs
   			printf("%d   ",a[i]);
   		else if(a[i]<100)
   			printf("%d  ",a[i]);
   		else
   			printf("%d ",a[i]);
   }
   
   printf("\nDISTANCE \t");
   if(a[0]<500)
   		b[0]=500-a[0];										//calculating values arm distance from header i.e. 500
   	else
   		b[0]=a[0]-500;
   		
   for(i=1;i<n;i++)											//calculating arm movement from each movement and storing them in array b
   {
   		if(a[i]>a[i-1])
   			b[i]=a[i]-a[i-1];
   		else
   			b[i]=a[i-1]-a[i];
   }
   
   for( i=0 ;i<n;i++)										// printing values in array b
   {
			if(b[i]<10)
   				printf("%d   ",b[i]);
   			else if(b[i]<100)
   				printf("%d  ",b[i]);
   			else
   				printf("%d ",b[i]);
	}
	total=0;
	for(i=0;i<n;i++)
	{
		total=total+b[i];									//storing the sum of arm movement in variable total
	}
	
	printf("\t TOTAL=%d",total);
	sum[0]=sum[0]+total;
	
	
   printf("\n\tSET %d SSF\n",set);
   printf("CYLINDERS \t");
   
   for(i=0;i<n;i++)
   {
   		b[i]=a[i];											// copying the original sequence of request in array b and c					
   		c[i]=a[i];
   }
   
   curr=500;												//curr stores the disk cylinder at which arm is currently present
   for(i=0;i<n;i++)											//this loop arranges the sequence in which the cylinders be accessed according to SSF
   	{
		for(j=i;j<n;j++)
   		{
	   		if(b[j]>curr)									// calculating the arm movement from current cylinder for each request			
	   			c[j]=b[j]-curr;
 	  		else
 	  			c[j]=curr-b[j];
 	  	}
 	   min=1000;
 	   for(j=i;j<n;j++)										//finding minimum arm disk movement cylinder and storing its position in variable pos
 	 	 {
 	  		if(c[j]<min)
 	  		{
 	  			min=c[j];
 	  			pos=j;
			}
 	 	 }
 	 	k=b[pos];											//swapping content of the variable at pos and the current
 	 	b[pos]=b[i];
 	 	b[i]=k;
 	 	curr=b[i];											// current cylinder to be updated
 	}
 	
 	for( i=0 ;i<n;i++)										//print sequence in which cylinder will be accessed	
   {
			if(b[i]<10)
   				printf("%d   ",b[i]);
   			else if(b[i]<100)
   				printf("%d  ",b[i]);
   			else
   				printf("%d ",b[i]);
	}
	
   for(i=0;i<n;i++)											//copying contents of b in c
   {
   		c[i]=b[i];
   }
   
   if (b[0]<500)											// finding number of movements which the first step will take
   		c[0]=500-b[0];
	else
   		c[0]=b[0]-500;
   		
   	for(i=1;i<n;i++)										// calculating the number of movements in each step and storring them in array c
   	{
   		if(b[i]>b[i-1])
   			c[i]=b[i]-b[i-1];
   		else
   			c[i]=b[i-1]-b[i];
	 }
	 printf("\nDISTANCE \t");									//printing the disk movements
	 
	 for( i=0 ;i<n;i++)
  	{
			if(c[i]<10)
   				printf("%d   ",c[i]);
   			else if(c[i]<100)
   				printf("%d  ",c[i]);
   			else
   				printf("%d ",c[i]);
	}
	 
   	total=0;
   	
   	for(i=0;i<n;i++)										// adding the disk movements in SSF
   	{
   		total=total+c[i];
	}
	
	printf("\t TOTAL=%d",total);
	sum[1]=sum[1]+total;
	
	
	printf("\n\tSET %d ELEVATOR\n",set);
    printf("CYLINDERS \t");
    for(i=0;i<n;i++)
    {
    	b[i]=a[i];
	}
	up=0;low=0;						//up stores the no of cylinder accessed in going up and low store the no of cylinder gets accessed while coming back
	for(i=0;i<n;i++)
	{
		if(b[i]>500)
		{
			c[up++]=b[i];
		}
		else 
		d[low++]=b[i];
	}
	for(i=0;i<up;i++)						//sorting the cylinders greater than 500 in increasing order as we are moving in up direction
	{
		for(j=i;j<up;j++)
		{
			if(c[i]>c[j])
			{
				k=c[i];
				c[i]=c[j];
				c[j]=k;
			}
		}
	}
	for(i=0;i<low;i++)						//sorting the cylinders less than 500 in decreasing order as we will service their request on back way
	{
		for(j=i;j<low;j++)
		{
			if(d[i]<d[j])
			{
				k=d[i];
				d[i]=d[j];
				d[j]=k;
			}
		}
	}
	for(i=0;i<up;i++)						//copying the increasing and decreasing list in array b			
	{
		b[i]=c[i];
	}
	low=0;
	for(i=up;i<n;i++)
	{
		b[i]=d[low++];
	}
	for( i=0 ;i<n;i++)						//print values of array b which will give us the order in which services are processed in ELEVATOR	
   {
			if(b[i]<10)
   				printf("%d   ",b[i]);
   			else if(b[i]<100)
   				printf("%d  ",b[i]);
   			else
   				printf("%d ",b[i]);
	}
	printf("\nDISTANCE \t");
	d[0]=b[i]-500;								//arm movement during first move
	flag=0;
	for(i=1;i<n;i++)
	{
		if((flag == 0)&&(b[i]<500))
		{									
			d[i]=(999-b[i-1]) + (999-b[i]);		//in elevator we go to the maximum memory accesible then follow back ,in our problem maximum memory is 999
			flag=1;
		}
		else if(b[i]<500)
		d[i]=b[i-1]-b[i];						//disk arm movement on our way back
		else 
		d[i]=b[i]-b[i-1];
	}
	for( i=0 ;i<n;i++)							//printing the arm movements in elevator algorithm
   {
			if(d[i]<10)
   				printf("%d   ",d[i]);			// eeach entry uses 4 spaces so that it produces equally spaced character and easy to read
   			else if(d[i]<100)
   				printf("%d  ",d[i]);
   			else
   				printf("%d ",d[i]);
	}
	total=0;
	for(i=0;i<n;i++)
	{
		total=total+d[i];
	}
	printf("\t TOTAL=%d",total);
	sum[2]=sum[2]+total;
	set++;
	printf("\n");
}

printf("\n\nThe average number of arm movements in FCFS is %d ,SSF is %d and ELEVATOR is %d .",sum[0]/12,sum[1]/12,sum[2]/12);
   return(0);
}
