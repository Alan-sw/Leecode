/*
 * =====================================================================================
 *
 *       Filename:  shm_com.h
 *
 *    Description:  define a share memory
 *
 *        Created:  10/14/2015 04:22:35 PM
 *       Compiler:  gcc
 *
 *         Author:  Alan Lee , 1127259111@qq.com
 *
 * =====================================================================================
 */
#define TEXT_SZ 2048

struct shared_use_st {
    int written_by_you;
    char some_text[TEXT_SZ];
};
