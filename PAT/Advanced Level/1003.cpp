#include <iostream>
#include <vector>

using namespace std;

#define MaxInt 32767
#define MVNum 500

typedef int ver_type;
typedef int arc_type;


typedef struct {
    ver_type vers[MVNum];
    arc_type arcs[MVNum][MVNum];
    int ver_num, arc_num;
}am_gragh;

typedef struct {
    am_gragh g;
    int c1, c2;
}rescue_task;

void init_am_gragh(am_gragh& g, int ver_num, int arc_num)
{
    g.ver_num = ver_num;
    g.arc_num = arc_num;
    for (int i = 0; i < g.ver_num; ++i)
        for (int j = 0; j < g.ver_num; ++j) {
            g.arcs[i][j] = MaxInt;
            g.arcs[j][i] = MaxInt;
        }
}

void shortest_path_dij(am_gragh& g, int v0, vector<int>& shortest_num, vector<int>& rescue_num)
{
    int n = g.ver_num;
    vector<bool> s(n);
    vector<int> d(n);
    for (int i = 0; i < n; ++i) {
        s[i] = false;
        d[i] = g.arcs[v0][i];
        shortest_num[i] = 1;
        rescue_num[i] = g.vers[v0] + g.vers[i];
    }
    s[v0] = true;
    d[v0] = 0;
    rescue_num[v0] = g.vers[v0];
    for (int i = 1; i < n; ++i) {
        int min = MaxInt;
        int k = v0;
        for (int w = 0; w < n; ++w) {
            if ((!s[w]) && (min > d[w])) {
                k = w;
                min = d[w];
            }
        }
        s[k] = true;
        for (int w = 0; w < n; ++w) {
            if (!s[w]) {
                if (d[k] + g.arcs[k][w] < d[w]) {
                    d[w] = d[k] + g.arcs[k][w];
                    rescue_num[w] = rescue_num[k] + g.vers[w];
                    shortest_num[w] = shortest_num[k];
                }
                else if (d[k] + g.arcs[k][w] == d[w]) {
                    if ((rescue_num[k] + g.vers[w]) > rescue_num[w])
                        rescue_num[w] = rescue_num[k] + g.vers[w];
                    shortest_num[w] += shortest_num[k];
                }
            }
        }
    }
}

int _1003(void)
{
    rescue_task rescue;

    int n, m;
    cin >> n >> m;
    cin >> rescue.c1 >> rescue.c2;
    init_am_gragh(rescue.g, n, m);
    for (int i = 0; i < n; ++i)
        cin >> rescue.g.vers[i];

    for (int k = 0; k < m; ++k) {
        int i, j;
        cin >> i >> j;
        cin >> rescue.g.arcs[i][j];
        rescue.g.arcs[j][i] = rescue.g.arcs[i][j];
    }

    vector<int> shortest_num(n);
    vector<int> rescue_num(n);
    shortest_path_dij(rescue.g, rescue.c1, shortest_num, rescue_num);
    cout << shortest_num[rescue.c2] << ' ' << rescue_num[rescue.c2] << endl;
    return 0;
}

/*
 *输入：
 第一行：4个正整数（<=500）:
     第一个N：城市数量（序号从0开始）
     第二个M：道路数量
     第三个C1：你所在城市
     第四个C2：需要救援的城市
 第二行：N个数：表示第i个城市的救援队的数量
 剩余的M行：每一行3个数：第一第二个数为城市序号，第三个数为这个两个城市之间的距离

 输出：
 一行；两个数：C1到C2的最短距离路线的条数，最短路径中能汇聚的救援队的最大数量
 */
 /*
 例：
 输入
 5 6 0 2
 1 2 1 5 3
 0 1 1
 0 2 2
 0 3 1
 1 2 1
 2 4 1
 3 4 1
 输出
 2 4
 */




/*
#include <iostream>
#include <climits>

using namespace std;

constexpr static int MaxSize = 1000;

typedef int RescueNum;

typedef struct {
    RescueNum vexs[MaxSize];
    int arcs[MaxSize][MaxSize];
    int vexnum,arcnum;
}AMGraph;

void CreateAMGraph(AMGraph &G, int vexnum, int arcnum)
{
    G.vexnum = vexnum;
    G.arcnum = arcnum;

    for (int i = 0; i < G.vexnum; ++i) {
        cin >> G.vexs[i];
    }

    for (int i = 0; i < G.vexnum; ++i)
        for (int j = 0; j < G.vexnum; ++j)
            G.arcs[i][j] = INT_MAX;

    for (int i = 0,v,w; i < G.arcnum; ++i) {
        cin >> v >> w;
        cin >> G.arcs[v][w];
        G.arcs[w][v] = G.arcs[v][w];
    }
}

void ShortestPath_DIJ(AMGraph G, int v0, bool S[], int D[], int Path[], int Rescue[])
{
    int n = G.vexnum;
    for (int w = 0; w < n; ++w) {
        S[w] = false;
        D[w] = G.arcs[v0][w];
        if (D[w] < INT_MAX) {
            Path[w] = v0;
            Rescue[w] = G.vexs[v0] + G.vexs[w];
        } else {
            Path[w] = -1;
            Rescue[w] = 0;
        }
    }
    S[v0] = true;
    D[v0] = 0;
    Rescue[v0] = G.vexs[v0];

    for (int i = 0,v = v0,min; i < n; ++i) {
        min = INT_MAX;
        for (int w = 0; w < n; ++w) {
            if (!S[w] && D[w] < min) {
                v = w;
                min = D[w];
            }
        }
        S[v] = true;
        for (int w = 0; w < n; ++w) {
            if ( !S[w] && static_cast<unsigned int>(D[v] + G.arcs[v][w]) <= static_cast<unsigned int>(D[w])) {
                if ( (static_cast<unsigned int>(D[v] + G.arcs[v][w]) == static_cast<unsigned int>(D[w])) && ((Rescue[v] + G.vexs[w]) < Rescue[w])) {
                    //cout << "ttt" << endl;
                    continue;
                }
                Rescue[w] = Rescue[v] + G.vexs[w];
                D[w] = D[v] + G.arcs[v][w];
                Path[w] = v;
            }
        }
    }
}

int main()
{
    int CityNum,PathNum;
    int CurrentCity,TargetCity;
    cin >> CityNum >> PathNum >> CurrentCity >> TargetCity;
    AMGraph G;
    CreateAMGraph(G, CityNum, PathNum);

    bool *S = new bool(G.vexnum);
    int *Path = new int(G.vexnum);
    int *D = new int(G.vexnum);
    int *Rescue = new int(G.vexnum);
    ShortestPath_DIJ(G, CurrentCity, S, D, Path, Rescue);
    cout << D[TargetCity] << ' ' << Rescue[TargetCity];
    cout << endl;

    return 0;
}*/