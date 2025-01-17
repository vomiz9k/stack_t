
#define STACKCONSTRUCT( _stack ) stack_construct(_stack, #_stack)
#define STACKDESTRUCT( _stack ) stack_destruct(_stack)

typedef int stack_type;
const int  CANARYCONST1 = 0xFAAAAAAC,
           CANARYCONST2 = 0XFAAAAACC,
           DATACANARYCONST1 = 0xFAAAACCC,
           DATACANARYCONST2 = 0xFAAACCCC,
           POISON = -123456789;

enum error_names
{
    STACK_POINTER = 1,
    DATA_POINTER,
    CANARY,
    UNDERFLOW,
    OVERFLOW,
    BAD_SIZE,
    BAD_HASH
};

enum func_asks
    {
        NEEDPOP,
        NEEDPUSH,
        CONSTRUCT,
        DESTRUCT
    };

struct stack_t
{
    #ifdef _DEBUG

    long int canary_1;
    char* name;

    #endif

    stack_type* data;
    int size;
    int max_size;

    #ifdef _DEBUG

    long long int hash_sum;
    long int canary_2;

    #endif
};

int stack_destruct(stack_t* _stack);
bool stack_construct(stack_t* _stack, char stack_name[]);
bool stack_push(stack_t* _stack, stack_type value);
stack_type stack_pop(stack_t* _stack);
void check_size(stack_t* _stack, int parameter);

long long int get_hash(stack_t _stack);
int stack_not_ok(stack_t *_stack, int func);
bool stack_dump(stack_t* _stack, int err_int);

#include "stack.cpp"
