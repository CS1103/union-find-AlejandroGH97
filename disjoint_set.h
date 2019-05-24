//
// Created by alejandro on 5/24/19.
//
#include <array>
#ifndef UNION_FIND_ALEJANDROGH97_DISJOINT_SET_H
#define UNION_FIND_ALEJANDROGH97_DISJOINT_SET_H

template <int N,class Container>

class disjoint_set{

private:

    Container vertices;
    Container root;

public:
    disjoint_set():vertices(N*N),root(N*N) {

        for (int i = 0; i < N*N; ++i) {
            vertices[i]=i;
            root[i]=i;
        }
    }
    int find(int num) {
        int temp = num;
        while(temp!=root[temp]){
            temp=root[temp];
        }
        return temp;
    }

    int findCompresion(int num){

    }

    bool same(int vert1, int vert2) {
        int temp1 = vert1;
        int temp2 = vert2;

        while(temp1!=root[temp1]){
            temp1=root[temp1];
        }

        while(temp2!=root[temp2]){
            temp2=root[temp2];
        }

        return temp1==temp2;
    }

    void join(int vert1, int vert2) {
        root[find(vert1)]=vert2;
    }
};


template <int N>
class disjoint_set<N,std::array<int,N>>{

private:

    std::array<int,N*N> vertices;
    std::array<int,N*N> root;

public:
     disjoint_set(){

        for (int i = 0; i < N*N; ++i) {
            vertices[i]=i;
            root[i]=i;
        }
    }
    int find(int num) {
        int temp = num;
        while(temp!=root[temp]){
            temp=root[temp];
        }
        return temp;
    }

    int findCompresion(int num){

    }

    bool same(int vert1, int vert2) {
        int temp1 = vert1;
        int temp2 = vert2;

        while(temp1!=root[temp1]){
            temp1=root[temp1];
        }

        while(temp2!=root[temp2]){
            temp2=root[temp2];
        }

        return temp1==temp2;
    }

    void join(int vert1, int vert2) {
        root[find(vert1)]=vert2;
    }
};




#endif //UNION_FIND_ALEJANDROGH97_DISJOINT_SET_H
