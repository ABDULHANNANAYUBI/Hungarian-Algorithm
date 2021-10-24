// Abdul Hannan Ayubi
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>
#include<algorithm>
#define SIZE 10 
using namespace std;

void GenerateRandomNumber(int A[][SIZE], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			A[i][j] = (rand() % (100 - 0 + 1) + 1);
		}
	}
}
void CopyingTheArray(int A[][SIZE], int B[][SIZE], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			B[i][j] = A[i][j];
		}
	}
}

void PrintTheArray(int A[][SIZE], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << A[i][j] << "\t";
		}
		cout << endl;
	}
}

void FindTheSmallestRowNumber(int A[][SIZE], int B[], int size) {
	int min = INT16_MAX;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (min > A[i][j]) {
				min = A[i][j];
			}
		}
		B[i] = min;
		min = INT16_MAX;
	}
}

void SubtractTheNumberFromRow(int A[][SIZE], int B[], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			A[i][j] -= B[i];
		}
	}
}

void FindTheSmallestColumnNumber(int A[][SIZE], int B[], int size) {
	int min = INT16_MAX, j;
	for (int i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (min > A[j][i]) {
				min = A[j][i];
			}
		}
		B[i] = min;
		min = INT16_MAX;
	}
}

void SubtractTheNumberFromColumn(int A[][SIZE], int B[], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			A[j][i] -= B[i];
		}
	}
}

int removeDuplicates(int arr[], int Array[], int n) {
	int temp[100], j = 0;
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] != arr[i + 1]) {
			temp[j] = arr[i];
			j++;
		}
	}
	temp[j] = arr[n - 1];
	for (int i = 0; i < j + 1; i++) {
		Array[i] = temp[i];
	}
	return j;
}

int StepThree(int A[][SIZE], int size) {
	int counter = 0, k = 0, NumberOfZeroes = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (A[i][j] == 0) {
				counter++;
				k = j;

			}
		}
		if (counter == 1) {
			for (int j = 0; j < size; j++) {
				A[i][k] = -2;
				if (A[j][k] == 0) {
					A[j][k] = -1;
				}
			}
		}
		counter = 0;
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (A[j][i] == 0) {
				counter++;
				k = j;
			}
		}
		if (counter == 1) {
			A[k][i] = -2;
			for (int j = 0, l = 0; j < size; j++, l++) {
				if (A[k][j] == 0) {
					A[k][j] = -1;
				}
			}
		}
		counter = 0;
	}
	int CounterForZero = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (A[i][j] == 0) {
				CounterForZero++;
			}
		}
	}
	static int limit = 0;
	limit++;
	int flagforreturn = 0, j;
	if (limit > size) {
		for (int i = 0; i < size; i++) {
			for (j = 0; j < size; j++) {
				if (A[i][j] == 0) {
					A[i][j] = -2;
					limit = 0;
					flagforreturn = 1;
					break;
				}
			}
			if (flagforreturn == 1) {
				for (int k = 0; k < size; k++) {
					if (A[k][j] == 0) {
						A[k][j] = -1;
					}
				}
				for (int k = 0; k < size; k++) {
					if (A[i][k] == 0) {
						A[i][k] = -1;
					}
				}
				break;
			}
		}
	}
	if (CounterForZero != 0) {
		StepThree(A, size);
	}
	CounterForZero = 0;
	cout << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (A[i][j] == -2) {
				NumberOfZeroes++;
			}
		}
	}
	return NumberOfZeroes;
}

int ColumnScan(int A[][SIZE], int size, int rowindex, int& Returnindex) {
	int B[100];
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < size; j++) {
			if (A[j][rowindex] == -2) {
				B[i] = j;
				Returnindex = B[i];
				return -2;
			}

		}
	}
	return -4;
}

int RowScan(int A[][SIZE], int size, int Column, int B[SIZE], int& Counter) {
	int counter = 0, k = 0;
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < size; j++) {
			if (A[Column][j] == -1) {
				B[k] = j;
				counter++, k++;
			}
		}
	}
	Counter = counter;
	if (Counter > 0) {
		return -2;
	}
	return -4;
}

