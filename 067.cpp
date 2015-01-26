/* Copyright 2015 ToxaKniotee */
#include <stdio.h>
#include <string>

using std::string;

class Node {
    public:
        explicit Node(int value);
        Node(int value, Node *parent);

        Node *child_left, *child_right, *parent_right, *parent_left,
            *max_parent, *brother_left, *brother_right;
        int size;
        unsigned parent_size;
};

class Tree {
    public:
        Tree();
        void loadFile(string text_file);
        void addNode(int size);
        int size();
        int depth();
        unsigned bigger();
        void save(string file_name);

    protected:
        Node *first, *actual_parent, *next_parent;
        int _size;
        int _depth;
};

int main(int argc, char const *argv[]) {
    Tree graph;
    graph.loadFile("files/p067.txt");
    graph.save("save.txt");
    printf("max: %i\n", graph.bigger());
    return 0;
}

Node::Node(int value) {
    child_right = child_left = parent_left = parent_right = max_parent =
        brother_left = brother_right = NULL;
    size = parent_size = value;
}

Tree::Tree() {
    first = actual_parent = next_parent = NULL;
    _size = _depth = 0;
}

void Tree::loadFile(string text_file) {
    int temp_size;
    FILE *pfile = fopen(text_file.c_str(), "r");
    while ((fscanf(pfile, "%2i", &temp_size)) != EOF) {
        addNode(temp_size);
    }
    fclose(pfile);
}

void Tree::addNode(int size) {
    Node *temp = new Node(size);
    _size++;
    if (first == NULL) {
        first = temp;
        actual_parent = next_parent = first;
        _depth++;
        return;
    } else if (actual_parent == next_parent) {
        /* Aumentamos la profundidad */
        _depth++;

        /* Ligamos al padre */
        actual_parent->child_left = temp;
        temp->parent_right = actual_parent;

        /* Calculamos el valor actual y ligamos */
        temp->parent_size += actual_parent->parent_size;
        temp->max_parent = actual_parent;

        /* Avanzamos el puntero next_parent */
        next_parent = temp;
        return;
    }

    /* Ligamos al padre */
    actual_parent->child_right = temp;
    temp->parent_left = actual_parent;

    /* Ligamos al hermano izquierdo */
    temp->brother_left = actual_parent->child_left;
    actual_parent->child_left->brother_right = temp;

    /* Calculamos el valor actual y ligamos */
    temp->parent_size += actual_parent->parent_size;
    temp->max_parent = actual_parent;

    /* Checamos si hay un parent_right */
    if (actual_parent->brother_right != NULL) {
        actual_parent = actual_parent->brother_right;

        /* Ligamos */
        actual_parent->child_left = temp;
        temp->parent_right = actual_parent;

        /* Checamos si es mayor que con el padre anterior */
        if (actual_parent->parent_size + size > temp->parent_size) {
            temp->parent_size = actual_parent->parent_size + size;
            temp->max_parent = actual_parent;
        }
    } else {
        actual_parent = next_parent;
    }
}

int Tree::size() {
    return _size;
}

int Tree::depth() {
    return _depth;
}

unsigned Tree::bigger() {
    Node *temp = first;
    while (temp->child_left != NULL) {
        temp = temp->child_left;
    }
    unsigned max = 0;
    while (temp != NULL) {
        if (temp->parent_size > max) {
            max = temp->parent_size;
        }
        temp = temp->brother_right;
    }
    return max;
}

void Tree::save(string file_name) {
    FILE *pfile = fopen("save.txt", "w");
    fprintf(pfile, "%u\n", first->parent_size);
    Node *temp, *row_temp;
    temp = row_temp = first->child_left;
    while (row_temp != NULL) {
        while (temp != NULL) {
            fprintf(pfile, "%u ", temp->parent_size);
            temp = temp->brother_right;
        }
        fprintf(pfile, "\n");
        row_temp = temp = row_temp->child_left;
    }
    fclose(pfile);
}
