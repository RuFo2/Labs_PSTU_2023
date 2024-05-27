#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <queue>
#include <stack>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QGraphicsLineItem>
#include <vector>


#include <limits>
#include <list>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <iomanip>
#include <fstream>


using namespace std;

const int INF = std::numeric_limits<int>::max();

// Основа графа
class Graph {
    int size = 0;
    int maxVal = 0;
    int lastIndx = 0;
    int **mat = 0;

    int *vertices = 0;
    int *shortWays = 0;
    int *checkNodes = 0;
    int *way = 0;
    queue<int> Q;
    stack<int> S;

    // Траспонированная матрица
    void generateMatrixT()
    {
        matrixT = new int*[size];
        for (int i = 0; i < size; ++i)
        {
            matrixT[i] = new int[size];
            for (int j = 0; j < size; ++j)
            {
                matrixT[i][j] = matrix[j][i];
            }
        }
    }

    // Поиск минимальной суммы элементов в матрице
    int findMinSum(int **matrix, vector<int> strs, vector<int> stbs)
    {
        int sum = 0;
        int str_pos = 0;
        for (int i = 0; i < size; ++i)
        {
            if(!isInVector(strs, str_pos))
            {
                int stb_pos = 0;
                int m = INF;
                for (int j = 0; j < size; ++j)
                {
                    if(matrix[i][j] < m && !isInVector(stbs, stb_pos)) m = matrix[i][j];
                    ++stb_pos;
                }
                sum += m;
            }
            ++str_pos;
        }
        return sum;
    }

public:
    int **matrix, **matrixT;
    Graph(){};
    ~Graph(){};
    vector<QGraphicsItemGroup*> arrGr;
    vector<QGraphicsLineItem*> l;
    vector<QGraphicsTextItem*> t;
    void addNode();
    void delNode(int num);
    void setMat(int firstVert, int secondVert, int weight);
    QString searchInWidth(int start);
    QString searchInDepth(int start);
    void dijkstra(int start);
    void show();
    QString showw(); 
    bool checkMat(int a, int b){if (mat[a][b] != 0) return 1; return 0; };
    int weidgt(int i, int j){return mat[i][j];};
    int getSize(){return size;};

    // Получение значение в строке str и столбце stb
    int get(int str, int stb)
    {
        return matrix[str][stb];
    }

    // Получение нижней оценки
    int getH(vector<int> strs, vector<int> stbs)
    {
        int H1 = findMinSum(matrix, strs, stbs);
        int H2 = findMinSum(matrixT, stbs, strs);
        return max(H1, H2);
    }

    // Получение верхней оценки
    int getV(vector<int> lastNodes, int currentPoint)
    {
        int V1 = 0;
        for(int i = 0; i < size; ++i)
        {
            if(!isInVector(lastNodes, i) && i != currentPoint)
            {
                V1 += matrix[currentPoint][i];
                lastNodes.push_back(currentPoint);
                currentPoint = i;
            }
        }
        V1 += matrix[currentPoint][0];
        return V1;
    }
    bool isInVector(vector<int> v, int e)
    {
        return find(v.begin(), v.end(), e) != v.end();
    }
    // Генерация матрицы
    void generateMatrix()
    {
        matrix = new int*[size];
        for (int i = 0; i < size; ++i)
        {
            matrix[i] = new int[size];
            for (int j = 0; j < size; ++j)
            {
                matrix[i][j] = mat[i][j];
            }
        }
        generateMatrixT();
    }

};

// класс, который отвечает за вершину
class Node
{
public:
    int V; // Верхняя оценка
    int H; // Нижняя оценка
    bool isInVector(vector<int> v, int e)
    {
        return find(v.begin(), v.end(), e) != v.end();
    }
    // Конструктор принимает список предыдущих вершин, их номер, сумму переходов
    Node(vector<int> lastNodes, int node, int sum_per, Graph *matrix)
    {
        this->lastNodes = lastNodes;
        this->node = node;
        this->nodeQuantity = matrix->getSize();
        this->matrix = matrix;

        this->sum_per = sum_per;

        if(this->lastNodes.size() > 0)
        {
            this->sum_per += this->matrix->get(lastNodes.back(), this->node);
        }

        vector<int> strs;
        vector<int> stbs;

        for(int i = 0; i < this->lastNodes.size(); ++i)
        {
            strs.push_back(this->lastNodes[i]);
            if(i+1 < this->lastNodes.size())
                stbs.push_back(this->lastNodes[i+1]);
            else
                stbs.push_back(this->node);
        }

        this->H = this->sum_per + this->matrix->getH(strs, stbs);
        this->V = this->sum_per + this->matrix->getV(lastNodes, node);
    }

    // Возвращение списка следующих вершин
    list<Node> getNextNodes()
    {
        list<Node> nodes;
        this->lastNodes.push_back(node);
        for(int i = 0; i < nodeQuantity; ++i)
        {
            if(!isInVector(this->lastNodes, i))
            {
                nodes.push_back(Node(this->lastNodes, i, this->sum_per, this->matrix));
            }
        }
        return nodes;
    }

    // печать маршрута
    QString print()
    {
        QString dat;
        for(int i: lastNodes)
        {
            cout << i + 1 << " -> ";
            dat+= QString::number(i+1) + " -> ";
        }
        cout << 1 <<  " Length " << V << '\n';
        dat+= "1 Length: " + QString::number(V);

        cout << "transition matrix: " << endl;
        vector<vector<int>> m;
        lastNodes.push_back(0);
        for(int i = 0; i < lastNodes.size()-1; ++i)
        {
            vector<int> str;
            for(int j = 0; j < lastNodes.size()-1; ++j)
                str.push_back(0);
            m.push_back(str);
        }
        for(int i = 0; i < lastNodes.size()-1; ++i)
        {
            m[lastNodes[i]][lastNodes[i+1]] = 1;
        }
        for (auto it = m.begin(); it!=m.end(); ++it)
        {
            for (const auto &i:*it)
            {
                cout << setw(6);
                cout << i;
            };
            cout<< '\n';
        }
        return dat;
    }

    ~Node(){};
private:
    vector<int> lastNodes;
    int node;
    Graph *matrix;
    int nodeQuantity;
    int sum_per;
};

// класс, который содержит список вершин
class Container
{
public:
    list<Node> nodes;
    int quantity;
    int r;
    int pr;

    Container(int pr)
    {
        quantity = 0;
        r = INF;
        this->pr = pr;
    }

    void add(Node node)
    {
        if(r >= node.V)
            r = node.V;
        
        nodes.push_back(node);
        ++quantity;
        newScreen();
    }

    void addSome(list<Node> nodes)
    {
        for(Node &n : nodes)
            this->add(n);
        
    }

    void changeNodes(list<Node> nodes)
    {
        this->quantity = 0;
        this->nodes = {};
        this->addSome(nodes);
    }

    list<Node>::iterator del(list<Node>::iterator itr)
    {
        --this->quantity;
        this->newScreen();
        return nodes.erase(itr);
    }

    // вывод рекорда и количества вершин
    void newScreen()
    {
        if(pr == 1)
        {
            cout << "\rRecord:" << setw(20) << this->r << endl;
            cout << "\rNumber of vertices:" << setw(6) << this->quantity << endl;
        }
    }
};

#endif // GRAPH_H