int StepFour(int A[][SIZE], int B[][SIZE], int size) {
	int F[SIZE][SIZE] = { 0 };
	int Row[100], Column[100], flag = 0, n = 0, m = 0;
	//First Step
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (A[i][j] == -2) {
				flag = 1;
			}
		}
		if (flag == 0) {
			Row[n] = i;
			n++;
		}
		flag = 0;
	}
	//Second Step
	for (int i = 0; i < n; i++) {
		int temp = Row[i];
		for (int j = 0; j < size; j++) {
			if (A[temp][j] == -1 || A[temp][j] == 0) {
				Column[m] = j;
				m++;
			}
		}
	}
	int Column2[100], x;
	for (x = 0; x < m; x++) {
		Column2[x] = Column[x];
	}
	int i = 0;
	int last = m;
	while (last != 0) {
		int temp = Column2[i];
		i++;
		int RowTemp, ColumnTemp, RowS = 1, ColumnS = 1;
		int B[SIZE], Counter;
		while (RowS != -4 && ColumnS != -4) {
			ColumnS = ColumnScan(A, size, temp, ColumnTemp);
			Row[n] = ColumnTemp;
			n++;
			RowS = RowScan(A, size, ColumnTemp, B, Counter);
			if (RowS == -4) break;
			RowTemp = B[0];
			Column[m] = RowTemp;
			m++;
			if (Counter > 1) {
				for (int i = 0; i < Counter; i++) {
					Column2[x] = B[i];
					last++, x++;
				}
			}
			temp = RowTemp;
		}
		last--;
	}
	for (int l = 0; l < i; l++, m++) {
		Column[m] = Column2[l];
	}
	//Last Step
	int l = 0, SaveRow[100];
	int flag2 = 0, j = 0;
	sort(Row, Row + n);
	int Row2[SIZE];
	n = removeDuplicates(Row, Row2, n);
	cout << "Row Index " << endl;
	for (int i = 0; i < n + 1; i++)
		cout << Row2[i] << " ";
	cout << endl;
	int b = 0, a = 0;
	for (int i = 0; i < size; i++) {
		int temp = Row2[l];
		for (int j = 0; b < size; j++) {
			if (b != temp) {
				SaveRow[a] = b;
				a++;
				b++;
			}
			else if (b == temp) {
				l++;
				b++;
				break;
			}
		}
	}

	cout << "Save Row Operation " << endl;
	for (int i = 0; i < a; i++) {
		cout << SaveRow[i] << " ";
	}
	cout << endl;
	l = 0;
	for (int i = 0; i < size; i++) {
		int temp = SaveRow[l];
		for (int j = 0; j < size; j++) {
			if (j == temp) {
				for (int k = 0; k < size; k++) {
					A[temp][k] = -3;
				}
				l++;
			}
		}
	}
	cout << endl;
	//For Column
	l = 0;
	int Column3[100];
	sort(Column, Column + m);
	cout << "Column Index " << endl;
	m = removeDuplicates(Column, Column3, m);
	for (int i = 0; i < m + 1; i++)
		cout << Column3[i] << " ";
	cout << endl;
	m++;
	for (int i = 0; i < m; i++) {
		int temp = Column3[l];
		for (int j = 0; j < size; j++) {
			if (j == temp) {
				for (int k = 0; k < size; k++) {
					A[k][temp] = -3;
				}
				l++;
			}
		}
	}
	cout << "Print The cross Array " << endl;
	cout << "--------------------------" << endl;
	PrintTheArray(A, size);

	//Finding The Min Value
	int min = INT16_MAX;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (min > A[i][j] && A[i][j] != -3 && A[i][j] != -1) {
				min = A[i][j];
			}
		}
	}
	//If The crossed line is equal..
	int CounterForMinus = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (A[i][j] == -3) {
				CounterForMinus++;
			}
		}
	}
	if (CounterForMinus == (size * size)) return CounterForMinus;
	cout << endl;
	cout << "        The Min Value " << endl;
	cout << "            " << min << endl << endl;
	//Subtracting Min From Line Which is Not Intersected....
	//Substract New Min..
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (A[i][j] != -3)
				A[i][j] -= min;
		}
	}
	//Copying The Array To Another Array ...
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (A[i][j] != -3) {
				B[i][j] = A[i][j];
			}
		}
	}
	int flagforcheak = 0;
	//The new Intersection
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (A[i][j] == -3) {
				for (int k = 0; k < size; k++) {
					if (A[i][k] == -3) {
						flagforcheak = 1;
					}
					else {
						flagforcheak = 0;
						break;
					}
				}
				if (flagforcheak == 1) {
					for (int k = 0; k < size; k++) {
						if (A[k][j] == -3) {
							flagforcheak = 1;
						}
						else {
							flagforcheak = 0;
							break;
						}
					}
				}
				if (flagforcheak == 1) {
					B[i][j] += min;
				}
			}
			flagforcheak = 0;
		}
	}
	cout << "New Array After Adding Minumum...." << endl;
	cout << "--------------------------" << endl;
	PrintTheArray(B, size);
	CopyingTheArray(B, F, size);
	int numberOFZeros = StepThree(B, size);
	cout << "Number OF New Zeros : " << endl << numberOFZeros << endl;;
	cout << "--------------------------" << endl;
	//After cheaking the new Zeros
	PrintTheArray(B, size);
	cout << "After Finding " << endl;
	if (numberOFZeros != size) {
		StepFour(B, F, size);
		CopyingTheArray(F, B, size);
	}
	else {
		return 0;
	}
}

