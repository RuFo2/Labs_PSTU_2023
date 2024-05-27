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



// Класс отвечающий за основу графа
class Graph {
    int size = 0; // Количество узлов
    int maxVal = 0; // Максимальная длина среди связей
    int lastIndx = 0;
    int **mat = 0; // Матрица смежности

    int *vertices = 0; // Посещенные вершины
    int *shortWays = 0; // Короткий путь
    int *checkNodes = 0; // Пройденные вершины при алгоритме Дейкстры
    int *way = 0; // Итоговый пройденый путь для алгоритма Дейкстры
    queue<int> Q; // Очередь для обхода в ширину
    stack<int> S; // Стек для обхона в глубину


public:

    Graph(){};
    ~Graph(){}; // Реализовать очищение всех переменных
    vector<QGraphicsItemGroup*> arrGr; // Хранение графических узлов
    vector<QGraphicsLineItem*> l; // Хранение линий связи
    vector<QGraphicsTextItem*> t; // Хранение текста, отвечающего за вес линий связи
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



};

#endif // GRAPH_H
