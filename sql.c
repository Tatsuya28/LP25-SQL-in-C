#include "sql.h"

#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

/**
 * Checks the presence of a sequence of one to an indeterminate number of spaces from the sql position.
 * @param sql the string to check
 * @return a pointer to the first non-space encountered
 */
char *get_sep_space(char *sql) {
    if (!sql)
        return NULL;

    char* copy_sql = sql;

    while (copy_sql[0] == ' ')
        copy_sql++;

    return copy_sql;
}


/**
 * Checks for a sequence of 0 or more spaces, then for the character c once, then for 0 or more spaces.
 * @param sql the string to check
 * @param c the unique character
 * @return a pointer to the character following this sequence
 */
char *get_sep_space_and_char(char *sql, char c) {
    if (!sql)
        return NULL;

    char* copy_sql = sql;
    bool separator_found = false;

    while (copy_sql[0] == ' ' || copy_sql[0] == c) {
        if (copy_sql[0] == c)
            separator_found = true;

        copy_sql++;
    }

    if (!separator_found)
        return NULL;

    return get_sep_space(copy_sql);
}

char *get_keyword(char *sql, char *keyword) {
    return sql;
}

char *get_field_name(char *sql, char *field_name) {
    return sql;
}

bool has_reached_sql_end(char *sql) {
    return false;
}

char *parse_fields_or_values_list(char *sql, table_record_t *result) {
    return sql;
}

char *parse_create_fields_list(char *sql, table_definition_t *result) {
    return sql;
}

char *parse_equality(char *sql, field_record_t *equality) {
    return sql;
}

char *parse_set_clause(char *sql, table_record_t *result) {
    return sql;
}

char *parse_where_clause(char *sql, filter_t *filter) {
    return sql;
}

query_result_t *parse(char *sql, query_result_t *result) {
    return NULL;
}

query_result_t *parse_select(char *sql, query_result_t *result) {
    return NULL;
}

query_result_t *parse_create(char *sql, query_result_t *result) {
    return NULL;
}

query_result_t *parse_insert(char *sql, query_result_t *result) {
    return NULL;
}

query_result_t *parse_update(char *sql, query_result_t *result) {
    return NULL;
}

query_result_t *parse_delete(char *sql, query_result_t *result) {
    return NULL;
}

query_result_t *parse_drop_db(char *sql, query_result_t *result) {
    return NULL;
}

query_result_t *parse_drop_table(char *sql, query_result_t *result) {
    return NULL;
}