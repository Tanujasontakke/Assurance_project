#ifndef CIRCULARDOUBLYLIST_H
#define CIRCULARDOUBLYLIST_H

struct nod {
    int info;
    struct nod *n;
    struct nod *p;
};

class circulardoublylist {
private:
    nod *start, *last;
    int count;

    nod* create_node(int v);

public:
    circulardoublylist();
    void create_node_success();
    void display();
    void insert_begin();
    void insert_end();
    void insert_position();
    void delete_begin();
    void delete_end();
    void delete_position();
};

#endif /* CIRCULARDOUBLYLIST_H */
