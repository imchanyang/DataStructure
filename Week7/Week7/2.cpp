//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//
//
//int main() {
//    vector<int> post_;
//    vector<int> depth_;
//    vector<int> pre_;
//    int sg = 1;
//    int rem = 0;
//    int max=0;
//    int T;
//    cin >> T;
//    
//    for (int i = 0; i < T; i++) {
//        int N;
//        cin >> N;
//        pre_.clear();
//        for(int j = 0; j < N; j++) {
//            int dt;
//            cin >> dt;
//            post_.push_back(dt);
//        }
//        for(int k = 0; k < N; k++) {
//            int dt;
//            cin >> dt;
//            if(max < dt) {
//                max = dt;
//            }
//            depth_.push_back(dt);
//        }
//
//        
//        pre_.push_back(1);
//        sg = max;
//      
//       
//            for(int r = 0; r < N; r++) {
//                if(depth_[r] == 1 ) {
//                    pre_.push_back(post_[r]);
//                    
//                    
//                    for(int a = 0; a <max; a++) {
//                        
//                    for(int b = rem; b < r; b++) {
//                    
//                        if(depth_[b] == sg) {
//                            pre_.push_back(post_[b]);
//                            
//                            
//                        }
//                       
//                    }
//                        sg--;
//                       
//                    }
//                    sg = max;
//                    rem = r;
//                }
//                
//                    
//            }
//        
//        
//        
//        for(int q = 0; q < N; q++) {
//            cout << pre_[q] << " ";
//        }
//        cout << endl;
//     
//        
//    }
//    
//    
//    return 0;
//}
