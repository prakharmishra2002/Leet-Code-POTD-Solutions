typedef struct {
    int* data;
    int size;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)malloc(capacity * sizeof(int));
    stack->size = 0;
    stack->capacity = capacity;
    return stack;
}

void push(Stack* stack, int value) {
    if (stack->size < stack->capacity) {
        stack->data[stack->size++] = value;
    }
}

int pop(Stack* stack) {
    if (stack->size > 0) {
        return stack->data[--stack->size];
    }
    return -1;
}

int isEmpty(Stack* stack) { return stack->size == 0; }

void freeStack(Stack* stack) {
    free(stack->data);
    free(stack);
}

char* clearStars(char* s) {
    int n = strlen(s);
    Stack* cnt[26];
    for (int i = 0; i < 26; i++) {
        cnt[i] = createStack(n);
    }
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != '*') {
            push(cnt[s[i] - 'a'], i);
        } else {
            for (int j = 0; j < 26; j++) {
                if (!isEmpty(cnt[j])) {
                    s[pop(cnt[j])] = '*';
                    break;
                }
            }
        }
    }

    char* ans = calloc(strlen(s) + 1, sizeof(char));
    for (int i = 0, j = 0; s[i] != '\0'; i++) {
        if (s[i] != '*') {
            ans[j++] = s[i];
        }
    }
    for (int i = 0; i < 26; i++) {
        freeStack(cnt[i]);
    }

    return ans;
}
