#include<iostream>
#include<vector>
using namespace::std;

int main(){
    int size;
    cout<<"Enter size for vector : ";
    cin>>size;
    vector <int> num(size);
    for(int i = 0;i<size;i++){
        cin>>num[i];
    }
   // cout<<num.size()<<endl;
    vector<string> names = {"saad","reyan","khan"};
    int i = 0;
    names.push_back("asif");
    names.push_back("khan");
    names.push_back("khan");
    names.push_back("khan");
    cout<<"khan is poped :";
    cout<<"\ncapacity is : "<<names.capacity();
    names.pop_back();
    cout<<"\nis the first value in vector : "<<names.front()<<endl;
    cout<<names.back()<<" : is the last value of vectore"<<endl;
    cout<<names.at(0)<<endl;
    cout<<"\nSize of the string is : "<<names.size()<<endl;
    cout<<"String elements are : "<<endl;
    for(string val : names){
        
        cout<<val<<" (index "<<i<<") ";
        i++;
    }

    int unique = 0;
    for(int val : num){
        unique = unique ^ val;
    }
    cout<<"\nThe unique value is : "<<unique<<endl;
    return 0;
}