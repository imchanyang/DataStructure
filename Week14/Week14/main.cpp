//#include <iostream>
//#include <queue>
//#include <vector>
//using namespace std;
//
//template<typename T>
//struct Node {
//    
//public:
//    T data;
//    Node<T>* prev;
//    Node<T>* next;
//    
//    Node() {
//        prev = next = NULL;
//    }
//    
//    Node(T dt) {
//        data = dt;
//        prev = next = NULL;
//    }
//};
//
//template<typename T>
//class LinkedList {
//public:
//    Node<T>* header;
//    Node<T>* trailer;
//    
//    LinkedList() {
//        header = new Node<T>();
//        trailer = new Node<T>();
//        header->next = trailer;
//        trailer->prev = header;
//    }
//    
//    void insert_back(Node<T>* new_Node) {
//        new_Node->prev = trailer->prev;
//        new_Node->next = trailer;
//        
//        trailer->prev->next = new_Node;
//        trailer->prev = new_Node;
//        return;
//    }
//    
//    void remove(Node<T>* del_Node) {
//        del_Node->prev->next = del_Node->next;
//        del_Node->next->prev = del_Node->prev;
//        
//        delete del_Node;
//        
//        return;
//    }
//    
//    
//};
//
//struct edge;
//
//struct vertex {
//    int vertex_id;
//    int degree;
//    int label = 0;
//    LinkedList<edge*>* incident_edges;
//    Node<vertex*>* vertex_node;
//    
//    vertex() {
//        vertex_id = 0;
//        degree = 0;
//        incident_edges = new LinkedList<edge*>();
//        vertex_node = new Node<vertex*>(this);
//    }
//    
//    vertex(int v_id) {
//        vertex_id = v_id;
//        degree = 0;
//        incident_edges = new LinkedList<edge*>();
//        vertex_node = new Node<vertex*>(this);
//    }
//};
//
//struct edge {
//    vertex* src_vertex;
//    vertex* dst_vertex;
//    Node<edge*>* src_incident_edge_node;
//    Node<edge*>* dst_incident_edge_node;
//    Node<edge*>* total_edge_node;
//    
//    edge() {
//        src_vertex = NULL;
//        dst_vertex = NULL;
//        src_incident_edge_node = new Node<edge*>(this);
//        dst_incident_edge_node = new Node<edge*>(this);
//        total_edge_node = new Node<edge*>(this);
//    }
//    
//    edge(vertex* src, vertex*  dst) {
//        src_vertex = src;
//        dst_vertex = dst;
//        src_incident_edge_node = new Node<edge*>(this);
//        dst_incident_edge_node = new Node<edge*>(this);
//        total_edge_node = new Node<edge*>(this);
//    }
//};
//
//class graph {
//private:
//    LinkedList<vertex*>* vertex_list;
//    
//    LinkedList<edge*>* edge_list;
//    int vertex_size;
//    
//    vertex* find_vertex(int v_id) {
//        for(Node<vertex*>* cur = vertex_list->header->next; cur != vertex_list->trailer; cur = cur->next) {
//            if(cur->data->vertex_id == v_id) {
//                return cur->data;
//            }
//        }
//        return NULL;
//    }
//    
//    edge* find_edge(vertex* src, vertex* dst){
//        if(src->degree <= dst->degree) {
//            for(Node<edge*>* cur = src->incident_edges->header->next; cur != src->incident_edges->trailer; cur = cur->next) {
//                if(cur->data->dst_vertex == dst) {
//                    return cur->data;
//                }
//            }
//        }
//        else {
//            for(Node<edge*>* cur = dst->incident_edges->header->next; cur != dst->incident_edges->trailer; cur = cur->next) {
//                if(cur->data->src_vertex == src) {
//                    return cur->data;
//                }
//            }
//        }
//        return NULL;
//    }
//public:
//    graph() {
//        vertex_list = new LinkedList<vertex*>();
//        edge_list = new LinkedList<edge*>();
//        vertex_size = 0;
//    }
//    
//    void insert_vertex(int v_id) {
//        if(find_vertex(v_id) != NULL) return;
//        
//        vertex* new_vertex = new vertex(v_id);
//        vertex_list->insert_back(new_vertex->vertex_node);
//        vertex_size++;
//        return;
//    }
//    
//    void insert_edge(int src_id, int dst_id) {
//        vertex* src = find_vertex(src_id);
//        vertex* dst = find_vertex(dst_id);
//        
//        if(src == NULL || dst == NULL) {
//            return;
//        }
//        
//        if(find_edge(src,dst) != NULL) {
//            return;
//        }
//        
//        edge* new_edge = new edge(src,dst);
//        src->incident_edges->insert_back(new_edge->src_incident_edge_node);
//        dst->incident_edges->insert_back(new_edge->dst_incident_edge_node);
//        
//        edge_list->insert_back(new_edge->total_edge_node);
//        src->degree++;
//        dst->degree++;
//        return;
//    }
//    
//    void erase_vertex(int v_id) {
//        vertex* del_vertex = find_vertex(v_id);
//        if(del_vertex == NULL) {
//            return;
//        }
//        
//        for(Node<edge*>* cur = del_vertex->incident_edges->header->next; cur != del_vertex->incident_edges->trailer;) {
//            edge* del_edge = cur->data;
//            cur = cur->next;
//            erase_edge(del_edge);
//        }
//        
//        vertex_list->remove(del_vertex->vertex_node);
//        vertex_size--;
//        delete del_vertex;
//        return;
//    }
//    
//    void erase_edge(edge* del_edge) {
//        del_edge->src_vertex->incident_edges->remove(del_edge->src_incident_edge_node);
//        del_edge->dst_vertex->incident_edges->remove(del_edge->dst_incident_edge_node);
//        
//        edge_list->remove(del_edge->total_edge_node);
//        del_edge->src_vertex->degree--;
//        del_edge->dst_vertex->degree--;
//        delete del_edge;
//        return;
//    }
//    
//    void erase_edge(int src_id, int dst_id) {
//        vertex* src_vertex = find_vertex(src_id);
//        vertex* dst_vertex = find_vertex(dst_id);
//        
//        if(src_vertex == NULL || dst_vertex == NULL) {
//            return;
//        }
//        
//        edge* del_edge = find_edge(src_vertex, dst_vertex);
//        if(del_edge == NULL) {
//            return;
//        }
//        
//        erase_edge(del_edge);
//        return;
//        
//    }
//    
//    void BFS(int v_id) {
//           vector<int> b;
//           queue<int> a;
//        Node<vertex *> *init = vertex_list->header;
//           for(int i = 0; i<vertex_size;i++) {
//               init = init->next;
//               init->data->label = 0;
//           }
//   
//           a.push(v_id);
//        
//        init = vertex_list->header;
//        vertex* f_vertex = nullptr;
//        for(int i = 0; i<vertex_size;i++) {
//            init = init->next;
//            if(init->data->vertex_id == v_id) {
//               f_vertex = init->data;
//                break;
//            }
//            
//        }
//        
//         
//           f_vertex->label = 1;
//           while (a.size() != 0) {
//               int v = a.front();
//   
//               b.push_back(v);
//   
//               a.pop();
//               
//               init = vertex_list->header;
//               for(int i = 1; i<vertex_size+1;i++) {
//                   init = init->next;
//                   if(init->data->vertex_id == v) {
//                      f_vertex = init->data;
//                   }
//                   
//               }
//               
//               LinkedList<edge *> * f_id = f_vertex->incident_edges;
//               Node<edge *> * d = f_id->header;
//               while(d != f_id->trailer) {
//                   d = d->next;
//                   
//                   if(v == d->data->dst_vertex->vertex_id) {
//                       vertex* c =  d->data->dst_vertex;
//                       
//                       a.push(c->vertex_id);
//                       c->label = 1;
//                   }
//                   else {
//                       vertex* c =  d->data->src_vertex;
//                       a.push(c->vertex_id);
//                       c->label = 1;
//                   }
//                   
//               }
//                    
//               
//             
//              
//           }
//           for(int i = 0; i < b.size(); i++) {
//               if(i == (b.size() - 1)) {
//                   cout << b[i] << endl;
//               }
//               else {
//                   cout << b[i] << " ";
//               }
//   
//           }
//   
//       }
//    
//    
//    
//};
//
//
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
//        a.BFS(1);
//
//    }
//
//    return 0;
//}
