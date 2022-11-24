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

    // naive way
    // while (sql[0] == ' ')
    //    sql++;
    while (isspace(*sql)) // better way
        sql++;

    return sql;
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

    sql = get_sep_space(sql);

    // Check if the character is present
    if (*sql == c)
        sql++;
    else
        return NULL;

    sql = get_sep_space(sql);

    return sql;
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