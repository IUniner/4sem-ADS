/*
17. 1087388483
Дана последовательность из N целых положительных чисел. Требуется определить можно ли путем перемножения некоторых чисел последовательности получить число 1087388483.
*/
#include <iostream>
using namespace std;

bool s(long long* numbers, int N, int target){
    for(int i =0; i<N; ++i) if(numbers[i]==target) return true;
    return false;
}

int main(){
    int N; cin >> N;
    long long n[N];
    for(int i = 0; i < N; i++) cin >> n[i];

    cout << (s(n,N,1021)&&s(n,N,1031)&&s(n,N,1033) ||
             s(n,N,1065023)&&s(n,N,1021) || s(n,N,1054693)&&s(n,N,1031) || s(n,N,1052651)&&s(n,N,1033) ||
             s(n,N,1087388483) ? "YES":"NO");
}

// ! 7 строк vs 32