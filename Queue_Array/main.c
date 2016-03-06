//
//  main.c
//  Queue_Array
//
//  Created by chenyufeng on 16/3/6.
//  Copyright © 2016年 chenyufengweb. All rights reserved.
//

/**
 *  使用静态数组来实现循环队列
 */

#include <stdio.h>

#define QUEUE_SIZE 5

static int queue[QUEUE_SIZE];
static int head = 0;
static int tail = 0;

//进队列
void EnQueue(int value){

    //要先判断队列是否已满
    if ((tail + 1) % QUEUE_SIZE == head) {
        printf("队列已满，无法从队尾插入元素\n");
    }else{

        queue[tail] = value;
        tail = (tail + 1) % QUEUE_SIZE;
    }
}

//出队列
int DeQueue(){

    int temp;
    if (tail == head) {
        printf("队列为空，元素无法出队列\n");
    }else{

        temp = queue[head];
        head = (head + 1) % QUEUE_SIZE;
    }

    printf("%d\n",temp);
    return temp;
}

//判断队列是否为空
int IsEmpty(){
    if (head == tail) {
        printf("队列为空\n");
        return 1;
    }

    printf("队列不为空\n");
    return 0;
}

//判断队列是否已满
/**
 *  我这里判断队满的的方法：
 牺牲一个单元来区分队空和队满，入队时少用一个队列单元。如果数组的大小为Size,那么实际只能存放(Size-1)个元素。（这是比较常用的判满的方式）
 *
 */
int IsFull(){

    if ((tail + 1) % QUEUE_SIZE == head) {
        printf("队列已满\n");
        return 1;
    }

    printf("队列未满\n");
    return 0;
}

//打印出队列元素
void PrintQueue(){

    for (int i = head; i < tail; i++) {
        printf("%d ",queue[i]);
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {

    EnQueue(4);EnQueue(1);EnQueue(2);EnQueue(9);EnQueue(8);
    PrintQueue();

    DeQueue();DeQueue();
    PrintQueue();
    
    return 0;
}
