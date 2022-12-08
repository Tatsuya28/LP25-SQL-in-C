#include "sql.h"

#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

/**
 * Check the presence of a sequence of one to an indeterminate number of spaces from the sql position.
 * @param sql Pointer to a position in the sql query.
 * @return char* Pointer to the first occurrence of a non-space character.
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
 * Check for a sequence of 0 or more spaces, then for the character c once, then for 0 or more spaces.
 * @param sql Pointer to a position in the sql query.
 * @param c Character to skip once
 * @return char* Pointer to the position in the query after the character and spaces.
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

/**
 * Check that the keyword is identical to the word whose first character is pointed to by sql. The keyword is not
 * case sensitive.
 * @param sql Pointer to a position in the sql query.
 * @param keyword Keyword to check in the sql query.
 * @return char* Pointer to the position in the query after the keyword.
 */
char *get_keyword(char *sql, char *keyword) {
    if (!sql || !keyword)
        return NULL;

    bool valid = true;

    sql = get_sep_space(sql);

    // Check if the keyword is present
    while (valid && *keyword != '\0') {
        if (toupper(*sql) != toupper(*keyword))
            valid = false;
        sql++;
        keyword++;
    }

    if (valid)
        return sql;
    else
        return NULL;
}

/**
 * Extract a field name, a table name, or a field value (before converting it to a given type).
 * @param sql Pointer to a position in the sql query.
 * @param field_name Buffer where to copy the field name, table name or field value.
 * @return char* Pointer to the position in the query after the field name, table name or field value.
 */
char *get_field_name(char *sql, char *field_name) {
    if (!sql || has_reached_sql_end(sql))
        return NULL;

    int i = 0;

    // Check if there is a simple quote character
    if (*sql == '\'') {
        sql++;
        while (*sql != '\'' || !has_reached_sql_end(sql)) {
            field_name[i] = *sql;
            i++;
            sql++;
        }

        // Check if sql has not reached its end before the simple quote character ending the field name
        if (has_reached_sql_end(sql))
            return NULL;

        field_name[i] = '\0';
    } else {
        while ((isalnum(*sql) || *sql == '_' || *sql == '.' || *sql == '-') && !has_reached_sql_end(sql)) {
            // Continues until a non-alphanumeric character or the end of the sql string
            field_name[i] = *sql;
            i++;
            sql++;
        }

        field_name[i] = '\0';
        if (field_name[0] == '\0')
            return NULL;
    }

    return sql;
}

/**
 * Check if it is the end of the sql query by looking if there are only spaces until the string's end.
 * @param sql Pointer to a position in the sql query.
 * @return true If it is the end of the sql query.
 * @return false If it is not the end of the sql query.
 */
bool has_reached_sql_end(char *sql) {
    if (!sql)
        return NULL;

    sql = get_sep_space(sql);

    if (*sql == '\0' || *sql == ';')
        return true;
    else
        return false;
}

/**
 * Extract a list of fields or values. The result is stored in the data structure table_record_t pointed by result.
 * @param sql Pointer to a position in the sql query.
 * @param result Pointer to the list of values or fields names in an organised data structure.
 * @return char* Pointer to the position in the query after the list of fields or values.
 */
char *parse_fields_or_values_list(char *sql, table_record_t *result) {
    if (!sql || !result)
        return NULL;

    char field[TEXT_LENGTH];
    bool continue_parsing = true;
    bool parenthesis_opened = false;

    sql = get_sep_space(sql);

    if (*sql == '(') {
        sql++;
        parenthesis_opened = true;
    }

    while (continue_parsing) {
        if (has_reached_sql_end(sql))
            continue_parsing = false;
        else {
            sql = get_field_name(sql, field);

            if (!sql)
                return NULL;

            result->fields[result->fields_count].field_type = TYPE_UNKNOWN;
            strcpy(result->fields[result->fields_count].field_value.text_value, field);
            result->fields_count++;

            // Check if the list of fields or values continues with the presence of a comma ','
            if (get_sep_space_and_char(sql, ',') != NULL)
                sql = get_sep_space_and_char(sql, ',');
            else
                continue_parsing = false;
        }
    }

    if (!sql)
        return NULL;

    // Check if the list of fields or values ends with a parenthesis as it has an opened parenthesis.
    if (parenthesis_opened && get_sep_space_and_char(sql, ')') != NULL) {
        sql = get_sep_space_and_char(sql, ')');
        return sql;
    } else if (!parenthesis_opened) {
        return sql;
    } else {
        printf("Error: Expected ')'\n");
        return NULL;
    }
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