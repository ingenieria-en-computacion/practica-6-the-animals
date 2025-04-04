#pragma once
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define QUEUE_CAPACITY 100

typedef struct {
    int data[QUEUE_CAPACITY];
    int front;
    int rear;
} CircularQueue;

CircularQueue* queue_create() {
    CircularQueue* queue = malloc(sizeof(CircularQueue));
    queue->front = queue->rear = 0;
    return queue;
}

bool queue_is_empty(CircularQueue* queue) {
    return queue->front == queue->rear;
}

bool queue_is_full(CircularQueue* queue) {
    return (queue->rear + 1) % QUEUE_CAPACITY == queue->front;
}

bool queue_enqueue(CircularQueue* queue, int value) {
    if (queue_is_full(queue)) return false;
    queue->data[queue->rear] = value;
    queue->rear = (queue->rear + 1) % QUEUE_CAPACITY;
    return true;
}

bool queue_dequeue(CircularQueue* queue, int* value) {
    if (queue_is_empty(queue)) return false;
    *value = queue->data[queue->front];
    queue->front = (queue->front + 1) % QUEUE_CAPACITY;
    return true;
}

void queue_destroy(CircularQueue* queue) {
    free(queue);
}
