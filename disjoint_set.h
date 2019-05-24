//
// Created by alejandro on 5/24/19.
//

#ifndef UNION_FIND_ALEJANDROGH97_DISJOINT_SET_H
#define UNION_FIND_ALEJANDROGH97_DISJOINT_SET_H

template <template<typename ,typename...>class Container>

class disjoint_set{

private:

    Container<int> vertices;
    Container<int> root;

public:
    explicit disjoint_set(int n):vertices(n*n),root(n*n) {

        for (int i = 0; i < n*n; ++i) {
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
        root[vert1]=vert2;
    }
};


#endif //UNION_FIND_ALEJANDROGH97_DISJOINT_SET_H
