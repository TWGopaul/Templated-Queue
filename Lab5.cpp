//Programmer: Travis Gopaul
//Date: 10/31/20
//Lab5.cpp
//Driver for Queue data structure

#include <iostream>
#include "Queue.h"
#include "Students.h"

using namespace std;

int main()
{
	//variable to get user input
	char queueChoice, userInput;

	cout << "Choose a queue to create: " << endl;
	cout << "1. Queue of Integers" << endl;
	cout << "2. Queue of Students" << endl;
	
	cin >> queueChoice;
	
	//input validation
	while ((queueChoice < '1') && (queueChoice > '2'))	
	{
		cout << "Please make valid selection: " << endl;
		cin >> queueChoice;
	}//end while

	Queue<int> i_queue;		//create queue of int
	Queue<Students*> s_queue;	//create queue of students


        do	 //present menu until user enters 4 to quit	
        {
                cout << "Queue Menu" << endl;
                cout <<"==========" << endl;
                cout << "1) enQueue() : insert a new element at the end of the Queue" << endl;
                cout << "2) deQueue() : remove an element from the front of the Queue" << endl;
                cout << "3) topQueue() : need display data in the top of Queue" << endl;
                cout << "4)  Quit" << endl;

                cin >> userInput;

                //input verification
                while((userInput < '1')&&(userInput > 4))
                {
                        cout << "Please make valid selection: " << endl;
                }//end while 

                if(userInput == '1')		//insert a node
                {
			system("clear");
			
			if(queueChoice == '1')		//if int queue
			{
                       		if(i_queue.isFull()) 	//if queue is full display message and do nothing
                                	cout << "Queue is full." << endl;
                        
                        	else			//else gather data and insert into queue
                        	{
                               		int data;	//variable to hold user input
                                	cout << "Enter int to push onto queue: " << endl;
                                	cin >> data;	//get user input
                                	i_queue.enQueue(data);	//insert into queue
                        	}//end else
			}//end if

			else			//if student queue
			{
                        	if(s_queue.isFull())	//if queue is full display message and do nothing
                        	        cout << "Queue is full." << endl;
                        	else			//else create a new student		
                        	{
                               		Students *data = new Students();
                               		s_queue.enQueue(data);		//insert student data into queue
                        	}//end else
			}//end else
                }//end if 1

		if(userInput == '2')		//delete a node from queue
                {
			system("clear");

			if(queueChoice == '1')		//if int queue
			{
                        	if(i_queue.isEmpty())		//if queue is empty display message and do nothing
                                	cout << "Queue is empty." << endl;
                        	else				//if queue is not empty
                        		i_queue.deQueue();	//delete the front node
			}//end if
			
			else				//if student queue
			{
                                if(s_queue.isEmpty())		//if queue is empty display message and do nothing
                                        cout << "Queue is empty." << endl;
                                else				//if queue is not empty
					s_queue.deQueue();	//delete the front node
			}//end else
                }//end if 2

                if(userInput == '3')		//print the front node
                {
			system("clear");

			if(queueChoice == '1')		//if int queue
			{	
                        	if(i_queue.isEmpty())		//if queue is empty display message and do nothing
                        	        cout << "Queue is empty." << endl;
                        	else				//if queue is not empty print data from front node
                		        cout << i_queue.topQueue() << endl;
			}//end if
			else				//if student queue
			{
                                if(s_queue.isEmpty())		//if queue is empty display message and do nothing
                                        cout << "Queue is empty." << endl;
                                else				//if queue is not empty print data from the front node
				{
					s_queue.topQueue()->printStudent();
			       		cout << endl;
				}//end else
			}//end else
                }//end if 3
        }//end do
        //program exits when user enters 4
        while(userInput != '4');
}//end main
