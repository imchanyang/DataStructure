#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Graph {
public:
    vector<int> a;
    vector<int> w[501];

    void insert_vertex(int dt) {
        a.push_back(dt);
    }

    void insert_edge(int dt1, int dt2) {
        int g1, g2;
        int d = 0;
        for (int i = 0; i < a.size(); i++) {
            if (dt1 == a[i]) {
                g1 = i;
            }
            if (dt2 == a[i]) {
                g2 = i;
            }
        }

        for (int i = 0; i < w[g1].size(); i++) {
            if (w[g1][i] == g2) {
                cout << "Exist" << endl;
                d++;
                break;
            }
        }
        if (d == 0) {
            w[g1].push_back(g2);
            w[g2].push_back(g1);
        }
    }
    vector<int> D;
    void DFS(int id, int e_n) {
        D.push_back(id);

        for (int i = 0; i < w[id].size(); i++) {
            for (int j = 0; j < D.size(); j++) {
                if (D[j] != w[id][i]) {
                    DFS(i, e_n);
                }
                
            }
        }
    }
};

int main() {
    int T;
    cin >> T;
        

    while (T--) {
        int N, K;
        cin >> N >> K;

        Graph b;

        for (int i = 0; i < N; i++) {
            
            b.insert_vertex(i);
        }

        for (int i = 0; i < K; i++) {
            int dt1, dt2;
            cin >> dt1 >> dt2;
            b.insert_edge(dt1, dt2);
        }

        b.DFS(0, K);
        for (int i = 0; i < b.D.size(); i++) {
            if (i == b.D.size() - 1) {
                cout << b.D[i] + 1 << endl;
            }
            else {
                cout << b.D[i] + 1 << " ";
            }
            
        }
    }

    return 0;
}
