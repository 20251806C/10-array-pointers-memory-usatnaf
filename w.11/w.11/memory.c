#include <stdio.h>

int* bp, * sp;
int* stack[1024];  // Change to an array of pointers to integers
int stackindex = 0;

void show() {
    printf("---------------------------\n");
    printf("현재 스택 상태 (top -> bottom):\n");
    for (int i = stackindex - 1; i >= 0; i--) {
        int* addr = stack[i];
        int value = *addr;
        printf("stack[%d]: %p (address), %d (value)\n", i, addr, value);
    }
    printf("basepointer (bp): %p\n", (void*)bp);
    printf("stackpointer (sp): %p\n", (void*)sp);
}

void push(int* value) {
    stack[stackindex++] = value;
    sp = &stack[stackindex];
}

int* pop() {
    if (stackindex > 0) {
        sp = &stack[--stackindex];
        return stack[stackindex];
    }
    return NULL; // Return NULL if the stack is empty
}

void test(int a, int b, int c) {
    int x = a + b;
    int y = b + c;
    int z = c + a;

    printf("test 함수의 진입-스택프레임 생성\n");

    push((int*)&x);
    push((int*)&y);
    push((int*)&z);

    show();

    printf("test()함수 반환 스택 프레임 해제\n");
    pop();
    pop();
    pop();

    bp = pop();

    show();
}

int main(void) {
    int a = 10, b = 20, c = 30;

    printf("main() 함수 시작- 초기 스택 상태\n");

    push((int*)&a);
    push((int*)&b);
    push((int*)&c);

    bp = stack[0]; // Set bp to the first item in the stack (starting point)

    show();

    printf("test()함수 호출\n");
    test(a, b, c);

    printf("main 함수 종료 스택 상태 복구\n");

    pop();
    pop();
    pop();

    show();

    return 0;
}
