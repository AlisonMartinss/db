#include <stdbool.h>
#include <stdio.h>

#include "utils.h"

#ifndef TABLE_H
#define TABLE_H

#define MAX_COLUMNS 100
#define MAX_NAME_SIZE 100
#define MAX_COLUMN_NAME 100
#define MAX_STRING_SIZE 100
#define MAX_REGISTER_SIZE 100

struct Column {
    char name[MAX_COLUMN_NAME];
    enum Type type;
    char type_s[20];

    union {
        unsigned int data_uint[MAX_REGISTER_SIZE];
        int data_int[MAX_REGISTER_SIZE];
        float data_float[MAX_REGISTER_SIZE];
        double data_double[MAX_REGISTER_SIZE];
        char data_char[MAX_REGISTER_SIZE];
        char data_string[MAX_REGISTER_SIZE][MAX_STRING_SIZE];
    };
};

struct Table {
    char name[MAX_NAME_SIZE];
    unsigned int num_columns;
    unsigned int num_rows;
    unsigned int primary_key_index;
    struct Column columns[MAX_COLUMNS];
};

enum Result create_table(char* table_name);

void list_tables();

enum Result list_data(char table_name[]);

enum Result delete_table(char table_name[]);

int delete_table_file(char table_name[]);

int table_already_exists(char table_name[]);

enum Result add_data(char table_name[]);

enum Result delete_data(char table_name[], unsigned int pk);

void print_data(struct Column col, enum Type type, size_t idx);

enum Result update_table_row(struct Table* t);

enum Result search_data(
    char table_name[], char col_name[], char value[], struct Table t);

bool primary_key_exists(struct Table* t, unsigned int pk);

enum Result get_table_info(char table_name[], struct Table* t);

bool column_exist(char column_name[], struct Table t);

void get_numerical_values(
    struct Column col, unsigned int num_rows, double* data);

#endif
