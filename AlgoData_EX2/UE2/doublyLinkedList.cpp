// Name: Jürgen Zangerl
// Matrikelnummer: 0216253
// MCI DiBSE JG 2021

#include "doublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
}

void DoublyLinkedList::insertAtStart(int key) {
    ExtendedListItem* temp = new ExtendedListItem(key);

    if(this->head == nullptr) {
        this->head = temp;
        this->tail = temp;
    } else {
        this->head->previous = temp;
        temp->next = this->head;
        this->head = temp;
    }
}

void DoublyLinkedList::insertAtEnd(int key) {
    ExtendedListItem* temp = new ExtendedListItem(key);

    if(this->head == nullptr) {
        this->head = temp;
        this->tail = temp;
    } else {
        this->tail->next = temp;
        temp->previous = this->tail;
        this->tail = temp;
    }
}

void DoublyLinkedList::insertSorted(int key) {
    ExtendedListItem* prev = nullptr;
    ExtendedListItem* current = this->head;
    ExtendedListItem* newItem = new ExtendedListItem(key); //create the new ExtendedListItem

    if(this->head == nullptr || key < this->head->key) {// list is empty OR new is samller than head->key => insert at front
        this->insertAtStart(key);
        return;
    }

    if(key > this->tail->key) { // new key is larger than tail->key=> insert at end
        this->insertAtEnd(key);
        return;
    }
    // search for correct position to insert
    bool inserted = false;
    while(inserted == false) {
        prev = current;
        current = current->next;

        if(key < current->key) {
            prev->next = newItem;
            newItem->previous = prev;
            newItem->next = current;
            current->previous = newItem;

            inserted = true;
        } else {
            continue;
        }
    }
}

void DoublyLinkedList::deleteItem(int key) {
    ExtendedListItem* current = this->head;
    while(current != nullptr) {
        if(key == current->key) {
            if(current->previous == nullptr) { // item to delete is head
                current->next->previous = nullptr;
                this->head = current->next;
            } else {
                current->previous->next = current->next;
            }

            if(current->next == nullptr) { // item to delete is tail
                current->previous->next = nullptr;
                this->tail = current->previous;
            } else {
                current->next->previous = current->previous;
            }

            delete current;
            std::cout << key << " deleted!" << std::endl;
            return;
        }
        current = current->next;
    }
    return;
}

void DoublyLinkedList::print() {
    ExtendedListItem* temp = this->head;
    if(temp == nullptr) {
        std::cout << "PRINT LIST: <Empty List>" << std::endl;
        return;
    }
    std::cout << "******************PRINT LIST***********************" << std::endl;
    while(temp != nullptr) {
        std::cout << temp->MakeItemString();
        temp = temp->next;
    }
    std::cout << "***************************************************" << std::endl;
}

void DoublyLinkedList::append(DoublyLinkedList* appendingList) {
    if(appendingList->head != nullptr && appendingList->tail != nullptr) {
        this->tail->next = appendingList->head;
        appendingList->head->previous = this->tail;
        this->tail = appendingList->tail;

        appendingList->head = nullptr;
        appendingList->tail = nullptr;
    }
}

void DoublyLinkedList::integrates(DoublyLinkedList* integratingList) {
    if(integratingList->head != nullptr && integratingList->tail != nullptr) {
        ExtendedListItem* temp = integratingList->head;
        while(temp != nullptr) {
            this->insertSorted(temp->key);
            temp = temp->next;
        }

        integratingList->head = nullptr;
        integratingList->tail = nullptr;
    }
}

void DoublyLinkedList::splice(DoublyLinkedList* insertingList, int position) {
    if(insertingList->head != nullptr & insertingList->tail != nullptr) {
        ExtendedListItem* current = nullptr;
        current = this->head;

        for(int i = 0; i < position; i++) {
            current = current->next;
        }
        current->previous->next = insertingList->head;
        insertingList->head->previous = current->previous;
        insertingList->tail->next = current;
        current->previous = insertingList->tail;

        insertingList->head = nullptr;
        insertingList->tail = nullptr;
    }
}