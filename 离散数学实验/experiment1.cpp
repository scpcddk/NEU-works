#include<bits/stdc++.h>
using namespace std;
//合取
bool And(bool a,bool b){
    return a&&b;
}
//析取
bool Or(bool a,bool b){
    return a||b;
}
//异或
bool Xor(bool a,bool b){
    return a^b;
}
//非
bool No(bool a){
    return !a;
}
//蕴含
bool Implies(bool a,bool b){
    if(a){
        if(b)
        return true;
        else
        return false;
    }
    else
    return true;
}
//三人表决结果
bool Vote(bool a,bool b,bool c){
    bool x=And(a,b);
    bool y=And(a,c);
    bool z=And(b,c);
    if(x||y||z)
    return true;
    else
    return false;
}
int main(){
    system("chcp 65001 > nul");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);   
    bool a,b,c;
    cout<<"输入3人表决值(1 表示通过 0 表示不通过)"<<endl<<"2人及以上同意则表决通过"<<endl;
    cin>>a>>b>>c;
    bool res=Vote(a,b,c);
    cout<<"表决结果："<<(res?"表决通过":"表决不通过")<<endl;
    return 0;
}