//
// Created by timruning on 18-5-11.
//

#include "../import_iostream.h"

template <typename T>
void printVec(const vector<T> &vec) {
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}

//void printVec(const vector<string> &vec) {
//    for (int i = 0; i < vec.size(); i++)
//        cout << vec[i] << " ";
//    cout << endl;
//}

//void split(const string& s,vector<string>& tokens,const string& delimiters){
//    string:: size_type  lastPos=s.find_first_not_of(delimiters,0);
//    string:: size_type  pos=s.find_first_of(delimiters,lastPos);
//    while (string::npos != pos || string::npos!=lastPos){
//        tokens.push_back(s.substr(lastPos,pos - lastPos));
//        lastPos=s.find_first_not_of(delimiters,pos);
//        pos=s.find_first_of(delimiters,lastPos);
//    }
//}

//void split(){
//    std::string text = "sdf sdf sdg ";
//    std::regex ws_re("\\s+");
//}