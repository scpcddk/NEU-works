#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 6;
string names[N] = {"故宫", "天安门", "颐和园", "天坛", "长城", "鸟巢"};
// 综合权重矩阵（距离+时间+成本）
int dist[N][N] = {
    {0,  2, 15, 8, 40, 12},
    {2,  0, 16, 6, 42, 10},
    {15, 16, 0, 18, 35, 20},
    {8,  6, 18, 0, 38, 14},
    {40, 42, 35, 38, 0, 30},
    {12, 10, 20, 14, 30, 0}
};
int dp[1<<N][N];
int path[1<<N][N];
int main() {
    system("chcp 65001 > nul");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, 0x3f, sizeof(dp));
    memset(path, -1, sizeof(path));
    int start = 0; // 随机选择故宫为起点
    dp[1<<start][start] = 0;
    // 状态压缩DP
    for(int state = 0; state < (1<<N); state++) {
        if(!(state & (1<<start))) 
        continue;
        for(int i = 0; i < N; i++) {
            if(!(state & (1<<i))) 
            continue;
            if(dp[state][i] == INF) 
            continue;
            for(int j = 0; j < N; j++) {
                if(state & (1<<j)) 
                continue;
                int nxt = state | (1<<j);
                if(dp[nxt][j] > dp[state][i] + dist[i][j]) {
                    dp[nxt][j] = dp[state][i] + dist[i][j];
                    path[nxt][j] = i;
                }
            }
        }
    }
    // 输出所有哈密尔顿回路（枚举验证）
    cout << "=== 旅行路线规划(北京6景点TSP)===\n\n";
    cout << "景点列表：\n";
    for(int i=0;i<N;i++) 
    cout<<"  "<<i<<": "<<names[i]<<"\n";
    cout<<"\n权重矩阵:\n";
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++)
        cout<<setw(4)<<dist[i][j];cout<<"\n";
    }
    // 枚举所有回路
    vector<int> perm;
    for(int i=0;i<N;i++) {
    if(i!=start) 
    perm.push_back(i);
    }
    int cnt=1, bestCost=INF;
    vector<int> bestRoute;
    cout<<"\n所有哈密尔顿回路及权重:\n";
    do{
        int cost=dist[start][perm[0]];
        for(int i=0;i<perm.size()-1;i++) 
        cost+=dist[perm[i]][perm[i+1]];
        cost+=dist[perm.back()][start];
        cout<<"S"<<cnt++<<"=("<<names[start];
        for(int x:perm) 
        cout<<","<<names[x];
        cout<<","<<names[start]<<") 权重="<<cost<<"\n";
        if(cost<bestCost) {
            bestCost=cost;bestRoute=perm;
        }
    }while(next_permutation(perm.begin(),perm.end()));
    // DP最优解
    int finalState=(1<<N)-1, minCost=INF, endNode=-1;
    for(int i=0;i<N;i++) if(i!=start) {
        if(dp[finalState][i]+dist[i][start]<minCost){
            minCost=dp[finalState][i]+dist[i][start];
            endNode=i;
        }
    }
    // 回溯路径
    vector<int> route;
    int curState=finalState, cur=endNode;
    while(cur!=-1){
        route.push_back(cur);
        int prev=path[curState][cur];
        if(prev==-1) 
        break;
        curState^=(1<<cur);
        cur=prev;
    }
    reverse(route.begin(),route.end());
    cout<<"\n【动态规划最优解】\n";
    cout<<"最优总权重："<<minCost<<"\n";
    cout<<"最优路线：";
    for(int i=0;i<route.size();i++){
        cout<<names[route[i]];
        if(i!=route.size()-1) 
        cout<<" -> ";
    }
    cout<<" -> "<<names[start]<<"\n";
    cout<<"\n【算法对比】\n";
    cout << "枚举法检查回路数："<<60<<" 条\n";
    cout<<"DP状态数:"<<(1<<N)*N<<" 个\n";
    cout<<"时间复杂度:O(n²·2ⁿ) 远优于枚举法 O(n!)\n";
    return 0;
}