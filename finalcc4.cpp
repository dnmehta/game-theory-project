#include<stdio.h>
#include<time.h>
//#include<conio.h>
int totalcount=0;
int counter=0;
int max(int a[][7],int count,int x,int y);
int min(int a[][7],int count,int x,int y);

int checkvertical(int a[][7],int r,int c){
	int k=0;
	while(a[r-k][c]==a[r][c] && r-k>=0){
		k++;
	}
	return k;
}
int checkhorizontal(int a[][7],int r,int c){
	int k=0,count=0;;
	while(a[r][c+k]==a[r][c] && c+k<=6){
		k++;
		count++;
	}
	k=0;
	while(a[r][c-k]==a[r][c] && c-k>=0){
		k++;
		count++;
	}
	return (count-1);
	
}

int checkdiagonal(int a[][7],int r,int c){
	int k=0,count=0;;
	while(a[r+k][c+k]==a[r][c] && r+k<=5 && c+k<=6){
		k++;
		count++;
	}
	k=0;
	while(a[r-k][c-k]==a[r][c] && r-k>=0 && c-k>=0){
		k++;
		count++;
	}
	k=0;
	int count1=0;
		while(a[r-k][c+k]==a[r][c] && r-k>=0 && c+k<=6){
		k++;
		count1++;
	}		
	k=0;
	while(a[r+k][c-k]==a[r][c] && r+k<=5 && c-k>=0){
		k++;
		count1++;
	}
	return count>count1?(count-1):(count1-1);
}




int gameover(int a[][7],int r,int c){
	if(r<=2){
	if(a[r][c]==a[r+1][c] && a[r+1][c]==a[r+2][c] && a[r+2][c]==a[r+3][c]){
		
		return 1;
		}
	}
	int c1=0;
	int k=0;
	while(a[r][c-k]==a[r][c] && c-k>=0){
		c1++;
		k++;
	}
	k=0;
	while(a[r][c+k]==a[r][c] && c+k<=6){
		c1++;
		k++;
	}
	
	if(c1>4){
	
		return 1;
	}
	c1=0;
	k=0;
	while(a[r+k][c+k]==a[r][c] && r+k<=5 && c+k<=6){
		c1++;
		k++;
	}
	k=0;
	while(a[r-k][c-k]==a[r][c] && r-k>=0 && c-k>=0){
		c1++;
		k++;
	}
	if(c1>4){
		return 1;
	}
	c1=0;
	k=0;
	
	while(a[r+k][c-k]==a[r][c] && r+k<=5 && c-k>=0){
		c1++;
		k++;
	}
	k=0;
	while(a[r-k][c+k]==a[r][c] && r-k>=0 && c+k<=6){
		c1++;
		k++;
	}
	if(c1>4){
		return 1;
	}
	
	
	
	return 0;
}

int gameevaluation(int a[][7],int r,int c,int n){
	int i,j;
	if(n==2){
		int min=100;
		if(gameover(a,r,c)==1){
		//	if((-100)<min){
				return -100;
		//	}
		}
		a[r][c]=1;
		if(gameover(a,r,c)==1){
			a[r][c]=2;
			//if((-90)<min){
				return -90;
			//}
		}
		a[r][c]=2;
		if(checkdiagonal(a,r,c)==3){
			//if((-70)<min){
				return -70;
			//}
			
		}
	    if(checkhorizontal(a,r,c)==3){
			//if((-50)<min)
			//{
				return -50;
			//}
		}
		a[r][c]=1;
			if(checkdiagonal(a,r,c)==3){
			//if((-60)<min){
				return -60;
			//}
		}
		a[r][c]=2;
		if(checkvertical(a,r,c)==3){
			//if((-40)<min){
				return -40;
			//}
		}
	    a[r][c]=1;
		
		if(checkhorizontal(a,r,c)==3){
			//if((-35)<min){
				return -35;
			//}
		}
		if(checkvertical(a,r,c)==3){
			//if((-30)<min){
				 return -30;
			//}
		}
		
		a[r][c]=2;
		
		
		
		if(checkdiagonal(a,r,c)==2){
			//if((-20)<min){
				return -20;
			//}
		}
		if(checkhorizontal(a,r,c)==2){
			//if((-15)<min){
				return -15;
			//}
		}
		if(checkvertical(a,r,c)==2){
			//if((-10)<min){
				return -10;
			//}
		}
		
		else{
			//if((-5)<min){
				return -5;
			//}
		}	
		return min;
		
		
	}
	
	else{
		int max=-100;
		if(gameover(a,r,c)==1){
			//if(100>max){
				return 100;
			//}
		}
		a[r][c]=2;
		if(gameover(a,r,c)==1){
			a[r][c]=1;
			//if(90>max){
				return 90;
			//}
		}
		a[r][c]=1;
		if(checkdiagonal(a,r,c)==3){
			//if(70>max){
				return 70;
			//}
		}
	    if(checkhorizontal(a,r,c)==3){
			//if(50>max){
				return 50;
			//}
		}
		a[r][c]=2;
			if(checkdiagonal(a,r,c)==3){
			//if(60>max){
				return 60;
			//}
		}
		a[r][c]=1;
		if(checkvertical(a,r,c)==3){
			//if(40>max){
				return 40;
			//}
		}
	    a[r][c]=2;
		if(checkvertical(a,r,c)==3){
			//if(30>max){
				return 30;
			//}
		}
		if(checkhorizontal(a,r,c)==3){
			//if(35>max){
				return 35;
			//}
		}
		a[r][c]=1;
		
		
		
		if(checkdiagonal(a,r,c)==2){
			//if(20>max){
				return 20;
			//}
		}
		if(checkvertical(a,r,c)==2){
			//if(10>max){
				return 10;
			//}
		}
		if(checkhorizontal(a,r,c)==2){
			//if(15>max){
				return 15;
			//}
		}
		else{
			//if(5>max){
			return 5;
		}
		}	
				
		
	}






