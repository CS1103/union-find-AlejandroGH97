//
// Created by alejandro on 5/24/19.
//
#include <array>
#ifndef UNION_FIND_ALEJANDROGH97_DISJOINT_SET_H
#define UNION_FIND_ALEJANDROGH97_DISJOINT_SET_H

template <int N,class Container>

class disjoint_set{

private:

    Container root;
    Container rank;

public:

    int getRank(int n){
        return rank[n];
    }

    int getRoot(int n){
        return root[n];
    }

    disjoint_set():root(N*N),rank(N*N) {

        for (int i = 0; i < N*N; ++i) {
            root[i]=i;
            rank[i]=0;
        }
    }
    int find(int num) {
        if (num == root[num]){
            return num;
        }
        else{
            root[num] = find(root[num]);
            return root[num];
        }

    }

    bool same(int vert1, int vert2) {
        int temp1 = find(vert1);
        int temp2 = find(vert2);

        return temp1==temp2;
    }

    void join(int vert1, int vert2) {
        int root1 = find(vert1);
        int root2 = find(vert2);

        if(rank[root1]>rank[root2]){
            root[root2]=root1;
        }
        else{
            root[root1] = root2;
            if(rank[root1] == rank[root2]) {
                rank[root2]++;
            }
        }
    }
};


template <int N>
class disjoint_set<N,std::array<int,N>>{

private:

    std::array<int,N*N> root;
    std::array<int,N*N> rank;

public:

    int getRank(int n){
        return rank[n];
    }

    int getRoot(int n){
        return root[n];
    }

     disjoint_set(){

        for (int i = 0; i < N*N; ++i) {
            root[i]=i;
            rank[i]=0;
        }
    }

    int find(int num) {
        if (num == root[num]){
            return num;
        }
        else{
            root[num] = find(root[num]);
            return root[num];
        }

    }

    bool same(int vert1, int vert2) {
        int temp1 = find(vert1);
        int temp2 = find(vert2);

        return temp1==temp2;
    }

    void join(int vert1, int vert2) {
        int root1 = find(vert1);
        int root2 = find(vert2);

        if(rank[root1]>rank[root2]){
            root[root2]=root1;
        }
        else{
            root[root1] = root2;
            if(rank[root1] == rank[root2]) {
                rank[root2]++;
            }
        }
    }
};




#endif //UNION_FIND_ALEJANDROGH97_DISJOINT_SET_H
