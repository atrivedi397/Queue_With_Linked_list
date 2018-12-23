#pragma once

/*****Implementing queue using Single linked list********/

template<typename T>
class Super_queue
{
public:
    virtual void insert(T to_be_inserted);
    virtual void delete_node();
    virtual void display();
    virtual int traversal();
    Super_queue* get_front_rear(int);
    Super_queue* front = nullptr;
    Super_queue* rear = nullptr;

    int priority = 0;
    T value;
    Super_queue<T> *next;
};

template<typename T>
void Super_queue<T>::insert(T to_be_inserted)
{
    Super_queue* temp; Super_queue* get_rear;
    temp = new Super_queue;
    temp->value = to_be_inserted;
    temp->next = nullptr;
    if(front == nullptr && rear == nullptr)
    {
        front = temp;
        rear = temp;
    }
    else
    {
        get_rear = get_front_rear(2);
        get_rear->next = temp;
        rear = temp;
    }
}

template<typename T>
Super_queue<T>* Super_queue<T>::get_front_rear(int a)
{
    return a == 1 ? front : rear;
}

template<typename T>
void Super_queue<T>::delete_node()
{
    Super_queue* temp;
    temp = get_front_rear(1);
    front = temp->next;
    delete temp;
    display();
}

template<typename T>
void Super_queue<T>::display()
{
    Super_queue* temp;
    temp = get_front_rear(1);
    if(temp == nullptr)
    {
        std::cout<<"\nUnderflow!!!! No Element present.\n";
        return;
    }
    else
    {
        std::cout<<"\nYour queue is :\n";
        while(temp != nullptr)
        {
            std::cout<<temp->value<<" <- ";
            temp = temp->next;
        }
    }
}

template<typename T>
int Super_queue<T>::traversal()
{
    Super_queue* temp; int count = 0;
    temp = get_front_rear(1);

    while(temp != nullptr)
    {
        temp = temp->next;
        count++;
    }

    return count;
}

template<typename T>
class p_queue : public Super_queue<T>
{
public:
    void insert(T to_be_inserted , int prior);
    Super_queue<T>* traversal_for_p_q(int);
    void display();
};

template<typename T>
void p_queue<T>::insert(T to_be_inserted , int prior)
{
    p_queue* temp; Super_queue<T>* traversed;    //traversed is used for position where it has to be inserted according to prior
    temp = new p_queue;
    temp->value = to_be_inserted;
    temp->priority = prior;
    temp->next = nullptr;

    //insertion if queue is blank
    if(Super_queue<T>::front == nullptr)
    {
        Super_queue<T>::front = temp;
        Super_queue<T>::rear = temp;
    }
        //insertion if queue's front's prior is less than given then creating a new front
    else if(prior < Super_queue<T>::front->priority)
    {
        temp->next = Super_queue<T>::front;
        Super_queue<T>::front = temp;
    }
        //insertion if queue's rear's prior is less than or equal given then creating a new rear and FCFS rule
    else if(prior >= Super_queue<T>::rear->priority)
    {
        Super_queue<T>::rear->next = temp;
        Super_queue<T>::rear = Super_queue<T>::rear->next;
    }
        //inserting according to the prior
    else
    {
        traversed = traversal_for_p_q(prior);
        temp->next = traversed->next;
        traversed->next = temp;
    }
}

template<typename T>
Super_queue<T>* p_queue<T>::traversal_for_p_q(int prior)
{
    Super_queue<T>* temp;
    temp = Super_queue<T>::get_front_rear(1);
    while(temp->next->priority <= prior)
        temp = temp->next;

    return temp;
}

template<typename T>
void p_queue<T>::display()
{
    Super_queue<T>::display();

    Super_queue<T>* ptr = Super_queue<T>::get_front_rear(1);

    if(ptr == nullptr)
    {
        std::cout<<"\nUnderflow Case . No element Present\n";
        return;
    }
    else
    {
        std::cout<<"\nYour queue is :\n";
        while(ptr != nullptr)
        {
            std::cout<<ptr->value<<"("<<ptr->priority<<")<-";
            ptr = ptr->next;
        }
    }
}

//
// Created by atrivedi on 3/29/18.
//