int indexoffreespace(int a[][7],int c){
	int i=0;
	while(1){
	
	if(a[i][c]==0 && i<6){
		i++;
	}
	else{
		return (i-1);
	
	}
}
}

int max(int a[][7],int count,int x,int y){

	
	
	
	int maxi=-999;
	int i,j;
	for(j=0;j<7;j++){
		int i=indexoffreespace(a,j);
		if(i<0){
			continue;
		}
		a[i][j]=1;
		if(gameover(a,i,j)==1){
			a[i][j]=0;
			return 100-count;
				}
		else{
			if(count>9){
				
				int k2=gameevaluation(a,i,j,1);
				totalcount++;
				a[i][j]=0;
				return k2;
			}
			else{
			
				int c2=min(a,count+1,x,y);
					if(c2<y){
						if(c2>x){
							x=c2;
						}
										}
					else{
						a[i][j]=0;
						return c2;
					}
					
		}
	}
		a[i][j]=0;
	}
	return x;
}

int min(int a[][7],int count,int x,int y){
	
	
	int mini=999;
	int i,j;
	for(j=0;j<7;j++){
		int i=indexoffreespace(a,j);
		if(i<0){
			continue;
		}
		a[i][j]=2;
		if(gameover(a,i,j)==1){
			a[i][j]=0;
			return -100+count;
		}
		else{
			
			if(count>9){
				
				int k1=gameevaluation(a,i,j,2);
				totalcount++;
		
				a[i][j]=0;
				return k1;
			}
			
			else{
	
		int c1=max(a,count+1,x,y);
				if(c1>x){
					if(c1<y){
						y=c1;
					}
				}
				else{
					a[i][j]=0;
					return c1;
				}
		}
	}
		a[i][j]=0;
	}
	return y;


}





int computerchance(int a[][7]){
	int maxi=-999;
	int c=0;
	int j;
	for(j=3;j<7;j++){
		int i=indexoffreespace(a,j);
		if(i<0){
			continue;
		}
		a[i][j]=1;
		if(gameover(a,i,j)){
			a[i][j]=0;
			return j;
		}
		else{
			
			counter++;
			
			int n1=min(a,0,-999,999);
			if(n1>maxi){
				maxi=n1;
			
				c=j;	
			}
		}
		a[i][j]=0;
	}
	
	for(j=0;j<3;j++){
		int i=indexoffreespace(a,j);
		if(i<0){
			continue;
			
		}
		a[i][j]=1;
		if(gameover(a,i,j)){
			a[i][j]=0;
			return j;
		}
		else{
			
			counter++;
			
			int n2=min(a,0,-999,999);
			if(n2>maxi){
				maxi=n2;
			
				c=j;	
			}
		}
		a[i][j]=0;
	}
	return c;
}

void printboard(int a[][7]){
	int i,j;

	printf("C NO. 1 2 3 4 5 6 7\n");
	printf("\n");
	for(i=0;i<6;i++){
		printf("      ");
		for(j=0;j<7;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}







int main(){
	int a[6][7],i,j,cchance,moves=0;
	for(i=0;i<6;i++){
		for(j=0;j<7;j++){
			a[i][j]=0;
		}
	}
	
	printf("normal indexing is followed..columns from 1 to 7\n");
	printf("do you want to play first ?Y or N\n");
	char c;
	scanf("%c",&c);
	if(c=='n' || c=='N'){
	printf("okay.. computer played in the 4th column\n");
	
	a[5][3]=1;
	moves++;
}
	clock_t start,end;
	
	while(moves<42){
		
		int r,c;
		printf("enter column of your move\n");
		scanf("%d",&c);
		moves++;
		if(moves>=42){
			break;
		}
		if(c<1 || c>7){
			printf("please enter column between 1 and 7..\n");
			continue;
		}
		c=c-1;
		start=clock();
		r=indexoffreespace(a,c);
		a[r][c]=2;
		printboard(a);
		if(gameover(a,r,c)){
			printf("player won");
			break;
		}
		
		cchance=computerchance(a);
		moves++;
		int q=indexoffreespace(a,cchance);
		a[q][cchance]=1;
		printf("\n");
		if(gameover(a,q,cchance)==1){
			
			printboard(a);
			printf("computer played in %dth column\n",cchance+1);
			printf("computer won\n");
			printf("%d\n",cchance+1);
			break;
		}
		printboard(a);
		printf("computer played in %dth column\n",cchance+1);
		//printf("%d\n",totalcount);
		
			end=clock();
	double time_taken=((double)(end-start))/CLOCKS_PER_SEC;
	printf("time taken by comp. %f sec\n",time_taken);
		
	}
	if(moves>=42){
		printf("draw..\n");
	}


}  
