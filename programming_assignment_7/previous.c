/** ****************************  
 * Dou Jingru
 * CS 241
 * programming assignment 7
 * printing image 2-D array 
 *******************************/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* ***********************************
This program has several function and 
dedicated to invert, remove red eye and
flip an image. In the main function is
for printing and checking, and each 
function just do its own job. dfs function
is putting the image in index for red eye
function.
 * **********************************/

//#define ROW 100
//#define COL 100

void printImage(int size, char grid[size][size]);
void inv(int size, char grid[size][size]);
void flip(int size, char grid[size][size], char c);
void dfs(int size, char grid[size][size]);
void redeye(int size, char grid[size][size], int *gridColSize);


int main(int argc, char *argv[]) {
    int size;
    
    //scanf("%d\n", &size);
    //if(!isdigit(size)){
        //printf("pixel exit\n");
        //exit(1);
    //}
    int check = scanf("%d", &size);
    if(check != 0 && check < 1){ 
        exit(1);
    }
    printf("pixel-1\n");
    //scanf("%d\n\n", check);
    
    //int newlineCounter=size;
    //int colCounter=size;
    char grid[size][size];
    char pixel;
    pixel = getchar();
    pixel = getchar();
    //int newlineCounter;//also means rowCounter
    //int colCounter;
    //while((pixel=getchar()) != EOF){     
        //newlineCounter= pixel + 1;
       	//colCounter = ++pixel;
	//if(grid[size][size] != ' ' 
	//		&& grid[size][size] != '*'){
        //    printf("pixel-2\n");
        //    exit(1);
        //}	    
        
	//printf("pixel-3\n");
	//printf("col counter is %d\n", size);
	//printf("row counter is %d\n", newlineCounter);
        //if(colCounter != newlineCounter){
        //    printf("pixel1.2\n");
        //    exit(1);
        //}
        //newlineCounter = pixel++;
	//colCounter = pixel++;
        
        //if(pixel == '\n'){
        //    newlineCounter++;            
        //    if(colCounter != size){
        //        printf("pixel3 %i \n", colCounter);
                
        //    }
            //pixel=getchar();
            //printf("pixel-4\n");
        //    colCounter = 0;
            //newlineCounter++;
        //}else{
	    //pixel = getchar();
            //grid[size][size] = pixel;
            
        //}
        
        //if(newlineCounter == size && colCounter != 0){
        //    printf("pixel-5\n");
        //    exit(1);
        //}
	
        //printf("pixel-6\n");
        //colCounter++;
        //matrix[size][size] = pixel;
    //}//end while
    
    for(int i=0; i<size; i++){
	for(int j=0; j<size; j++){
	    grid[i][j] = pixel;
	    pixel = getchar();
	}
	pixel = getchar();
    }
    //++newlineCounter;
    //printf("%d newline counter\n", newlineCounter);
    printf("%d size\n", size);
    //if(newlineCounter != size){
    //    printf("pixel-7\n");
    //    exit(1);    
    //}
    //if(newlineCounter == size && colCounter == size){
    //    printf("pixel-8\n");
    //    exit(0);
    //}      
    //printf("&grid[%d][%d] = %c\t", i, j, &grid[i][j]);
    
     
    // parse parameters
    for(int i = 1; i < argc; i++){
	printf("check-3\n");
	//inside here rotate the function to call
        if(strcmp(argv[i], "flip") == 0){
            printf("check-1\n");
	    i++;
	    printf("%d", i);
            if((strcmp(argv[i], "v") != 0) && (strcmp(argv[i], "V") != 0)
             &&(strcmp(argv[i], "h") != 0) && (strcmp(argv[i], "H") != 0)){
                exit(2);
            }
	    printf("check-2\n");
	    flip(size, grid, argv[i][0]);
	    printImage(size, grid);
        }else if(strcmp(argv[i], "inv") == 0){
	    inv(size, grid);
            printImage(size, grid);
        }else if(strcmp(argv[i], "redeye") == 0){
            //redeye(grid, size, pixel);
            printImage(size, grid);
        }else if(strcmp(argv[i], " ") == 0){
            printImage(size, grid);
        }else{
            printf("exit to else\n");
            exit(2);
        }
    }
} 

void printImage(int size, char grid[size][size]){
    int i, j;
    printf("image\n");
    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
    return ;
}

void inv(int size, char grid[size][size]){
    char c = '*';
    char d = ' ';
    int i, j; 
    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){
            if(grid[i][j] == c){
                grid[i][j] = d;
            }else if(grid[i][j] == d){
                grid[i][j] = c;
            }else{
                exit(2);
            }
        }
    }    
}


void flip(int size, char grid[size][size], char c){
    int i, j;
    char temp;    
    if(c == 'h' || c == 'H'){
        for(i = 0; i < size/2; i++){
            for(j = 0; j < size; j++){
		temp = grid[i][j];
		grid[i][j] = grid[size-1-i][j];
                grid[size-1-i][j] = temp;
            }   
        }
    }
    if(c == 'v' || c == 'V'){
        for(i = 0; i < size; i++){
            for(j = 0; j < size/2; j++){
		temp = grid[i][j];
		grid[i][j] = grid[i][size-1-j];
		grid[i][size-1-j] = temp;
            }
        }
    }
}
/*
void dfs(int size, char grid[size][size]){
    int i,j;
    if(i<0 || i>= size || j<0 || j>=size){
        return false;
    }
    if(grid[i][j] == 1){
        return true;
    }
    grid[i][j] = '*';
    bool up =  dfs(grid, i-1, j, size);
    bool down = dfs(grid, i+1, j, size);
    bool left = dfs(grid, i, j-1, size);
    bool right = dfs(grid, i, j+1, size);
    bool upleft = dfs(grid, i-1, j-1, size);
    bool upright = dfs(grid, i-1, j+1, size);
    bool downleft = dfs(grid, i+1, j-1, size);
    bool downright = dfs(grid, i+1, j+1, size);

}
*//*
void redeye(int size, char grid[size][size], int *gridColSize){
    int i, j;
    bool redeye(grid, (i-1), j, size);
    bool redeye(grid, (i+1), j, size);
    bool redeye(grid, i, (j-1), size);
    bool redeye(grid, i, (j+1), size);
    bool redeye(grid, (i-1), (j-1), size);
    bool redeye(grid, (i-1), (j+1), size);
    bool redeye(grid, (i+1), (j-1), size);
    bool redeye(grid, (i+1, j+1, size);
    
    //if(i<0 || i>= size || j<0 || j>=size){
    //    return false;
    //}
    //if(grid[i][j] == 1){
    //    return true;
    //}
    int col = gridColSize[0];
    for(i = 0; i < size; i++){
        for(j = 0; j < col; j++){
            
	    if(grid[i][j]=='*' && dfs(grid, i, j, size)){
                grid[i][j] = ' ';
            }
	    
        }
    }
}
*/
