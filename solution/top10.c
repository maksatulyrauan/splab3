#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
void substring(char s[], char sub[], int p, int l) {
   int c = 0;
   
   while (c < l) {
      sub[c] = s[p+c-1];
      c++;
   }
   sub[c] = '\0';
}
//lines=$(cut -f4 -d' ' log.txt | wc -l)
int lines(){

	int A[2]; 
	pipe(A);
	pid_t pid1 = fork(); 
	if (!pid1) {
		dup2(A[1], 1);
		close(A[0]);
		close(A[1]);
		execlp("cat","cat", "log.txt", NULL);
		exit(EXIT_FAILURE);
	}

	int B[2];
	pipe(B);
	pid_t pid2 = fork();
	if (!pid2) { 
		dup2(A[0], 0);
		close(A[0]);
		close(A[1]);

		dup2(B[1], 1);
		close(B[0]);
		close(B[1]);
		execlp("cut", "cut", "-f4", "-d ", "log.txt", NULL);
		exit(EXIT_FAILURE);
	}
	close(A[0]);
	close(A[1]);
	int C[2];
	pipe(C);
	pid_t pid3 = fork();
	if (!pid3) { 
		dup2(B[0], 0);
		close(B[0]);
		close(B[1]);

		dup2(C[1], 1);
		close(C[0]); 	
		close(C[1]);

		execlp("wc","wc", "-l", NULL);
		exit(EXIT_FAILURE);
	}
	close(B[0]);
	close(B[1]);
	close(C[1]);

	FILE* Cin = fdopen(C[0],"r"); 
	int x,sum=0;
	while(fscanf(Cin,"%d",&x)>0){
		sum+=x;
	}
    return sum;
}
//pop=$(cut -f4 -d' ' log.txt | cut -f1 -d':' | sort -k1 | uniq -c | sort -k1 | tail -10 | sed 's/\[//' | sed 's/ *//' | awk '{a=$1; $1=$2; $2=a; print}' | sed 's/\//-/g')

//arr=($pop)
//for i in {1..20..2}; do echo ${arr[i-1]} - ${arr[i]} - $((arr[i]*100/$lines))%; done

int main()	{

	int l = lines();
	//printf("%d", l);
    	int A[2];
    	pipe(A);
    	pid_t pid1 = fork();
    	if (!pid1) {
        	dup2(A[1], 1); 
        	close(A[0]);
        	close(A[1]);
        	execlp("cut","cut", "-f4", "-d ", "log.txt", NULL);
        	exit(EXIT_FAILURE);
    	}
    
     
    	int B[2];
    	pipe(B);
    	pid_t pid2 = fork();
    	if (!pid2) { 
        	dup2(A[0], 0);
        	close(A[0]);
        	close(A[1]);
        
        	dup2(B[1], 1);
        	close(B[0]);
        	close(B[1]);
        
        	execlp("cut","cut", "-f1", "-d:", NULL);
        	exit(EXIT_FAILURE);
    	}
	close(A[0]);
       	close(A[1]);
 	int C[2]; 
    	pipe(C);
    
    	pid_t pid3 = fork();
    	if (!pid3) { 
        	dup2(B[0], 0);
        	close(B[0]);
       		close(B[1]);
        
        	dup2(C[1], 1);
        	close(C[0]);
        	close(C[1]);
        	execlp("sed", "sed", "s/\\[//", NULL);
        	exit(EXIT_FAILURE);
    	}
	close(B[0]);
       	close(B[1]);
	int D[2]; 
    	pipe(D);
    
    	pid_t pid4 = fork();
    	if (!pid4) { 
        	dup2(C[0], 0);
        	close(C[0]);
        	close(C[1]);
        
        	dup2(D[1], 1);
	        close(D[0]);
        	close(D[1]);
		execlp("sort","sort", NULL);
        	exit(EXIT_FAILURE);
    	}
	close(C[0]);
       	close(C[1]);
	int E[2]; 
    	pipe(E);
    
    	pid_t pid5 = fork();
    	if (!pid5) { 
        	dup2(D[0], 0);
        	close(D[0]);
        	close(D[1]);
        
        	dup2(E[1], 1);
        	close(E[0]);
        	close(E[1]);
        	execlp("uniq", "uniq", "-c", NULL);
        	exit(EXIT_FAILURE);
    	}
	close(D[0]);
       	close(D[1]);
	int F[2]; 
    	pipe(F);
    
    	pid_t pid6 = fork();
    	if (!pid6) { 
        	dup2(E[0], 0);
        	close(E[0]);
        	close(E[1]);
        
        	dup2(F[1], 1);
	        close(F[0]);
        	close(F[1]);
		execlp("sort","sort", NULL);
        	exit(EXIT_FAILURE);
    	}
	close(E[0]);
       	close(E[1]);
	int G[2]; 
    	pipe(G);
    
    	pid_t pid7 = fork();
    	if (!pid7) { 
        	dup2(F[0], 0);
        	close(F[0]);
        	close(F[1]);
        
        	dup2(G[1], 1);
	        close(G[0]);
        	close(G[1]);
		execlp("tail","tail", "-10", NULL);
        	exit(EXIT_FAILURE);
    	}
	close(F[0]);
       	close(F[1]);
	int H[2]; 
    	pipe(H);
    
    	pid_t pid8 = fork();
    	if (!pid8) { 
        	dup2(G[0], 0);
        	close(G[0]);
        	close(G[1]);
        
        	dup2(H[1], 1);
	        close(H[0]);
        	close(H[1]);
		execlp("sed","sed", "s/ *//", NULL);
        	exit(EXIT_FAILURE);
    	}
	close(G[0]);
       	close(G[1]);
 
	int I[2]; 
    	pipe(I);
    
    	pid_t pid9 = fork();
    	if (!pid9) { 
        	dup2(H[0], 0);
        	close(H[0]);
        	close(H[1]);
        
        	dup2(I[1], 1);
	        close(I[0]);
        	close(I[1]);
		execlp("awk","awk", "{a=$1; $1=$2; $2=a; print}", NULL);
        	exit(EXIT_FAILURE);
    	}
	close(H[0]);
       	close(H[1]);
	int J[2]; 
    	pipe(J);
    
    	pid_t pid10 = fork();
    	if (!pid10) { 
        	dup2(I[0], 0);
        	close(I[0]);
        	close(I[1]);
        
        	dup2(J[1], 1);
	        close(J[0]);
        	close(J[1]);
		execlp("sed","sed", "s/\\//-/g", NULL);
        	exit(EXIT_FAILURE);
    	}
	close(I[0]);
       	close(I[1]);
	int K[2]; 
    	pipe(K);
    
    	pid_t pid11 = fork();
    	if (!pid11) { 
        	dup2(J[0], 0);
        	close(J[0]);
        	close(J[1]);
        
        	dup2(K[1], 1);
	        close(K[0]);
        	close(K[1]);
		execlp("awk","awk", "-F ", "{print $1, \"-\", $2}", NULL);
        	exit(EXIT_FAILURE);
    	}
	close(J[0]);
       	close(J[1]);
	close(K[1]);
	FILE* Cin = fdopen(K[0],"r"); 
	char line[1000];
	int k = 0;
	char sub[1000];
	while (fgets(line, sizeof(line), Cin)) {
		strtok(line, "\n");
		substring(line, sub, 14, 4);
		int y = atoi(sub);
		printf("%s - %d%c\n", line, y * 100 / l, 37);
	}
	return 0;
}



 
