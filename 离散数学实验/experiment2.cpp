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
int main(){
    system("chcp 65001 > nul");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);   
    /*符号化命题:
    A:A 盗窃了 x
    B:B 盗窃了 x
    C:作案时间发生在午夜前
    D:B 证词正确
    E:午夜时屋里灯光灭了
    */
    bool E=true;
    bool all=true;
    cout<<"枚举 A B C D 所有取值"<<endl;
    for(int a=0;a<2;a++){
        for(int b=0;b<2;b++){
            for(int c=0;c<2;c++){
                for(int d=0;d<2;d++){
                    /*已知条件
                    1.A析取B
                    2.A蕴含非C
                    3.D蕴含非E
                    4.非D蕴含C
                    5.E为真
                    */
                    bool con1=Or(a,b);
                    bool con2=Implies(a,No(c));
                    bool con3=Implies(d,No(E));
                    bool con4=Implies(No(d),c);

                    bool pre=And(And(And(And(con1,con2),con3),con4),E);
                    // 复合命题：前提 → A
                    bool imp=Implies(pre,a);
                    if(!imp)
                    all=false;
                }
            }
        }
    }
    if(all)
    cout<<1<<"A盗窃了x"<<endl;
    else
    cout<<0<<"B盗窃了x"<<endl;
    return 0;
}