#include <iostream>
#include <string>
using namespace std;

class Array{
private:
    int *arr;
    int arrSize;
public:
    Array(int sz)
    {
        this->arrSize = sz;
        this->arr = new int[arrSize];
        for (int i = 0; i < arrSize; i++)
        {
            arr[i] = 0;
        }
    }

    int at(int idx)
    {
        return arr[idx];
    }

    void add(int idx, int value)
    {
        for (int i = arrSize -2; i >= idx; i--)
        {
            arr[i+1] = arr[i];
        }
        arr[idx] = value;
    }

    void set(int idx, int value)
    {
        arr[idx] = value;
        cout << arr[idx] << endl;

    }

    void print()
    {
        for (int i = 0; i < arrSize; i++)
        {
            if(i == arrSize -1)
            {
                cout << arr[i];
            }
            else cout << arr[i] << " ";
        }
        cout << endl;
    }

    void remove(int idx)
    {
        for (int i = idx + 1; i < arrSize; i++)
        {
            arr[i-1] = arr[i];
        }
        arr[arrSize-1] = 0;

    }
    int find_min()
    {
        int min = arr[0];
        for (int i = 1; i < arrSize; ++i) {
            if (min > arr[i]) {
                min = arr[i];
            }
        }

        return min;
    }


};



int main()
{
    int N;
    int T;
    int L=0; // 명령 횟수
    string M; // 명령어

    cin >> N >> T ;
    Array ar(N);


    while(L < T)
    {
    cin >> M;
    if(M == "at")
    {
        int a;
        cin >> a;
        cout << ar.at(a) << endl;
        L++;
    }

    else if(M == "add")
    {
        int a, b;
        cin >> a >> b;
        ar.add(a,b);
        L++;
    }

    else if(M == "set")
    {
        int a ,b;
        cin >> a >> b;
        ar.set(a,b);
        L++;
    }

    else if(M == "print")
    {
        ar.print();
        L++;
    }

    else if(M == "remove")
    {
        int a;
        cin >> a;
        ar.remove(a);
        L++;
    }

    else if(M == "find_min")
    {
        cout << ar.find_min() << endl;
        L++;
    }

    }
    return 0;
}

//
//
//
//
//
//
