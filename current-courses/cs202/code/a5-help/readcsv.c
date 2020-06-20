#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE  1252
#define MAX_LINE    1024

typedef struct {
    char *id;
    char *first_name;
    char *last_name;
    char *email;
    char *gender;
    char *company_name;
} info_t;

info_t *process_line(char *line);
info_t *make_info(char *id, char *first_name, char *last_name, char *email, 
                  char *gender, char *company_name);
int identity_hash(char *key);
void hash_insert(info_t *table[], info_t *info);
info_t *hash_search(info_t *table[], char *id);

int main()
{
    FILE *fd = fopen("./data.csv", "r");

    if(!fd) {
        fprintf(stderr, "Error: Unable to open data.csv!\n");
        exit(1);
    }

    info_t *table[TABLE_SIZE];   // <---- This is the hash table
    char buffer[MAX_LINE];
    while(fgets(buffer, MAX_LINE, fd) != NULL) {
        // Remove that pesky newline
        int line_length = strlen(buffer) - 1;
        if(buffer[line_length] == '\n') buffer[line_length] = '\0';
        info_t *curr_info = process_line(buffer);
        hash_insert(table, curr_info);
    }

    return 0;
}

info_t *process_line(char *line)
{
    char *id = strtok(line, ",");
    char *first_name = strok(NULL, ",");
    char *last_name = strok(NULL, ",");
    char *email = strok(NULL, ",");
    char *gender = strok(NULL, ",");
    char *company_name = strok(NULL, ",");
    return make_info(id, first_name, last_name, email, gender, company_name);
}

info_t *make_info(char *id, char *first_name, char *last_name, char *email, 
                  char *gender, char *company_name)
{
    info_t *info = (info_t *)malloc(sizeof(info_t));
    if(!info) {
        fprintf(stderr, "Error: malloc failed!\n");
        exit(1);
    }
    info->id = strdup(id);
    info->first_name = strdup(first_name);
    info->last_name = strdup(last_name);
    info->email = strdup(email);
    info->gender = strdup(gender);
    info->company_name = strdup(company_name);
    return info;
}

int identity_hash(char *key)
{
    int sum = 0;
    int len = strlen(key);
    for(int i = 0; i < len; i++) {
        sum += i * key[i];
    }
    return sum % TABLE_SIZE;
}

void hash_insert(info_t *table[], info_t *info)
{
    int index = identity_hash(info->id);

    // Linear probing
    int start_index = index;
    while(table[index] != NULL) {
        index = (index + 1) % TABLE_SIZE;
        if(index == start_index) {
            fprintf(stderr, "Error: Hash table full!\n");
            exit(1);
        }
    }

    table[index] = info;
}

info_t *hash_search(info_t *table[], char *id)
{
    // NEXT STEP!
    // 1. Hash id
    // 2. Linear probe until id matches table[index]->id, return table[index]
    // 3. If you don't find match (start_index == index), return NULL
}
