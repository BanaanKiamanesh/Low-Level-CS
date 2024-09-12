#include <stdio.h>
#include <stdlib.h>

// Stack Impl using Arrays
struct Stack
{
    int size;
    int top;
    int *S;
};

void Create(struct Stack *st, int Size)
{
    st->size = Size;
    st->top = -1;
    st->S = (int *)malloc(st->size * sizeof(int));
}

void Display(struct Stack st)
{
    int i;
    for (i = st.top; i >= 0; i--)
        printf("%d ", st.S[i]);
    printf("\n");
}

void Push(struct Stack *st, int x)
{
    if (st->top == st->size - 1)
        printf("Stack overflow\n");
    else
        st->S[++st->top] = x;
}

int Pop(struct Stack *st)
{
    int x = -1;
    if (st->top == -1)
        printf("Stack Underflow\n");
    else
        x = st->S[st->top--];

    return x;
}

int Peek(struct Stack st, int index)
{
    int x = -1;
    if (st.top - index + 1 < 0)
        printf("Invalid Index \n");

    x = st.S[st.top - index + 1];

    return x;
}

int isEmpty(struct Stack st) { return (st.top == -1) ? 1 : 0; }

int isFull(struct Stack st) { return (st.top == st.size) - 1; }

int StackTop(struct Stack st) { return (!isEmpty(st)) ? st.S[st.top] : -1; }

int main()
{
    struct Stack st;
    Create(&st, 4);

    printf("is MT %d\n", isEmpty(st));
    printf("is Full %d\n", isFull(st));

    Push(&st, 10);
    Push(&st, 20);
    Push(&st, 30);
    Push(&st, 40);

    printf("is MT %d\n", isEmpty(st));
    printf("is Full %d\n", isFull(st));

    printf("Stack Top: %d \n", StackTop(st));
    printf("Element 3: %d \n", Peek(st, 2));

    Display(st);

    return 0;
}