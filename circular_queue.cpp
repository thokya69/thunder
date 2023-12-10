//circularqueue
#include<iostream>
using namespace std;

class Queue
{
    public:
    int rear=-1,front=-1;
    int size, element;
    int Q[5];
    Queue()
    {
        size=5;
    }
    void enQueue()
    {
        if((front==0&&rear==size-1)||(front==rear+1))
        cout<<"Queue is Full";
        
        else
        {
            cout<<"Enter the Element to be Inserted";
            cin>>element;
            if(rear==size-1&&front!=0)
            rear =-1;
            Q[++rear]=element;
            if(front==-1)
            front=0;
        }
    }
    void deQueue()
    {
        if(front==-1&&rear==-1)
        {
            cout<<"Queue is empty";
        }
        else
        {
            cout<<"Deleted element is"<<Q[front++];
            if(front==size)
            front=0;
            if(front-1==rear)
            front=rear=-1;
        }
    }
    void display()
    {
        if(front==-1)
        cout<<"Circular queue is empty";
        else
        {
            int i=front;
            cout<<"Elements are";
            if(front<=rear)
            {
                while(i<=rear)
                cout<<" "<<Q[i++];
            }
            else
            {
                while(i<=size-1)
                cout<<" "<<Q[i++];
                i=0;
                while(i<=rear)
                cout<<" "<<Q[i++];
            }
        }
    }
};

int main()
{
    int choice;
    Queue obj;
    while(1)
    {
        cout<<"\nMenu\n";
        cout<<"1.insert\n2.delete\n3.display\n4.exit\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
            obj.enQueue();
            break;
            case 2:
            obj.deQueue();
            break;
            case 3:
            obj.display();
            break;
            case 4:
            exit(0);
        }
    }
}