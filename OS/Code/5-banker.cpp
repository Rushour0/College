/*
Name: Rushikesh Patade
Batch: G2
Roll no.: PG19
*/
#include <iostream>
#include <stdlib.h>
using namespace std;
#define clrscr system("cls");

int main()
{

	int n, m, i, j, k;

	clrscr

	cout << "Enter number of processes : ";
	cin >> n ; // Number of processes

	cout << "Enter number of resources : ";
	cin >> m ; // Number of resources
	cout << endl;

	int **alloc = new int*[n];
	int **max = new int*[n];
	int **need = new int*[n];
	int *avail = new int[m];
	int *finished = new int[n];

	// finished set to 0
	for (k = 0; k < n; k++) {
		finished[k] = 0;
	}

	// Creating inner arrays
	for( i = 0; i < n; i++ )
	{
		max[i] = new int[m];
		alloc[i] = new int[m];
		need[i] = new int[m];
	}

	// Get Allocation matrix
	cout << "ALLOCATION MATRIX" << endl;
	for ( i = 0; i < n; i++ )
	{	
		cout << "Enter P" << i << " : "; 
		for ( j = 0; j < 3; j++ )
			cin >> alloc[i][j];
	}
	cout << endl;

	// Get Allocation matrix
	cout << "MAX MATRIX" << endl;
	for ( i = 0; i < n; i++ )
	{	
		cout << "Enter P" << i << " : "; 
		for ( j = 0; j < 3; j++ )
			cin >> max[i][j];
	}
	cout << endl;

	// Get Resource matrix
	for( i = 0; i < m; i++ )
	{
		cout << "Resource " << i << " : ";
		cin >> avail[i];
	}
	cout << endl;
	
	// Calculate need matrix
	cout << "NEED MATRIX" << endl;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
		{
			need[i][j] = max[i][j] - alloc[i][j];
			cout << need[i][j] << "\t";
		}	
		cout << endl;
	}
	cout << endl;
	cout << endl;
	
	int *request = new int[m]; 
	int process_for_request;
	
	cout << "Enter process number for requesting : ";
	cin >> process_for_request;

	cout << "Enter additional request" << endl;

	// Request entry
	for( i = 0; i < m; i++ )
	{
		cout << "Resource " << i << " : ";
		cin >> request[i];	
	}
	cout << endl;

	for( i = 0; i < m; i++ )
	{
		if ( request[i] > avail[i] )
		{
			cout << "ERROR! These many amount of resources are not available!";
			exit(0);
		}
	}

	for( i = 0; i < m; i++ )
	{
		if ( request[i] > need[process_for_request][i] )
		{
			cout << "Resources unavailable at the moment!";
			exit(0);
		}
	}

	for( i = 0; i < m; i++ )
	{
		avail[i] -= request[i];
		alloc[process_for_request][i] += request[i];
		need[process_for_request][i] -= request[i];
	}

	cout << "NEED MATRIX" << endl;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			cout << need[i][j] << "\t";
		cout << endl;
	}
	cout << endl;

	cout << "ALLOCATION MATRIX" << endl;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			cout << alloc[i][j] << "\t";
		cout << endl;
	}
	cout << endl;

	cout << "AVAILABLE RESOURCES AFTER REQUEST" << endl;
	for (i = 0; i < m; i++) 
		cout << avail[i] << "\t";
	cout << endl;
	cout << endl;

	int *safe_process_sequence = new int[n], ind = 0;
	
	int *work = new int[n];

	// Work = Available initially
	for( i = 0; i < m; i++ )
		work[i] = avail[i];

	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			if (finished[i] == 0) {

				int flag = 0;
				for (j = 0; j < m; j++) {
					if (need[i][j] > work[j]){
						flag = 1;
						break;
					}
				}

				if (flag == 0) {
					safe_process_sequence[ind++] = i;
					for ( int y = 0; y < m; y++)
						work[y] += alloc[i][y];

					cout << "Work done after P" << i << " process execution : ";
					for ( int t = 0; t < m; t++ )
						cout << work[t] << " ";
					cout << endl;
					finished[i] = 1;
				}
			}
		}
	}

	// Display work final
	cout << "Final Work done : ";
	for ( i = 0; i < m; i++ )
		cout << work[i] << " ";
	cout << endl << endl;

	int flag = 1;
	
	// To check if sequence is safe or not
	for( i = 0; i < n; i++ )
	{
		if( finished[i] == 0 )
		{
			flag = 0;
			cout << "The given sequence is not safe";
			break;
		}
	}
	
	if( flag == 1 )
	{
		cout << "Following is the SAFE Sequence" << endl;
		for (i = 0; i < n - 1; i++)
			cout << " P" << safe_process_sequence[i] << " ->";
		cout << " P" << safe_process_sequence[n - 1] <<endl;
	}
 
	return 0;

}



/*
5
3
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
3
3
2
1
1
0
2
*/