#include <iostream>
using namespace std;

// 只用两个变量front和rear，长度为n的队列，
// 可以容纳的最大元素个数是多少？
// 答：最大元素个数是n-1
// 如果不保留一个空位，则空队列和满队列时:(rear + 1) % n == front都满足
// 所以，为了区分空和满队列，必须保留一个空位
// 空队列：（rear+1） % n == front
// 满队列：（rear+2） % n == front

// 如果不愿意浪费队列的存储单元，还可以采用什么方法？
// 答：可以增加一个变量count，表示当前的元素个数

// 顺序队列：固定的存储空间
// 链式队列：可以满足大小无法估计的情况

#define DEFAULT_QUQUE_SIZE 10

// 保留一个空位的队列的实现
template <class T>
class CQueue{
public:
    CQueue(int size=DEFAULT_QUQUE_SIZE) {
        m_size = size + 1;
        front = 0; rear = -1;
        queue = new T[m_size];
    }
    ~CQueue() {
        if(queue) delete[] queue;
    }
    // 入队前先判断，如果rear和front之间只隔了一个位置，则为满队
    bool enqueue(const T& newvalue) {
        if((rear + 2) % m_size == front) return false;
        rear = (rear + 1) % m_size;
        queue[rear] = newvalue;
        return true;
    }
    // 出队前先判断，如果length《=0，则为空队列
    bool dequeue(T& newvalue) {
        if(length() <= 0) return false;
        newvalue = queue[front];
        front = (front + 1) % m_size;
        return true;
    }
    bool frontValue(T& value) const {
        if(length() <= 0) return false;
        value = queue[front];
        return true;
    }
    void clear() {
        front = 0; rear = -1;
    }
    int length() const {
        return (rear - front + 1 + m_size) % m_size;
    }
private:
    int m_size;
    int front;
    int rear;
    T* queue;
};

template <class T>
class CNoWasteQueue {
public:
    CNoWasteQueue(int size=DEFAULT_QUQUE_SIZE) {
        m_size = size;
        count = 0;
        front = 0; rear = -1;
        queue = new T[m_size];
    }
    ~CNoWasteQueue() {
        delete[] queue;
    }
    bool enqueue(const T& newvalue) {
        if(count >= m_size) return false;
        rear = (rear + 1) % m_size;
        queue[rear] = newvalue;
        count++;
        return true;
    }
    bool dequeue(T& newvalue) {
        if(count <= 0) return false;
        newvalue = queue[front];
        front = (front + 1) % m_size;
        count--;
        return true;
    }
    bool frontValue(T& newvalue) const{
        if(count <= 0) return false;
        newvalue = queue[front];
        return true;
    }
    void clear() {
        front = 0; rear = -1; count = 0;
    }
    int length() const {
        return count;
    }
private:
    int m_size;
    int front;
    int rear;
    int count; // 增加变量count以避免一个空间的浪费
    T* queue;
};

// 链式队列的实现
template <class T>
class CLinkedQueue {
public:
    CLinkedQueue() {
        front = rear = NULL;
    }
    ~CLinkedQueue() {
        clear();
    }
    bool enqueue(const T& newvalue) {
        if(front == NULL) {
            front = rear = new T(newvalue.item, NULL);
        } else {
            rear->next = new T(newvalue.item, NULL);
            rear = rear->next;
            count++;
        }
        return true;
    }
    bool dequeue(T& newvalue) {
        if(front == NULL) return false;
        T* temp;
        newvalue.item = front->item;
        newvalue.next = NULL;
        temp = front->next;
        delete front;
        front = temp;
        if(front == NULL) rear = NULL;
        count--;
        return true;
    }
    bool frontValue(T& newvalue) const {
        if(front == NULL) return false;
        newvalue.item = front->item;
        newvalue.next = NULL;
        return true;
    }
    void clear() {
        T* temp;
        while(front) {
            temp = front->next;
            delete front;
            front = temp;
        }
        count = 0;
    }
    int length() const {
        return count;
    }
private:
    int count;
    T* front;
    T* rear;
};


typedef struct ELEM{
    int item;
    ELEM* next;
}ELEM;


int main(int argc, char const *argv[])
{
    CQueue<int> queue;
    int value;
    cout << queue.dequeue(value) << endl;

    CNoWasteQueue<int> q2;
    cout << q2.dequeue(value) << endl;

    CLinkedQueue<ELEM> q3;
    ELEM temp;
    cout << q3.dequeue(temp) << endl;


    return 0;
}