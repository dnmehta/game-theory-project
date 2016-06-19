#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int gameover(int a[][3],int r,int c){
	if(r==c){
		if(a[0][0]==a[1][1]&& a[1][1]==a[2][2] && a[0][0]!=0){
			return 1;
		}
		if(a[0][c]==a[1][c] && a[1][c]==a[2][c] && a[0][c]!=0){
			return 1;
		}
		if(a[r][0]==a[r][1] && a[r][1]==a[r][2] && a[r][0]!=0){
			return 1;
		}
	}
	 if(r==(2-c)){
		if(a[0][2]==a[1][1]&& a[1][1]==a[2][0] && a[0][2]!=0){
			return 1;
		}
		if(a[0][c]==a[1][c] && a[1][c]==a[2][c] && a[0][c]!=0){
			return 1;
		}
		if(a[r][0]==a[r][1] && a[r][1]==a[r][2] && a[r][0]!=0){
			return 1;
		}
	}
	if(a[0][c]==a[1][c] && a[1][c]==a[2][c] && a[0][c]!=0){
			return 1;
		}
		if(a[r][0]==a[r][1] && a[r][1]==a[r][2] && a[r][0]!=0){
			return 1;
		}
	return 0;
}






 
int max(int a[][3],int rp,int x,int y);
int min(int a[][3],int rp,int x,int y);


int max(int a[][3],int rp,int x,int y){
	

	
	int temp1[3][3];
	int i,j;
	int maxi=-999;
	
	
	
	
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			temp1[i][j]=a[i][j];
		}
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(temp1[i][j]==0){
			
				temp1[i][j]=1;
				int q=gameover(temp1,i,j);
				if(q==1){
					
					return 10;
				}
				if(q==0 && rp==1){
					return 0; 
				}
				else{
					int c2=min(temp1,rp-1,x,y);
					if(c2!=(-999) && c2>x){
						x=c2;
					}
					if(x>y){
						return 999;
					}
				}
			
			temp1[i][j]=0;
			}
			
		}
	}
	
	return x;
}


int min(int a[][3],int rp,int x,int y){
	
	int temp2[3][3];
	int i,j;
	
	
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			temp2[i][j]=a[i][j];
		}
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(temp2[i][j]==0){
				
				temp2[i][j]=2;
				int q=gameover(temp2,i,j);
				if(q==1){
					return -10;
				}
				if(q==0 && rp==1){
					return 0; 
				}
				else{
				int c1=max(temp2,rp-1,x,y);
				if(c1!=999 && c1<y){
					y=c1;
				}
				if(y<x){
					
					return -999;
				}
			}
			temp2[i][j]=0;
		}
		
		}
	}
	return y;
	
	
}




int computerchance(int a[][3],int rp){
	int temp3[3][3],i,j,l=0,k=0;
		for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			temp3[i][j]=a[i][j];
		}
	}
	
	
	
	
	
	
	int maximum=-999;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(temp3[i][j]==0){
				
				temp3[i][j]=1;
				int q=gameover(temp3,i,j);
				if(q==1){
					
					a[i][j]=1;
					return 10;
				} 
				if(q==0 && rp==1){
					return 0; 
				}
				else{
				
				int c=min(temp3,rp-1,-999,999);
				
				if(c>maximum){
					
					l=i;
					k=j;
					maximum=c;
				}
				
			}
			temp3[i][j]=0;
			
		}
		
		
		
		}
	}
	a[l][k]=1;
	return 3*l+k;
	
}





int main(){
	int r,c,a[3][3],i,j,k=0,cchance=1;
	
	printf("player is 2 and computer is 1 :)\n");
	printf("please follow zero indexing\n");

	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			a[i][j]=0;
		}
	}
	printf("do u wanna play first, Y or N \n?");
		char ans;
		scanf("%c",&ans);
	
	if(ans=='N'){
	
		a[1][1]=1;
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	
while(cchance<10 && k<10){
		clock_t start,end;
		
		printf("please enter your move in terms of the co-ordinate of your box seperated by a space.. Please dont enter a cordinate which is already filled\n");
		
		
		
		scanf("%d %d",&r,&c);
		
		start=clock();
		
		a[r][c]=2;
		
		int q=gameover(a,r,c);
		if(q==10){
			cchance=-20;
			break;
		}
		
		cchance=computerchance(a,8-k);
		
		
		printf("computer played at %d %d\n",(cchance/3),(cchance%3));
	
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
		k+=2;
		end=clock();
		double time_taken=((double)(end-start))/CLOCKS_PER_SEC;
		printf("%f\n",time_taken);
}
		
	
	if(cchance==10){
		printf("computer won");
	}
	if(k==10){
		
		printf("draw");
	}
	if(cchance<0){
		printf("player won");
	}

}
