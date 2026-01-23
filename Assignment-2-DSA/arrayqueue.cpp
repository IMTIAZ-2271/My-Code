#include "queue.h"
#include <iostream>
using namespace std;
// Constructor implementation
ArrayQueue::ArrayQueue(int initial_capacity)
{
    // TODO: Initialize data members (data, capacity, front_idx, rear_idx)
    // TODO: Allocate memory for the array with the specified initial capacity
    if(initial_capacity < 2)
    {
        initial_capacity = 2;
    }
    data = new int[initial_capacity];
    capacity = initial_capacity;
    front_idx = 0;
    rear_idx = -1;
}

// Destructor implementation
ArrayQueue::~ArrayQueue()
{
    // TODO: Free the dynamically allocated memory for the array
    delete[] data;
    data = nullptr;
    capacity = 0;
    front_idx = 0;
    rear_idx = -1;
}

// Enqueue implementation (add an item to the rear of the queue)
void ArrayQueue::enqueue(int item)
{
    // TODO: Check if the array is full
    // TODO: If full, resize the array to double its current capacity
    // TODO: Add the new element to the rear of the queue
    int size = this->size();
    if( size == capacity || rear_idx == capacity -1){
        resize(capacity * 2);
    }

   rear_idx++;
   data[rear_idx] = item;
}

// Dequeue implementation (remove an item from the front of the queue)
int ArrayQueue::dequeue()
{
    // TODO: Check if the queue is empty, display error message if it is
    // TODO: Decrement current_size and return the element at the front of the queue
    // TODO: Update front index
    // TODO: If the array is less than 25% full, resize it to half its current capacity (but not less than 2)
    // TODO: Return the dequeued element
    if(rear_idx == -1 ){
        cerr << "Queue is empty, cannot dequeue." << endl;
        return -1; 
    }
    int dlt_value = data[front_idx];
    front_idx++;
    if(front_idx > rear_idx){
        front_idx = 0;
        rear_idx = -1;
    }
    int current_capacity = (rear_idx - front_idx + 1);
    if(current_capacity < capacity/4 && capacity > 2){
        resize(capacity/2);
    }
    return dlt_value;
}

// Clear implementation
void ArrayQueue::clear()
{
    // TODO: Reset the queue to be empty (reset capacity, front_idx, rear_idx, data)
    delete[] data;
    capacity = 2;
    data = new int[capacity];
    front_idx = 0;
    rear_idx = -1;
}

// Size implementation
int ArrayQueue::size() const
{
    // TODO: Return the number of elements currently in the queue
    if(rear_idx == -1){
        return 0;
    }
    return (rear_idx - front_idx + 1);
}

// Front implementation
int ArrayQueue::front() const
{
    // TODO: Check if the queue is empty, display error message if it is
    // TODO: Return the element at the front of the queue without removing it
    if(rear_idx == -1 ){
        cerr << "Queue is empty, cannot get front element." << endl;
        return -1; 
    }
    return data[front_idx];
}

// Back implementation (get the element at the back of the queue)
int ArrayQueue::back() const
{
    // TODO: Check if the queue is empty, display error message if it is
    // TODO: Return the element at the back of the queue without removing it
    if(rear_idx == -1 ){
        cerr << "Queue is empty, cannot get back element." << endl;
        return -1; 
    }
    return data[rear_idx];
}

// Empty implementation
bool ArrayQueue::empty() const
{
    // TODO: Return whether the queue is empty (current_size == 0)
    int current_size = size();
   return (current_size == 0);
}

// Print implementation
string ArrayQueue::toString() const
{
    // TODO: Convert queue to a string representation in the format: <elem1, elem2, ..., elemN|
    if(rear_idx == -1 ){
        return "<|";
    }
    string result = "<";
    for(int i = front_idx ; i <= rear_idx; i++){
        result += to_string(data[i]);
        if(i != rear_idx){
            result += ", ";
        }
    }
    result += "|";
    return result;
}

// Resize implementation
void ArrayQueue::resize(int new_capacity)
{
    // TODO: Create a new array with the new capacity
    // TODO: Copy elements from the old array to the new array
    // TODO: Delete the old array
    // TODO: Update the data pointer and capacity
    // TODO: Update front and rear indices
    if(new_capacity<2){
        new_capacity = 2;
    }
    int *newdata = new int[new_capacity];
    int temp_idx = -1;
    for(int i = front_idx; i<=rear_idx; i++){
        newdata[++temp_idx] = data[i];
    }
    delete[] data;
    data = newdata;
    front_idx = 0;
    rear_idx = temp_idx;
    capacity = new_capacity;
}

int ArrayQueue::getCapacity() const
{
    // TODO: Return the current capacity of the queue
    return this->capacity;
}