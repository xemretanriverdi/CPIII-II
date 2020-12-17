#include "compress.h"
#include <stdio.h>
#include <stdlib.h>
#define X 6
#define Y 6





void compress_IJ(int **A, int *nz, int *rows, int *cols){

	
}

int **decompress_IJ(int *nz, int *rows, int *cols){

	
	
	
}

void compress_CRS(int **A, int *nz, int *col_ind, int *row_ptr){
	int count = 0;
int i,j;
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
	
	

	
	
	
}


int **decompress_CRS(int *nz, int *col_ind, int *row_ptr){
	
	
	
}


void compress_CCS(int **A, int *nz, int *row_ind, int *col_ptr){
	
int i,j;
  int count = 0;
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
	
	
	
}


int **decompress_CCS(int *nz, int *row_ind, int *col_ptr){
	
	
	
}

