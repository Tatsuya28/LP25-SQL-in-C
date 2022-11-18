cmake_minimum_required(VERSION 3.23)
project(SQL_project C)

set(CMAKE_C_STANDARD 99)

add_executable(SQL_project project.c sql.c sql.h utils.c utils.h check.c check.h table.h table.c expand.c expand.h query_exec.c query_exec.h database.c database.h record_list.c record_list.h)