void CalculateTheFinal(int A[][SIZE], int B[][SIZE], int size) {
	int Sum = 0, C[SIZE];
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (A[i][j] == -2) {
				Sum += B[i][j];
				C[i] = j;
			}
		}
	}
	for (int i = 0; i < size; i++) {
		cout << "Worker [" << i + 1 << "] " << "Perform Job => " << C[i] + 1 << endl;
	}
	cout << endl;
	cout << "-THE FINAL MINIMUM SUM OFF THIS ASSAIGNMENT IS =>> " << Sum << endl;
}

int main() {
	srand(time(NULL));
	int A[SIZE][SIZE], B[SIZE], C[SIZE], D[SIZE][SIZE], E[SIZE][SIZE], F[SIZE][SIZE], size;
	cout << "Please Enter your Array Size : ";
	cin >> size;
	if (size > 10) return 0;
	else if (size < 3) return 0;
	GenerateRandomNumber(A, size);
	cout << "Random Array " << endl;
	cout << "--------------------------" << endl;
	PrintTheArray(A, size);
	CopyingTheArray(A, E, size);
	FindTheSmallestRowNumber(A, B, size);
	SubtractTheNumberFromRow(A, B, size);
	cout << "After Row Subtracting" << endl;
	cout << "--------------------------" << endl;
	PrintTheArray(A, size);
	FindTheSmallestColumnNumber(A, C, size);
	SubtractTheNumberFromColumn(A, C, size);
	cout << "After Column Subtracting" << endl;
	cout << "--------------------------" << endl;
	PrintTheArray(A, size);
	CopyingTheArray(A, F, size);
	if ((StepThree(A, size) == size)) {
		CopyingTheArray(F, D, size);
		cout << "The Array With Zeros .." << endl;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (D[i][j] == -2 || D[i][j] == -1) {
					D[i][j] = 0;
				}
			}
		}
		cout << "The Orginal Array " << endl;
		PrintTheArray(E, size);
		cout << "The Array With Zeros .." << endl;
		PrintTheArray(D, size);
		CalculateTheFinal(A, E, size);
		cout << "We ARE DONE .." << endl;
		return 0;
	}
	cout << "Continue With Step Four.....! " << endl;
	StepFour(A, F, size);
	CopyingTheArray(F, D, size);
	cout << "The Array With Zeros .." << endl;
	cout << "--------------------------" << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (D[i][j] == -2 || D[i][j] == -1) {
				D[i][j] = 0;
			}
		}
	}
	PrintTheArray(D, size);
	cout << "The Orginal Array " << endl;
	cout << "--------------------------" << endl;
	PrintTheArray(E, size);
	CalculateTheFinal(F, E, size);
	system("pause");
	return 0;
}