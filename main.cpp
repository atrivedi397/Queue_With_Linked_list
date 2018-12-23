#include <iostream>
#include "Queue.h"
#include "swapping.h"
using namespace std;

int size, answer0, answer1 , no_of_elements ,  priority = 0;
float element_i ;
bool flag = true;
Super_queue<float>s_float;
p_queue<float>p_float;

template<typename  T>
void lq_functions(Super_queue <T>object) {
    cout << "\nWhat is the size of the queue?\n";
    cin >> size;
    do {
        cout << "\nThese are the operations on the \n1. Insert\n2. Delete\n3. Display\n4. Exit\n";
        cin >> answer1;
        switch (answer1)
        {
            case 1 :
            {
                if (no_of_elements == size)
                {
                    cout << "\nQueue Overflow!! Aborting. Please Delete First.\n";
                    object.display();
                }
                else
                {
                    cout << "\nEnter your element.\n";
                    cin >> element_i;
                    object.insert(element_i);
                    no_of_elements = object.traversal();
                    object.display();
                }
            }
                break;
            case 2 :
                object.delete_node();
                break;

            case 3 :
                object.display();
                break;

            case 4 :
                exit(0);

            default :
                cout << "\nEnter valid input.\n";
        }
    } while (flag);
}


template<typename T>
void pq_functions(p_queue <T>object)
{
    cout<<"\nWhat is the size of the queue?\n";
    cin>>size;
    do
    {
        cout<<"\nThese are the operations on the \n1. Insert\n2. Delete\n3. Display\n4. Exit\n";
        cin>>answer1;
        switch (answer1)
        {
            case 1 :
            {
                if(no_of_elements == size)
                {
                    cout<<"\nQueue Overflow!! Aborting.\n";
                    object.display();
                }
                else
                {
                    cout<<"\nEnter your element and priority one by one.\n";
                    cin>>element_i>>priority;
                    object.insert(element_i,priority);
                    no_of_elements = object.traversal();
                    object.display();
                }
            }
            break;

            case 2 : object.delete_node();
            break;

            case 3 :  object.display();
            break;

            case 4 : exit(0);

            default : cout<<"\nEnter valid input\n";
        }
    }while(flag);
}

void full_operations()
{
    cout<<"\nWhich type of queue you want to implement?\n\n1. Linear\n2. Priority\n3. Circular\n";
    cin>>answer0;
    if(answer0 == 1)
    {
        lq_functions(s_float);
    }

    if(answer0 == 2)
    {
        pq_functions(p_float);
    }
}

int main() {
    swapping object;
    full_operations();


    int a = 9;
    float b = 1.2;
    cout << "\n\n\na = " << a << "  b = " << b << endl;
    object.swap(&a, &b);
    std::cout << "a = " << a << " b = " << b << endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}