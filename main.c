#include "compress.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define X 6
#define Y 6

int main(){ 
//    Dev C kaynaklý projem çalýsmadý tüm methodlarý mainde yazdým. olduðu kadar hocam. saygýlar.
int nzsize;
int *nz;
int **A;
int i, j;
A=(int**)malloc(X*sizeof (int*));

for(i = 0;i<X;i++){
	A[i]=(int*)malloc(Y*sizeof (int)); 
	
	
}

for(i=0;i<X;i++){
	
for(j=0;j<Y;j++){
	A[i][j]=rand()%10;
	if(A[i][j]%2==0){  // sýfýr sayýsý arttýrmak icin
		A[i][j]=0;
	}
		
	
	
}
		
	
	
}



  for (i = 0; i < X; i++) {

    for (j = 0; j < Y; j++) {

      if (A[i][j] != 0) {
        nzsize++;
      }
    }
  }
nz=(int *)malloc(nzsize*sizeof (int));
  int * col_ind[nzsize];
  int * row_ptr[X + 1];
  int * row_ind[nzsize];
  int * col_ptr[Y + 1];

  puts("A elemanlari yazdir \n");
  for (i = 0; i < X; i++) {

    for (j = 0; j < Y; j++) {
      printf("%d  ", A[i][j]);

    }
    puts("\n ");

  }

  // nz olustur
  int count = 0;
  for (i = 0; i < X; i++) {

    for (j = 0; j < Y; j++) {

      if (A[i][j] != 0) {

        nz[count] = A[i][j]; //nz elemanlarýi
        count++;

      }
    }
  }
  
  
  puts("nz elemanlari \n");
  for (i = 0; i < nzsize; i++) {

    printf(" (%d) ", nz[i]);
  }
  puts("\n");

 

  count = 0;

  for (i = 0; i < X; i++) {
    int rest = 0;

    for (j = 0; j < Y; j++) {

      if (A[i][j] != 0) {
col_ind[count] = j; //nz sutun
        rest++;
        if (rest == 1) { //sadece ilk elemani yazdirmak icib
          row_ptr[i] = count;
        }

        

        count++;
      }
    }
    row_ptr[Y] = count;

  }
  	for(i=0;i<count;i++){

  		printf("%d elemani sutun indisi %d\n",nz[i],col_ind[i] );
  			
  }
  	for(i=0;i<Y;i++){

  		printf("%d. satirlardaki 0 dan farkli ilk eleman nz de indisi %d\n",i+1,row_ptr[i] );	
  }
  		printf("son eleman %d\n",row_ptr[Y] );	

  	

  		printf("*******************************************************");	

  count = 0;
  puts("\n \n \n");
int control[Y]={0};

  for (i = 0; i < X; i++) {
  
    for (j = 0; j < Y; j++) {
    	
      if (A[i][j] != 0) {
      	
        row_ind[count] = i; //nz sutun
        
        if(control[j]==0){
        
        	
        	col_ptr[j]=count;
        	
        	control[j]++;
		}
        

        count++;

      }
      col_ptr[X] = count;

    }
  }
  
  
  
  for (i = 0; i < count; i++) {

    printf("%d elemani satir indisi %d\n", nz[i], row_ind[i]);
  }
  for (i = 0; i < Y; i++) {

    printf("%d. sutunundaki 0 dan farkli ilk eleman nz de indisi %d\n", i + 1, col_ptr[i]);
  }
  	printf("son eleman %d\n",col_ptr[X] );
getch();
  return 0;
  
}
