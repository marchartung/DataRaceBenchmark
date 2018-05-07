#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdio>
#include <ctime>
#include <iomanip>

using namespace std;

vector< vector<int> > mat1;
vector< vector<int> > mat2;
vector< vector<int> > mat3;


int curr_i,curr_j = 0;

int _m, _n, _p = 0;

/* So that data will not get intermixed while using multiple threads*/
pthread_mutex_t lock;

/* POOL OF THREADS*/
pthread_t *threads;

/* Whether the thread is created or terminated*/
int *threadstatus;

/* Each thread computes a single element in matrix*/
void* compute(int id){
	while(curr_i < _m){ //bad should be loc_i
		int loc_i, loc_j;

		pthread_mutex_lock(&lock); //So that data will not get intermixed with multiple threads.
		loc_i = curr_i;
		loc_j = curr_j;
		if(curr_i < _m){
			curr_j++;
			if(curr_j >= _p){
				curr_i++;
				curr_j = 0;
			}
		}
		pthread_mutex_unlock(&lock);
		if(loc_i < _m){
			mat3[loc_i][loc_j] = 0;
			for(int i = 0;i < _n;i++){
				mat3[loc_i][loc_j] += mat1[loc_i][i] * mat2[i][loc_j];
			}
		}
	}
	return NULL;
}

/*  Main Function  */
int main(){
	int m=10, n=10, p=10, num=0;

		int no=2, i, j, entry;
		i = j = 0;


		// Allocating rows
		mat1.resize(m);
		mat2.resize(n);
		mat3.resize(m);

		// Allocating columns
		for(int i = 0;i < m; i++){
			mat1[i].resize(n);
			mat3[i].resize(p);
		}

		for(int i = 0;i < n;i++){
			mat2[i].resize(p);
		}

		

		for(i = 0; i < m; i++){
			for(j = 0; j < n; j++){
				 mat1[i][j] = (i+j);
			}
		}


            for(i = 0;i < n;++i)
                for(j = 0;j<p;++j)
                {		
			mat2[i][j] = (i+j);
			j++;
		
                }

		//to prevent intermixing of data
		pthread_mutex_lock(&lock);
		if(num > no){
			for(;num > no; num--){
                // deleting threads which are extra
				threadstatus[num-1] = 0;
			}
			threads = (pthread_t *) realloc(threads, sizeof(pthread_t) * num);
		}

		curr_i = 0;
		curr_j = 0;
		_m = m;
		_n = n;
		_p = p;

		pthread_mutex_unlock(&lock);

        // Starting the clock to note execution time
        double duration;
        clock_t start;
        start = clock();

		//Creating threads
		if(no > num){
			threads = (pthread_t *) realloc(threads, sizeof(pthread_t) * no);
			threadstatus = (int *) realloc(threadstatus, sizeof(int) * no);
			for(;num < no; num++){
				threadstatus[num] = 1;
				pthread_create(&threads[num], NULL, (void *(*) (void *)) compute, (void *) (num + 1));
				cout << "Thread " << (num + 1) << " created\n";
			}
		}

		/*Final thread that is main function gives final output*/
		// bounded wait
		for(i=0;i<no;++i)
		   pthread_join(threads[i],NULL);
		delete[] threads;

	return 0;
}
