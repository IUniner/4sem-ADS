#include <iostream>
#include <string>
using namespace std;

int main(){
    string S; cin >> S;
    int Q = S.length(), Li, Ri; cin >> Q;
    bool InChange = false;
    bool *NewInterval = new bool[S.length()] {false};

    for(int i = 0; i < Q; i++)
    {
        cin >> Li >> Ri;
        if(Li > Ri)
        {
            int temp = Li;
            Li = Ri;
            Ri = temp;
        }
        Li--;
        NewInterval[Li] = !NewInterval[Li];
        NewInterval[Ri] = !NewInterval[Ri];
    }

    for(int i = 0; i < S.length(); i++) {
        if (NewInterval[i])
            InChange = !InChange;
        if (InChange)
            if (S[i] >= 97 && S[i] <= 122)
                S[i] = toupper(S[i]);
            else
            {
                if (S[i] >= 65 && S[i] <= 90)
                    S[i] = tolower(S[i]);
            }
    }
    cout << S;
}
/*
9. Инвертирование
Дана строка S и Q запросов. Запрос представляет собой пару чисел L и R — промежуток строки S, на котором нужно инвертировать регистр символов. Требутеся найти строку S после выполнения всех запросов.
*/