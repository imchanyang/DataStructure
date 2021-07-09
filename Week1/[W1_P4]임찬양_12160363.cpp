#include<iostream>
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
        }
    
    void set(int idx, int value)
       {
           arr[idx] = value;
   
       }
    
    void shift(int d)
    {
            // 1번 과정
            for(int j = 0; j < d/2; j++)
            {
                int temp;
                temp = arr[j];
                arr[j] = arr[(d-1) - j];
                arr[(d-1) - j] = temp;
            }
        
            // 2번 과정
            for(int j = 0; j < (arrSize-d)/2; j++)
            {
                int temp;
                temp = arr[(j+d)];
                arr[(j+d)] = arr[arrSize-1-j];
                arr[arrSize-1-j] = temp;
            }
            // 3번 과정
        for(int j = 0; j <arrSize/2 ; j++)
        {
            int temp;
            temp = arr[j];
            arr[j] = arr[(arrSize-1) - j];
            arr[(arrSize-1) - j] = temp;
        }
    
    }
    void print()
    {
        // 출력
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
    
};
int main()
{
    int N;
    int T;
    int D;
    
    cin >> T;
    
    for (int i = 0; i < T; i++)
    {
        cin >> N >> D;
        Array ar(N);
        
        for(int j = 0; j < N; j++)
        {
            int x;
            cin >> x;
            ar.set(j,x);
        }
        
        // 여기에 쉬프트 연산 작동
        ar.shift(D);
        ar.print();
        
        
    }
    return 0;
}
//// D가 3일떄 연산 순서
//12345 // 원본
//
//32145 // 1 왼쪾 부터 D개수 만큼 뒤집기
//01234
//32154 // 2 안뒤집은거 뒤집기
//
//45123 // 3 전체 뒤집기
//012345678
//
