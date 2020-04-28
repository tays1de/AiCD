// Обменная поразрядная сортировка :
#include<iostream>
#include<ctime>
using namespace std;


void sort(int* M, int a, int b, size_t bit) {

	if (bit == 0 || a >= b) return;
	int i = a, j = b;
	do
	{
		while (!(M[i] & bit) && i <= j)     // пока M[i]!=1
			i++;
		while (M[j] & bit && i <= j)        // пока M[j]!=0
			j--;
		if (i < j)
		{
			swap(M[i], M[j]);
			i++;
			j--;
		}
	} while (i < j);
	sort(M, a, j, bit >> 1);
	sort(M, i, b, bit >> 1);

	
}

void sort1(int* M, int a, int b, int &IF, int &swipe,  size_t bit) {



	if (bit == 0 || a >= b) return;
	IF++;
	int i = a, j = b;
	do
	{
		IF++;
		while (!(M[i] & bit) && i <= j) {     // пока M[i]!=1
			i++;
			IF++;
		}
		IF++;
		while (M[j] & bit && i <= j)        // пока M[j]!=0
		{
			IF++;
			j--;
		}
		IF++;
		if (i < j)
		{
			
			swap(M[i], M[j]);
			swipe++;
			i++;
			j--;
		}
		IF++;
	} while (i < j);
	sort(M, a, j, bit >> 1);
	sort(M, i, b, bit >> 1);


}






int main() {
	int a;
	cin >> a;
	int* mas3 = new int[a];
	int* mas4 = new int[a];
	int* mas5 = new int[a];



	int* mas = new int[a];
	for (int i = 0; i < a; i++) {
		mas3[i] = i;
		mas[i] = i;
	}
	clock_t time, start, finish;
	start = clock();
	sort(mas, 0, a-1,256);
	finish = clock();
	time = finish - start;
	cout << "TIME:" << time << endl << endl;






	int* mas1 = new int[a];
	int k = a;
	for (int i = 0; i < a; i++) {
		mas4[i] = k;
		mas1[i] = k;
		k--;
	}
	start = clock();
	sort(mas1, 0, a-1,256);
	finish = clock();
	time = finish - start;
	cout << "TIME:" << time << endl << endl;






	int* mas2 = new int[a];
	for (int i = 0; i < a; i++) {
		mas5[i] = mas2[i] = rand();
	}
	start = clock();
	sort(mas2, 0, a-1,256);
	finish = clock();
	time = finish - start;
	cout << "TIME:" << time << endl << endl;

	//--------------------------------------------------------

	int ifes = 0;
	int swap = 0;
	start = clock();
	sort1(mas3, 0, a-1, ifes, swap, 256);
	finish = clock();
	time = finish - start;
	cout << "IF:" << ifes << endl;
	cout << "SWAP:" << swap << endl << endl;





	ifes = 0;
	swap = 0;

	start = clock();
	sort1(mas4, 0, a-1, ifes, swap,256);
	finish = clock();
	time = finish - start;
	cout << "IF:" << ifes << endl;
	cout << "SWAP:" << swap << endl << endl;





	ifes = 0;
	swap = 0;
	start = clock();
	sort1(mas5, 0, a-1, ifes, swap, 256);
	finish = clock();
	time = finish - start;
	cout << "IF:" << ifes << endl;
	cout << "SWAP:" << swap << endl << endl;

	system("pause");
	return 0;
}


