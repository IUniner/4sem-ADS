/*
14. Количество способов
Дан неориентированный граф. Определить количество маршрутов (по ребрам можно перемещаться несколько раз) длиной L между вершинами U и V.
*/

#include <iostream>
using namespace std;
typedef unsigned long long ull;
int N;
const ull mod = 1000000007;
ull *Mat, *tempC, *Eye;


ull* Module(ull *A)
{
	for(int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			A[i*N + j] %= mod;
	return A;
}

ull* Multiple(ull * A, ull * B)
{
	ull* C = tempC;
    for (int i = 0; i < N; ++i)
    {
        ull * c = C + i * N;
        for (int j = 0; j < N; ++j)
            c[j] = 0;
        for (int k = 0; k < N; ++k)
        {
            const ull * b = B + k * N;
            ull a = A[i*N + k];
            for (int j = 0; j < N; ++j) {
                c[j] += a * b[j];
                c[j] %= mod;
            }
        }
    }
	tempC = A;
	return C;
}

ull* Binary_Ind(int n)
{
	if (n == 0)
		return Eye;
	if (n % 2 == 1)
		return Multiple(Binary_Ind(n-1), Mat);
	else {
		ull* b = Binary_Ind(n / 2);
		return Multiple(b, b);
	}
}

int main()
{
    int M, U, V, L;
    cin >> N >> M;
    cin >> U >> V >> L;
    --U; --V;

    ull Mat_Last[N][N], tempC1[N][N], tempC2[N][N];
    Mat = *Mat_Last; tempC = *tempC1; Eye = *tempC2;
    for(int i = 0; i < N; i++) {
    	for(int j = 0; j < N; j++) {
    		Mat_Last[i][j] = 0;
    		tempC2[i][j] = 0;
    	}
    	tempC2[i][i] = 1;
    }
    
    
    int at, to;
    for(int i = 0; i < M; i++){
    	cin >> at >> to;
    	--at; --to;
    	Mat_Last[at][to]++;
    	Mat_Last[to][at]++;
    }

    ull *dist = Binary_Ind(L);
    cout << dist[U*N + V];
}
