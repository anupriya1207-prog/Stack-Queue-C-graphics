#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

#define MAX_SIZE 5
#define MAX_HEIGHT 400
#define BASE_Y 450
#define BASE_X 100
#define WIDTH 50
#define HEIGHT 30

// Structure of a stack
struct stack {
    int items[MAX_SIZE];
    int top;
};

// Initialize the stack
void initialize(struct stack *s) {
    s->top = -1;
}

// Check if the stack is full
int isFull(struct stack *s) {
    return s->top == MAX_SIZE - 1;
}

// Check if the stack is empty
int isEmpty(struct stack *s) {
    return s->top == -1;
}

// Push an element onto the stack
void push(struct stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++s->top] = value;
}

// Pop an element from the stack
int pop(struct stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->items[s->top--];
}

// Visualize the stack using graphics
void visualize(struct stack *s, int gd, int gm) {
    initgraph(&gd, &gm, ""); // Initialize graphics mode

    setbkcolor(WHITE); // Set background color
    cleardevice(); // Clear screen

    // Draw base line
    line(BASE_X, BASE_Y, BASE_X + MAX_SIZE * WIDTH, BASE_Y);

    // Draw stack elements
    for (int i = 0; i <= s->top; i++) {
        int x = BASE_X + i * WIDTH;
        int y = BASE_Y - (i + 1) * HEIGHT;
        rectangle(x, y, x + WIDTH, y + HEIGHT);
        char num[5];
        sprintf(num, "%d", s->items[i]);
        outtextxy(x + 10, y + 10, num);
    }

    delay(2000); // Delay to show the graphics
    closegraph(); // Close graphics mode
}

// Main function to demonstrate the stack operations
int main() {
    int gd = DETECT, gm; // Detect graphics driver and mode
    struct stack s;
    initialize(&s);

    push(&s, 10);
    visualize(&s, gd, gm);
    push(&s, 20);
    visualize(&s, gd, gm);
    push(&s, 30);
    visualize(&s, gd, gm);
    push(&s, 40);
    visualize(&s, gd, gm);
    push(&s, 50);
    visualize(&s, gd, gm);

    printf("Popped element: %d\n", pop(&s));
    visualize(&s, gd, gm);
    printf("Popped element: %d\n", pop(&s));
    visualize(&s, gd, gm);
    printf("Popped element: %d\n", pop(&s));
    visualize(&s, gd, gm);
    printf("Popped element: %d\n", pop(&s));
    visualize(&s, gd, gm);
    printf("Popped element: %d\n", pop(&s));
    visualize(&s, gd, gm);

    return 0;
}