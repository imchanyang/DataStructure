#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct vertex {
    int vertex_id;
    int matrix_id;
    vertex* prev;
    vertex* next;
    
    vertex() {
        vertex_id = matrix_id = -1;
        prev = next = NULL;
    }
    
    vertex(int v_id) {
        vertex_id = v_id;
        matrix_id = -1;
        prev = next = NULL;
    }
};

struct edge {
    vertex* src;
    vertex* dst;
    edge* prev;
    edge* next;
    
    edge() {
        src = dst = NULL;
        prev = next = NULL;
    }
    
    edge(vertex* s, vertex* d) {
        src = s;
        dst = d;
        prev = next = NULL;
    }
};

class VertexList{
private:
    vertex* header;
    vertex* trailer;
public:
    VertexList() {
        header = new vertex();
        trailer = new vertex();
        
        header->next = trailer;
        trailer->prev = header;
    }
    
    void insert_back(vertex* new_vertex) {
        new_vertex->prev = trailer->prev;
        new_vertex->next = trailer;
        new_vertex->matrix_id = new_vertex->prev->matrix_id + 1;
        trailer->prev->next = new_vertex;
        trailer->prev = new_vertex;
        return;
    }
    
    void remove(vertex* del_vertex) {
        for(vertex* cur = del_vertex->next; cur != trailer; cur = cur->next) {
            cur->matrix_id--;
        }
        del_vertex->prev->next = del_vertex->next;
        del_vertex->next->prev = del_vertex->prev;
        delete del_vertex;
        return;
    }
    
    vertex* find_vertex(int v_id) {
        for(vertex* cur = header->next; cur != trailer; cur = cur->next){
            if(cur->vertex_id == v_id) {
                return cur;
            }
        }
        return NULL;
    }
};

class EdgeList {
private:
    edge* header;
    edge* trailer;
public:
    EdgeList() {
        header = new edge;
        trailer = new edge;
        header->next = trailer;
        trailer->prev = header;
    }
    
    void insert_back(edge* new_edge)  {
        new_edge->prev = trailer->prev;
        new_edge->next = trailer;
        trailer->prev->next = new_edge;
        trailer->prev = new_edge;
        return;
    }
    
    void remove(edge* del_edge) {
        del_edge->prev->next = del_edge->next;
        del_edge->next->prev = del_edge->prev;
        delete del_edge;
        return;
    }
    
};

class graph {
private:
    edge*** edge_matrix;
    VertexList vertex_list;
    EdgeList edge_list;
    int vertex_size;
public:
    graph() {
        vertex_size = 0;
        edge_matrix = NULL;
    }
    
    void insert_vertex(int v_id) {
        if(vertex_list.find_vertex(v_id) != NULL) {
            return;
        }
        vertex* new_vertex = new vertex(v_id);
        
        edge *** new_matrix = new edge * *[vertex_size + 1];
        for(int i = 0; i < vertex_size + 1; i++) {
            new_matrix[i] = new edge * [vertex_size + 1];
        }
        
        for(int i = 0; i < vertex_size; i++) {
            for(int j = 0; j < vertex_size; j++) {
                new_matrix[i][j] = edge_matrix[i][j];
            }
        }
        
        for(int i = 0; i < vertex_size + 1; i++) {
            new_matrix[i][vertex_size] = new_matrix[vertex_size][i] = NULL;
        }
        
        for(int i = 0; i < vertex_size; i++) {
            delete[] edge_matrix[i];
        }
        delete[] edge_matrix;
        
        edge_matrix = new_matrix;
        vertex_list.insert_back(new_vertex);
        vertex_size++;
        return;
        
    }
    void erase_vertex(int v_id) {
        vertex* del_vertex = vertex_list.find_vertex(v_id);
        if(del_vertex == NULL) {
            return;
        }
        
        int del_idx = del_vertex->matrix_id;
        
        edge*** new_matrix = new edge * *[vertex_size - 1];
        for(int i = 0; i < vertex_size -1; i++) {
            new_matrix[i] = new edge * [vertex_size - 1];
        }
        
        for(int i = 0; i < vertex_size - 1; i++) {
            for(int j = 0; j <  vertex_size - 1; j++) {
                if(i < del_idx && j < del_idx) {
                    new_matrix[i][j] = edge_matrix[i][j];
                }
                else if(i < del_idx) {
                    new_matrix[i][j] = edge_matrix[i][j + 1];
                }
                else if(j < del_idx) {
                    new_matrix[i][j] = edge_matrix[i+1][j];
                }
                else{
                    new_matrix[i][j] = edge_matrix[i+1][j+1];
                }
            }
        }
        
        for(int i = 0; i < vertex_size; i++) {
            if(edge_matrix[del_idx][i] != NULL) {
                edge_list.remove(edge_matrix[del_idx][i]);
            }
        }
        
        for(int i = 0; i < vertex_size; i++) {
            delete[] edge_matrix[i];
        }
        delete[] edge_matrix;
        
        edge_matrix = new_matrix;
        vertex_list.remove(del_vertex);
        vertex_size--;
        return;
    }
    
