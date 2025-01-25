#include <bits/stdc++.h>
using namespace std;

// Doubly Linked List Node.
class Node
{

private:
public:
    int key;
    int value;
    Node *next;
    Node *prev;

    // Constructor.
    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
        next = prev = NULL;
    }
};

class LRUCache
{

    // DLL is used to perfrom deletion of (key, value) pair in O(1) time complexity.

    // Head and Tail Pointer.
    // Most Recently Used key, value pair will be present at the tail of the DLL.
    // Least Recently Used kry, value pair will be present at the head of the DLL.
    Node *head, *tail;

    // Unordered_map is used to search for a given key in O(1) avg. time complexity.
    unordered_map<int, Node *> map;

    // to store the total capacity of cache.
    int capacity;

    // length of the Doublt Linked List.
    int len;

public:
    // Constrictor.
    LRUCache(int capacity)
    {

        this->capacity = capacity;
        len = 0;
        head = NULL;
        tail = NULL;
    }

    int get(int key)
    {

        // If Key not present, in this case simply return -1.
        if (map.find(key) == map.end())
        {
            return -1;
        }

        // Else, if key is present.

        // Get the node (key, value) pair from the map.
        Node *keyNode = map[key];

        // erase this key from map.
        map.erase(key);

        // take out the value from the node.
        int value = keyNode->value;

        // Delete the keyNode from its current position, because we have to shift this (key, value) pair at the tail of the DLL, because Must Recently Used key, value pair is present at the tail of the DLL.
        if (head != NULL && head == tail && head == keyNode)
        {
            delete head;
            head = tail = NULL;
        }
        else if (head == keyNode)
        {
            head = head->next;

            if (head != NULL)
                head->prev = NULL;

            keyNode->next = NULL;
            delete keyNode;
        }
        else if (tail == keyNode)
        {
            tail = tail->prev;
            if (tail != NULL)
                tail->next = NULL;
            keyNode->prev = NULL;
            delete keyNode;
        }
        else
        {

            keyNode->prev->next = keyNode->next;
            keyNode->next->prev = keyNode->prev;

            keyNode->next = NULL;
            keyNode->prev = NULL;
            delete keyNode;
        }

        // Push key, value pair at the tail of the DLL.
        Node *newNode = new Node(key, value);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;

            tail = newNode;
        }

        // Insert key, value pair in the map.
        map[key] = newNode;

        // return value.
        return value;
    }

    void put(int key, int value)
    {

        // If Key not present.
        if (map.find(key) == map.end())
        {
            // Create a new node with the given key, value and insert the node at the tail of the DLL.
            Node *newNode = new Node(key, value);
            if (head == NULL)
            {
                head = tail = newNode;
            }
            else
            {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }

            // Store key, value pair in map also.
            map[key] = newNode;

            // increment the length of the DLL.
            len++;
        }

        // else If Key is Present.
        else
        {

            // take out the node from the map.
            Node *keyNode = map[key];

            // erase this key from the map.
            map.erase(key);

            // Delete the keyNode from its current position, because we have to shift this (key, value) pair at the tail of the DLL, because Must Recently Used key, value pair is present at the tail of the DLL.
            if (head != NULL && head == tail && head == keyNode)
            {
                delete head;
                head = tail = NULL;
            }
            else if (head == keyNode)
            {
                head = head->next;

                if (head != NULL)
                    head->prev = NULL;

                keyNode->next = NULL;
                delete keyNode;
            }
            else if (tail == keyNode)
            {
                tail = tail->prev;
                if (tail != NULL)
                    tail->next = NULL;
                keyNode->prev = NULL;
                delete keyNode;
            }
            else
            {

                keyNode->prev->next = keyNode->next;
                keyNode->next->prev = keyNode->prev;

                keyNode->next = NULL;
                keyNode->prev = NULL;
                delete keyNode;
            }

            // Push key, value pair at the tail of the DLL.
            Node *newNode = new Node(key, value);

            if (head == NULL)
            {
                head = tail = newNode;
            }
            else
            {
                tail->next = newNode;
                newNode->prev = tail;

                tail = newNode;
            }

            // Store key, value pair in map also.
            map[key] = newNode;
        }

        // if the length of the DLL is greater then the cache capacity, then simply delete the head node, because Least Recently Used (key, value) pair is present at the head of the DLL.
        if (len > capacity)
        {
            Node *nodeToDelete = head;
            if (head == NULL)
            {
                return;
            }

            else if (head->next == NULL)
            {
                delete head;
                head = tail = NULL;
            }
            else
            {

                head = head->next;
                head->prev = NULL;

                nodeToDelete->next = NULL;
            }

            // erase the key from the map also.
            map.erase(nodeToDelete->key);

            // delete the node.
            delete nodeToDelete;

            // decrement the length.
            len--;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */