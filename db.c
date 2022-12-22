#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char * buffer;
    size_t buffer_len;
    ssize_t input_len;
    /* data */
} db_input_buffer;

// intialize a input buffer for user
db_input_buffer* new_input_buffer() {
    db_input_buffer* input_buffer = malloc(sizeof(db_input_buffer));
    memset(input_buffer, 0x00, sizeof(db_input_buffer));
}
void print_prompt() { printf("db > "); }

void read_input(db_input_buffer* input_buffer) {
    ssize_t read_bytes = getline(&(input_buffer->buffer), &(input_buffer->buffer_len), stdin);

    if (read_bytes <= 0)
    {
        printf("Error input \n");
        exit(EXIT_FAILURE);
    }
    
    input_buffer->input_len = read_bytes - 1;
    input_buffer->buffer[read_bytes - 1] = 0;
}

void clean_buffer(db_input_buffer* input_buffer) {
    free(input_buffer->buffer);
    free(input_buffer);
}

int main(int argc, char* argv[]) {
    // alloc the buffer
    db_input_buffer* input_buffer = new_input_buffer();
    
    while (true) {
        print_prompt();
        read_input(input_buffer);

        if (!strcmp(input_buffer->buffer, ".exit")) {
            clean_buffer(input_buffer);
            printf("Exit Successfully! \n");
            exit(EXIT_SUCCESS);
        } else {
            printf("Unrecognized command '%s'\n", input_buffer->buffer);
        }
        
    }
    
    printf("hello world\n");
}