    void insert_edge(int s_v_id, int d_v_id) {
        vertex* src_vertex = vertex_list.find_vertex(s_v_id);
        vertex* dst_vertex = vertex_list.find_vertex(d_v_id);
        
        if(src_vertex == NULL || dst_vertex == NULL) {
           
            return;
        }
        
        int src_id = src_vertex->matrix_id;
        int dst_id = dst_vertex->matrix_id;
        
        if(edge_matrix[src_id][dst_id] != NULL || edge_matrix[dst_id][src_id] != NULL) {
            return;
        }
        
        edge* new_edge = new edge(src_vertex, dst_vertex);
        edge_list.insert_back(new_edge);
        edge_matrix[src_id][dst_id] = edge_matrix[dst_id][src_id] = new_edge;
        return;
    }
    
    void erase_edge(int s_v_id, int d_v_id) {
        vertex* src_vertex = vertex_list.find_vertex(s_v_id);
        vertex* dst_vertex = vertex_list.find_vertex(d_v_id);
        if(src_vertex == NULL || dst_vertex ==NULL) {
            return;
        }
        
        int src_id = src_vertex->matrix_id;
        int dst_id = dst_vertex->matrix_id;
        
        if(edge_matrix[src_id][dst_id] == NULL || edge_matrix[dst_id][src_id] == NULL) {
            cout << "None" << endl;
            return;
        }
        
        edge_list.remove(edge_matrix[src_id][dst_id]);
        edge_matrix[src_id][dst_id] = edge_matrix[dst_id][src_id] = NULL;
        return;
    }
    
    int incidentEdges(int v_id) {
        vertex* f_vertex = vertex_list.find_vertex(v_id);
        int f_id = f_vertex->matrix_id;
        
        int Num_edge = 0;
        
        for(int i = 0; i <vertex_size ; i++) {
            if(edge_matrix[f_id][i] != NULL) {
                Num_edge++;
            }
        }
        
        return Num_edge;
    }
    
    void find_Friend(int v_id) {
        
       
        vector<int> a;
        vector<int> b;
        
        
        vertex* f_vertex = vertex_list.find_vertex(v_id);
        int f_id = f_vertex->matrix_id;
        

        // 일단 친구 찾기
        for(int i = 0; i < vertex_size; i++) {
            if(edge_matrix[f_id][i] != NULL) {
                a.push_back(i);
                
            }
        }

        // 친구의 친구 찾기
        for(int i = 0; i < a.size(); i++) {
            for(int j = 0 ; j < vertex_size; j++) {
                if((edge_matrix[a[i]][j] != NULL) && (edge_matrix[j][f_id] == NULL && (j != f_id))) {
                 
                    if(b.size() == 0) {
                        b.push_back(j);
                    }
                    else {
                        // 중복 방지
                        int as = 0;
                        for(int k = 0; k < b.size(); k++) {
                            if(b[k] == j) {
                                as++;
                            }
                        }
                        if(as == 0) {
                            b.push_back(j);
                        }
                    }
                   
                   
                }
               
            }
          
        }
        // 친구의 친구가 없을때
        if(b.size() == 0) {
            cout << 0 << endl;
            return;
        }
        // 오름차순 정렬
        for(int i = 0; i < b.size()-1; i++) {
            for(int j = i+1; j < b.size(); j++) {
                if(b[i] > b[j]) {
                    int temp;
                    temp = b[i];
                    b[i] = b[j];
                    b[j] = temp;
                }
            }
      
        }
        // 출력
        for(int i = 0; i<b.size();i++) {
            if(i == (b.size() -1) ) {
                cout << b[i]+1 << endl;
                return;
            }
            cout << b[i]+1 << " ";
        }
    }

};

int main() {
    graph a;
    
    int T;
    int M;
    cin >> T >> M;
    
    for(int i = 0; i < T; i++) {
        a.insert_vertex(i + 1);
    }
    
    for(int i = 0; i < T; i++) {
        for(int j = 0; j < T; j++) {
            int F;
            cin >> F;
            if(F == 1) {
                a.insert_edge(i+1, j+1);
            }
            else {
                
            }
        }
    }
    
    while (M--) {
        int dt;
        cin >> dt;
        a.find_Friend(dt);
    }
    return 0;
}
