#ifndef RUN_LEN_ENCODING
#define RUN_LEN_ENCODING

#define MAX_TEMP_BUFFER_LEN 12
#define MAX_BUFFER_LEN 1024 //  HACK: Using static arrays instead of dynamic allocation 🙂 

void encode(const char *const text, char result[MAX_BUFFER_LEN]);
void decode(const char *const data, char result[MAX_BUFFER_LEN]);

#endif 
