//#include <iostream>
//#include <queue>
//#include <vector>
//
//using namespace std;
//
//struct vertex {
//    int vertex_id;
//    int matrix_id;
//    int label = 0;
//    vertex* prev;
//    vertex* next;
//
//    vertex() {
//        vertex_id = matrix_id = -1;
//        prev = next = NULL;
//    }
//
//    vertex(int v_id) {
//        vertex_id = v_id;
//        matrix_id = -1;
//        prev = next = NULL;
//    }
//};
//
//struct edge {
//    vertex* src;
//    vertex* dst;
//    edge* prev;
//    edge* next;
//
//    edge() {
//        src = dst = NULL;
//        prev = next = NULL;
//    }
//
//    edge(vertex* s, vertex* d) {
//        src = s;
//        dst = d;
//        prev = next = NULL;
//    }
//};
//
//class VertexList{
//private:
//    vertex* header;
//    vertex* trailer;
//public:
//    VertexList() {
//        header = new vertex();
//        trailer = new vertex();
//
//        header->next = trailer;
//        trailer->prev = header;
//    }
//
//    void insert_back(vertex* new_vertex) {
//        new_vertex->prev = trailer->prev;
//        new_vertex->next = trailer;
//        new_vertex->matrix_id = new_vertex->prev->matrix_id + 1;
//        trailer->prev->next = new_vertex;
//        trailer->prev = new_vertex;
//        return;
//    }
//
//    void remove(vertex* del_vertex) {
//        for(vertex* cur = del_vertex->next; cur != trailer; cur = cur->next) {
//            cur->matrix_id--;
//        }
//        del_vertex->prev->next = del_vertex->next;
//        del_vertex->next->prev = del_vertex->prev;
//        delete del_vertex;
//        return;
//    }
//
//    vertex* find_vertex(int v_id) {
//        for(vertex* cur = header->next; cur != trailer; cur = cur->next){
//            if(cur->vertex_id == v_id) {
//                return cur;
//            }
//        }
//        return NULL;
//    }
//};
//
//class EdgeList {
//private:
//   
//public:
//    edge* header;
//    edge* trailer;
//    EdgeList() {
//        header = new edge;
//        trailer = new edge;
//        header->next = trailer;
//        trailer->prev = header;
//    }
//
//    void insert_back(edge* new_edge)  {
//        new_edge->prev = trailer->prev;
//        new_edge->next = trailer;
//        trailer->prev->next = new_edge;
//        trailer->prev = new_edge;
//        return;
//    }
//
//    void remove(edge* del_edge) {
//        del_edge->prev->next = del_edge->next;
//        del_edge->next->prev = del_edge->prev;
//        delete del_edge;
//        return;
//    }
//
//};
//
//class graph {
//private:
//    edge*** edge_matrix;
//    VertexList vertex_list;
//    EdgeList edge_list;
//    int vertex_size;
//public:
//    graph() {
//        vertex_size = 0;
//        edge_matrix = NULL;
//    }
//
//    void insert_vertex(int v_id) {
//        if(vertex_list.find_vertex(v_id) != NULL) {
//            return;
//        }
//        vertex* new_vertex = new vertex(v_id);
//
//        edge *** new_matrix = new edge * *[vertex_size + 1];
//        for(int i = 0; i < vertex_size + 1; i++) {
//            new_matrix[i] = new edge * [vertex_size + 1];
//        }
//
//        for(int i = 0; i < vertex_size; i++) {
//            for(int j = 0; j < vertex_size; j++) {
//                new_matrix[i][j] = edge_matrix[i][j];
//            }
//        }
//
//        for(int i = 0; i < vertex_size + 1; i++) {
//            new_matrix[i][vertex_size] = new_matrix[vertex_size][i] = NULL;
//        }
//
//        for(int i = 0; i < vertex_size; i++) {
//            delete[] edge_matrix[i];
//        }
//        delete[] edge_matrix;
//
//        edge_matrix = new_matrix;
//        vertex_list.insert_back(new_vertex);
//        vertex_size++;
//        return;
//
//    }
//    void erase_vertex(int v_id) {
//        vertex* del_vertex = vertex_list.find_vertex(v_id);
//        if(del_vertex == NULL) {
//            return;
//        }
//
//        int del_idx = del_vertex->matrix_id;
//
//        edge*** new_matrix = new edge * *[vertex_size - 1];
//        for(int i = 0; i < vertex_size -1; i++) {
//            new_matrix[i] = new edge * [vertex_size - 1];
//        }
//
//        for(int i = 0; i < vertex_size - 1; i++) {
//            for(int j = 0; j <  vertex_size - 1; j++) {
//                if(i < del_idx && j < del_idx) {
//                    new_matrix[i][j] = edge_matrix[i][j];
//                }
//                else if(i < del_idx) {
//                    new_matrix[i][j] = edge_matrix[i][j + 1];
//                }
//                else if(j < del_idx) {
//                    new_matrix[i][j] = edge_matrix[i+1][j];
//                }
//                else{
//                    new_matrix[i][j] = edge_matrix[i+1][j+1];
//                }
//            }
//        }
//
//        for(int i = 0; i < vertex_size; i++) {
//            if(edge_matrix[del_idx][i] != NULL) {
//                edge_list.remove(edge_matrix[del_idx][i]);
//            }
//        }
//
//        for(int i = 0; i < vertex_size; i++) {
//            delete[] edge_matrix[i];
//        }
//        delete[] edge_matrix;
//
//        edge_matrix = new_matrix;
//        vertex_list.remove(del_vertex);
//        vertex_size--;
//        return;
//    }
//
//    void insert_edge(int s_v_id, int d_v_id) {
//        vertex* src_vertex = vertex_list.find_vertex(s_v_id);
//        vertex* dst_vertex = vertex_list.find_vertex(d_v_id);
//
//        if(src_vertex == NULL || dst_vertex == NULL) {
//
//            return;
//        }
//
//        int src_id = src_vertex->matrix_id;
//        int dst_id = dst_vertex->matrix_id;
//
//        if(edge_matrix[src_id][dst_id] != NULL || edge_matrix[dst_id][src_id] != NULL) {
//            cout << "Exist" << endl;
//            return;
//        }
//
//        edge* new_edge = new edge(src_vertex, dst_vertex);
//        edge_list.insert_back(new_edge);
//        edge_matrix[src_id][dst_id] = edge_matrix[dst_id][src_id] = new_edge;
//        return;
//    }
//
//    void erase_edge(int s_v_id, int d_v_id) {
//        vertex* src_vertex = vertex_list.find_vertex(s_v_id);
//        vertex* dst_vertex = vertex_list.find_vertex(d_v_id);
//        if(src_vertex == NULL || dst_vertex ==NULL) {
//            return;
//        }
//
//        int src_id = src_vertex->matrix_id;
//        int dst_id = dst_vertex->matrix_id;
//
//        if(edge_matrix[src_id][dst_id] == NULL || edge_matrix[dst_id][src_id] == NULL) {
//            cout << "None" << endl;
//            return;
//        }
//
//        edge_list.remove(edge_matrix[src_id][dst_id]);
//        edge_matrix[src_id][dst_id] = edge_matrix[dst_id][src_id] = NULL;
//        return;
//    }
//
//    int incidentEdges(int v_id) {
//        vertex* f_vertex = vertex_list.find_vertex(v_id);
//        int f_id = f_vertex->matrix_id;
//
//        int Num_edge = 0;
//
//        for(int i = 0; i <vertex_size ; i++) {
//            if(edge_matrix[f_id][i] != NULL) {
//                Num_edge++;
//            }
//        }
//
//        return Num_edge;
//    }
//    
//        void print_d(int v_id) {
//            vertex* f_vertex = vertex_list.find_vertex(v_id);
//            int f_id = f_vertex->matrix_id;
//
//            int Num_edge = 0;
//
//            for(int i = 0; i <vertex_size ; i++) {
//                if(edge_matrix[f_id][i] != NULL) {
//                    Num_edge++;
//                }
//            }
//            int max = Num_edge;
//            
//            for(int i = 0; i <vertex_size ; i++) {
//                
//                Num_edge = 0;
//                if(edge_matrix[f_id][i] != NULL) {
//                   int id = i;
//                    for(int j = 0; j <vertex_size ; j++) {
//                        if(edge_matrix[id][j] != NULL) {
//                            Num_edge++;
//                        }
//                    }
//                    if(max < Num_edge) {
//                        max = Num_edge;
//                    }
//                }
//            }
//            cout << max+1 << endl;
//        }
//    
//    void BFS(int v_id, int ES) {
//        vector<int> b;
//        queue<int> a;
//        for(int i = 1; i<vertex_size+1;i++) {
//            vertex* init = vertex_list.find_vertex(i);
//            init->label=0;
//        }
//        
//        a.push(v_id);
//        vertex* f_vertex = vertex_list.find_vertex(v_id);
//        f_vertex->label = 1;
//        while (a.size() != 0) {
//            int v = a.front();
//        
//            b.push_back(v);
//            
//            a.pop();
//            
//             f_vertex = vertex_list.find_vertex(v);
//            edge* y = edge_list.header;
//            
//            vertex* f1_vertex = NULL;
//            for(int i =0; i < ES; i++) {
//                y = y->next;
//                if(f_vertex == y->src) {
//                     f1_vertex = y->dst;
//                    if(f1_vertex->label == 0) {
//                        a.push(f1_vertex->vertex_id);
//                        f1_vertex->label = 1;
//                    }
//                    
//                }
//                else if(f_vertex == y->dst) {
//                    f1_vertex = y->src;
//                    
//                    if(f1_vertex->label == 0) {
//                        a.push(f1_vertex->vertex_id);
//                        f1_vertex->label = 1;
//                    }
////                }
////            }
////
////
////
//////            for(int i = 0; i < vertex_size; i++) {
//////                if(edge_matrix[f_id][i] != NULL) {
//////                     vertex* f1_vertex = vertex_list.find_vertex(i+1);
////                    if(f1_vertex->label == 0) {
////                        a.push(f1_vertex->vertex_id);
////                        f1_vertex->label = 1;
////                    }
////                }
//                
//                
//            }
//        for(int i = 0; i < b.size(); i++) {
//            if(i == (b.size() - 1)) {
//                cout << b[i] << endl;ie.
//            }
//            else {
//                cout << b[i] << " ";
//            }
//            
//        }
//        }
//       
//        
//    
//    
//  
//    
//        
//
//};
//
//int main() {
//    int T;
//    cin >> T;
//
//    while(T--) {
//        graph a;
//        int N, M;
//        cin >> N >> M;
//        
//        for(int i = 1; i < N+1; i++) {
//            a.insert_vertex(i);
//        }
//        
//        for(int i = 0; i < M; i++) {
//            int dt1, dt2;
//            cin >> dt1 >> dt2;
//            a.insert_edge(dt1, dt2);
//        }
//        
//        a.BFS(1,M);
//
//    }
//
//    return 0;
//}
