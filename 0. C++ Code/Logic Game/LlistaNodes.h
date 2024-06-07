#ifndef LLISTA_NODES_H
#define LLISTA_NODES_H

class LlistaNodes 
{
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* head;
    Node* tail;
    int length;

public:
    LlistaNodes() : head(nullptr), tail(nullptr), length(0) {}
 void afegeix(int valor) {
        Node* newNode = new Node;
        newNode->data = valor;
        newNode->next = nullptr;

        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    // Esborra tots els elements de la llista
    void esborraTot() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    // Obté la longitud de la llista
    int longitud() const { return length; }

    // Comprova si la llista està buida
    bool esBuida() const { return length == 0; }

    // Destructor per esborrar la memòria
    ~LlistaNodes() {
        esborraTot();
    }

};

#endif
