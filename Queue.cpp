//Programmer: Travis Gopaul
//Date: 10/29/20
//Queue.cpp
//Function definitions for Queue.h

#include "Queue.h"


//Queue constructor
template<class DataType>
Queue<DataType>::Queue(int x)
{
	front = NULL;	//back and front pointers point to NULL until nodes are inserted
	back = NULL;	
	queueSize = x; //queue size is 10 by default if no parameters passes in
	queueCnt = 0; //initial queue size is 0
}//end constructor


//Queue destructor
template<class DataType>
Queue<DataType>::~Queue()
{
	while(!(isEmpty())) 	//while Queue is not empty
	{
		deQueue();	//call deQueue to delete the front node	
	}//end while
}//end destructor


//Function to insert node into queue
//Pass in data; create a Queue node with the data; insert at the end
template<class DataType>
void Queue<DataType>::enQueue(const DataType data)
{
	QueueNode<DataType> *newNode;		//pointer to a Queue node
	newNode = new QueueNode<DataType>;	//set pointer equal to a newly created node
	newNode->data = data;			//set the new Queue node's data to the data passed into the function

	if(isEmpty())			//if Queue is empty
	{
		front = newNode;		//set front pointer to new node
		back = newNode;			//set back pointer to new node
	}//end if
	else				//if queue is not empty
	{
		QueueNode<DataType> *temp;	//temp pointer to hold a place
		temp = back;			//set temp equal to current rear
		back = newNode;			//set current rear to the new node at the end of the queue
		temp->next = back;		//temp is now pointing to the second to last node, set that node's next to the current rear
	}//end else
	queueCnt ++;			//increase the queue's count of nodes
}//end enQueue


//function to delete the node in the front of the Queue
template<class DataType>
DataType Queue<DataType>::deQueue()
{
	QueueNode<DataType> *temp;	//temp pointer to hold a place
	temp = front;			//set temp equal to the current front

	if(queueCnt == 1)	//if there is only one node in the queue
	{
		temp = front;		//set temp equal to the node
		front = NULL;		//set front to NULL
		back = NULL;		//set back to NULL
		delete temp;		//delete temp
	}//end if
	else			//else if there are more than 1 node
	{
		front = front->next;	//set front equal to the next node in the queue
		delete temp;		//delete the old front node
	}//end else
	queueCnt--;			//decrease the queue's count of nodes	
}//end deQueue


//function that returns front node
template<class DataType>
DataType Queue<DataType>::topQueue() const
{
	return front->data;	//return the data from the front node in the queue
}//end topQueue


//function returns true if queue is empty, false if it has nodes
template<class DataType>
bool Queue<DataType>::isEmpty() const
{
	return (queueCnt == 0) ? true:false; //if queue is empty return true, else return false
}//end isEmpty


//function returns true if queue is full, false if it isn't
template<class DataType> 
bool Queue<DataType>::isFull() const
{
	return (queueCnt == queueSize ) ? true : false; //if queue is full return true, else return false
}//end isEmpty


