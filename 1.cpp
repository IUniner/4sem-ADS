/*
1. Добавление
Дан неориентированный граф. Определить минимальное количество ребер, после добавления которых граф станет связным. Вывести -1 если ответа не существует.
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> *g;
bool *used;
vector<int> comp;

void CES (int v) {
	used[v] = true;
	comp.push_back (v);
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (! used[to])
            CES (to);
	}
}

int Find_Pairs(int N) {
    int counter = 0;
	for (int i=0; i<N; ++i)
		used[i] = false;
	for (int i=0; i<N; ++i)
		if (! used[i]) {
			comp.clear();
			CES (i);
			counter++;
		}
    return counter;
}

int main()
{
    int N, M;
    cin >> N >> M;

    g = new vector<int>[N];
    used = new bool[N];
    int A, B;
    for (int i = 0; i < M; i++)
    {
        cin >> A >> B;
        g[A-1].push_back(B-1);
        g[B-1].push_back(A-1);
    }

    int counter = Find_Pairs(N) - 1;
    cout << counter;
}
