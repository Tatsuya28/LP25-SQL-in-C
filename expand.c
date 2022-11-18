#include "expand.h"

void expand(query_result_t *query) {
    if (query->query_type == QUERY_SELECT) {
        expand_select(&query->query_content.select_query);
    } else if (query->query_type == QUERY_INSERT) {
        expand_insert(&query->query_content.insert_query);
    }
}

void expand_select(update_or_select_query_t *query) {
}

void expand_insert(insert_query_t *query) {
}

bool is_field_in_record(table_record_t *record, char *field_name) {
    return false;
}

void make_default_value(field_record_t *field, char *table_name) {
}